/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define LS 11      // left sensor
#define RS 10      // right sensor
#define CS 12

/*-------definning Outputs------*/
#define LM1 5       // left motor
#define LM2 3       // left motor
#define RM1 9       // right motor
#define RM2 6       // right motor
#define MOTOR_SPEED 128
int motorSpeed = 128;
void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  Serial.print(digitalRead(LS));
  Serial.print(digitalRead(CS));
  Serial.print(digitalRead(RS));
  Serial.println();
  if(digitalRead(LS)==0 && digitalRead(RS)==0)     // Move Forward
  {
    //motorSpeed = 200;
    //digitalWrite(LM1, HIGH);
    //digitalWrite(LM2, LOW);
    //digitalWrite(RM1, HIGH);
    //digitalWrite(RM2, LOW);
    analogWrite(LM1,motorSpeed);
    analogWrite(LM2, 0);
    analogWrite(RM1, motorSpeed);
    analogWrite(RM2, 0);
  }
  if(digitalRead(CS)==1)
  {
    //motorSpeed = 200;
    analogWrite(LM1,motorSpeed);
    analogWrite(LM2, 0);
    analogWrite(RM1, motorSpeed);
    analogWrite(RM2, 0);
  }
  
  if((!digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
    //motorSpeed = 200;
    //digitalWrite(LM1, LOW);
    //digitalWrite(LM2, LOW);
    //digitalWrite(RM1, HIGH);
    //digitalWrite(RM2, LOW);
    analogWrite(LM1,motorSpeed);
    analogWrite(LM2,0);
    analogWrite(RM1,0);
    analogWrite(RM2,0);
  }
  
  if((digitalRead(LS)) && (!digitalRead(RS)))     // turn left
  {
    //motorSpeed = 200;
    //digitalWrite(LM1, HIGH);
    //digitalWrite(LM2, LOW);
    //digitalWrite(RM1, LOW);
    //digitalWrite(RM2, LOW);
    analogWrite(LM1, 0);
    analogWrite(LM2,0);
    analogWrite(RM1,motorSpeed);
    analogWrite(RM2,0);
  }
  
  if((digitalRead(LS)==1) && (digitalRead(RS)==1) && digitalRead(CS)==1)     // stop
  {
    motorSpeed = 0;
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
    //digitalWrite(LM1, LOW);
    //digitalWrite(LM2, LOW);
    //digitalWrite(RM1, LOW);
    //digitalWrite(RM2, LOW);
  }
}

