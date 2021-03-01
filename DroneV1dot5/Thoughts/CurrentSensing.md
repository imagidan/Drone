# Current Sensing

Current sensing allows one to calculate the power being used by a certain device to know how much it is contributing to the electricity bill or it can let one know how much time their device's battery will last. They can be used in the drone and the drone's charger just to name a few of the device I will be creating with these sensors.

So current sensing can be done in 2 ways: using a resistor and measuring with ohm's law or using hall effect sensors. 

With a resistor, a small resistance resistor is used called a shunt resistor. This type of resistor allows a large range of current (achieved by a low resistance that can handle the heat) and the error of the marked resistance is minimal to reduce errors of how much amps is going through a certain circuit. This way of sensing current can only detect current flowing one way since the microcontroller will not detect negative voltages which signify the current. I am still not too sure on this, so I will ask one of my teachers which explains these things well. Another thing that is good about these shunt resistors is they allow pretty accurate values. If the shunt resistor you need has too small of a voltage drop since you want to allow for pretty high currents or you don't want the voltage to drop too much, you can always use a current sense amplifier.

To explain why current sense amplifiers are best for this use case, I will go into why other amplifiers suck for this case. First some general current sensing knowledge: input common-mode voltage (Vcm) is the average of both voltages that go into the differential amplifier; low-side sensing refers to the current sensing circuit being next to ground while high-side is next to voltage. Due to some factors such as not knowing if the load is open-circuit inside, or any problems arising, we choose high-side circuits most of the time. 

There is 4 types of differential amplifiers: 
- Op amps: They are low cost, low accuracy devices, which need a Vcm lower than supply voltage (Vs). The problem is making op-amps accurate is expensive and not worth it because of the bad defaults already in place. Another problem is because they are mostly used for low-side sensing and that they only have one input voltage when considering ground as the default, PCB parasitics could have a negative effect in accuracy as well.
- Difference amps: They are better suited for low and high side application as they have 2 inputs from the circuit destroying possibility of parasitics having an effect. Problem is they dont allow for high enough Vcm just like the op amp, and the resistors used in the circuit are a bit too high.
- Instrumentation amps: They are the combination of difference amps with buffers on each inputs. They are good for measuring small currents, and yet again they remove parasitics as a problem. The gain is largely adjustable.
-Current Sensing Amps: the best amps for the application because it allows for Vcm to be higher than Vs. This is possible because of the input bias stage. The stable fixed gain allows for a very accurate output especially at higher currents (great for the drone).

The hall effect sensors work by sensing the magnetic field which is created by the current. Some of its benefits are that they sense current both ways, and that you dont even need any electrical attachment. The problem is it is kind of expensive and inaccurate. Without considering these problems, it would be reasonable to believe these are perfect for charging and discharging circuits, or for any type of circuit, honestly.

In the consideration for the drone, I should think about a low ohm shunt resistor that can handle the amps and an efficient current sensing amplifier with a gain that suits the range of the analog pins on my selected microcontroller.

It is quite surprising how tough of a problem current sensing seems to be compared to voltage sensing which I will cover in one of the next learnings.
