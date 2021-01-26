# DS18B20-single

An easy to use library to read one single DS18B20 sensor on a 1-wire bus in mbed-os.

## Usage

1. include Library
```
#include "DS18B20.h"
```

2. Open instance of sensor and pass the PinName to the constructor
```
DS18B20 sensor(PinName) //Substitude PinName for the pin to witch the Sensor is connected
```

3. Read temperature by by using readTemp()
```
float temperature = sensor.readTemp();
```
Please note that taking a measurement will take over 750ms

## Example
### Nucleo L432KC with sensor on pin A0 (mbed-os 5)
```
#include "mbed.h"
#include "DS18B20.h" //include the library

DS18B20 sensor(A0); //Create an instance of DS18B20, name it sensor, set A0 as pin
 
int main()
{
    while(1)
	{
		printf("Temp: %6.1f C\n", tempsense.readTemp()); //read the temperature and output it to the default debug serial interface.
		ThisThread::sleep_for(1000); //wait 1s before measuring again
    }
}
```

### Nucleo L432KC with sensor on pin A0 (mbed-os 6)
1. main.cpp
```
#include "mbed.h"
#include "DS18B20.h" //include the library

DS18B20 sensor(A0); //Create an instance of DS18B20, name it sensor, set A0 as pin
 
int main()
{
    while(1)
	{
		printf("Temp: %6.1f C\n", tempsense.readTemp()); //read the temperature and output it to the default debug serial interface.
		ThisThread::sleep_for(1s); //wait 1s before measuring again
    }
}
```

2. Printing floats in mbed-os 6 is disabled by default to save space. If you have a mbed_app.json file in your project root directory, add
```
    "target_overrides": {
        "*": {
            "target.printf_lib": "std"
        }
    }
```
to this file. Otherwise, create mbed_app.json in the projects root directory and paste the following code into it:
```
{
    "target_overrides": {
        "*": {
            "target.printf_lib": "std"
        }
    }
}
```

## Installation

### MBED online compiler
1. Right-Click your project.
2. select Import "Library" > "From URL".
3. Type
```
https://github.com/LukasGessner/DS18B20-single
```
as URL.

### MBED Studio
1. Make shure your target program is selected under "Active program".
2. On the bottom of the screen, select the "Library" tab.
3. Click the "+" icon.
4. Enter
```
https://github.com/LukasGessner/DS18B20-single
```
as the URL.


### MBED CLI
1. Open the command prompt in the project folder.
2. Type
```
mbed add https://github.com/LukasGessner/DS18B20-single
```
into the command prompt.

