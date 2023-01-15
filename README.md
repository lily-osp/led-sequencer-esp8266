# ESP8266 Based LED Sequencer

This repository contains the code for a simple LED sequencer using the ESP8266 microcontroller. The sequencer is controlled by a web interface and uses the [FastLED library](https://github.com/FastLED/FastLED) to control the LEDs.

## Hardware
- ESP8266 (NodeMCU v3 used in development)
- WS2812B LED strip
- Power supply (5V, at least 3A)

## Features
- Web interface for controlling the sequencer
- Adjustable brightness and speed
- Multiple preset patterns
- Ability to save and load custom patterns

## Getting Started
1. Connect the ESP8266 to your computer and upload the code to the microcontroller using the Arduino IDE.
2. Connect the LED strip to the ESP8266 using the following pinout:
    - Data pin: D6 (GPIO 12)
    - +5V pin: VCC
    - GND pin: GND
3. Connect the ESP8266 to your network and open the web interface by entering the IP address of the device in your web browser.
4. Use the interface to adjust the settings and select patterns.

## Troubleshooting
- Make sure the power supply can handle the current draw of the LED strip.
- Double check the connections to the LED strip and ensure that the data pin is connected to the correct pin on the ESP8266.
- If the LEDs do not light up, try reversing the data pin connections to the LED strip.
- If the web interface is not accessible, check that the ESP8266 is connected to the network and obtain the IP address.

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
