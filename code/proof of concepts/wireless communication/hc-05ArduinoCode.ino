const long BAUD_RATE = 9600; 
const int STATUS_LED = 13;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(STATUS_LED, OUTPUT);
  
  delay(1000);
  Serial.println("--- SYSTEM READY ---");
  Serial.println("Typ iets om de verbinding te testen...");
}

void loop() {
  if (Serial.available() > 0) {
    String inkomendeData = Serial.readStringUntil('\n');
    inkomendeData.trim(); 
    
    digitalWrite(STATUS_LED, HIGH);
    delay(100);
    digitalWrite(STATUS_LED, LOW);
    
    Serial.print("Robot ontving: ");
    Serial.println(inkomendeData);
  }
}