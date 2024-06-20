/*
    Project name : ESP8266 Infrared sensor receiver module
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-infrared-sensor-receiver-module
*/

// Include the IRremoteESP8266 library for IR signal decoding
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const int RECV_PIN = D2; // GPIO pin where the IR receiver module is connected

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print the received IR signal details
    Serial.print("IR Value: ");
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100); // Small delay to avoid reading too fast
}
