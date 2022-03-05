#include <stdint.h>

typedef uint8_t boolean;

void taskFunction2ms(void);
void taskFunction4ms(void);
void taskFunction5ms(void);
void taskFunction10ms(void);

#define TRUE 1U
#define FALSE 0U
#define  SCHM_CODE
#define VAR(vartype, memclass) vartype
#define FUNC(rettype, memclass) rettype