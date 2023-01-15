#include <ESP8266WiFi.h>
#include <FastLED.h>

#define LED_PIN     D6
#define NUM_LEDS    150
#define BRIGHTNESS  128
#define SPEED       20

CRGB leds[NUM_LEDS];
WiFiServer server(80);

// preset patterns
enum {
  PATTERN_RAINBOW,
  PATTERN_RAINBOW_CYCLE,
  PATTERN_THEATER_CHASE,
  PATTERN_CUSTOM
};

int pattern = PATTERN_RAINBOW;
int speed = SPEED;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  WiFi.begin("your_ssid", "your_password");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  server.begin();
  Serial.println("Server started");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/brightness") != -1) {
      int start = request.indexOf("=") + 1;
      int end = request.indexOf("&");
      String value = request.substring(start, end);
      FastLED.setBrightness(value.toInt());
    }

    if (request.indexOf("/speed") != -1) {
      int start = request.indexOf("=") + 1;
      int end = request.indexOf("&");
      String value = request.substring(start, end);
      speed = value.toInt();
    }

    if (request.indexOf("/pattern") != -1) {
      int start = request.indexOf("=") + 1;
      int end = request.indexOf("&");
      String value = request.substring(start, end);
      pattern = value.toInt();
    }
  }

  switch (pattern) {
    case PATTERN_RAINBOW:
      rainbow();
      break;
    case PATTERN_RAINBOW_CYCLE:
      rainbowCycle();
      break;
    case PATTERN_THEATER_CHASE:
      theaterChase();
      break;
    case PATTERN_CUSTOM:
      // your custom pattern here
      break;
  }
  FastLED.show();
  delay(speed);
}

void rainbow() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(i + millis() / 10, 255, 255);
  }
}

void rainbowCycle() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV((i * 256 / NUM_LEDS) + millis() / 10, 255, 255);
  }
}

void theaterChase() {
  for (int i = 0; i < NUM_LEDS; i += 3) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
  delay(speed);
  for (int i = 0; i < NUM_LEDS; i += 3) {
    leds[i] = CRGB::Black;
  }
}
