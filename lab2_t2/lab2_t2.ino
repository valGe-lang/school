
volatile int status = 0, i0 = 0, i1= 0;
volatile int value0[10] = { 0 }, value1[10] = { 0 };

void setup() {
    
  Serial.begin(9600);
  cli(); //Disable interrupts
  
  ADMUX ^= ADMUX;
  ADCSRA ^= ADCSRA;
  
  ADCSRA |= (1 << ADEN); //Enable analog converter
  ADCSRA |= 0x7;  //Set prescalar to 128
  ADCSRA |= (1 << ADIE); //Enable analog converter interrupt
  
  ADCSRA |= (1 << ADSC); //Start the first conversion
  sei(); //Enable interrupts
}

void loop() {
  int result0 = 0, result1 = 0;
  ADCSRA |= (1 << ADSC);
  
  for (int i = 0; i < 10; i++) {
  	result0 += value0[i];
    result1 += value1[i];
  }
  
  result0 /= 10;
  result1 /= 10;
  
  Serial.print("A0: ");
  Serial.print(result0);
  //Serial.print(" : ");
  //Serial.print(value0[0]);
  Serial.print("\tA1: ");
  Serial.println(result1);
  //Serial.print(" : ");
  //Serial.println(value1[0]);
  
  delay(100);
}

ISR(ADC_vect) {
  switch(status) {
    case 0:
    	if(i0 == 10) i0 = 0;
    	value0[i0++] = ADCL | (ADCH << 8);
    	ADMUX |= 1;
    	//ADCSRA |= (1 << ADSC);
    	status = 1;
    	break;
    case 1:
    	if(i1 == 10) i1 = 0;
    	value1[i1++] = ADCL | (ADCH << 8);
    	ADMUX &= 0xf0;
    	//ADCSRA |= (1 << ADSC);
    	status = 0;
    	break;
  }
}
