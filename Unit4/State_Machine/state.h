#ifndef _STATE_H_
#define _STATE_H_

#include "stdio.h"
#include "stdlib.h"


// Automatic STATE Function generated
#define ST_STATE_define(_statFUN_) void ST_##_statFUN_()
#define ST_STATE(_statFUN_) ST_##_statFUN_

//States Connections
void US_Set_distance(int distance);
void DC_Set_speed(int speed);



#endif /* STATE_H_ */