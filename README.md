# Sample app for HC_SRO4 single pin ultrasonic sensor

This is a sample app for the HC-SR04 ultrasonic sensor. It uses a single pin to trigger the sensor and read the echo.

More information are provided in the driver module repository : https://github.com/ptournoux/hcsr04-trig.git



## Dependancy

This sample app obviously requires the hcsr04-trig driver module.

This can be added to your workspace through west.


Add the module hcsr04-trig to your project's west.yml file e.g. through
`vi ~/zephyrproject/zephyr/west.yml`


```yml

- name: hcsr04-trig 
      url: https://github.com/ptournoux/hcsr04-trig.git
      revision: main
      path: modules/lib/hcsr04-trig

```

Run west update :

```bash
cd ~/zephyrproject/zephyr
west update
```

## Clone this repository

Clone this repository to your zephyr workspace.

```bash
cd ~/zephyrproject/zephyr
git clone https://github.com/ptournoux/hcsr04-trig-sample.git
```


## Build the app

```bash
west build --board=nucleo_l073rz -p always hcsr04-trig-sample
```

## Flash the app

```bash
west flash
```

May require the stlink tools to be installed.

## What is the expected output?

Open the serial terminal :

```bash
picocom -b 115200 /dev/ttyACM0
```

You should see the distance measured by the sensor in m.

```
stance: 0.911000 m
Distance: 0.912000 m
Distance: 5.313000 m
*** Booting Zephyr OS build v4.0.0-3689-g2615ec879e04 ***
HCSR04TRIG device found and ready
Distance: 0.916000 m
Distance: 0.916000 m
Distance: 0.912000 m
Error: sensor_sample_fetch failed: -5
Distance: 1.913000 m
Distance: 5.314000 m
Distance: 1.913000 m
Distance: 0.911000 m
```

Note that the sensor is not very accurate and may return some errors if the echo delay exceeds 10ms.

## What is my next step?

If you don't have a nucleo_l073rz board, you should add an overlay file in the board directory. Contributions are welcome.