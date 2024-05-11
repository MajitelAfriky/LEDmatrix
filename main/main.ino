#include <FastLED.h>

#define NUM_LEDS 64
#define DATA_PIN 8

int lever = 0;
int pip = 2;
int i;
int r;
int g;
int b;
const int from = 50;
const int to = 200;
const int cas = 10;
int play;
int pipTrig = 10;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
  pinMode(pip, OUTPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
}

void loop() {
  lever = digitalRead(10);
  if (lever == 0) {
    if (pipTrig == 1) {
      start();
      tone(pip, 1000, 250);
      delay(250);
      tone(pip, 1500, 250);
    }
    randomizer();
  } 
  else if (pipTrig == 0) {
    stop();
    tone(pip, 1000, 250);
    delay(250);
    tone(pip, 500, 250);
    pipTrig = 1;
  }
  else if (pipTrig == 10) {
    tone(pip, 1100, 200);
    delay(210);
    tone(pip, 400, 200);
    delay(210);
    tone(pip, 1200, 250);
    pipTrig = 1;
  }
}

void randomizer() {
  play = random(1, 10);
  FastLED.setBrightness(2 * from);

  //spstjbc();

  if (play == 1) {
    smile();
  }
  if (play == 2) {
    angry();
  }
  if (play == 3) {
    heart();
  }
  if (play == 4) {
    police();
  }
  if (play == 5) {
    rain();
  }
  if (play == 6) {
    ani1();
  }
  if (play == 7) {
    aniR();
  }
  if (play == 8) {
    ani2();
  }
  if (play == 9) {
    ani3();
  }
  pipTrig = 0;
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
}

void smile() {
  FastLED.setBrightness(from);
  leds[0] = CRGB(0, 0, 0);
  leds[1] = CRGB(0, 0, 0);
  leds[2] = CRGB(0, 255, 0);
  leds[3] = CRGB(0, 255, 0);
  leds[4] = CRGB(0, 255, 0);
  leds[5] = CRGB(0, 255, 0);
  leds[6] = CRGB(0, 0, 0);
  leds[7] = CRGB(0, 0, 0);
  leds[8] = CRGB(0, 0, 0);
  leds[9] = CRGB(0, 255, 0);
  leds[10] = CRGB(0, 0, 0);
  leds[11] = CRGB(0, 0, 0);
  leds[12] = CRGB(0, 0, 0);
  leds[13] = CRGB(0, 0, 0);
  leds[14] = CRGB(0, 255, 0);
  leds[15] = CRGB(0, 0, 0);
  leds[16] = CRGB(0, 255, 0);
  leds[17] = CRGB(0, 0, 0);
  leds[18] = CRGB(0, 0, 0);
  leds[19] = CRGB(0, 255, 0);
  leds[20] = CRGB(0, 0, 0);
  leds[21] = CRGB(0, 255, 0);
  leds[22] = CRGB(0, 0, 0);
  leds[23] = CRGB(0, 255, 0);
  leds[24] = CRGB(0, 255, 0);
  leds[25] = CRGB(0, 0, 0);
  leds[26] = CRGB(0, 255, 0);
  leds[27] = CRGB(0, 0, 0);
  leds[28] = CRGB(0, 0, 0);
  leds[29] = CRGB(0, 0, 0);
  leds[30] = CRGB(0, 0, 0);
  leds[31] = CRGB(0, 255, 0);
  leds[32] = CRGB(0, 255, 0);
  leds[33] = CRGB(0, 0, 0);
  leds[34] = CRGB(0, 255, 0);
  leds[35] = CRGB(0, 0, 0);
  leds[36] = CRGB(0, 0, 0);
  leds[37] = CRGB(0, 0, 0);
  leds[38] = CRGB(0, 0, 0);
  leds[39] = CRGB(0, 255, 0);
  leds[40] = CRGB(0, 255, 0);
  leds[41] = CRGB(0, 0, 0);
  leds[42] = CRGB(0, 0, 0);
  leds[43] = CRGB(0, 255, 0);
  leds[44] = CRGB(0, 0, 0);
  leds[45] = CRGB(0, 255, 0);
  leds[46] = CRGB(0, 0, 0);
  leds[47] = CRGB(0, 255, 0);
  leds[48] = CRGB(0, 0, 0);
  leds[49] = CRGB(0, 255, 0);
  leds[50] = CRGB(0, 0, 0);
  leds[51] = CRGB(0, 0, 0);
  leds[52] = CRGB(0, 0, 0);
  leds[53] = CRGB(0, 0, 0);
  leds[54] = CRGB(0, 255, 0);
  leds[55] = CRGB(0, 0, 0);
  leds[56] = CRGB(0, 0, 0);
  leds[57] = CRGB(0, 0, 0);
  leds[58] = CRGB(0, 255, 0);
  leds[59] = CRGB(0, 255, 0);
  leds[60] = CRGB(0, 255, 0);
  leds[61] = CRGB(0, 255, 0);
  leds[62] = CRGB(0, 0, 0);
  leds[63] = CRGB(0, 0, 0);
  FastLED.show();
  for (i = from; i < to; i++) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(cas);
  }
  for (i = to; i > from; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(cas);
  }
}

