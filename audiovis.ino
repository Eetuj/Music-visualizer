int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int button = 9;
String mic = "A0";
String knob = "A1";
int sensorvalue;
int sens;
int buttonState;
int randomizer;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);
  sens = map(abs(analogRead(A1)), 0, 1023, 10, 1);
  sensorvalue = abs(analogRead(A0)) * sens;
  sensorvalue = map(sensorvalue, 0, 900, 6, 0);
  //Serial.println(sens);
  //Serial.println(sensorvalue);

  shutDown();

  if(buttonState == LOW) {
    randomizer = random(0, 3);
    switch (randomizer){
      case 1:
        ledAnimation1();
        break;
      case 2:
        ledAnimation2();
        break;
      default:
        break;
    }
  }

  switch (sensorvalue){
    case 0:
      digitalWrite(led1, HIGH);
    case 1:
      digitalWrite(led2, HIGH);
    case 2:
      digitalWrite(led3, HIGH);
    case 3:
      digitalWrite(led4, HIGH);
    case 4:
      digitalWrite(led5, HIGH);
    case 5:
      digitalWrite(led6, HIGH);
    case 6:
      digitalWrite(led7, HIGH);
    default:
      break;
  }
  
}

void shutDown() {
  for(int i = 2; i < 9; i++) {
    digitalWrite(i, LOW);
  }
}

void ledAnimation1() {

  shutDown();

  digitalWrite(led1, HIGH);
  digitalWrite(led7, HIGH);
  delay(250);
  digitalWrite(led1, LOW);
  digitalWrite(led7, LOW);

  digitalWrite(led2, HIGH);
  digitalWrite(led6, HIGH);
  delay(250);
  digitalWrite(led2, LOW);
  digitalWrite(led6, LOW);

  digitalWrite(led3, HIGH);
  digitalWrite(led5, HIGH);
  delay(250);
  digitalWrite(led3, LOW);
  digitalWrite(led5, LOW);

  digitalWrite(led4, HIGH);
  delay(250);
  digitalWrite(led4, LOW);
  
}

void ledAnimation2() {

  shutDown();

  for(int i = 2; i < 9; i++) {
    digitalWrite(i, HIGH);
    delay(250);
    digitalWrite(i, LOW);
  }
  
}
