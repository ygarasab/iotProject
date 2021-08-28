#include "WifiConnection.h"
#include "MQTTConnection.h"

int lastMessage = 0;

void setup()
{

	pinMode(BUILTIN_LED, OUTPUT);
	Serial.begin(9600);
	Serial.println();
	stablishWiFiConnection();
	stablishMQTTConnection();
}

void loop()
{
	if(!client.connected())
		mqttReconnect();
	
	client.loop();
	unsigned int now = millis();

	if(now - lastMessage > 1000)
	{
		lastMessage = now;
		Serial.println("Checando os arredores");
		client.publish("ygarasab/", "Apenas checando...");
	}
}
