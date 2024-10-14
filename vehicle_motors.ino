#include "defines.h"

const int in1 = 7;
const int in2 = 6;
const int in3 = 5;
const int in4 = 4;
const int enA = 10;
const int enB = 9;

uint8_t l_power = 0;
uint8_t r_power = 0;

void vehicle_motors_configure(uint8_t left_power, uint8_t right_power)
{
  l_power = left_power;
  r_power = right_power;

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void stop(void) // Função para parar o robô
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void forward(void) // Mover para frente
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void reverse(void) // Mover para trás
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turn_left(void) // Mover para esquerda
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turn_right(void) // Mover para direita
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void vehicle_motors_move(vehicle_directions_e dir, uint8_t step_ms)
{
  switch (dir)
  {
  case DIR_FORWARD:
    forward();
    break;
  case DIR_REVERSE:
    reverse();
    break;
  case DIR_LEFT:
    turn_left();
    break;
  case DIR_RIGHT:
    turn_right();
    break;
  }
  analogWrite(enA, r_power);
  analogWrite(enB, l_power);
  delay(step_ms);
  stop();
}