void angry() {
  FastLED.setBrightness(from);
  leds[0] = CRGB(0, 0, 0);
  leds[1] = CRGB(0, 0, 0);
  leds[2] = CRGB(255, 0, 0);
  leds[3] = CRGB(255, 0, 0);
  leds[4] = CRGB(255, 0, 0);
  leds[5] = CRGB(255, 0, 0);
  leds[6] = CRGB(0, 0, 0);
  leds[7] = CRGB(0, 0, 0);
  leds[8] = CRGB(0, 0, 0);
  leds[9] = CRGB(255, 0, 0);
  leds[10] = CRGB(0, 0, 0);
  leds[11] = CRGB(0, 0, 0);
  leds[12] = CRGB(0, 0, 0);
  leds[13] = CRGB(0, 0, 0);
  leds[14] = CRGB(255, 0, 0);
  leds[15] = CRGB(0, 0, 0);
  leds[16] = CRGB(255, 0, 0);
  leds[17] = CRGB(0, 0, 0);
  leds[18] = CRGB(255, 0, 0);
  leds[19] = CRGB(0, 0, 0);
  leds[20] = CRGB(0, 0, 0);
  leds[21] = CRGB(255, 0, 0);
  leds[22] = CRGB(0, 0, 0);
  leds[23] = CRGB(255, 0, 0);
  leds[24] = CRGB(255, 0, 0);
  leds[25] = CRGB(0, 0, 0);
  leds[26] = CRGB(0, 0, 0);
  leds[27] = CRGB(255, 0, 0);
  leds[28] = CRGB(0, 0, 0);
  leds[29] = CRGB(0, 0, 0);
  leds[30] = CRGB(0, 0, 0);
  leds[31] = CRGB(255, 0, 0);
  leds[32] = CRGB(255, 0, 0);
  leds[33] = CRGB(0, 0, 0);
  leds[34] = CRGB(0, 0, 0);
  leds[35] = CRGB(255, 0, 0);
  leds[36] = CRGB(0, 0, 0);
  leds[37] = CRGB(0, 0, 0);
  leds[38] = CRGB(0, 0, 0);
  leds[39] = CRGB(255, 0, 0);
  leds[40] = CRGB(255, 0, 0);
  leds[41] = CRGB(0, 0, 0);
  leds[42] = CRGB(255, 0, 0);
  leds[43] = CRGB(0, 0, 0);
  leds[44] = CRGB(0, 0, 0);
  leds[45] = CRGB(255, 0, 0);
  leds[46] = CRGB(0, 0, 0);
  leds[47] = CRGB(255, 0, 0);
  leds[48] = CRGB(0, 0, 0);
  leds[49] = CRGB(255, 0, 0);
  leds[50] = CRGB(0, 0, 0);
  leds[51] = CRGB(0, 0, 0);
  leds[52] = CRGB(0, 0, 0);
  leds[53] = CRGB(0, 0, 0);
  leds[54] = CRGB(255, 0, 0);
  leds[55] = CRGB(0, 0, 0);
  leds[56] = CRGB(0, 0, 0);
  leds[57] = CRGB(0, 0, 0);
  leds[58] = CRGB(255, 0, 0);
  leds[59] = CRGB(255, 0, 0);
  leds[60] = CRGB(255, 0, 0);
  leds[61] = CRGB(255, 0, 0);
  leds[62] = CRGB(0, 0, 0);
  leds[63] = CRGB(0, 0, 0);
  FastLED.show();
  for (i = from; i < to; i++) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(cas);
  }
  for (i = to; i > from; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(cas);
  }
}

