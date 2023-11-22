#include <Servo.h>

Servo servo1;
Servo servo2;
float theta1_deg = 0; 
float theta2_deg = 0; 

void setup() {
  servo1.attach(9);  
  servo2.attach(10); 
  
  Serial.begin(9600); 
}

void loop() {
  // membaca input dari user (if available)
  if (Serial.available() > 0) {
    theta1_deg = Serial.parseFloat(); // sudut servo1
    theta2_deg = Serial.parseFloat(); // sudut for servo2

    // Move servos to reach the provided angles
    int servo1_pos = theta1_deg; //int servo1_pos = map(theta1_deg, 0, 180, 0, 180); // jika butuh mapping
    int servo2_pos = theta2_deg; //int servo2_pos = map(theta2_deg, 0, 180, 0, 180); // jika butuh mapping

    servo1.write(servo1_pos);
    servo2.write(servo2_pos);
  }

  // hitung kordinat (x, y) dengan sudut yang baru
  float theta1_rad = radians(theta1_deg);
  float theta2_rad = radians(theta2_deg);

  float l1 = 10; // panjang link 1 (in cm)
  float l2 = 10; // panjang link 2 (in cm)
  float x = l1 * cos(theta1_rad) + l2 * cos(theta1_rad + theta2_rad);
  float y = l1 * sin(theta1_rad) + l2 * sin(theta1_rad + theta2_rad);

  // Print (x, y) pada serial monitor
  Serial.print("Theta1: ");
  Serial.print(theta1_deg);
  Serial.print(", Theta2: ");
  Serial.print(theta2_deg);
  Serial.print(", X: ");
  Serial.print(x);
  Serial.print(", Y: ");
  Serial.println(y);

  delay(1000); // Adjust delay as needed for smoother motion
}
