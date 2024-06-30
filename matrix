#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#ifndef PSTR
 #define PSTR // Prevent compiler error
#endif

#define PIN 8
#define NUM_LEDS 64

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 1, 1, PIN,
  NEO_TILE_BOTTOM   + NEO_TILE_LEFT   + NEO_TILE_COLUMNS   + NEO_TILE_PROGRESSIVE +
  NEO_MATRIX_BOTTOM + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB + NEO_KHZ800);

const uint16_t color = matrix.Color(255, 0, 0); // Red color for text

String displayText = "....."; // Default text

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
      }
      dataBuffer = ""; // Clear the buffer for next data
    } else {
      dataBuffer += c; // Add character to buffer
    }
  }

  if (displayText.startsWith("$", 0)) {
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
  } else {
    displayTextOnMatrix();
  }
}

void displayTextOnMatrix() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(displayText); // Display the received text
  x -= 1; // Move text to the left
  int textWidth = displayText.length() * 8; // Assuming each character is 8 pixels wide
  if (x < -textWidth) {
    x = matrix.width(); // Reset position if text has scrolled completely
  }
  matrix.show();
  delay(100);
}
