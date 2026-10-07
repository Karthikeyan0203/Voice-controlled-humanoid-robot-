# Hardware and PCB Guide

This document provides complete hardware specifications, pinout configurations, circuit diagrams, PCB design, fabrication, etching, and assembly/soldering guidelines for the Voice-Controlled Humanoid Robot project.

---

## 1. Bill of Materials (BOM)

| Component | Specification | Quantity | Description |
| --- | --- | --- | --- |
| Microcontroller | ATmega328P | 1 | 8-bit AVR Microcontroller (Arduino Uno core) |
| Bluetooth Module | HC-05 | 1 | Wireless communication for voice control |
| Motor Driver Shield | L293D Shield | 1 | Quadruple H-bridge motor driver shield |
| Motors | DC Gear Motors | 4 | 12V / 300 RPM DC Geared Motors for movement |
| Battery | 3.7V 2000mAh Li-ion | 1 | Rechargeable power source |
| Voltage Regulator | LM7805 | 1 | 5V linear voltage regulator IC |

---

## 2. Pinout Configuration & Mapping

### ATmega328P Pin Mapping
- **Digital Pin 0 (RX):** Connected to HC-05 Bluetooth TX.
- **Digital Pin 1 (TX):** Connected to HC-05 Bluetooth RX.
- **Digital Pins 3, 5, 6, 11 (PWM):** L293D Motor Speed & Direction control lines.
- **Digital Pins 4, 7, 8, 12:** L293D Motor Control Logic lines.
- **VCC (Pin 7, 20):** +5V Power Supply from LM7805.
- **GND (Pin 8, 22):** Common Ground connection.

### LM7805 Voltage Regulator Pinout
- **Pin 1 (Input / VI):** Unregulated Input Voltage from Li-ion Battery / Power Source.
- **Pin 2 (Ground / GND):** Common Ground.
- **Pin 3 (Output / VO):** Regulated +5V DC Output to ATmega328P and HC-05.

### L293D Motor Shield Terminal Connections
- **M1 Terminals:** Front-Left DC Gear Motor.
- **M2 Terminals:** Front-Right DC Gear Motor.
- **M3 Terminals:** Rear-Left DC Gear Motor.
- **M4 Terminals:** Rear-Right DC Gear Motor.

### HC-05 Bluetooth Module Connections
- **VCC:** +5V DC (LM7805 Output).
- **GND:** Common Ground.
- **TX:** Connected to ATmega328P RX (Pin 0).
- **RX:** Connected to ATmega328P TX (Pin 1).

---

## 3. Circuit & Block Diagram Descriptions

### System Block Diagram
1. **Power Supply Stage:** 3.7V Li-ion battery stepped/regulated via LM7805 regulator providing a stable 5V supply to the microcontroller and sensors.
2. **Control Unit:** ATmega328P processes voice commands received via Bluetooth and controls motor driver IC outputs.
3. **Communication Unit:** HC-05 Bluetooth module receives text/voice data strings from smartphone app and forwards them serially to ATmega328P.
4. **Drive Unit:** L293D motor driver shield controls 4x DC Gear motors (M1-M4) for forward, backward, left, right, and stop motion.

---

## 4. PCB Design in EasyEDA

1. **Schematic Creation:** Place ATmega328P, HC-05 header, LM7805 regulator, capacitors, and L293D headers. Connect netlabels according to pin mapping guide.
2. **PCB Layout:** Define board outline and place high-current components (motors, regulator) near board edges.
3. **Bottom-Layer Track Routing:** Route tracks on bottom layer (Single-Sided Copper PCB). Maintain minimum track width of 30 mil for power/motor signals and 15 mil for signal lines.
4. **3D Modeling:** Verify physical component clearances and pin alignment using EasyEDA 3D view.
5. **PDF Layer Export:** Export Bottom Layer copper artwork as a mirrored black-and-white PDF for toner transfer printing.

---

## 5. PCB Fabrication & Etching Process

1. **Glossy Toner Transfer:** Print PCB layout onto glossy paper using a laser printer. Iron the printed paper onto a cleaned copper-clad sheet for ~5-10 minutes.
2. **Ferric Chloride (FeCl3) Etching:** Submerge the copper plate into a Ferric Chloride (FeCl3) solution for 30 minutes, agitating gently until exposed copper dissolves.
3. **Cleaning:** Wash the etched board with water and remove toner from tracks using thinner or acetone.
4. **PCB Drilling:** Drill component holes using a 0.8mm - 1.0mm carbide drill bit.

---

## 6. Soldering Guidelines

- **Soldering Temperature:** Set soldering iron to approximately 600°F (315°C).
- **Flux Application:** Apply rosin-core liquid flux to pads prior to soldering to prevent oxidation and ensure clean joints.
- **Component Placement:** Place low-profile passive components first, followed by IC sockets, headers, and larger components. Trim lead tails cleanly after soldering.
