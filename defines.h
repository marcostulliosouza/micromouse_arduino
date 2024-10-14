#ifndef __DEFINES_H__
#define __DEFINES_H__

typedef struct
{
  uint16_t front_cm;
  uint16_t left_cm;
  uint16_t right_cm;
} vehicle_distance_t;

typedef enum
{
  DIR_FORWARD = 0,
  DIR_REVERSE,
  DIR_LEFT,
  DIR_RIGHT
} vehicle_directions_e;

// Definições físicas do labirinto
#define LABYRINTH_WIDTH 200  // Largura do labirinto em cm (exemplo)
#define LABYRINTH_HEIGHT 200 // Altura do labirinto em cm (exemplo)
#define CELL_SIZE 10         // Tamanho de cada célula em cm (exemplo)

// Cálculo do tamanho do labirinto com base nas definições físicas
#define MAZE_WIDTH (LABYRINTH_WIDTH / CELL_SIZE)   // Número de células na largura
#define MAZE_HEIGHT (LABYRINTH_HEIGHT / CELL_SIZE) // Número de células na altura

#define MAX_DISTANCE 200 // Distância máxima que os sensores ultrassônicos podem medir (em cm)

#endif
q