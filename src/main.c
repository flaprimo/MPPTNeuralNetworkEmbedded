/*
 * See results with: "minicom -D /dev/ttyACM0 [-c on]" on a linux terminal
 */
#include "lib/stellarisware/inc/hw_memmap.h"
#include "lib/stellarisware/inc/hw_types.h"
#include "lib/stellarisware/inc/hw_uart.h"
#include "lib/stellarisware/inc/hw_sysctl.h"
#include "lib/stellarisware/inc/hw_gpio.h"

#include "lib/stellarisware/driverlib/sysctl.h"
#include "lib/stellarisware/driverlib/gpio.h"
#include "lib/stellarisware/driverlib/ssi.h"
#include "lib/stellarisware/driverlib/rom.h"
#include "lib/stellarisware/driverlib/uart.h"

#include "lib/uart_debug.h"
#include "lib/neuralnet.h"
#include "lib/helper.h"


int main(void) {

	/* Set the clock frequency of the processor */
	SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

	InitUARTDebug();

	while (1) {
		float input[] = {976.8660, 392.1671, 342.6210};

		// compute NN
		float output = computeNN(input);

		// print results
		/*char risultato[32];
		PrintString(floatToString(risultato, output));
		PrintString(" ");*/

		// blink led :D
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xFF);
		SysCtlDelay(SysCtlClockGet() / 10);
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x00);
		SysCtlDelay(SysCtlClockGet() / 10);
	}
}
