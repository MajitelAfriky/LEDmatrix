#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
// #0000000000000000010100010111001001110110011111000111110001010100
#ifndef PSTR
 #define PSTR // Prevent compiler error
#endif

#define PIN 8
#define NUM_LEDS 64

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 1, 1, PIN,
  NEO_TILE_BOTTOM   + NEO_TILE_LEFT   + NEO_TILE_COLUMNS   + NEO_TILE_PROGRESSIVE +
  NEO_MATRIX_BOTTOM + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB + NEO_KHZ800);

uint16_t color = matrix.Color(255, 0, 0); // Red color for text

String displayText = "....."; // Default text
String hexColor;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600); // UART1 for ESP-01

  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(color);

  Serial.println("Setup complete, waiting for data...");
}

int x = matrix.width();
String dataBuffer; // Buffer to store incoming data

void loop() {
  while (Serial1.available()) {
    char c = Serial1.read();
    if (c == '\n') { // Pokud přijde nový řádek, zpracuj data
      dataBuffer.trim(); // Remove any leading or trailing whitespace
      if (dataBuffer.length() > 0) {
        displayText = dataBuffer;
        Serial.print("Received text: ");
        Serial.println(displayText); // Print received text for debugging
        x = matrix.width(); // Reset position for new text
        matrix.fillScreen(0);
      }
      dataBuffer = ""; // Clear the buffer for next data
    } else {
      dataBuffer += c; // Add character to buffer
    }
  }

  if (displayText.startsWith("$", 0) || displayText.startsWith("#", 0)) {
    if (displayText.startsWith("red", 1)) {
      matrix.fillScreen(color);
      matrix.show();
    }
    if (displayText.startsWith("green", 1)) {
      matrix.fillScreen(matrix.Color(0, 255, 0));
      matrix.show();
    }
    if (displayText.startsWith("blue", 1)) {
      matrix.fillScreen(matrix.Color(0, 0, 255));
      matrix.show();
    }
    if (displayText.startsWith("#", 0)) {
      hexColor = displayText.substring(65);
      long number = (long) strtol( &hexColor[1], NULL, 16);
      int r = number >> 16;
      int g = number >> 8 & 0xFF;
      int b = number & 0xFF;
    


      for (int i = 1; i <= 64; i++) {
        // Výpočet souřadnic z indexu
        int Yrow = (i - 1) / 8;
        int Xcol = (i - 1) % 8;

        // Přečtení bitu na aktuální pozici
        char bit = displayText.charAt(i);

        if (bit == '1') {
          matrix.drawPixel(Xcol, Yrow, matrix.Color(r, g, b));
          Serial.print(Xcol);
          Serial.print("|");
          Serial.println(Yrow);
          matrix.show();
        }
        delay(30);
      }
    }
  } else {
    text();
  }
}

/*void text() {
  for (int i = 0; i < displayText.length(); i++) {

    Serial.print(i);
    Serial.print("/");
    Serial.println(displayText.length());

    matrix.fillScreen(0);
    matrix.setCursor(x, 0);
    matrix.print(displayText); // Display the received text
    x -= 1; // Move text to the left¨
    int textWidth = displayText.length() * 8; // Assuming each character is 8 pixels wide

    if (x < -textWidth) {
      x = matrix.width(); // Reset position if text has scrolled completely
    }
    matrix.show();
    delay(100);
  }
}*/

void text() {
  matrix.fillScreen(0); // Vyčistíme matici
  matrix.setTextColor(color); // Nastavíme barvu textu
  matrix.setTextWrap(false); // Vypneme zalamování textu
  matrix.setCursor(x, 0); // Nastavíme pozici kurzoru pro text

  int textWidth = displayText.length() * 6; // Předpokládáme, že každý znak má šířku 6 pixelů
  int displayTime = textWidth * 10; // Čas zobrazení je proporcionální k délce textu

  for (int i = 0; i < textWidth + matrix.width(); i++) {
    matrix.fillScreen(0); // Vyčistíme matici
    matrix.setCursor(x - i, 0); // Nastavíme pozici kurzoru pro text

    if (x - i < -textWidth) {
      x = matrix.width(); // Resetujeme pozici, pokud text překročí matici
    }

    matrix.print(displayText); // Zobrazíme text
    matrix.show(); // Aktualizujeme matici
    delay(100); // Čekáme 100 ms
  }

  delay(displayTime); // Čekáme po dobu odpovídající délce textu
}
