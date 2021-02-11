// The goal of this file is to receive data from an Arduino Uno
//    Receiver    : Arduino Nano
//    Transmitter : Arduino Uno 
// ** This file is meant to be uploaded to the Arduino Nano (Receiver)

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define cePin   7   // D7
#define csnPin  8   // D8
#define sckPin  13  // D13
#define mosiPin 11  // D11
#define misoPin 12  // D12
// irq not connected

RF24 radio(cePin, csnPin);

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.print("Received: ");
    Serial.println(text);
    delay(1000);
  }else{
    Serial.println("Not Available");
    delay(1000);
  }
}
