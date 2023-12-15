// The alpha value of the filter, which controls the degree of filtering, ranges from 0 to 1.
const float alpha = 0.6; 
float sensorValFiltered = 0.0;
float minThreshold = 1000;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  Serial.begin(115200);
}

void loop() {
  // Read sensor data
  int analogValue = analogRead(A0);

  // Filtering the data
  sensorValFiltered = alpha * analogValue + (1 - alpha) * sensorValFiltered;

  if (sensorValFiltered < 1000)
  {
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
  }
  else{
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
  }
  
  delay(100);
}
