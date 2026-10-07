# 🤖 Voice Control Humanoid Robot

A wireless, voice-controlled robotic vehicle built around the **ATmega328P** microcontroller and an **HC-05 Bluetooth module**. The robot is driven entirely by spoken commands, given through an Android voice-control app, making it a low-cost assistive and educational robotics platform.

---

## 📖 Hardware & PCB Documentation

For complete hardware details, pinout mappings, circuit diagrams, PCB layout steps, etching procedures, and soldering guidelines, please refer to the comprehensive guide:
- 📄 **[Hardware and PCB Guide](docs/HARDWARE_AND_PCB_GUIDE.md)**

---

## 🛠️ Bill of Materials (BOM)

| Component | Specification | Quantity | Description |
| --- | --- | --- | --- |
| Microcontroller | ATmega328P | 1 | 8-bit AVR Microcontroller (Arduino Uno core) |
| Bluetooth Module | HC-05 | 1 | Wireless communication for voice control |
| Motor Driver Shield | L293D Shield | 1 | Quadruple H-bridge motor driver shield |
| Motors | DC Gear Motors | 4 | 12V / 300 RPM DC Geared Motors for movement |
| Battery | 3.7V 2000mAh Li-ion | 1 | Rechargeable power source |
| Voltage Regulator | LM7805 | 1 | 5V linear voltage regulator IC |

---

## 💻 System Architecture & Operation

1. **Voice Input:** Smartphone application captures user voice input and converts speech to text.
2. **Bluetooth Transmission:** App sends text strings via Bluetooth to the HC-05 module connected to the microcontroller's RX pin.
3. **Command Processing:** ATmega328P parses the incoming text command (e.g., "forward", "backward", "left", "right", "stop").
4. **Motor Control:** Microcontroller outputs PWM and logic signals to the L293D motor driver shield to actuate the 4 DC gear motors.
