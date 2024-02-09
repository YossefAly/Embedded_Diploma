#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/***************************************INCLUDES**************************************/

#include "EXTI_Private.h"

/***************************************CONFIG***************************************/




#define EXTI_TRIGGER_RISING						0
#define EXTI_TRIGGER_FALLING					1
#define EXTI_TRIGGER_RISINGANDFALLING			2


 /***************************************APIS***************************************/

 void EXTI_INIT(uint8_t CopyPort_ID,uint8_t CopyPin_ID,uint8_t CopyEXTI_Trigger_ID,void (*LPF)(void));
 void EXTI_UPDATE(uint8_t CopyPort_ID,uint8_t CopyPin_ID,uint8_t CopyEXTI_Trigger_ID,void (*LPF)(void));
 void EXTI_DEINIT(void);

#endif
