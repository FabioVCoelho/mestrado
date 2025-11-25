// #include <Arduino.h>
// #include <Adafruit_Sensor.h>
// #include <DHT.h>
// #include <ESP8266WiFi.h>

// // ================= EDIT YOUR DETAILS HERE =================
// const char* ssid = "DENISE_2.4Ghz";       // Keep the quotes!
// const char* password = "PASSWORD"; 
// // ==========================================================

// // Define the pin where the data wire is connected
// // #define DHTPIN 5     // GPIO 5 is usually labeled D1 on NodeMCU/Wemos

// // Define the sensor type. Uncomment the one you are using!
// #define DHTTYPE DHT11   // DHT 11
// // D5 on the board corresponds to GPIO 14 in code
// #define DHTPIN 14
// // #define DHTTYPE DHT22   // DHT 22 (AM2302), AM2321

// // Initialize DHT sensor
// DHT dht(DHTPIN, DHTTYPE);

// void setup() {
//   Serial.begin(115200);
//   delay(10); // Small pause to let things settle

//   Serial.println();
//   Serial.println("=================================");
//   Serial.print("Connecting to Wi-Fi Network: ");
//   Serial.println(ssid);

//   // Start the Wi-Fi module
//   WiFi.begin(ssid, password);

//   // Wait loop: Check status every 0.5 seconds
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   // Success!
//   Serial.println("");
//   Serial.println("Wi-Fi Connected successfully!");
//   Serial.print("My IP Address is: ");
//   Serial.println(WiFi.localIP()); // Important: You need this address sometimes
//   Serial.println("=================================");
  
//   Serial.println("\nStarting DHT Sensor...");
  
//   dht.begin();
// }

// void loop() {
//   // Wait a few seconds between measurements.
//   delay(2000);

//   // Reading temperature or humidity takes about 250 milliseconds!
//   float h = dht.readHumidity();
//   // Read temperature as Celsius (the default)
//   float t = dht.readTemperature();

//   // Check if any reads failed and exit early (to try again).
//   if (isnan(h) || isnan(t)) {
//     Serial.println("Failed to read from DHT sensor!");
//     return;
//   }

//   // Print to Serial Monitor using printf for cleaner formatting
//   Serial.printf("Humidity: %.2f %%  |  Temperature: %.2f C\n", h, t);
// }