void heart() {
  FastLED.setBrightness(from);
  leds[0] = CRGB(0, 0, 0);
  leds[1] = CRGB(0, 0, 0);
  leds[2] = CRGB(0, 0, 0);
  leds[3] = CRGB(255, 0, 95);
  leds[4] = CRGB(255, 0, 95);
  leds[5] = CRGB(255, 0, 95);
  leds[6] = CRGB(255, 0, 95);
  leds[7] = CRGB(0, 0, 0);
  leds[8] = CRGB(0, 0, 0);
  leds[9] = CRGB(0, 0, 0);
  leds[10] = CRGB(255, 0, 95);
  leds[11] = CRGB(255, 0, 95);
  leds[12] = CRGB(255, 0, 95);
  leds[13] = CRGB(255, 0, 95);
  leds[14] = CRGB(255, 0, 95);
  leds[15] = CRGB(255, 0, 95);
  leds[16] = CRGB(0, 0, 0);
  leds[17] = CRGB(255, 0, 95);
  leds[18] = CRGB(255, 0, 95);
  leds[19] = CRGB(255, 0, 95);
  leds[20] = CRGB(255, 0, 95);
  leds[21] = CRGB(255, 0, 95);
  leds[22] = CRGB(255, 0, 95);
  leds[23] = CRGB(255, 0, 95);
  leds[24] = CRGB(255, 0, 95);
  leds[25] = CRGB(255, 0, 95);
  leds[26] = CRGB(255, 0, 95);
  leds[27] = CRGB(255, 0, 95);
  leds[28] = CRGB(255, 0, 95);
  leds[29] = CRGB(255, 0, 95);
  leds[30] = CRGB(255, 0, 95);
  leds[31] = CRGB(0, 0, 0);
  leds[32] = CRGB(255, 0, 95);
  leds[33] = CRGB(255, 0, 95);
  leds[34] = CRGB(255, 0, 95);
  leds[35] = CRGB(255, 0, 95);
  leds[36] = CRGB(255, 0, 95);
  leds[37] = CRGB(255, 0, 95);
  leds[38] = CRGB(255, 0, 95);
  leds[39] = CRGB(0, 0, 0);
  leds[40] = CRGB(0, 0, 0);
  leds[41] = CRGB(255, 0, 95);
  leds[42] = CRGB(255, 0, 95);
  leds[43] = CRGB(255, 0, 95);
  leds[44] = CRGB(255, 0, 95);
  leds[45] = CRGB(255, 0, 95);
  leds[46] = CRGB(255, 0, 95);
  leds[47] = CRGB(255, 0, 95);
  leds[48] = CRGB(0, 0, 0);
  leds[49] = CRGB(0, 0, 0);
  leds[50] = CRGB(255, 0, 95);
  leds[51] = CRGB(255, 0, 95);
  leds[52] = CRGB(255, 0, 95);
  leds[53] = CRGB(255, 0, 95);
  leds[54] = CRGB(255, 0, 95);
  leds[55] = CRGB(255, 0, 95);
  leds[56] = CRGB(0, 0, 0);
  leds[57] = CRGB(0, 0, 0);
  leds[58] = CRGB(0, 0, 0);
  leds[59] = CRGB(255, 0, 95);
  leds[60] = CRGB(255, 0, 95);
  leds[61] = CRGB(255, 0, 95);
  leds[62] = CRGB(255, 0, 95);
  leds[63] = CRGB(0, 0, 0);
  FastLED.show();
  for (i = from; i < to; i++) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(cas);
  }
  for (i = to; i > from; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(cas);
  }
}

