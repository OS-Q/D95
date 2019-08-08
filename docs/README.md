## [arduino传感器](https://github.com/OS-Q/D95)

```
This chip uses I2C bus to communicate, specials pins are required to interface
Board:                                    SDA                    SCL                    Level
Uno, Mini, Pro, ATmega168, ATmega328..... A4                     A5                     5v
Mega2560................................. 20                     21                     5v
Due, SAM3X8E............................. 20                     21                     3.3v
Leonardo, Micro, ATmega32U4.............. 2                      3                      5v
Digistump, Trinket, ATtiny85............. 0/physical pin no.5    2/physical pin no.7    5v
Blue Pill, STM32F103xxxx boards.......... PB7                    PB6                    3.3v/5v
ESP8266 ESP-01........................... GPIO0/D5               GPIO2/D3               3.3v/5v
NodeMCU 1.0, WeMos D1 Mini............... GPIO4/D2               GPIO5/D1               3.3v/5v
ESP32.................................... GPIO21/D21             GPIO22/D22             3.3v

Frameworks & Libraries:
ATtiny  Core          - https://github.com/SpenceKonde/ATTinyCore
ESP32   Core          - https://github.com/espressif/arduino-esp32
ESP8266 Core          - https://github.com/esp8266/Arduino
STM32   Core          - https://github.com/rogerclarkmelbourne/Arduino_STM32

```

### [温湿度](https://github.com/OS-Q/D95) 

* [Si7021](docs/)
* [SHT31](src/)
* [HTU21](HTU21/)
* [AM2320](AM2320/)
* [DHT](DHT/)

### [空气检测](https://github.com/OS-Q/D95) 

* [SGP30](HTU21/)
* [CCS811](AM2320/)

### [综合感知](https://github.com/OS-Q/D95) 

* [BME](BME/)
* [BMP](BMP/)