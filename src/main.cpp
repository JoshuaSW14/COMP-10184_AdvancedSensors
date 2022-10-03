//I, Joshua Symons-Webb, 000812836 certify that this material is my original work. No
//other person's work has been used without due acknowledgement.

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int oneWireBus = D3;
OneWire oneWire(oneWireBus);
DallasTemperature DS18B20(&oneWire);
uint8_t address[8];

void setup()
{
  Serial.begin(115200);
  DS18B20.begin();
  uint8_t address[8];

  if (DS18B20.getAddress(address, 0))
  {
    Serial.print("\n\nAddress fetched:");
  }
  else
  {
    Serial.println("Error fetching the address");
    return;
  }

  for (int i = 0; i < 8; i++)
  {
    Serial.printf("%02X ", address[i]);
    Serial.println();
  }
}

void loop()
{
  // When your application starts, print out the sensor ID.  If no sensor is attached to your breadboard, your program
  // must print an explanatory message to the serial debug port and terminate gracefully.

  float fTemp;
  DS18B20.requestTemperatures();
  fTemp = DS18B20.getTempCByIndex(0);

  Serial.print("Current temperature is: " + String(fTemp) + " C or ");

  if (fTemp < 10)
  {
    Serial.println("Cold!");
  }
  else if (fTemp >= 10 && fTemp <= 15)
  {
    Serial.println("Cool");
  }
  else if (fTemp > 15 && fTemp <= 25)
  {
    Serial.println("Perfect");
  }
  else if (fTemp > 25 && fTemp <= 30)
  {
    Serial.println("Warm");
  }
  else if (fTemp > 30 && fTemp <= 35)
  {
    Serial.println("Hot");
  }
  else if (fTemp > 35)
  {
    Serial.println("Too Hot!");
  }

  delay(5000);
}