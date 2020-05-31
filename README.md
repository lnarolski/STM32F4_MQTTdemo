# STM32F4_MQTTdemo
Demo project showing possibility to combine projects from TouchGFX and STM32CubeMX software

# Table of contents

* [General info](#general-info)
* [Pinout](#pinout)
* [Schematic](#schematic)
* [Screens](#screens)
* [Video](#video)

# General info

The goal of this project was to try combine projects made in TouchGFX (GUI), STM32CubeMX (peripherals configuration) and Keil software (algorithms). You can try to use IWARM or IWARM6 as substitute for Keil (generated projects in [Project](/Project/) directory). MQTT was tested on OpenWRT router with installed Mosquitto broker.

# Pinout

Pinout of STM32F429ZI is shown below:
<p align="center">
  <img align="center" src="/Img/pinout.png">
</p>

# Schematic

<p align="center">
  <img align="center" src="/Schematic/schematic.png">
</p>

# Screens

## Main Screen

<p align="center">
  <img align="center" src="/Img/MainScreen.png">
</p>

On this screen you can see 10 messages received from 'demo' broker topic. Maximum lenght of message is 30 characters (maximum size of buffer; you can change it in TouchGFX project source code). To connect STM32F4 to MQTT broker I used ESP32 programmed with [MQTToverSerial](https://github.com/lnarolski/MQTToverSerial) library. Arduino code for ESP32 you can find in [ESP32](/ESP32/esp32) directory.

## Temp Screen

<p align="center">
  <img align="center" src="/Img/TempScreen.png">
</p>

On this screen you can read value of temperature from Dallas DS18B20 temperature sensor connected to STM32 via 1-Wire interface. To read this value I used a little modified by me [DS18B20_STM32_HAL](https://github.com/lamik/DS18B20_STM32_HAL) library. Value of temperature is showed on Text Area and Box Progress widgets. Also about every second value of temperature is sended to 'temp' broker topic.

## Light Screen

<p align="center">
  <img align="center" src="/Img/LightScreen.png">
</p>

On this screen you can read value of light from photoresistor connected to STM32 via Analog-Digital Converter. Value of light is showed on Text Area and Box Progress widgets as percent value. Also about every second percent value of light is sended to 'light' broker topic.

## RGB Screen

<p align="center">
  <img align="center" src="/Img/RGBScreen.png">
</p>

On this screen you can control light of RGB diode with 3 Slider widgets. To control value of light I used 3 output pin channels with PWM DMA control.

# Video

<p align="center">
<a href="http://www.youtube.com/watch?feature=player_embedded&v=lVDuat6gULU
" target="_blank"><img src="http://img.youtube.com/vi/lVDuat6gULU/0.jpg" 
alt="YouTube video" border="10" /></a>
</p>
