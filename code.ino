// The following program demonstrates how interrupts are configured.
// The program toggles the LED on every switch button press.

// NOTE:
// Use the predifned directives (ISC00, ISC01, DDD2, PORTB5, INT0, etc)


void setup() {
  cli(); // Disable global interrupts
  
  // Set PD2 as input / 0
  DDRD &= ~(1 << DDD2);
  
  // Set PB5 as output / 1
  DDRB |= (1 << DDB5);
	
  // The button is configured with a PULL-DOWN resistor
  //PORTD &= ~(1 << PORTD2);
  
  // Configure the interrupt trigger condition (rising edge)

  EICRA  |= (1 << ISC01);
  EICRA  |= (1 << ISC00);

  // Enable INT0
  EIMSK |= (1 << INT0);

  sei(); // Enable global interrupts
}


// The ISR will toggle the built-in LED (pin 13)
volatile bool ledState = false;

ISR(INT0_vect) {
  ledState = !ledState;
  if (ledState) {
    PORTB |= (1 << PORTB5); // Set PB5 (pin 13) HIGH
  } else {
    PORTB &= ~(1 << PORTB5); // Set PB5 (pin 13) LOW
  }
}



void loop() {
  // The main loop will remain empty, as the ISR will handle the LED state change
}
