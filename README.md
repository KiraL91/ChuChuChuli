# ChuChuChuli

ESP-32 project. Plays custom audio file using a low power speaker. Tryes Folder the Simpson's chapter in which Ralph receives from Lisa the I choo-choo-choose you Valentines card.

## Hardware

* ESP-32 microcontroller.
* PAM8302A audio amplifier.
* Low power speaker.

## Configuration

Project developed with Visual Code IDE. Platformio plugin for this IDE is required. Once installed, you should see a new item in the left bar. Left click and for uploading the code to the board, click on `esp32dev > General > Upload`.

Once you try to build the project, a error would appear on hte console about the `esp32-hal-timer` dependency not found. You should try to 

## Wiring

For more information on the pin configuration, watch the `include/config.h`  configuration file.

## Issues

If Arduino library is declared as missing, try to delete the `.vscode` folder and restart Visual Code.
