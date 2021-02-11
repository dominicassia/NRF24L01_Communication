// The goal of this file is to send data from an Arduino Uno
//    Receiver    : Arduino Nano
//    Transmitter : Arduino Uno 
// ** This file is meant to be uploaded to the Arduino Uno (Transmitter)

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define cePin   8   // D8
#define csnPin  10  // D10
#define sckPin  13  // D13
#define mosiPin 11  // D11
#define misoPin 12  // D12
// irq not connected

RF24 radio(cePin, csnPin);

const byte address[6] = "00001";

void setup() {
  pinMode(csnPin, OUTPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);
}
