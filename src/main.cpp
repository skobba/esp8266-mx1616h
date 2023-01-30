/*************************************
 * Dual Channel DC Motor Driver Board* 
 *  Code Written by Idayu - MYBOTIC  *
 *************************************/

#include <Arduino.h>
#include <Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire display(0x3c, SDA, SCL);

// void loop() {
//   Serial.println("Hello world!");
//   delay(1000);
// }
 
int IN1 = 16; 
int IN2 = 14; 
int IN3 = 12;
int IN4 = 13;

void setup()
{
  Serial.begin(9600);
  display.init();
  display.flipScreenVertically();
  display.drawString(5, 0, "Hello world");
  display.display();

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter number for control option:");
  Serial.println("1. FORWARD");
  Serial.println("2. REVERSE");
  Serial.println("3. STOP");
  Serial.println();  
}

void Forward()
{
  // digitalWrite(IN1, 10);
  analogWrite(IN1, 100);
  digitalWrite(IN2, LOW);
  Serial.print("Motor 1 Forward");
  Serial.println();
  
  // digitalWrite(IN3, 10);
  analogWrite(IN3, 250);
  digitalWrite(IN4, LOW);  
  Serial.println("Motor 2 Forward");
  Serial.println();
}

void Reverse()
{
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  Serial.print("Motor 2 Reverse");
  Serial.println();
  
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
  Serial.println("Motor 2 Reverse");
  Serial.println();
}

void Stop()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    Serial.print("Motor 1 Stop");
    Serial.println();
    
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    Serial.println("Motor 2 Stop");
    Serial.println();
}

void loop()
{
  char user_input;
  
  while(Serial.available())
  {
    user_input = Serial.read();
    digitalWrite(IN1, LOW); //OFF
    digitalWrite(IN2, LOW);

    if (user_input =='1')
    {
       Forward();
    }
    else if(user_input =='2')
    {
      Reverse();
    }
    else if(user_input =='3')
    {
      Stop();
    }
    else
    {
      Serial.println("Invalid option entered.");
    }
  }
}


