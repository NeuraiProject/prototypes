/*
  Tiny Neural Test for ESP32 - Neurai.org
  --------------------------
  This sketch demonstrates a minimal perceptron:
   - Reads a fake sensor value (you can swap this for a real analogRead)
   - Computes a weighted sum + bias
   - Applies a sigmoid activation
   - Prints the result to Serial
*/

#include <Arduino.h>

// ---- Perceptron parameters ----
// Weights for a single-input neuron (just one weight here for simplicity)
const float weight = 0.75;  
const float bias   = -0.50; 

// Sigmoid activation function
float sigmoid(float x) {
  return 1.0 / (1.0 + exp(-x));
}

void setup() {
  Serial.begin(115200);
  // Give the serial some time to connect
  delay(500);
  Serial.println("Neural Test Starting...");
}

void loop() {
  // Simulate a sensor reading between 0.0 and 1.0
  // (replace with: float sensorValue = analogRead(34) / 4095.0;)
  float sensorValue = random(0, 1001) / 1000.0;  

  // Compute the perceptron output
  float linearOutput = weight * sensorValue + bias;
  float activated    = sigmoid(linearOutput);

  // Print out all the details
  Serial.print("Sensor: ");
  Serial.print(sensorValue, 3);
  Serial.print("  |  Weighted Sum: ");
  Serial.print(linearOutput, 3);
  Serial.print("  |  Activation: ");
  Serial.println(activated, 3);

  // Wait a bit before next reading
  delay(1000);
}
