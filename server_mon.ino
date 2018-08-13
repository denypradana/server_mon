#include <SPI.h>
#include <Ethernet.h>

int pinOUT1 = 2;
int pinOUT2 = 3;
int pinOUT3 = 4;
int pinOUT4 = 5;
int pinOUT5 = 6;
int pinOUT6 = 7;
int pinOUT7 = 8;
int pinOUT8 = 9;

int pos = 0;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   
byte ip[] = { 192, 168, 2, 200 };                    
byte gateway[] = { 192, 168, 2, 1 };                 
byte subnet[] = { 255, 255, 255, 0 };                  
EthernetServer server(8888);                           
String readString;
String outStatus;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
  // Mulai Server
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("Server ip address : ");
  Serial.println(Ethernet.localIP());
  outStatus="DEVALL_OFF";

  pinMode(pinOUT1,OUTPUT);
  pinMode(pinOUT2,OUTPUT);
  pinMode(pinOUT3,OUTPUT);
  pinMode(pinOUT4,OUTPUT);
  pinMode(pinOUT5,OUTPUT);
  pinMode(pinOUT6,OUTPUT);
  pinMode(pinOUT7,OUTPUT);
  pinMode(pinOUT8,OUTPUT);
  
}

void loop() {
  // Membuat koneksi client
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
          // Menghentikan client  
          client.stop();
          /* 
            Kontrol digital output arduino
            Membaca URL input untuk kemudian diteruskan ke perintah
          */
          if (readString.indexOf("?device1up") > 0) {
            digitalWrite(pinOUT1, HIGH);
            outStatus="DEV1_ON";
          }
          if (readString.indexOf("?device1down") > 0) {
            digitalWrite(pinOUT1, LOW);
            outStatus="DEV1_OFF";
          }
          if (readString.indexOf("?device2up") > 0) {
            digitalWrite(pinOUT2, HIGH);
            outStatus="DEV2_ON";
          }
          if (readString.indexOf("?device2down") > 0) {
            digitalWrite(pinOUT2, LOW);
            outStatus="DEV2_OFF";
          }
          if (readString.indexOf("?device3up") > 0) {
            digitalWrite(pinOUT3, HIGH);
            outStatus="DEV3_ON";
          }
          if (readString.indexOf("?device3down") > 0) {
            digitalWrite(pinOUT3, LOW);
            outStatus="DEV3_OFF";
          }
          if (readString.indexOf("?device4up") > 0) {
            digitalWrite(pinOUT4, HIGH);
            outStatus="DEV4_ON";
          }
          if (readString.indexOf("?device4down") > 0) {
            digitalWrite(pinOUT4, LOW);
            outStatus="DEV4_OFF";
          }
          if (readString.indexOf("?device5up") > 0) {
            digitalWrite(pinOUT5, HIGH);
            outStatus="DEV5_ON";
          }
          if (readString.indexOf("?device5down") > 0) {
            digitalWrite(pinOUT5, LOW);
            outStatus="DEV5_OFF";
          }
          if (readString.indexOf("?device6up") > 0) {
            digitalWrite(pinOUT6, HIGH);
            outStatus="DEV6_ON";
          }
          if (readString.indexOf("?device6down") > 0) {
            digitalWrite(pinOUT6, LOW);
            outStatus="DEV6_OFF";
          }
          if (readString.indexOf("?device7up") > 0) {
            digitalWrite(pinOUT7, HIGH);
            outStatus="DEV7_ON";
          }
          if (readString.indexOf("?device7down") > 0) {
            digitalWrite(pinOUT7, LOW);
            outStatus="DEV7_OFF";
          }
          if (readString.indexOf("?device8up") > 0) {
            digitalWrite(pinOUT8, HIGH);
            outStatus="DEV8_ON";
          }
          if (readString.indexOf("?device8down") > 0) {
            digitalWrite(pinOUT8, LOW);
            outStatus="DEV8_OFF";
          }
          if (readString.indexOf("?deviceallup") > 0) {
            digitalWrite(pinOUT1, HIGH);
            digitalWrite(pinOUT2, HIGH);
            digitalWrite(pinOUT3, HIGH);
            digitalWrite(pinOUT4, HIGH);
            digitalWrite(pinOUT5, HIGH);
            digitalWrite(pinOUT6, HIGH);
            digitalWrite(pinOUT7, HIGH);
            digitalWrite(pinOUT8, HIGH);
            outStatus="DEVALL_ON";
          }
          if (readString.indexOf("?devicealldown") > 0) {
            digitalWrite(pinOUT1, LOW);
            digitalWrite(pinOUT2, LOW);
            digitalWrite(pinOUT3, LOW);
            digitalWrite(pinOUT4, LOW);
            digitalWrite(pinOUT5, LOW);
            digitalWrite(pinOUT6, LOW);
            digitalWrite(pinOUT7, LOW);
            digitalWrite(pinOUT8, LOW);
            outStatus="DEVALL_OFF";
          }
          if (readString.indexOf("?devicestatus") > 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");
            client.println();
            client.println("<HTMl>");
            client.println("<HEAD>");
            client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
            client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
            client.println("<meta http-equiv='refresh' content='10' >");
            client.println("<TITLE>DEVICE MONITORING</TITLE>");
            client.println("</HEAD>");
            client.println("<BODY>");
            client.println("<H1>Device Status</H1>");
            client.println("<hr />");
            client.println("<br />");
            client.println("<H2>STATUS</H2>");
            client.println("<br />");
            client.println(outStatus);
            client.println("</BODY>");
            client.println("</HTMl>");
          }

          readString = "";
        }
      }
    }
  }  
}
