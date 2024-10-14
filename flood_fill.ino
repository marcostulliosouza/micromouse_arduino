#include "defines.h"

int maze[MAZE_WIDTH][MAZE_HEIGHT]; // Matriz que representa o labirinto

void floodFill(int goal_x, int goal_y)
{
  for (int x = 0; x < MAZE_WIDTH; x++)
  {
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
      /* Calcula a distância de Manhattan até o destino.
      A distância de Manhattan é simplesmente a soma das
      diferenças absolutas entre as coordenada.
      Isso gera um mapa de distâncias onde as células mais próximas
      do objetivo têm valores menores, e as mais
      distantes têm valores maiores*/
      maze[x][y] = abs(goal_x - x) + abs(goal_y - y);
    }
  }
}

/*Com base nas distâncias no labirinto e
nas leituras dos sensores de ultrassom,
escolhe a melhor direção para o robô se mover,
priorizando a célula com o menor valor na matriz do labirinto. */
vehicle_directions_e flood_nav_system(vehicle_distance_t *distance, int current_x, int current_y)
{
  int min_value = maze[current_x][current_y];
  vehicle_directions_e best_direction = DIR_FORWARD;
  /* Se a célula à esquerda (current_x - 1)
  tem um valor menor e o sensor esquerdo detecta mais de 10 cm,
  o robô considera virar para a esquerda. */
  if (maze[current_x][current_y - 1] < min_value && distance->front_cm >= 10)
  {
    min_value = maze[current_x][current_y - 1];
    best_direction = DIR_FORWARD;
  }
  if (maze[current_x - 1][current_y] < min_value && distance->left_cm >= 10)
  {
    min_value = maze[current_x - 1][current_y];
    best_direction = DIR_LEFT;
  }
  if (maze[current_x + 1][current_y] < min_value && distance->right_cm >= 10)
  {
    min_value = maze[current_x + 1][current_y];
    best_direction = DIR_RIGHT;
  }
  return best_direction;
}