void police() {
  FastLED.setBrightness(255);
  for (r = 0; r < 5; r++) {
    for (i = 0; i < 5; i++) {
    fill_solid(leds, 32, CRGB(0, 0, 255));
    fill_solid(leds+32, 32, CRGB(0, 0, 0));
    FastLED.show();
    delay(cas+35);

    fill_solid(leds, 32, CRGB(0, 0, 0));
    FastLED.show();
    delay(cas+35);
    }
    for (i = 0; i < 5; i++) {
    fill_solid(leds+32, 32, CRGB(255, 0, 0));
    FastLED.show();
    delay(cas+35);

    fill_solid(leds+32, 32, CRGB(0, 0, 0));
    FastLED.show();
    delay(cas+35);
    }
  }
}

void rain() {
  for (i = 0; i < 5; i++) {
    fill_gradient_RGB(leds, NUM_LEDS, CRGB(255, 0, 0), CRGB(0, 255, 0), CRGB(0, 0, 255));
    FastLED.show();
    delay(250);
    fill_gradient_RGB(leds, NUM_LEDS, CRGB(0, 0, 255), CRGB(0, 255, 0), CRGB(255, 0, 0));
    FastLED.show();
    delay(250);
  }
}

void ani1() {
  FastLED.setBrightness(from);
  for (i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(255, 0, 0);
    FastLED.show();
    delay(cas);
  }
  for (i = NUM_LEDS; i > 0; i--) {
    leds[i] = CRGB(0, 255, 0);
    FastLED.show();
    delay(cas);
  }
  for (i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 255);
    FastLED.show();
    delay(cas);
  }
}

void aniR() {
  FastLED.setBrightness(from);
  for (r = 0; r < 5; r++) {
    for (i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(random(0, 256), random(0, 256), random(0, 256));
      FastLED.show();
     delay(cas);
    }
    for (i = NUM_LEDS; i > 0; i--) {
      leds[i] = CRGB(0, 0, 0);
      FastLED.show();
      delay(cas);
    }
  }
}

void ani2() {
  r = 31;
  g = 31;
  b = 31;

  for (i = 0; i < 8; i++) {
    leds[i] = CRGB(r, 0, 0);
    FastLED.show();
    delay(cas);
    leds[i] = CRGB(0, 0, 0);
    r = r + 31;
  }
  for (i = 8; i < NUM_LEDS; i++) {
    i = i + 7;
    leds[i] = CRGB(r, g, 0);
    FastLED.show();
    delay(cas);
    leds[i] = CRGB(0, 0, 0);
    r = r - 31;
    g = g + 31;
  }
  for (i = 63; i > 55; i--) {
    leds[i] = CRGB(0, g, b);
    FastLED.show();
    delay(cas);
    leds[i] = CRGB(0, 0, 0);
    g = g - 31;
    b = b + 31;
  }
  for (i = 55; i > 0; i--) {
    i = i - 7;
    leds[i] = CRGB(0, 0, b);
    FastLED.show();
    delay(cas);
    leds[i] = CRGB(0, 0, 0);
    b = b - 31;
  }
}

void ani3() {
  i = random(1, 4);
  r = 0;
  g = 0;
  b = 0;

  if (i == 1) {
    r = 255;
  }
  if (i == 2) {
    g = 255;
  }
  if (i == 3) {
    b = 255;
  }

  for (i = 0; i < 8; i++) {
    leds[i] = CRGB(r, g, b);
    FastLED.show();
    delay(cas);
    leds[i] = CRGB(0, 0, 0);
  }
  for (i = 8; i < NUM_LEDS; i++) {
    i = i + 7;
    leds[i] = CRGB(r, g, b);
    FastLED.show();
    delay(cas);
    leds[i] = CRGB(0, 0, 0);
  }
  for (i = 63; i > 55; i--) {
    leds[i] = CRGB(r, g, b);
    FastLED.show();
    delay(cas);
    leds[i] = CRGB(0, 0, 0);
  }
  for (i = 55; i > 0; i--) {
    i = i - 7;
    leds[i] = CRGB(r, g, b);
    FastLED.show();
    delay(cas);
    leds[i] = CRGB(0, 0, 0);
  }
}

