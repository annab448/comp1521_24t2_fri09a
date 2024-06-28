#include <stdint.h>
#include <stdio.h>

#define N_PRINTER_BITS	8

// Whether the printer is out of ink
#define NO_INK (0x1)       // 0b 0000 0001
// Whether to print/scan in colour
#define COLOUR (0x2)       // 0b 0000 0010
// Select print mode
#define SELECT_PRINT (0x4) // 0b 0000 0100
// Select scan mode
#define SELECT_SCAN (0x8)  // 0b 0000 1000
// Start print/scan
#define START (0x10)       // 0b 0001 0000


uint8_t printerControl = 0; // 0b 0000 0000

void checkInk(void);               // Question A
void replaceInk(void);             // Question B
void useColourAndSelectScan(void); // Question C
void toggleMode(void);             // Question D
void start(void);                  // Question E

void showPrinter(void); 	   // show printer bits in hex and decimal

int main(void) {
	// printer is printing in colour and has ink
	printerControl = printerControl | SELECT_PRINT | COLOUR;
	// printer has run out of ink :(
	printerControl |= NO_INK;
	showPrinter();
	checkInk();
	replaceInk();
	checkInk();
	useColourAndSelectScan();
	showPrinter();
	toggleMode();
	showPrinter();
	toggleMode();
	showPrinter();
}

// a. that prints (to terminal) whether the printer is out of ink.
void checkInk(void) {
	if (printerControl & NO_INK) {
		printf("no ink :((((\n");
	} else {
		printf("we have ink.\n");
	}
	return;
}

// a. that tells the printer the ink has been replaced.
void replaceInk(void) {
	printf("ink has been replaced\n");
	printerControl = printerControl & (~NO_INK);
	return;
}
// c. to use colour and select scan mode. Assume no mode has been selected yet.
void useColourAndSelectScan(void) {
	printf("colour scan\n");
	// make sure that print mode is off
	printerControl &= ~SELECT_PRINT;

	// select scan and colour
	printerControl |= SELECT_SCAN | COLOUR;

	return;
}

// d. that toggles between print and scan mode. Assume 1 mode is already selected.
void toggleMode(void) {
	printf("toggle between scan and print\n");

	printerControl ^= (SELECT_PRINT | SELECT_SCAN);

	return;
}

/* e. (Extension question)
	i. check that one (and only one) mode is selected
	ii. check there's ink if printing.
	iii. print (to terminal) what it's doing and any error messages.
	iv. wait until the printing/scanning is finished and print a 'finished' message. Since there isn't an actual printer on the other side, a correct implementation of this will infinite loop and never print 'finished'.
*/
void start(void) {

	return;
}

void showPrinter(void) {
	printf("printer = 0x%02x = ", printerControl);
	for (int i = 0; i < N_PRINTER_BITS; i++) {
		printf("%d", (printerControl >> (N_PRINTER_BITS - 1 - i)) & 1);
	}
	printf("\n");
}
