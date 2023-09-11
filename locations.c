#include "monty.h"
/**
 * swap - swap locations of previous stack with the top stack
 * @h: node to be swapped
 * @line_number: node number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	if (tmp->next != NULL)
	{
		(*stack)->next = tmp->next;
		(*stack)->next->prev = *h;

	}
	else
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}
	tmp->prev = NULL;
	tmp->next = *h;
	(*stack) = tmp;
}
/**
 * rotl - rotate so top of stack becomes last one, second becomes first one
 * @h: node to be rotated
 * @line_number: node number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if ((*stack)->next != NULL)
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*stack)->prev = tmp;
		tmp->next = *h;
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		tmp->next->next = NULL;
	}
}
/**
 * rotr - rotate so only bottom node of stack becomes first one
 * @h: node to be rotated
 * @line_number: node number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if ((*stack)->next != NULL)
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*stack)->prev = tmp;
		tmp->next = *h;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*stack) = (*stack)->prev;
	}
}
