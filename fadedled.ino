#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


char auth[] = "WyDUeQm7-0MXDWvmKK9urzIxz64qy05t";

char ssid[] = "adalovelace";
char pass[] = "geladotrincando";

WidgetLED led2(V2);

BlynkTimer timer;

// V2 LED Widget is fading
void fadeLedWidget()
{
  static int value = 0;
  static int delta = 30;
  value += delta;
  if (value > 255 || value < 0) {
    delta = -delta;
  } else {
    Serial.print("LED on V2: ");
    Serial.println(value);
    led2.setValue(value);
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(3000L, fadeLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}
