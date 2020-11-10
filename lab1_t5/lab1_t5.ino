//Seven segment display pin order {f, g, b, a, d, e, c}.
int pins[] = {1, 2, 3, 4, 5, 6, 7};

unsigned long interval = 2000; //Number draw delay.
unsigned long previous_time; //Previous draw time.
char state = 0; //Animation state.
void (*num[10])(); //Function pointer array for all the numbers.

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
  for (int i = 0; i < 7; i++) {
  	pinMode(pins[i], OUTPUT);
  }

  //Assignment of the function pointers.
  num[0] = number0;
  num[1] = number1;
  num[2] = number2;
  num[3] = number3;
  num[4] = number4;
  num[5] = number5;
  num[6] = number6;
  num[7] = number7;
  num[8] = number8;
  num[9] = number9;

  //Random seed initialization.
  unsigned long seed = analogRead(A0);
  randomSeed(seed);
  unsigned long rnd = random(sizeof(long) * 8);
  seed = analogRead(A1);
  seed += rnd;
  randomSeed(seed);
}

void loop()
{
  unsigned long time = millis();
  if (time - previous_time >= interval) { //Number generation and printing for 2 seconds
  	char rnd = random(0, 8);
  	num[rnd]();
    state = 0;
    delay(2000);
    previous_time = millis();
  }

  //Animation between numbers
  switch(state) {
   case 0:
    reset();
    digitalWrite(pins[0], HIGH);
    state++;
    break;
   case 1:
    reset();
    digitalWrite(pins[6], HIGH);
    state++;
    break;
   case 2:
    reset();
    digitalWrite(pins[4], HIGH);
    state++;
    break;
   case 3:
    reset();
    digitalWrite(pins[5], HIGH);
    state++;
    break;
   case 4:
    reset();
    digitalWrite(pins[1], HIGH);
    state++;
    break;
   case 5:
    reset();
    digitalWrite(pins[3], HIGH);
    state++;
    break;
   case 6:
    reset();
    digitalWrite(pins[2], HIGH);
    state = 1;
    break;
  }
  delay(75);
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
