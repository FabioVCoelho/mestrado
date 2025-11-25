#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// ================= EDIT YOUR DETAILS HERE =================
const char* ssid = "DENISE_2.4Ghz";       // Keep the quotes!
const char* password = "Derrnise301*"; 
// ==========================================================

// Define the pin where the data wire is connected
// #define DHTPIN 5     // GPIO 5 is usually labeled D1 on NodeMCU/Wemos

// Define the sensor type. Uncomment the one you are using!
#define DHTTYPE DHT11   // DHT 11
// D5 on the board corresponds to GPIO 14 in code
#define DHTPIN 14
// #define DHTTYPE DHT22   // DHT 22 (AM2302), AM2321

// MQTT Broker Settings 
//const char* mqtt_server = "test.mosquitto.org"; 
const char* mqtt_server = "broker.hivemq.com";  // Outro servidor teste
//const char* mqtt_server = "192.168.0.55"; teste local
const int mqtt_port = 1883;

// Objects
WiFiClient espClient;
PubSubClient client(espClient);

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Function to connect/reconnect to MQTT
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID so the broker doesn't kick us off
    String clientId = "ESP8266-" + String(random(0xffff), HEX);
    
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected!");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(10); // Small pause to let things settle

  Serial.println("\nStarting DHT Sensor...");
  dht.begin();

  Serial.println();
  Serial.println("=================================");
  Serial.print("Connecting to Wi-Fi Network: ");
  Serial.println(ssid);

  // Start the Wi-Fi module
  WiFi.begin(ssid, password);

  // Wait loop: Check status every 0.5 seconds
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Success!
  Serial.println("");
  Serial.println("Wi-Fi Connected successfully!");
  Serial.print("My IP Address is: ");
  Serial.println(WiFi.localIP()); // Important: You need this address sometimes
  Serial.println("================================="); 

  // 2. Configure MQTT Server 
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  // Ensure MQTT is connected
  if (!client.connected()) {
    reconnect();
  }
  client.loop();  


  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print to Serial Monitor using printf for cleaner formatting
  Serial.printf("Humidity: %.2f %%  |  Temperature: %.2f C\n", h, t);

  // 4. Prepare Topics 
  String topicTemp = "mestrado/iot/aluno/coelho/temperatura";
  String topicHum = "mestrado/iot/aluno/coelho/umidade";

  // 5. Publish Raw Data [cite: 22]
  // We convert the float numbers to Strings, then to char arrays for MQTT
  client.publish(topicTemp.c_str(), String(t).c_str());
  client.publish(topicHum.c_str(), String(h).c_str());

  // Debug Output
  Serial.println("------------------------------------------------");
  Serial.printf("Temp: %.2f C  -> Sent to %s\n", t, topicTemp.c_str());
  Serial.printf("Hum:  %.2f %%  -> Sent to %s\n", h, topicHum.c_str());  
}