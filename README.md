# Seeed-ArduPy-ads1115 [![Build Status](https://travis-ci.com/Seeed-Studio/seeed-ardupy-ads1115.svg?branch=master)](https://travis-ci.com/Seeed-Studio/seeed-ardupy-ads1115)

## Introduction

An ArduPy library for AGrove - Temp&Humi&Barometer Sensor (BME280). Grove BME280 provides a precise measurement of not only barometric pressure and temperature, but also the humidity in the environment. The air pressure can be measured in a range from 300 hPa to 1100hPa with ±1.0 hPa accuracy, while the sensor works perfectly for temperatures between - 40℃ and 85℃ with an accuracy of ±1℃. As for the humidity, you can get a humidity value with an error less than 3%.



## How to binding with ArduPy

- Install [AIP](https://github.com/Seeed-Studio/ardupy-aip)
```shell
pip3 install aip
```
- Build firmware with Seeed ArduPy ads1115
```shell
aip install https://github.com/Seeed-Studio/seeed-ardupy-bme280
aip build
```
- Flash new firmware to you ArduPy board
```shell
aip flash [Ardupy Bin PATH]
```
For more examples of using AIP, please refer to [AIP](https://github.com/Seeed-Studio/ardupy-aip).

## Usage

```python
from arduino import grove_bme280
import time

bme280 = grove_bme280()

while True:
    print ("Temperature: ", bme280.temperature, "C")
    print ("Humidity: ", bme280.humidity, "%")
    print ("Pressure: ", bme280.pressure, "Pa")
    time.sleep(1)

```


This software is written by seeed studio<br>
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>