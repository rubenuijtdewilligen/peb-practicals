# LAB1: Arduino Temperature Sensor

This project measures the temperature using a DS18B20 sensor connected to an Arduino and logs the data to a CSV-file using a Python script.

The DS18B20 temperature sensor has a temperature range of -55°C to +125°C and an accuracy of ±0.5°C.

The temperature has a resolution which can be set to 9, 10, 11, or 12 bits. The default resolution at boot is 12-bit, which gives the highest 0.0625°C precision.

This project was built to simulate an adiabatic calorimeter. This was done by putting the sensor inside a Dewar thermosflask and using a magnetic stirrer to distribute the temperature evenly in the flask.

## Files

- Arduino code: `temperature_sensor.ino`
- Python log script: `read_temperature.py`
- Example data: `output/temperatures.csv`

## Hardware

- Arduino Nano
- DS18B20 temperature sensor
- SSD1306 display

![1](/temperature-sensor/docs/1.png)
![2](/temperature-sensor/docs/2.png)

## Software Requirements

- Arduino IDE with:

  - OneWire
  - DallasTemperature
  - Adafruit_SSD1306
  - Adafruit_GFX

- Python 3 with:
  - pyserial

## Usage

1. Upload the Arduino code.
2. Start the Python script with the correct COM port.
3. Read your data from `output/temperatures.csv`.

## Example data

The example data in `output/temperatures.csv` was recorded while holding the sensor to warm it up and then letting it cool down again.
