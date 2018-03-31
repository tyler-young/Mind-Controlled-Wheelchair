//turning variables
const int switchPin = 6;
const int enablePin = 7;
//Motor variables
const int frontMotorLB = 12;
const int frontMotorLF = 11;
const int frontMotorRB = 10;
const int frontMotorRF = 9;
const int rearLB = 5;
const int rearLF = 4;
const int rearRB = 3;
const int rearRF = 2;
const int tx = 6;
const int rx = 7;

int toggleR = 1;
int toggleL = 1;

char data = 0;
char prev = 0;
int pinled = 13;

//might have other 

void setup() {
  //Initializing the different inputs for the motor signals
 pinMode(frontMotorLB, OUTPUT);
 pinMode(frontMotorLF, OUTPUT);
 pinMode(frontMotorRB, OUTPUT);
 pinMode(frontMotorRF, OUTPUT);
 pinMode(rearLB, OUTPUT);
 pinMode(rearLF, OUTPUT);
 pinMode(rearRB, OUTPUT);
 pinMode(rearRF, OUTPUT);

 pinMode(pinled, OUTPUT);

 Serial.begin(38400);
 Serial.println("Waiting for command...");
}

void stopMotors() {
  analogWrite(frontMotorLF,0); analogWrite(frontMotorRF,0); analogWrite(frontMotorLB,0); analogWrite(frontMotorRB,0);
  analogWrite(rearLF,0); analogWrite(rearLB,0); analogWrite(rearRF,0); analogWrite(rearRB,0);
  delay(1000);
}

void loop() {

    if( Serial.available() ) {
      data = Serial.read();
      if( data != prev ) {
        stopMotors();
      }
      Serial.println(data);
      prev = data;
    }
    switch(data) {
        case '1': //Forwards
          analogWrite(frontMotorLF, 255);
          analogWrite(frontMotorRF, 255);
          analogWrite(rearLF, 255);
          analogWrite(rearRF, 255);
          break;
        case '2': //Turn left
          analogWrite(frontMotorLB, 255);
          analogWrite(frontMotorRF, 255);
          analogWrite(rearRF, 255);
          analogWrite(rearLB, 255);
          for(int i = 0; i < 10; i++) {
            Serial.read();
            delay(100);      
          }
          break;
        case '3': //Turn Right
          analogWrite(frontMotorLF, 255);
          analogWrite(frontMotorRB, 255);
          analogWrite(rearRB, 255);
          analogWrite(rearLF, 255);
          for(int i = 0; i < 10; i++) {
            Serial.read();
            delay(100);      
          }
          break;
//        default:
//          stopMotors();
//          break;
     }
     delay(100);

//    if(data == '1') {
//        digitalWrite(pinled,HIGH);
//        Serial.println("LED On!");
//      } else if (data == '0') {
//        digitalWrite(pinled,LOW);
//        Serial.println("LED Off!");
//      } else {;}
  
//    analogWrite(frontMotorLF, 255);
//    analogWrite(frontMotorRF, 255);
//    analogWrite(rearRF, 255);
//    analogWrite(rearLF, 255);

  // Left Turn if(toggleL % 2)
  //   analogWrite(frontMotorLB, 100);
  //   analogWrite(frontMotorRF, 100);
  //   analogWrite(rearRF, 100);
  //   analogWrite(rearLB, 100);
  //   
  
  // Right Turn if(toggleR % 2)
  //   analogWrite(frontMotorLF, 100);
  //   analogWrite(frontMotorRB, 100);
  //   analogWrite(rearRB, 100);
  //   analogWrite(rearLF, 100);
  //   delay(3000);

}


