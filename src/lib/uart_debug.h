#ifndef UART_DEBUG_H_
#define UART_DEBUG_H_

#define TO_HEX_CHAR(y,x)		{ 	if(x > 9)\
										y = 'A' + x - 9;\
									else\
										y = '0' + x;\
								}

void InitUARTDebug(void);
void PrintRegValue(const char *string_val, unsigned long reg_value);
void PrintString(const char *string_val);

#endif /* UART_DEBUG_H_ */