void start() {
  for (i = 50; i < 100; i++) {
    FastLED.setBrightness(i);
    leds[27] = CRGB(0, 255, 0);
    leds[28] = CRGB(0, 255, 0);
    leds[35] = CRGB(0, 255, 0);
    leds[36] = CRGB(0, 255, 0);
    FastLED.show();
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  for (i = 50; i < 100; i++) {
    FastLED.setBrightness(i);
    leds[18] = CRGB(0, 255, 0);
    leds[19] = CRGB(0, 255, 0);
    leds[20] = CRGB(0, 255, 0);
    leds[21] = CRGB(0, 255, 0);
    leds[29] = CRGB(0, 255, 0);
    leds[37] = CRGB(0, 255, 0);
    leds[45] = CRGB(0, 255, 0);
    leds[44] = CRGB(0, 255, 0);
    leds[43] = CRGB(0, 255, 0);
    leds[42] = CRGB(0, 255, 0);
    leds[34] = CRGB(0, 255, 0);
    leds[26] = CRGB(0, 255, 0);
    FastLED.show();
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  for (i = 50; i < 100; i++) {
    FastLED.setBrightness(i);
    leds[9] = CRGB(0, 255, 0);
    leds[10] = CRGB(0, 255, 0);
    leds[11] = CRGB(0, 255, 0);
    leds[12] = CRGB(0, 255, 0);
    leds[13] = CRGB(0, 255, 0);
    leds[14] = CRGB(0, 255, 0);
    leds[22] = CRGB(0, 255, 0);
    leds[30] = CRGB(0, 255, 0);
    leds[38] = CRGB(0, 255, 0);
    leds[46] = CRGB(0, 255, 0);
    leds[54] = CRGB(0, 255, 0);
    leds[53] = CRGB(0, 255, 0);
    leds[52] = CRGB(0, 255, 0);
    leds[51] = CRGB(0, 255, 0);
    leds[50] = CRGB(0, 255, 0);
    leds[49] = CRGB(0, 255, 0);
    leds[41] = CRGB(0, 255, 0);
    leds[33] = CRGB(0, 255, 0);
    leds[25] = CRGB(0, 255, 0);
    leds[17] = CRGB(0, 255, 0);
    FastLED.show();
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  for (i = 50; i < 100; i++) {
    FastLED.setBrightness(i);
    leds[0] = CRGB(0, 255, 0);
    leds[1] = CRGB(0, 255, 0);
    leds[2] = CRGB(0, 255, 0);
    leds[3] = CRGB(0, 255, 0);
    leds[4] = CRGB(0, 255, 0);
    leds[5] = CRGB(0, 255, 0);
    leds[6] = CRGB(0, 255, 0);
    leds[7] = CRGB(0, 255, 0);
    leds[15] = CRGB(0, 255, 0);
    leds[23] = CRGB(0, 255, 0);
    leds[31] = CRGB(0, 255, 0);
    leds[39] = CRGB(0, 255, 0);
    leds[47] = CRGB(0, 255, 0);
    leds[55] = CRGB(0, 255, 0);
    leds[63] = CRGB(0, 255, 0);
    leds[62] = CRGB(0, 255, 0);
    leds[61] = CRGB(0, 255, 0);
    leds[60] = CRGB(0, 255, 0);
    leds[59] = CRGB(0, 255, 0);
    leds[58] = CRGB(0, 255, 0);
    leds[57] = CRGB(0, 255, 0);
    leds[56] = CRGB(0, 255, 0);
    leds[48]= CRGB(0, 255, 0);
    leds[40]= CRGB(0, 255, 0);
    leds[32]= CRGB(0, 255, 0);
    leds[24]= CRGB(0, 255, 0);
    leds[16]= CRGB(0, 255, 0);
    leds[8]= CRGB(0, 255, 0);
    FastLED.show();    
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
}

void stop() {
  for (i = 50; i < 100; i++) {
    FastLED.setBrightness(i);
    leds[0] = CRGB(0, 255, 0);
    leds[1] = CRGB(0, 255, 0);
    leds[2] = CRGB(0, 255, 0);
    leds[3] = CRGB(0, 255, 0);
    leds[4] = CRGB(0, 255, 0);
    leds[5] = CRGB(0, 255, 0);
    leds[6] = CRGB(0, 255, 0);
    leds[7] = CRGB(0, 255, 0);
    leds[15] = CRGB(0, 255, 0);
    leds[23] = CRGB(0, 255, 0);
    leds[31] = CRGB(0, 255, 0);
    leds[39] = CRGB(0, 255, 0);
    leds[47] = CRGB(0, 255, 0);
    leds[55] = CRGB(0, 255, 0);
    leds[63] = CRGB(0, 255, 0);
    leds[62] = CRGB(0, 255, 0);
    leds[61] = CRGB(0, 255, 0);
    leds[60] = CRGB(0, 255, 0);
    leds[59] = CRGB(0, 255, 0);
    leds[58] = CRGB(0, 255, 0);
    leds[57] = CRGB(0, 255, 0);
    leds[56] = CRGB(0, 255, 0);
    leds[48]= CRGB(0, 255, 0);
    leds[40]= CRGB(0, 255, 0);
    leds[32]= CRGB(0, 255, 0);
    leds[24]= CRGB(0, 255, 0);
    leds[16]= CRGB(0, 255, 0);
    leds[8]= CRGB(0, 255, 0);
    FastLED.show();    
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  for (i = 50; i < 100; i++) {
    FastLED.setBrightness(i);
    leds[9] = CRGB(0, 255, 0);
    leds[10] = CRGB(0, 255, 0);
    leds[11] = CRGB(0, 255, 0);
    leds[12] = CRGB(0, 255, 0);
    leds[13] = CRGB(0, 255, 0);
    leds[14] = CRGB(0, 255, 0);
    leds[22] = CRGB(0, 255, 0);
    leds[30] = CRGB(0, 255, 0);
    leds[38] = CRGB(0, 255, 0);
    leds[46] = CRGB(0, 255, 0);
    leds[54] = CRGB(0, 255, 0);
    leds[53] = CRGB(0, 255, 0);
    leds[52] = CRGB(0, 255, 0);
    leds[51] = CRGB(0, 255, 0);
    leds[50] = CRGB(0, 255, 0);
    leds[49] = CRGB(0, 255, 0);
    leds[41] = CRGB(0, 255, 0);
    leds[33] = CRGB(0, 255, 0);
    leds[25] = CRGB(0, 255, 0);
    leds[17] = CRGB(0, 255, 0);
    FastLED.show();
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  for (i = 50; i < 100; i++) {
    FastLED.setBrightness(i);
    leds[18] = CRGB(0, 255, 0);
    leds[19] = CRGB(0, 255, 0);
    leds[20] = CRGB(0, 255, 0);
    leds[21] = CRGB(0, 255, 0);
    leds[29] = CRGB(0, 255, 0);
    leds[37] = CRGB(0, 255, 0);
    leds[45] = CRGB(0, 255, 0);
    leds[44] = CRGB(0, 255, 0);
    leds[43] = CRGB(0, 255, 0);
    leds[42] = CRGB(0, 255, 0);
    leds[34] = CRGB(0, 255, 0);
    leds[26] = CRGB(0, 255, 0);
    FastLED.show();
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  for (i = 50; i < 100; i++) {
    FastLED.setBrightness(i);
    leds[27] = CRGB(0, 255, 0);
    leds[28] = CRGB(0, 255, 0);
    leds[35] = CRGB(0, 255, 0);
    leds[36] = CRGB(0, 255, 0);
    FastLED.show();
  }
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
}

void spstjbc() {
  fill_solid(leds, 27, CRGB(0, 0, 255));
  fill_solid(leds+32, 3, CRGB(0, 0, 255));
  fill_solid(leds+40, 3, CRGB(0, 0, 255));
  fill_solid(leds+48, 3, CRGB(0, 0, 255));
  fill_solid(leds+56, 3, CRGB(0, 0, 255));

  fill_solid(leds+27, 5, CRGB(255, 255, 255));
  fill_solid(leds+35, 5, CRGB(255, 255, 255));
  fill_solid(leds+43, 5, CRGB(255, 255, 255));
  fill_solid(leds+51, 5, CRGB(255, 255, 255));
  fill_solid(leds+59, 5, CRGB(255, 255, 255));

  leds[27] = CRGB(0, 0, 0);
  leds[31] = CRGB(0, 0, 0);
  leds[63] = CRGB(0, 0, 0);
  leds[59] = CRGB(0, 0, 0);

  FastLED.show();
}