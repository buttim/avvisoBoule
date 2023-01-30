# avvisoBoule
Convert optical feedback to acoustical (LED light to buzzer)

Uses STC15W201 MCU

Connections:
---
- P33 momentary pushbutton
- P10 buzzer +
- P11 buzzer -
- P32 LED sensor +
- VCC LED sensor -
- P55 optional signaling LED +
- GND optional signalling LED -

Programming with USB/UART adapter
---
- VCC -> VCC
- GND -> GND
- P30 -> RX
- P31 -> TX