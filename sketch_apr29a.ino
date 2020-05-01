#include <SoftwarSerial.h>
SoftwareSerial BTSerial(2,3);


void setup() {
  {
    Serial.begin(9600);
    BTSerial.begin(9600);

      Serial.println("ESP8266 DEMO");
      Serial.println();


      pinMode(8,OUTPUT);
      pinMode(9,OUTPUT);

     digitalWrite(8 ,LOW);
     digitalWrite(9 ,LOW);
     

}

  

void loop() {
  static boolean flag =true;

  if(BTSerial.available()){
    char br = BTSerial.read();
    Serial.write(br);
    switch(br);
    case '1' :
      for(int i=0;i<3;i++){
        digitalWrite(9,HIGH);
        delay(500);
        digitalWrite(9,LOW);
        delay(500);
      }
      break;

      case '2' :
        for(int i=0;i<3;i++){
          digitalWrite(9,HIGH);
          delay(3000);
          digitalWrite(9,LOW);
          delay(3000);
        }
        break;

        case'3':
        digitalWrite(8,LOW);
        digitalWrite(9,HIGH);
        delay(30);
        break;

        case '4':
        {
          switch(flag){
            case true:
            digitalWrite(9,HIGE);
            flag=false;
            break;
            case false:
            digitalWrite(9,LOW);
            flag=true;
            break;
          }
          break;
        }

          case'5':
          for(int i=0;i<3;i++){
            digitalWrite(8,LOW);
            digitalWrite(9,HIGE);
            delay(500);
            digitalWrite(8,HIGH);
            digitalWrite(9,Low);
            delay(500);
          }

          digitalWrite(8,LOW);
          digitalWrite(9,LOW);
          break;

          case 'a':
          digitalWrite(8,LOW);
          digitalWrite(9,LOW);
          break;
  }
}
}
