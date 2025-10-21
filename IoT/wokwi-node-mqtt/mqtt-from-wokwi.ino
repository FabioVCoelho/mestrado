/**
   ESP32 + DHT22 Example for Wokwi

   https://wokwi.com/arduino/projects/322410731508073042


#include "DHTesp.h"

const int DHT_PIN = 15;

DHTesp dhtSensor;

void setup() {
  Serial.println("Setup dhtSensor");
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  Serial.println("Finished setup dhtSensor");
}

void loop() {
  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  if (isnan(data.temperature) || isnan(data.humidity)) {
    Serial.println("Data is not available");
    delay(2000);
    return;
  }
  Serial.println("Temp: " + String(data.temperature, 2) + "°C");
  Serial.println("Humidity: " + String(data.humidity, 1) + "%");
  Serial.println("---");
  delay(2000); // Wait for a new reading from the sensor (DHT22 has ~0.5Hz sample rate)
}

*/

#include <WiFi.h>
#include <MQTTPubSubClient.h>
/**
   ESP32 + DHT22 Example for Wokwi

   https://wokwi.com/arduino/projects/322410731508073042
*/

#include "DHTesp.h"

const int DHT_PIN = 15;

DHTesp dhtSensor;

/*
 Basic ESP8266 MQTT example
 This sketch demonstrates the capabilities of the pubsub library in combination
 with the ESP8266 board/library.
 It connects to an MQTT server then:
  - publishes "hello world" to the topic "outTopic" every two seconds
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary
  - If the first character of the topic "inTopic" is an 1, switch ON the ESP Led,
    else switch it off
 It will reconnect to the server if the connection is lost using a blocking
 reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 achieve the same result without blocking the main loop.
 To install the ESP8266 board, (using Arduino 1.6.4+):
  - Add the following 3rd party board manager under "File -> Preferences -> Additional Boards Manager URLs":
       http://arduino.esp8266.com/stable/package_esp8266com_index.json
  - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
  - Select your ESP8266 in "Tools -> Board"
*/

#include <PubSubClient.h>
#include <ArduinoJson.h>

// Update these with values suitable for your network.

// --- MQTT Broker Settings ---
// We will use the public test.mosquitto.org broker
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
// Create a unique client ID for your device
const char* mqtt_client_id = "wowki-node-fabio";
const char* ssid = "Wokwi-GUEST";
const char* password = "";


WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("wowki-node-fabio", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  Serial.println("Setup dhtSensor");
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  Serial.println("Finished setup dhtSensor");

}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    StaticJsonDocument<128> doc;
    TempAndHumidity data = dhtSensor.getTempAndHumidity();
    if (isnan(data.temperature) || isnan(data.humidity)) {
      Serial.println("Data is not available");
      delay(2000);
      return;
    }
    Serial.println("Temp: " + String(data.temperature, 2) + "°C");
    Serial.println("Humidity: " + String(data.humidity, 1) + "%");
    Serial.println("---");
    delay(2000); // Wait for a new reading from the sensor (DHT22 has ~0.5Hz sample rate)

// --- Prepare Data for Publishing ---
    doc["temperature"] = data.temperature;
    doc["humidity"] = data.humidity;
    String json_output;
    serializeJson(doc, json_output);
    client.publish("wowki-node-fabio", json_output.c_str());
    Serial.println("Published to MQTT");

    lastMsg = now;
    ++value;
    snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
    client.publish("outTopic", msg);
  }
}