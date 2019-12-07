/****************************************************************************** 
SparkFun Big Easy Driver Basic Demo
Toni Klopfenstein @ SparkFun Electronics
February 2015
https://github.com/sparkfun/Big_Easy_Driver

Simple demo sketch to demonstrate how 5 digital pins can drive a bipolar stepper motor,
using the Big Easy Driver (https://www.sparkfun.com/products/12859). Also shows the ability to change
microstep size, and direction of motor movement.

Development environment specifics:
Written in Arduino 1.6.0

This code is beerware; if you see me (or any other SparkFun employee) at the local, and you've found our code helpful, please buy us a round!
Distributed as-is; no warranty is given.

Example based off of demos by Brian Schmalz (designer of the Big Easy Driver).
http://www.schmalzhaus.com/EasyDriver/Examples/EasyDriverExamples.html
******************************************************************************/
//Declare pin functions on Arduino
#define stp 9
#define dir 6
#define EN  7

//Declare variables for functions
char user_input;
int x;
int y;
int state;

void setup() {
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(EN, OUTPUT);
  resetBEDPins(); //Set step, direction, microstep and enable pins to default states
  Serial.begin(9600); //Open Serial connection for debugging
}

//Main loop
void loop() {
  while(Serial.available()){
      user_input = Serial.read(); //Read user input and trigger appropriate function
      digitalWrite(EN, LOW); //Pull enable pin low to set FETs active and allow motor control
      if (user_input == '1')
      {
        StepForward();
      }
      else if(user_input =='2')
      {
        FrameForward();
      }
      else if(user_input =='3')
      {
        FrameBackward();
      }
      else if(user_input =='4')
      {
        MoveForward();
      }
      else if(user_input =='5')
      {
        MoveBackward();
      }
      else
      {
        //Serial.println("Invalid option entered.");
      }
      resetBEDPins();
  }
}

//Reset Big Easy Driver pins to default states
void resetBEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(EN, HIGH);
}

//
void StepForward()
{
  //Serial.println("Moving forward at default step mode.");
  digitalWrite(dir, HIGH); //Pull direction pin low to move "forward"
  for(x=1; x<2; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  //Serial.println("Enter new option");
  //Serial.println("1");
}

//
void FrameForward()
{
  //Serial.println("Moving forward at frame mode.");
  delay(1500);
  digitalWrite(dir, HIGH); //Pull direction pin high to move in "reverse"
  for(x=1; x<45; x++)  //Loop the stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  //Serial.println("Enter new option");
  delay(1500);
  Serial.println("1");
}

//
void FrameBackward()
{
  //Serial.println("Moving backward at frame mode.");
  delay(2000);
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x=1; x<450; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
  //Serial.println("Enter new option");
  //Serial.println("1");
}

//
void MoveForward()
{
  digitalWrite(dir, HIGH); //Pull direction pin low to move "forward"
  for(x=1; x<10; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
}

//
void MoveBackward()
{
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x=1; x<10; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
}


/*
//Forward/reverse stepping function
void ForwardBackwardStep()
{
  Serial.println("Alternate between stepping forward and reverse.");
  for(x= 1; x<5; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    //Read direction pin state and change it
    state=digitalRead(dir);
    if(state == HIGH)
    {
      digitalWrite(dir, LOW);
    }
    else if(state ==LOW)
    {
      digitalWrite(dir,HIGH);
    }
    
    for(y=1; y<1000; y++)
    {
      digitalWrite(stp,HIGH); //Trigger one step
      delay(1);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(1);
    }
  }
  Serial.println("Enter new option");
  Serial.println();
}
*/
