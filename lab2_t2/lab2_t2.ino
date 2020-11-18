//Variables for soring value states and channel state
volatile int status = 0, i0 = 0, i1= 0;
//Variables for storing read values
volatile int value0[10] = { 0 }, value1[10] = { 0 };

void setup() {
    
  Serial.begin(9600);
  cli(); //Disable interrupts

  //Zero both registers
  ADMUX ^= ADMUX;
  ADCSRA ^= ADCSRA;
  
  ADCSRA |= (1 << ADEN); //Enable analog converter
  ADCSRA |= 0x7;  //Set prescalar to 128
  ADCSRA |= (1 << ADIE); //Enable analog converter interrupt
  
  ADCSRA |= (1 << ADSC); //Start the first conversion
  sei(); //Enable interrupts
}

void loop() {
  int result0 = 0, result1 = 0; //Variables for calculating average
  ADCSRA |= (1 << ADSC); //Start the conversion again

  //Sum all the values
  for (int i = 0; i < 10; i++) {
  	result0 += value0[i];
    result1 += value1[i];
  }

  //And divide byte count of values for average
  result0 /= 10;
  result1 /= 10;

  //Print the result
  Serial.print("A0: ");
  Serial.print(result0);
  Serial.print("\tA1: ");
  Serial.println(result1);
  
  delay(100); //Wait for 100ms
}


//AD-conversion interrupt service routine
ISR(ADC_vect) {
  switch(status) {
    case 0:
    	if(i0 == 10) i0 = 0; //Set i back to 0
    	//Combine the upper and lower registers for a result
    	value0[i0++] = ADCL | (ADCH << 8); 
    	ADMUX |= 1; //Switch channel to the second channel
    	//ADCSRA |= (1 << ADSC);
    	status = 1; //Switch status for different channel
    	break;
    case 1:
    	if(i1 == 10) i1 = 0; //Set i back to 0
      //Combine the upper and lower registers for a result
    	value1[i1++] = ADCL | (ADCH << 8);
    	ADMUX &= 0xf0; //Switch back to the first channel
    	//ADCSRA |= (1 << ADSC);
    	status = 0; //Switch status for different channel
    	break;
  }
}
