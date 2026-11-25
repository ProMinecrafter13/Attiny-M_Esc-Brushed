# Attiny-M_Esc-Brushed
Micro Brushed Esc based on the newer attiny 0 and 1 series for RC receivers.

Uses 8 pin attiny such as attiny202/212/402/412, N channel mosfet (like SL3416, si2300, si2302), diode (like SS24), resistors (10k ohm, 1k ohm), capacitors (100uf, 10uf, 100nf) and a LED.

The current capability of the ESC depends on the mosfet. I have used SL3416 n channel mosfet in the attached picture, which has a 6A current capability and a very low Rds on. Make sure to note that the mosfet is N channel, works at 3.3V (turns on) and has enough current capability for your motor/use case (about 20% headroom is considered safe generally)

Note: I have supplied the attiny directly from a 1s lipo. Since the attiny could tolerate upto 5.5V, this is not a problem. However for higher voltages, consider incorporating a voltage regulator such as SL7603P50PR-Slkor-5V  or SL7603P33PR-Slkor-3.3V voltage regulator. Else the attiny might get burnt out.
I have done the soldering by hand on perfboard and used a dip adapter, however direct soldering can also be done to save weight and space.

Overall, this tiny esc is perfectly suited for micro rc projects such as light rc planes and drones using coreless motors, offering flexibility for choosing current capability of your own choice.

Param
