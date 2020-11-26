volatile int value = 0;

void setup() {
  Serial.begin(9600);
  cli(); //Disable interrupts

  //Zero ADMUX and ADCSRA
  ADMUX ^= ADMUX;
  ADCSRA ^= ADCSRA;

  ADCSRA |= (1 << ADEN); //Enable ad-conversion conversion
  ADCSRA |= 0x7; //Set ad-conversion prescalar to 128
  ADCSRA |= (1 << ADIE); //Enable ad-conversion interrupt
  
  ADCSRA |= (1 << ADSC); //Start first conversion
  sei(); //Enable interrupts
}

void loop() {
  ADCSRA |= (1 << ADSC); //Start subsequent conversions
  
  float Ux = value * 5 / 1023.0f; //Conver ad value to voltage
  float Ir = (5 - Ux) / 10000; //Calculate current for the circuit
  float Rx = Ux / Ir; //And solve the resistor value

  Serial.print(value); //Print ad
  Serial.print("\t");  //One tab
  Serial.println(Rx);  //Pirnt resistor value
    
  delay(100); //Wait 100ms
}

//Interrupt service routine for ad-conversion
ISR(ADC_vect) {
  value = ADCL | (ADCH << 8);
}
