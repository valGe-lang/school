//Seven segment display pin order {f, g, b, a, d, e, c}.
int pins[] = {1, 2, 3, 4, 5, 6, 7};

//Forward declaration of all the number functions.
void reset();
inline void number9();
inline void number8();
inline void number7();
inline void number6();
inline void number5();
inline void number4();
inline void number3();
inline void number2();
inline void number1();
inline void number0();

void setup()
{
  //Setup all pins as an output.
  for (int i = 0; i < 7; i++) {
  	pinMode(pins[i], OUTPUT);
  }
}

void loop()
{
  //Call all the numbers repeatedly with a 1 second delay between them.
  number0();
  delay(1000);
  number1();
  delay(1000);
  number2();
  delay(1000);
  number3();
  delay(1000);
  number4();
  delay(1000);
  number5();
  delay(1000);
  number6();
  delay(1000);
  number7();
  delay(1000);
  number8();
  delay(1000);
  number9();
  delay(1000);
  
}

void reset() { //Reset the seven segment display by setting all pins to low.
  for (int i = 0; i < 7; i++) {
    digitalWrite(pins[i], LOW);
  }
}

//All the number configurations.
  
inline void number9() {
  reset();
  
  digitalWrite(pins[3], HIGH);
  digitalWrite(pins[1], HIGH);
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[6], HIGH);
  digitalWrite(pins[4], HIGH);
}

inline void number8() {
  reset();
  
  digitalWrite(pins[3], HIGH);
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[1], HIGH);
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[5], HIGH);
  digitalWrite(pins[6], HIGH);
  digitalWrite(pins[4], HIGH);
}

inline void number7() {
  reset();
  
  digitalWrite(pins[3], HIGH);
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[6], HIGH);
}

inline void number6() {
  reset();
  
  digitalWrite(pins[3], HIGH);
  digitalWrite(pins[1], HIGH);
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[5], HIGH);
  digitalWrite(pins[6], HIGH);
  digitalWrite(pins[4], HIGH);
}

inline void number5() {
  reset();
  
  digitalWrite(pins[3], HIGH);
  digitalWrite(pins[1], HIGH);
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[6], HIGH);
  digitalWrite(pins[4], HIGH);
}

inline void number4() {
  reset();
  
  digitalWrite(pins[1], HIGH);
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[6], HIGH);
}

inline void number3() {
  reset();
  
  digitalWrite(pins[3], HIGH);
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[6], HIGH);
  digitalWrite(pins[4], HIGH);
}

inline void number2() {
  reset();
  
  digitalWrite(pins[3], HIGH);
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[0], HIGH);
  digitalWrite(pins[5], HIGH);
  digitalWrite(pins[4], HIGH);
}

inline void number1() {
  reset();
  
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[6], HIGH);
}

inline void number0() {
  reset();
  
  digitalWrite(pins[1], HIGH);
  digitalWrite(pins[2], HIGH);
  digitalWrite(pins[3], HIGH);
  digitalWrite(pins[4], HIGH);
  digitalWrite(pins[5], HIGH);
  digitalWrite(pins[6], HIGH);
}
