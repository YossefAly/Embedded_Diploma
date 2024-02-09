

#include "LCD.h"

void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}


void LCD_INIT(){
	
	delay_ms(20);
	
	GPIO_INIT(LCD_PORT,RW,OUTPUT_PUSHPULL);
	GPIO_INIT(LCD_PORT,RS,OUTPUT_PUSHPULL);
	GPIO_INIT(LCD_PORT,EN,OUTPUT_PUSHPULL);
	
	
	for(int i=0;i<8;i++){
		GPIO_INIT(LCD_PORT,i,OUTPUT_PUSHPULL);
	}
	


	GPIO_WRITE_PIN(LCD_PORT,RW,LOW);
	GPIO_WRITE_PIN(LCD_PORT,RS,LOW);
	GPIO_WRITE_PIN(LCD_PORT,EN,LOW);
	
	delay_ms(15);
	
	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}
void LCD_WRITE_COMMAND(unsigned char command){


		//LCD_check_lcd_isbusy();

		GPIO_WRITE_PORT(LCD_PORT,command);

		GPIO_WRITE_PIN(LCD_PORT,RW,LOW);
		GPIO_WRITE_PIN(LCD_PORT,RS,LOW);

		delay_ms(1);

		LCD_lcd_kick();
}
void LCD_WRITE_CHAR(unsigned char character){

	//LCD_check_lcd_isbusy();

	GPIO_WRITE_PORT(LCD_PORT,character);

	GPIO_WRITE_PIN(LCD_PORT,RW,LOW);
	GPIO_WRITE_PIN(LCD_PORT,RS,HIGH);

	delay_ms(1);

	LCD_lcd_kick();

}
void LCD_WRITE_STRING(char* string){

	//LCD_check_lcd_isbusy();

	int count = 0;
	while (*string > 0) {
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16) {
			LCD_GOTO_XY(2, 0);
		} else if (count == 32) {
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}

}
void LCD_check_lcd_isbusy(void){
	
	for(int i=0;i<8;i++){
		GPIO_INIT(LCD_PORT,i,INPUT_FLOATING);
	}
	GPIO_WRITE_PIN(LCD_PORT,RW,HIGH);
	GPIO_WRITE_PIN(LCD_PORT,RS,LOW);

	LCD_lcd_kick();

	GPIO_WRITE_PIN(LCD_PORT,RW,LOW);

	for(int i=0;i<2000;i++);

	LCD_lcd_kick();
}
void LCD_lcd_kick(void){

	GPIO_WRITE_PIN(LCD_PORT,EN,HIGH);

	delay_ms(50);

	GPIO_WRITE_PIN(LCD_PORT,EN,LOW);

}
void LCD_clear_screen(){LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);}
void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}
