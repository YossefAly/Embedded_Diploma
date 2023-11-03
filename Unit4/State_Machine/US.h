#ifndef _US_H_
#define _US_H_

#include "state.h"
#include "US.h"

// Define Status
enum {
	US_busy
}US_Status;

// Declare Status Functions US
ST_STATE_define(US_busy);

// STATE Pointer to Function
extern void (*US_state)();

void US_init();
int ultrasonic_get_distance_random(int start, int end, int count);


#endif /* _US_H_ */
