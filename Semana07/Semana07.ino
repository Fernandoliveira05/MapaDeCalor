#include <WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

// Configurações do Adafruit IO
#define IO_SERVER "io.adafruit.com"
#define IO_SERVERPORT 1883 // Porta MQTT padrão
#define IO_USERNAME "LilFer777"
#define IO_KEY "aio_YYlP74FfrECTqHhkHkdxQiAtPCGY"

// Configurações de Wi-Fi
const char* ssid = "Inteli.Iot";
const char* password = "@Intelix10T#";

// Cliente Wi-Fi e MQTT
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, IO_SERVER, IO_SERVERPORT, IO_USERNAME, IO_KEY);

// Tópico MQTT para enviar os dados de RSSI
Adafruit_MQTT_Publish wifiRSSI = Adafruit_MQTT_Publish(&mqtt, IO_USERNAME "/feeds/signal-strength");

// Configuração para tempos mais rápidos
const int MQTT_RECONNECT_INTERVAL = 500; // 0,5 segundos para reconexão
const int LOOP_DELAY = 250;              // 0,25 segundos entre medições

// Função para conectar ao Wi-Fi
void connectToWiFi() {
  Serial.print("Conectando-se ao Wi-Fi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200); // Reduz o tempo de espera entre verificações
    Serial.print(".");
  }

  Serial.println("\nConectado ao Wi-Fi!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

// Função para conectar ao Adafruit IO
void connectToMQTT() {
  while (mqtt.connected() == false) {
    Serial.print("Conectando ao Adafruit IO... ");
    int8_t ret = mqtt.connect();
    if (ret == 0) {
      Serial.println("Conectado!");
    } else {
      Serial.println(mqtt.connectErrorString(ret));
      Serial.println("Tentando novamente...");
      delay(MQTT_RECONNECT_INTERVAL); // Intervalo menor para reconexão
    }
  }
}

void setup() {
  Serial.begin(115200);

  // Conexão Wi-Fi
  connectToWiFi();

  // Conexão ao Adafruit IO
  connectToMQTT();
}

void loop() {
  // Verificar conexão com o Adafruit IO
  if (!mqtt.connected()) {
    connectToMQTT();
  }
  mqtt.processPackets(1000); // Processar pacotes rapidamente
  mqtt.ping();               // Mantém a conexão ativa

  // Coletar potência do sinal Wi-Fi
  int32_t rssi = WiFi.RSSI();
  Serial.print("Potência do sinal (dBm): ");
  Serial.println(rssi);

  // Publicar o RSSI no Adafruit IO
  if (!wifiRSSI.publish(rssi)) {
    Serial.println("Falha ao publicar o valor RSSI.");
  } else {
    Serial.println("RSSI publicado com sucesso!");
  }

  // Aguardar intervalo reduzido antes da próxima medição
  delay(LOOP_DELAY);
}
