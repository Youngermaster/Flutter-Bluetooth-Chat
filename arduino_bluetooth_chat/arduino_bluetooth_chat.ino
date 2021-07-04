#include <SoftwareSerial.h>
SoftwareSerial MyBlue(2, 3);  // RX | TX
#define LED 13

int flag = 0;

void setup() {
    Serial.begin(9600);
    MyBlue.begin(9600);
    pinMode(LED, OUTPUT);
    Serial.println("Ready to connect\nDefualt password is 1234 or 000");
}
void loop() {
    if (MyBlue.available()) {
        flag = MyBlue.read();
        Serial.println(flag);
    }
    if (flag == 1) {
        digitalWrite(LED, HIGH);
        Serial.println("LED On");
    } else if (flag == 0) {
        digitalWrite(LED, LOW);
        // Serial.println("LED Off");
    }
}
