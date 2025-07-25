#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "";
const char* password = "";

WebServer server(80);

#define LED_PIN 2  // Pino onde o LED está conectado

void handleRoot() {
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <title>ESP32 C3 SUPER MINI</title>
      <meta charset="UTF-8">
      <style>
        body { font-family: Arial; background: #111; color: white; text-align: center; padding-top: 50px; }
        button { font-size: 20px; padding: 10px 20px; margin: 20px; background: #f90; border: none; border-radius: 5px; cursor: pointer; }
      </style>
    </head>
    <body>
      <h1>ESP32 Conectado com sucesso!</h1>
      <button onclick="location.href='/on'">Ligar LED</button>
      <button onclick="location.href='/off'">Desligar LED</button>
    </body>
    </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

void handleOn() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED LIGADO");
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleOff() {
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED DESLIGADO");
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Garante que comece desligado

  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
  Serial.println("Servidor web iniciado");
}

void loop() {
  server.handleClient();
}
