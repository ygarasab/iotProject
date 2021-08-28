#include <PubSubClient.h>
#include <ESP8266WiFi.h>

#define MESSAGE_BUFFER_SIZE (50)

const char* host = "broker.emqx.io";

WiFiClient espClient;
PubSubClient client(espClient);

char msg[MESSAGE_BUFFER_SIZE];

void mqttReconnect()
{
    while (!client.connected())
    {
        String clientID = "PlaquinhaBraba";
        Serial.print("Connectando a ");
        Serial.println(host);
        
        if(client.connect(clientID.c_str()))
        {
            Serial.println("Connectado");
            client.publish("ygarasab/", "Bom dia");
        }
        else
        {
            Serial.println("Conexão falhou");
            delay(5000);
        }
    }
    
}

void stablishMQTTConnection()
{
    client.setServer(host, 1883);
}



