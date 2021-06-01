#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


char auth[] = "WyDUeQm7-0MXDWvmKK9urzIxz64qy05t";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "adalovelace";
char pass[] = "geladotrincando";

WidgetLED led1(V1);

BlynkTimer timer;


void blinkLedWidget()
{
  if (led1.getValue()) {
    led1.off();
    Serial.println("LED on V1: off");
  } else {
    led1.on();
    Serial.println("LED on V1: on");
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
 
  timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}
