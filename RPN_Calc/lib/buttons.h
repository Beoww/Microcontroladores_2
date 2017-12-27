#ifndef BUTTONS_H
#define BUTTONS_H

// Includes
#include "calculator_functions.h"

namespace
{
	static int			num = 0;
	static bool			has_num = false;
}

void bnum(char digit);

run  badd(void);
run  bsub(void);
run  bdiv(void);
run  bmul(void);
run  beq(void);

void bpm(void);

bool is_num_initialized(void);

int  ret_num(void);

#endif // BUTTONS_H
