        #include <BluetoothSerial.h>
BluetoothSerial BTSerialBT;

#define motorRE D0 //ena
#define motorLE D1 //enb
#define motorR1 D4 // in1
#define motorR2 D9 //in2
#define motorL1 D13 //in3
#define motorL2 D14 // in4
int hiz= 150;
void setup() {
  Serial.begin(115200);
  BTSerialBT.begin("DeneyapKartVakkasileYagiz");
  pinMode(motorRE,OUTPUT);
  pinMode(motorLE,OUTPUT);
  pinMode(motorR1,OUTPUT);
  pinMode(motorR2,OUTPUT);
  pinMode(motorL1,OUTPUT);
  pinMode(motorL2,OUTPUT);
  
  }
            
void loop() {
  while(BTSerialBT.available()){
  char veri = (char) BTSerialBT.read();
    switch(veri){
      case 'W':
        {
          digitalWrite(motorR1,HIGH);
          digitalWrite(motorR2,LOW);
  analogWrite(motorRE,hiz);
            digitalWrite(motorL1,HIGH);
          digitalWrite(motorL2,LOW);
  analogWrite(motorLE,hiz);
          break;
        }
      case 'S':
        {
              digitalWrite(motorR1,LOW);
          digitalWrite(motorR2,HIGH);
  analogWrite(motorRE,hiz);
            digitalWrite(motorL1,LOW);
          digitalWrite(motorL2,HIGH);
  analogWrite(motorLE,hiz);
          break;
        }
      case 'A':
        {
            digitalWrite(motorR1,HIGH);
          digitalWrite(motorR2,LOW);
  analogWrite(motorRE,hiz);
            digitalWrite(motorL1,LOW);
          digitalWrite(motorL2,LOW);
  analogWrite(motorLE,hiz);
          break;
        }
      case 'D':
        {
          digitalWrite(motorR1,LOW);
          digitalWrite(motorR2,LOW);
  analogWrite(motorRE,hiz);
            digitalWrite(motorL1,HIGH);
          digitalWrite(motorL2,LOW);
  analogWrite(motorLE,hiz);
          break;
        }
      case 'O':
        {
             digitalWrite(motorR1,LOW);
          digitalWrite(motorR2,LOW);
  analogWrite(motorRE,hiz);
            digitalWrite(motorL1,LOW);
          digitalWrite(motorL2,LOW);
  analogWrite(motorLE,hiz);
          break;
        }
    }
  }
    
}


