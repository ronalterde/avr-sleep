#include <avr/io.h>

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

int main(void) {
	while(1) {
		setSleepModePowerDown();
		enterSleepMode();

		// [things to do after wake-up]

		disableSleepMode();
	}

	return 0;
}
