#include <SoftwareSerial.h>
SoftwareSerial simSerial(2, 3); // RX, TX

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  simSerial.begin(19200);
  simSerial.println("AT");
    
  Serial.println(F("Board ready\n"));
  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);                       // wait for a second

  // sms("Test from sin800l", "+7953xxxxxxx");
  
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for a second
}

void sms(String text, String phone) {
  Serial.println("SMS send started");
  simSerial.println("AT+CMGS=\"" + phone + "\"");
  delay(1000);
  simSerial.print(text);
  delay(300);
  simSerial.print((char)26);
  delay(300);
  Serial.println("SMS send finish");
  delay(3000);
}

// the loop function runs over and over again forever
void loop() {
  if (simSerial.available())
    Serial.write(simSerial.read());
  if (Serial.available())
    simSerial.write(Serial.read());  
}
