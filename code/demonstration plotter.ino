// The alpha value of the filter, which controls the degree of filtering, ranges from 0 to 1.
const float alpha = 0.6; 
float sensorValFiltered = 0.0;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(115200);
}

void loop() {
  // Read sensor data
  int analogValue = analogRead(A0);

  // Filtering the data
  sensorValFiltered = alpha * analogValue + (1 - alpha) * sensorValFiltered;

  int a = 1000;

  Serial.print(a);
  Serial.print(" ");
  Serial.print(sensorValFiltered);
  Serial.println();

  delay(100);
}
