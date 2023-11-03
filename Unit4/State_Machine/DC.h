#ifndef _DC_H_
#define _DC_H_

#include "state.h"

// Define Status
enum {
	DC_idle,
	DC_busy
}DC_Status;

// Declare Status Functions DC
ST_STATE_define(DC_idle);
ST_STATE_define(DC_busy);

void DC_init();

// STATE Pointer to Function
extern void (*DC_state)();


#endif /* DC_MOTOR_H_ */
