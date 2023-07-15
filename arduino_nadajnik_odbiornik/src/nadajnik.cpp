#include <Arduino.h>

#include <VirtualWire.h>

#include <SPI.h>

#define stop 4

#define go 2

#define left 3

#define return 5

#define transmit_pin 10




void setup()

{

  vw_set_tx_pin(transmit_pin);

  vw_setup(2000);

   pinMode(stop, INPUT_PULLUP);

  pinMode(left, INPUT_PULLUP);

  pinMode(go,INPUT_PULLUP);

  pinMode(return,INPUT_PULLUP);




}

  void loop()

{

  if (digitalRead(go) == LOW)

  {

    const char* message = "F";

    vw_send((uint8_t*)message, strlen(message));

    vw_wait_tx();

    delay(100);

  }




  if (digitalRead(stop) == LOW)

  {

    const char* message = "B";

    vw_send((uint8_t*)message, strlen(message));

    vw_wait_tx();

    delay(100);

  }




  if (digitalRead(left) == LOW)

  {

    const char* message = "C";

    vw_send((uint8_t*)message, strlen(message));

    vw_wait_tx();

    delay(100);

  }

  if (digitalRead(return) == LOW)

  {

    const char* message = "D";

    vw_send((uint8_t*)message, strlen(message));

    vw_wait_tx();

    delay(100);

  }




}