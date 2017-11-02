#include <Adafruit_GFX.h>   // Hardware-specific library, LCD Library
#include <MCUFRIEND_kbv.h>  // LCD Library
MCUFRIEND_kbv tft;          // LCD Library
#include <DHT.h>            // Temperature-Humidity Sensor Library
#include <DHT_U.h>          // Temperature-Humidity Sensor Library  

int SENSOR = 22;
int temp, humedad;
DHT dht(SENSOR, DHT11);

void setup()
{
    Serial.begin(9600);
    //LCD
    tft.reset();
    uint16_t identifier = tft.readID();  
    if (identifier == 0xEFEF) identifier = 0x9486;
    tft.begin(identifier);
    //Humidity-Temperature
    dht.begin();
}

void loop()
{
    uint16_t x = 50, y = 100;
    tft.setRotation(1);
    tft.fillScreen(0x0000);
    tft.setCursor(0, 0);
    tft.setTextSize(2);
    tft.println("Temperatura (C):");
    tft.setCursor(240, 0);
    tft.println(dht.readTemperature());
    tft.println("Humedad     (%):");
    tft.setCursor(240, 20);
    tft.println(dht.readHumidity());
    tft.println("Humedad Tierra : ");
    tft.setCursor(240, 40);
    tft.println(analogRead(15));
    delay(50000);



      
}

