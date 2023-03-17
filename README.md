# Program Description
This program demonstrates how to configure interrupts in an Atmel AVR microcontroller using the INT0 external interrupt. The program toggles an LED on every switch button press, triggered by a rising edge on the input signal.

# Requirements
This code requires the following hardware components:

* Atmel AVR microcontroller
* LED (connected to PB5)
* Switch button (connected to PD2)
# Installation
To use this program, simply copy and paste the code into your AVR development environment and upload it to your microcontroller.

# Usage
When the program is running, pressing the switch button will cause an interrupt to be triggered, which will toggle the LED on and off.

# Program Flow
1. Disable global interrupts.
2. Configure PD2 as an input and PB5 as an output.
3. Configure the interrupt trigger condition to be a rising edge on INT0.
4. Enable INT0.
5. Enable global interrupts.
6. In the ISR (Interrupt Service Routine), toggle the LED on every switch button press.
7. The main loop remains empty as the ISR handles the LED state change.
# Predefined Directives
The program uses the following predefined directives:

* ISC00 and ISC01: Interrupt Sense Control bits for INT0, used to configure the trigger condition of the external interrupt.
* DDD2: Data Direction bit for PD2, used to set the input/output mode of PD2.
* DDB5: Data Direction bit for PB5, used to set the input/output mode of PB5.
* PORTB5: Port B bit 5, used to set the state of PB5.
* INT0: External Interrupt 0, used to trigger an interrupt on the rising edge of the input signal.
# License
This code is released under the MIT License.
