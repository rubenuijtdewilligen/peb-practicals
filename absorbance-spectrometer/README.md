# LAB2: Arduino Absorbance Spectrometer

This project expands the LAB1 temperature measurement setup by adding an absorbance spectrometer using a laser and a photoresistor (LDR). It allows monitoring the decomposition of brilliant blue dye (after adding hydrogen peroxide) over time by measuring absorbance. This data can then be used to analyse the reaction kinetics, reaction order, rate constant, and activation energy.

## Files

- Arduino code: `arduino.ino`
- Python log script: `read.py`
- Example data: `output/logs.csv`

## Hardware

- Arduino Nano
- DS18B20 temperature sensor
- SSD1306 display
- Laser diode
- Photoresistor (LDR)

![1](/absorbance-spectrometer/docs/1.jpg)

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
3. Read your data from `output/logs.csv`.

## Example data

The example data in `output/logs.csv` was recorded by adding hydrogen peroxide to the brilliant blue dye at 40 degrees Celsius and measuring the decrease in light absorbance.
