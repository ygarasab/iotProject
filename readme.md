# IoT Project

Este é um projeto universitário de IoT. Todos os comandos e scripts listados abaixo são para uma placa esp8266 mini, na porta /dev/ttyUSB0.

## Setup 

Note que vocẽ precisa ter o `arduino-cli` instalado e no path, além do que você precisa preencher o nome do seu WiFi e sua senha.

```sh
$ arduino-cli config set board_manager.additional_urls https://arduino.esp8266.com/stable/package_esp8266com_index.json

$ arduino-cli core install esp8266:esp8266

$ arduino-cli lib install PubSubClient

$ printf '#define WIFI_NAME ("mywifiname")\n#define WIFI_PASSWORD ("mywifipassword")' > Settings.h

 ```

 ou só 

```sh 
$ ./setup mywifiname mywifipassword
```

## Rodando

 ```
$ arduino-cli compile --fqbn esp8266:esp8266:d1_mini

$ arduino-cli upload -p /dev/ttyUSB0 --fqbn esp8266:esp8266:d1_mini
 ``` 

## Checando a interface serial

Estou usando aqui um pacote node para isso.

 ```
$ sudo npm i -g @serialport/terminal

$ serialport-terminal -p /dev/ttyUSB0
 ```

## Quick Run

Você pode usar esse script para compilar, gravar e ouvir à porta serial :) .

```
$ ./run