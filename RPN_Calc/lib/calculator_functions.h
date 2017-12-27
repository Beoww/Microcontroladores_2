#ifndef CALCULATOR_FUNCTIONS_H
#define CALCULATOR_FUNCTIONS_H

// Defines
#define STACK_SIZE 256

// Enums
enum run
{
	RUN_OKAY,
	RUN_DOMAIN_ERROR,
	RUN_INSUFFICIENT_STACK,
	RUN_STACK_OVERFLOW,
};

run 	add(void);
run 	sub(void);
run 	div(void);
run 	mul(void);
run	push(int num);

bool	is_stack_empty(void);

int	peek(void);

#endif // CALCULATOR_FUNCTIONS_H
