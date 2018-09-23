#include <Servo.h>  // Includes servo library.
// defines pins numbers
const int trigPin = 12;
const int echoPin = 11;
#define M1A 4
#define M1B 5

#define M2A 8
#define M2B 9
const int servoPin=13;

Servo myservo;

// defines variables
long duration;
int distance;
int distance_f;
int distance_r;
int distance_l;
int maxLowDistance=40;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

 pinMode(M1A,OUTPUT);
  pinMode(M1B,OUTPUT);
  pinMode(M2A,OUTPUT);
  pinMode(M2B,OUTPUT);

myservo.attach(servoPin);
myservo.write(90);
delay(1000);

Serial.begin(9600); // Starts the serial communication
}


void loop() {
 
Break();
  
  myservo.write(90);
  distance_f=ping();
   Serial.println(distance_f);
   if(distance_f >= maxLowDistance){

   
       front();
     Serial.println("forward");
     delay(300);
          
    }

    else{

      if (distance_f<= (maxLowDistance-10)){

          back();
          delay(500);
        
        }
      
      Break();
  
    
  
       

      
      delay(100);
       myservo.write(10);
     distance_r= ping();
      delay(1000);
       
      Serial.println("look right=");
      Serial.println(distance_r);
        delay(500);
      myservo.write(170);
      distance_l= ping();
      delay(1000);
      
      Serial.println(" look left =");
      Serial.println(distance_l);
      
      myservo.write(90);

        
        
      if (distance_r > distance_l ){
        right();
        delay(1500);
        myservo.write(145);
        delay(500);
        int second_left= ping();
        if(second_left<30){
          right();
          delay(1000);
          }
        
      
        
        }
      else{
        
        left();
          delay(1500);
          myservo.write(45);
          delay(500);
        int second_right= ping();
        if(second_right<30){
          left();
          delay(1000);
       
      
        }
       
     
      }
 
  }
}


  void front(){
  digitalWrite(M1A,1);
  digitalWrite(M2A,1);
  digitalWrite(M1B,0);
  digitalWrite(M2B,0);

    Serial.println("Front");

  
}


void back(){
  digitalWrite(M1A,0);
  digitalWrite(M2A,0);
  digitalWrite(M1B,1);
  digitalWrite(M2B,1);

    Serial.println("Back");
 
}

void left(){
  digitalWrite(M1A,1);
  digitalWrite(M1B,0);
  
  digitalWrite(M2A,0);
  digitalWrite(M2B,1);
    Serial.println("Left");
}

void right(){
  digitalWrite(M1B,1);
  digitalWrite(M1A,0);
  digitalWrite(M2A,0);

  digitalWrite(M2A,1);
    Serial.println("RIght");
}

void Break(){
  digitalWrite(M1B,0);
  

  digitalWrite(M2B,0);

  digitalWrite(M1A,0);
  

  digitalWrite(M2A,0);
  Serial.println("Stop");
  
}

  int ping(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  return distance;
}
