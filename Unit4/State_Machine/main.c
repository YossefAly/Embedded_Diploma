
#include "CA.h"
#include "DC.h"
#include "US.h"



void setup(void)
{
	// init all the drivers
	US_init();
	DC_init();

	// init IRQ ....
	// init HAL US_Driver DC_Driver
	// init BLOCK
	// Set States pointers for each block
	CA_state = ST_STATE(CA_waiting);

	US_state = ST_STATE(US_busy);
	DC_state = ST_STATE(DC_idle);
}

int main(void)
{
	volatile int i;
	setup();

	while(1)
	{
		// Call state for each block
		US_state();
		CA_state();
		DC_state();

		// Delay
		for(i = 0 ; i <= 50000 ; i++);
	}
	return 0;
}