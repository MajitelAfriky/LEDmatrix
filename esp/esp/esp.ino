#include <ESP8266WiFi.h>

const char* ssid = "AFRIKA";
const char* password = "lolopolo";
const char* host = "sluk.borec.cz";
const int httpPort = 80;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  WiFiClient client;

  if (!client.connect(host, httpPort)) {
    delay(1000);
    return;
  }

  client.print(String("GET ") + "/esp/esp.php" + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "X-ESP-Auth: lolopolo\r\n" +
               "Connection: close\r\n\r\n");

  delay(500);

  // Přeskakování HTTP hlaviček
  while (client.available()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  // Čtení pouze obsahu <main>
  String response = "";
  bool inMainTag = false;

  while (client.available()) {
    String line = client.readStringUntil('\n');

    // Hledání začátku <main>
    if (line.indexOf("<main>") != -1) {
      inMainTag = true;
      line = line.substring(line.indexOf("<main>") + 6); // Odstranit <main> z řetězce
    }

    // Hledání konce </main>
    if (line.indexOf("</main>") != -1) {
      line = line.substring(0, line.indexOf("</main>")); // Získat obsah před </main>
      response += line;
      inMainTag = false;
      break;
    }

    // Ukládání obsahu uvnitř <main>
    if (inMainTag) {
      response += line;
    }
  }

  response.trim();
  Serial.println(response);

  delay(10000); // Opakování každých 10 sekund
}
