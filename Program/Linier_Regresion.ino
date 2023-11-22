const int sensor = A0;
float vout;
float adc;
int pemanass;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  delay(100);
}

void loop()
{
  adc = analogRead(sensor);
  
  // Linear equation: y = mx + b
  int pemanas = int(-0.28 * adc + 77.55); // Adjust the multiplier and intercept as needed
  
  // Ensure motor speed is within valid range (0-100)
  pemanass = constrain(pemanas, 0, 100);
  
  Serial.print("Suhu: ");
  Serial.print(adc);
  Serial.print(" pemanas: ");
  Serial.println(pemanass);
  
  delay(1000); 

  
}
