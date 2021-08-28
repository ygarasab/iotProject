#include <ESP8266WiFi.h>
#include "Settings.h"

const char* ssid = WIFI_NAME;
const char* password = WIFI_PASSWORD;

void stablishWiFiConnection()
{
    Serial.print("Connecting to");
	Serial.println(ssid);

	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, password);
	
	while(WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");	
	}

	Serial.println();
	Serial.println("Wifi connected");
	Serial.println(WiFi.localIP());
}