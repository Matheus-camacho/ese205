#include <Servo.h>      // include the servo library
 
Servo myServo;  
#define MAX_SIGNAL 2000
#define MIN_SIGNAL 1000
#define MOTOR_PIN 9

int DELAY = 1000; 
int servoPin = 10; 
int motorPin=9;  
int servoAngle = 0; 


void setup() {      
  myServo.attach(servoPin);
  Serial.begin(9600);
  Serial.println("ELECTRONOOBS ESC calibration...");
  Serial.println(" ");
  delay(1500);
  Serial.println("Program begin...");
  delay(1000);
  Serial.println("This program will start the ESC.");

  motor.attach(MOTOR_PIN);

  Serial.print("Now writing maximum output: (");Serial.print(MAX_SIGNAL);Serial.print(" us in this case)");Serial.print("\n");
  Serial.println("Turn on power source, then wait 2 seconds and press any key.");
  motor.writeMicroseconds(MAX_SIGNAL);

  // Wait for input
  while (!Serial.available());
  Serial.read();

  // Send min output
  Serial.println("\n");
  Serial.println("\n");
  Serial.print("Sending minimum output: (");Serial.print(MIN_SIGNAL);Serial.print(" us in this case)");Serial.print("\n");
  motor.writeMicroseconds(MIN_SIGNAL);
  Serial.println("The ESC is calibrated");
  Serial.println("----");
  Serial.println("Now, type a values between 1000 and 2000 and press enter");
  Serial.println("and the motor will start rotating.");
  Serial.println("Send 1000 to stop the motor and 2000 for full throttle");
} 


int pos = 0;
void loop()
{ 
  if (Serial.available() > 0)
  {
    int DELAY = Serial.parseInt();
    if (DELAY > 999)
    {
      
      motor.writeMicroseconds(DELAY);
      float SPEED = (DELAY-1000)/10;
      Serial.print("\n");
      Serial.println("Motor speed:"); Serial.print("  "); Serial.print(SPEED); Serial.print("%"); 
    }else{
    switch (DELAY){
      case 6:
       myServo.attach(servoPin);
       myServo.write(0); 
       delay(2000); 
       myServo.write(90); 
       delay(1000); 
       break;
      case 7:
       myServo.attach(servoPin);
       myServo.write(180); 
       delay(2000); 
       myServo.write(90); 
       delay(1000); 
       break;
      }
      myServo.detach();  
      
      } 
  }
}
