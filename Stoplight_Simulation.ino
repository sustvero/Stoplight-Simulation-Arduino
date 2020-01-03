//NS light
int NSred = 10;
int NSyellow = 9;
int NSgreen = 8;
int NWB2 = 2;
volatile int NSredState = 0;
volatile int NSyellowState = 0;
volatile int NSgreenState = 0;
//EW light
int EWred = 7;
int EWyellow = 6;
int EWgreen = 5;
int SWB1 = 3;
int EWgreen = 0;
volatile int EWredState = 0;
volatile int EWyellowState = 0;
volatile int EWgreenState = 0;

void setup() {
  Serial.begin(9600);
  //NS light
  pinMode(NSred, OUTPUT);
  pinMode(NSyellow, OUTPUT);
  pinMode(NSgreen, OUTPUT);
  pinMode(NWB2, INPUT);
  
  //EW light
  pinMode(EWred, OUTPUT);
  pinMode(EWyellow, OUTPUT);
  pinMode(EWgreen, OUTPUT);
  pinMode(SWB1, INPUT);
  
  //initialize vector interrupts
  attachInterrupt(1, pedestrian1, RISING);
  attachInterrupt(0, pedestrian2, RISING); 

  
}

void loop() {
   
  digitalWrite(NSred, NSredState);
  digitalWrite(NSyellow, NSyellowState);
  digitalWrite(NSgreen, NSgreenState);
  digitalWrite(EWred, EWredState);
  digitalWrite(EWyellow, EWyellowState);
  digitalWrite(EWgreen, EWgreenState);
  delay(1000);
  
  
}

void pedestrian1() {
  delay(100);
  if (digitalRead(NSred) == HIGH && digitalRead(SWB1) == HIGH) {
    Serial.println("button pressed");
    delay(100);
    cross1();
   
  }
}

 void pedestrian2() {
    delay(10);
    if (digitalRead(EWred) == HIGH && digitalRead(NWB2) == HIGH) {
      cross2();
     
      
    }
  }
  
void changeLights() {
  
  //NS light is red, EW light is green
  
  digitalWrite(EWgreen, HIGH);
  delay(9000);
  
  //EW light turns yellow
  digitalWrite(EWred, LOW);
  digitalWrite(EWgreen, LOW);
  digitalWrite(EWyellow, HIGH);
  delay(2000);
  
  //NS light turns green, EW light turns red
  digitalWrite(NSred, LOW);
  digitalWrite(NSgreen, HIGH);
  digitalWrite(EWyellow, LOW);
  digitalWrite(EWred, HIGH);
  delay(9000);
  
  //NS light turns yellow
  digitalWrite(EWred, HIGH);
  digitalWrite(NSgreen, LOW);
  digitalWrite(NSyellow, HIGH);
  delay(2000);
  
  digitalWrite(NSyellow, LOW);
  digitalWrite(EWred, LOW);
}

void cross2() {
  //change NS light to yellow
    digitalWrite(NSgreen, LOW);
    digitalWrite(NSyellow, HIGH);
    delay(2000);

    //change NS light to red, EW light to green
    digitalWrite(NSyellow, LOW);
    digitalWrite(NSred, HIGH);
    digitalWrite(EWred, LOW);
    digitalWrite(EWgreen, HIGH);
    delay(5000);

    //change EW light to yellow
    digitalWrite(NSred, HIGH);
    digitalWrite(EWgreen, LOW);
    digitalWrite(EWyellow, HIGH);
    delay(2000);
      
    digitalWrite(NSred, LOW);
    digitalWrite(NSgreen, HIGH);
    digitalWrite(EWyellow, LOW);
    digitalWrite(EWred, HIGH);
    delay(5000);
}

void cross1() {
  //change EW light to yellow
    digitalWrite(EWgreen, LOW);
    digitalWrite(EWyellow, HIGH);
    delay(2000);

    //change EW light to red, NS light to green
    digitalWrite(EWyellow, LOW);
    digitalWrite(EWred, HIGH);
    digitalWrite(NSred, LOW);
    digitalWrite(NSgreen, HIGH);
    delay(5000);

    //change NS light to yellow
    digitalWrite(NSgreen, LOW);
    digitalWrite(NSyellow, HIGH);
    delay(2000);
    
    digitalWrite(NSyellow, LOW);
    digitalWrite(NSred, HIGH);
    digitalWrite(EWred, LOW);
    digitalWrite(EWgreen, HIGH);
    delay(5000);
    
}

  
  
  
  
