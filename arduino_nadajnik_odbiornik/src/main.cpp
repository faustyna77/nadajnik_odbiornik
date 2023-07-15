#include <Arduino.h>
#include <VirtualWire.h>
#include <SPI.h>


#include <VirtualWire.h>

#define led_pin 13
#define receive_pin 11
#define motor1 3
#define motor2 7
#define motor3 4
#define motor4 5


void setup()
{
    Serial.begin(9600);
    Serial.println("Setup");
    
    vw_set_rx_pin(receive_pin);
    vw_setup(2000);
    vw_rx_start();

    pinMode(led_pin, OUTPUT);
    pinMode(motor1, OUTPUT);
    pinMode(motor2, OUTPUT);
    pinMode(motor3, OUTPUT);
    pinMode(motor4, OUTPUT);
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen))
    {
        digitalWrite(led_pin, HIGH); // Zapalamy diodę

        if (buflen >= 1)
        {
            switch (buf[0])
            {
                case 'F': // Do przodu
                    digitalWrite(motor1, HIGH);
                    digitalWrite(motor2, LOW);
                    digitalWrite(motor3, HIGH);
                    digitalWrite(motor4, LOW);
                    break;
                
                case 'B': // Do tyłu
                    digitalWrite(motor1, LOW);
                    digitalWrite(motor2, LOW);
                    digitalWrite(motor3, LOW);
                    digitalWrite(motor4, LOW);
                    break;
                
                case 'C': // W lewo
                    digitalWrite(motor1, HIGH);
                    digitalWrite(motor2, LOW);
                    digitalWrite(motor3, LOW);
                    digitalWrite(motor4, LOW);
                    break;
                
                case 'D': // W prawo
                    digitalWrite(motor1, LOW);
                    digitalWrite(motor2, LOW);
                    digitalWrite(motor3, LOW);
                    digitalWrite(motor4, HIGH);
                    break;
                
                
                
                default:
                    break;
            }
        }

        delay(200);

        digitalWrite(led_pin, LOW); // Gasimy diodę
    }
}