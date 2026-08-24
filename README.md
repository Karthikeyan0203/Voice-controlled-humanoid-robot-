# 🤖 Voice Control Humanoid Robot

A wireless, voice-controlled robotic vehicle built around the **ATmega328P** microcontroller and an **HC-05 Bluetooth module**. The robot is driven entirely by spoken commands, given through an Android voice-control app, making it a low-cost assistive and educational robotics platform.

---

## 📖 Overview

Many people with mobility impairments depend on others for daily tasks, and conventional bots rely on joysticks, touch switches, or GUIs that aren't always accessible. This project replaces those interfaces with **voice**: a smartphone app captures speech, converts it to text commands, and sends them over Bluetooth to the robot's controller, which drives motors accordingly.

**Goals of the project:**
- Control a robotic vehicle using human voice.
- Integrate a mobile app, actuators, and controllers with wireless communication.
- Interface the mobile app and the bot via Bluetooth technology.

---

## ✨ Features

- Fully wireless voice control — no manual driving required.
- Four core movement commands: **Forward, Backward, Left, Right, Stop.**
- Built on the widely-used, low-cost **ATmega328P** (Arduino-compatible) microcontroller.
- Simple, reproducible hardware build (custom PCB, off-the-shelf modules).
- Assistive-tech friendly design — adaptable for wheelchairs and mobility aids.

---

## 🛠️ Hardware Components

| Component | Purpose |
|---|---|
| **ATmega328P** | Main microcontroller — processes commands and drives outputs |
| **HC-05 Bluetooth Module** | Wireless serial link between smartphone and controller |
| **L293D Motor Driver Shield** | Drives up to 4 DC motors (600 mA–1.2 A per channel) |
| **Gear Motors** | Provide drive torque for the robot's wheels |
| **LM7805 Voltage Regulator** | Regulates power supply to 5V logic |
| **Li-ion Battery (3.7V, 2000mAh)** | Powers the motor drivers |
| **Smartphone (Android)** | Runs the voice-control app (transmitter) |

---

## 🧩 System Architecture

```
 Voice Input → Android App (Speech-to-Text) → Bluetooth (HC-05)
              → ATmega328P (decodes command) → L293D Motor Driver → DC Motors
```

1. User speaks a command (e.g., "Forward") into the Android app.
2. The app converts speech to text and transmits it over Bluetooth as a single character (`U`, `D`, `L`, `R`, `S`).
3. The HC-05 module on the robot relays this to the ATmega328P.
4. The microcontroller decodes the character and signals the L293D motor driver.
5. The gear motors rotate accordingly, moving the robot.

---

## 💻 Software

### Requirements
- [Arduino IDE](https://www.arduino.cc/en/software)
- `AFMotor` library (for the L293D motor shield)
- Android voice-control app (e.g., **sriTu Hobby** voice controller app) installed on your phone

### Firmware Logic

The robot listens for single-character serial commands over Bluetooth:

| Command | Action |
|---|---|
| `U` | Move Forward |
| `D` | Move Backward |
| `L` | Turn Left |
| `R` | Turn Right |
| `S` | Stop |

See [`voice_control_robot.ino`](./voice_control_robot.ino) for the full source code.

---

## ⚙️ Setup & Usage

1. **Assemble the hardware** — wire the ATmega328P, L293D motor shield, HC-05 module, and gear motors per the circuit diagram.
2. **Flash the firmware** — open the sketch in Arduino IDE, select the correct board and COM port, and upload.
3. **Pair Bluetooth** — power on the robot and pair your phone with the HC-05 module.
4. **Install the app** — install the voice-control Android app and connect it to the robot via Bluetooth.
5. **Give voice commands** — enable voice mode in the app and speak commands like "Forward," "Backward," "Left," "Right," or "Stop."

---

## 🚀 Applications

- Home automation & smart device control
- Assistive robots for people with mobility impairments
- Industrial automation and inventory handling
- Educational and interactive robotics
- Precision agriculture, surveillance, and search-and-rescue platforms

---

## ✅ Advantages

- Intuitive, hands-free control
- Inclusive design for users with disabilities
- Fast, natural-language command execution
- Easily extensible to other smart-device integrations

## ⚠️ Limitations

- Sensitive to ambient noise and speech-recognition accuracy
- Limited, predefined vocabulary of commands
- Requires Bluetooth/internet connectivity
- Possible response latency and security considerations

---

## 🔮 Future Enhancements

- IoT integration for remote monitoring and control
- AI-based user voice identification for personalized access
- Object detection/tracking for collision avoidance
- Extended command sets for more complex maneuvers

---

## 📚 References

Full component datasheets, PCB design steps, and circuit diagrams are documented in the project report. PCB was designed using **EasyEDA** and fabricated via the toner-transfer + ferric chloride etching method.

---

## 📄 License

Add your preferred license here (e.g., MIT, Apache 2.0).
