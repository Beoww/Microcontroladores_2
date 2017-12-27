#include "buttons.h"

void bnum(char digit)
{
	int neg = (num < 0) ? -1 : 1;
	num *= neg;
	num *= 10;
	num += digit;
	num *= neg;
	has_num = true;
}

run badd(void)
{
	return add();
}
run bsub(void)
{
	return sub();
}
run bdiv(void)
{
	return div();
}
run bmul(void)
{
	return mul();
}

run beq(void)
{
	run status;
	status = push(num);
	num = 0;
	has_num = false;
	return status;
}
void bpm(void)
{
	num *= -1;
}

bool is_num_initialized(void)
{
	return has_num;
}

int  ret_num(void)
{
	return num;
}
