#include "calculator_functions.h"

namespace
{
	static int	stack[STACK_SIZE] = {0};
	static int	stack_top = 0;
	static bool	empty_stack = true;
}

run add(void)
{
	if(stack_top != 0)
	{
		stack[stack_top - 1] += stack[stack_top];
		stack_top--;
		return RUN_OKAY;
	}
	else
	{
		return RUN_INSUFFICIENT_STACK; // INSUFICCIENT STACK ERROR
	}
}

run sub(void)
{
	if(stack_top != 0)
	{
		stack[stack_top - 1] -= stack[stack_top];
		stack_top--;
		return RUN_OKAY;
	}
	else
	{
		return RUN_INSUFFICIENT_STACK; // INSUFICCIENT STACK ERROR
	}
}

run div(void)
{
	if(stack[stack_top] == 0)
	{
		return RUN_DOMAIN_ERROR; // DIVISION BY ZERO ERROR
		for(int i = 0; i < stack_top; i++)
		{
			stack[i] = 0;
		}
		stack_top = 0;
		empty_stack = true;
	}
	else if(stack_top != 0)
	{
		stack[stack_top - 1] /= stack[stack_top];
		stack_top--;
		return RUN_OKAY;
	}
	else
	{
		return RUN_INSUFFICIENT_STACK; // INSUFICCIENT STACK ERROR
	}
}

run mul(void)
{
	if(stack != 0)
	{
		stack[stack_top - 1] *= stack[stack_top];
		stack_top--;
		return RUN_OKAY;
	}
	else
	{
		return RUN_INSUFFICIENT_STACK; // INSUFICCIENT STACK ERROR
	}
}

run push(int num)
{
	if(stack_top == STACK_SIZE-1)
	{
		return RUN_STACK_OVERFLOW; // STACK OVERFLOW ERROR
		for(int i = 0; i < stack_top; i++)
		{
			stack[i] = 0;
		}
		stack_top = 0;
		empty_stack = true;
	}
	else
	{
		stack_top += (empty_stack) ? 0 : 1 ;
		stack[stack_top] = num;
		empty_stack = false;
		return RUN_OKAY;
	}
}

bool is_stack_empty(void)
{
	return empty_stack;
}

int peek(void)
{
	if(empty_stack)
	{
		return 0; // EMPTY STACK ERROR
	}
	else
	{
		return stack[stack_top];
	}
}
