#include <SPI.h>
#include <Ethernet.h>

int pinLED1 = 2;
int pinLED2 = 3;
int pinLED3 = 4;
int pinLED4 = 5;
int pinLED5 = 6;
int pinLED6 = 7;
int pinLED7 = 8;
int pinLED8 = 9;

int pos = 0;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   
byte ip[] = { 192, 168, 2, 200 };                    
byte gateway[] = { 192, 168, 2, 1 };                 
byte subnet[] = { 255, 255, 255, 0 };                  
EthernetServer server(8888);                           
String readString;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
  // Start Server
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("Server ip address : ");
  Serial.println(Ethernet.localIP());

  pinMode(pinLED1,OUTPUT);
  pinMode(pinLED2,OUTPUT);
  pinMode(pinLED3,OUTPUT);
  pinMode(pinLED4,OUTPUT);
  pinMode(pinLED5,OUTPUT);
  pinMode(pinLED6,OUTPUT);
  pinMode(pinLED7,OUTPUT);
  pinMode(pinLED8,OUTPUT);
  
}

void loop() {
  // Create a Client Connection
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();

        if (readString.length() < 100) {

          readString += c;

        }


        if (c == '\n') {
          delay(1);
          //stopping client
          client.stop();
          //controls the Arduino if you press the buttons
          if (readString.indexOf("?device1up") > 0) {
            digitalWrite(pinLED1, HIGH);
          }
          if (readString.indexOf("?device1down") > 0) {
            digitalWrite(pinLED1, LOW);
          }
          if (readString.indexOf("?device2up") > 0) {
            digitalWrite(pinLED2, HIGH);
          }
          if (readString.indexOf("?device2down") > 0) {
            digitalWrite(pinLED2, LOW);
          }
          if (readString.indexOf("?device3up") > 0) {
            digitalWrite(pinLED3, HIGH);
          }
          if (readString.indexOf("?device3down") > 0) {
            digitalWrite(pinLED3, LOW);
          }
          if (readString.indexOf("?device4up") > 0) {
            digitalWrite(pinLED4, HIGH);
          }
          if (readString.indexOf("?device4down") > 0) {
            digitalWrite(pinLED4, LOW);
          }
          if (readString.indexOf("?device5up") > 0) {
            digitalWrite(pinLED5, HIGH);
          }
          if (readString.indexOf("?device5down") > 0) {
            digitalWrite(pinLED5, LOW);
          }
          if (readString.indexOf("?device6up") > 0) {
            digitalWrite(pinLED6, HIGH);
          }
          if (readString.indexOf("?device6down") > 0) {
            digitalWrite(pinLED6, LOW);
          }
          if (readString.indexOf("?device7up") > 0) {
            digitalWrite(pinLED7, HIGH);
          }
          if (readString.indexOf("?device7down") > 0) {
            digitalWrite(pinLED7, LOW);
          }
          if (readString.indexOf("?device8up") > 0) {
            digitalWrite(pinLED8, HIGH);
          }
          if (readString.indexOf("?device8down") > 0) {
            digitalWrite(pinLED8, LOW);
          }
          if (readString.indexOf("?deviceallup") > 0) {
            digitalWrite(pinLED1, HIGH);
            digitalWrite(pinLED2, HIGH);
            digitalWrite(pinLED3, HIGH);
            digitalWrite(pinLED4, HIGH);
            digitalWrite(pinLED5, HIGH);
            digitalWrite(pinLED6, HIGH);
            digitalWrite(pinLED7, HIGH);
            digitalWrite(pinLED8, HIGH);
            
          }
          if (readString.indexOf("?devicealldown") > 0) {
            digitalWrite(pinLED1, LOW);
            digitalWrite(pinLED2, LOW);
            digitalWrite(pinLED3, LOW);
            digitalWrite(pinLED4, LOW);
            digitalWrite(pinLED5, LOW);
            digitalWrite(pinLED6, LOW);
            digitalWrite(pinLED7, LOW);
            digitalWrite(pinLED8, LOW);
            
          }

          readString = "";
        }
      }
    }
  }  
}
