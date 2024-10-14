/*
O robô usa sensores ultrassônicos para detectar obstáculos à frente, à esquerda e à direita.
O algoritmo de Flood Fill é usado para encontrar o caminho até o destino no labirinto.
O robô lê as distâncias, calcula a melhor direção para seguir, move-se e atualiza sua posição.
O código é cíclico, repetindo esses passos até que o robô atinja o destino no labirinto.
*/
#include "defines.h"

int current_x = 0;
int current_y = 0;

vehicle_distance_t vehicle_distance;
vehicle_directions_e dir;

void setup()
{
  vehicle_motors_configure(255, 255);   // Configura os motores com 100% de potência
  vehicle_distance_sensors_configure(); // Configura os sensores de distância
  Serial.begin(9600);
  Serial.println("Início!");

  floodFill(MAZE_SIZE - 1, MAZE_SIZE - 1); // Definir destino no canto inferior direito do labirinto. Ex: [15,15]
}

void loop()
{
  vehicle_distance_read(&vehicle_distance);

  dir = flood_nav_system(&vehicle_distance, current_x, current_y);

  vehicle_motors_move(dir, 500);

  vehicle_distance_print(&vehicle_distance);

  update_position(dir);
  delay(300);
}

void update_position(vehicle_directions_e dir)
{
  switch (dir)
  {
  case DIR_FORWARD:
    current_y++;
    break;
  case DIR_LEFT:
    current_x--;
    break;
  case DIR_RIGHT:
    current_x++;
    break;
  case DIR_REVERSE:
    current_y--;
    break;
  }
}
