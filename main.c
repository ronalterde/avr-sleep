#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#include <util/delay.h>

ISR(INT2_vect) {
}

static void configurePortPins() {
	DDRB |= (1<<PB6); // Output LED
	DDRB &= ~(1<<PB2); // INT2 input
	PORTB |= (1<<PB2); // pull-up for INT2
}

static void configureInterrupts() {
	// Enable interrupt on falling edge of INT2
	MCUCSR &= ~(1<<ISC2);
	GICR |= (1<<INT2);
	
	// Enable interrupts globally
	sei();
}

static void setSleepModePowerDown() {
	MCUCR &= ~(1<<SM2);
	MCUCR |= (1<<SM1);
	MCUCR &= ~(1<<SM0);
}

static void enterSleepMode() {
	MCUCR |= (1<<SE);
	asm volatile("sleep");
}

static void disableSleepMode() {
	MCUCR &= ~(1<<SE);
}

static void toggleLED() {
	PORTB |= (1<<PB6);
	_delay_ms(2000);
	PORTB &= ~(1<<PB6);
}

int main(void) {
	configurePortPins();
	configureInterrupts();

	while(1) {
		setSleepModePowerDown();
		enterSleepMode();
		disableSleepMode();
		toggleLED();
	}

	return 0;
}
