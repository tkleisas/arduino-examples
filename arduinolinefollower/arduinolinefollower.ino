/*------ Arduino Line Follower Code
         Based on some example found on the vast archives of the Internet----- */
/*-------defining Inputs------*/
#define LS 11      // left sensor
#define RS 10      // right sensor
#define CS 12      // center sensor

/*-------definning Outputs------*/
#define LM1 5       // left motor
#define LM2 3       // left motor
#define RM1 9       // right motor
#define RM2 6       // right motor
#define MOTOR_SPEED 128
int motorSpeed = 128; // speed at 50% so that we have time to turn
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
  Serial.print(digitalRead(LS)); //log sensor read values for debugging
  Serial.print(digitalRead(CS));
  Serial.print(digitalRead(RS));
  Serial.println();
  if(digitalRead(LS)==0 && digitalRead(RS)==0)     // the edge sensors are white so move on
  {
    analogWrite(LM1,motorSpeed); //both motors on 
    analogWrite(LM2, 0);
    analogWrite(RM1, motorSpeed);
    analogWrite(RM2, 0);
  }
  if(digitalRead(CS)==1) // the center sensor tracks black
  {
    analogWrite(LM1,motorSpeed); //both motors on
    analogWrite(LM2, 0);
    analogWrite(RM1, motorSpeed);
    analogWrite(RM2, 0);
  }
  
  if((!digitalRead(LS)) && digitalRead(RS))   // the left sensor tracks black so turn right
  {
    analogWrite(LM1,motorSpeed);
    analogWrite(LM2,0);
    analogWrite(RM1,0);
    analogWrite(RM2,0);
  }
  
  if((digitalRead(LS)) && (!digitalRead(RS)))  // the right sensor tracks black so turn left
  {
    analogWrite(LM1, 0);
    analogWrite(LM2,0);
    analogWrite(RM1,motorSpeed);
    analogWrite(RM2,0);
  }
  
  if((digitalRead(LS)==1) && (digitalRead(RS)==1) && digitalRead(CS)==1)     // all three sensors track black so stop
  {
    motorSpeed = 0; //setting speed to zero in order to stop
    analogWrite(LM1, 0);
    analogWrite(LM2, 0);
    analogWrite(RM1, 0);
    analogWrite(RM2, 0);
  }
}
