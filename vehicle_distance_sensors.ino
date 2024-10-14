#include "defines.h"
#include <NewPing.h>

// Sensor 1 (Frontal)
#define HC_SR04_1_TRIG_PIN A0
#define HC_SR04_1_ECHO_PIN A1

// Sensor 2 (Lateral Esquerdo)
#define HC_SR04_2_TRIG_PIN A2
#define HC_SR04_2_ECHO_PIN A3

// Sensor 3 (Lateral Direito)
#define HC_SR04_3_TRIG_PIN A4
#define HC_SR04_3_ECHO_PIN A5

NewPing sonar[3] = {
    NewPing(HC_SR04_1_TRIG_PIN, HC_SR04_1_ECHO_PIN, MAX_DISTANCE),
    NewPing(HC_SR04_2_TRIG_PIN, HC_SR04_2_ECHO_PIN, MAX_DISTANCE),
    NewPing(HC_SR04_3_TRIG_PIN, HC_SR04_3_ECHO_PIN, MAX_DISTANCE)};

void vehicle_distance_sensors_configure(void) {}

void vehicle_distance_read(vehicle_distance_t *readings)
{
  readings->front_cm = sonar[0].ping_cm();
  readings->left_cm = sonar[1].ping_cm();
  readings->right_cm = sonar[2].ping_cm();

  if (readings->front_cm == 0)
    readings->front_cm = MAX_DISTANCE;
  if (readings->left_cm == 0)
    readings->left_cm = MAX_DISTANCE;
  if (readings->right_cm == 0)
    readings->right_cm = MAX_DISTANCE;
}

void vehicle_distance_print(vehicle_distance_t *readings)
{
  char text_to_print[50];
  sprintf(text_to_print, "frontal: %d, esquerdo: %d, direito: %d", readings->front_cm, readings->left_cm, readings->right_cm);
  Serial.println(text_to_print);
}
