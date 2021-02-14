# Drone V1
### Get done by February 17, 2021

The goal is to transfer Drone V1 onto a PCB format.

Here are the main issues of the first Drone V1:
- Control of the drone by mobile phone (MIT App Inventor) causing interrupting BLE signals
- Orientation sensor was at an angle because of unorganized cabling and through-hole tech
- Ultrasound sensor for precise height measurement was missing
- Working with a proprietary ESC without a traditional flight controller (missing back EMF)
- Li-Po battery is less endurant than Li-Ion Battery
- Lack of a deep understanding of PID Controllers

Drone V1 is composed of 3 computing parts that interface with the motors:
- Arduino Nano 33 BLE Sense
- 35A ESC
- Buck Converter

Here are the improvements to make in the PCB version of Drone V1:
- Adding an RF sensor
- Getting a non-proprietary Remote Controller
- All Surface Mount tech
- Programmable ESC with retrievable back EMF
- Li-Ion Battery
- Adjust PID values
