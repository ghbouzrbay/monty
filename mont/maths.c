#include "monty.h"

#include "monty.h"

/**
 * f_sub - sub top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp = *stack;
  int sub = 0, i = 0;

  if (tmp == NULL)
    {
      fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  while (tmp)
    {
      tmp = tmp->next;
      i++;
    }

  if (stack == NULL || (*stack)->next == NULL || i <= 1)
    {
      fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  sub = (*stack)->next->n - (*stack)->n;
  m_pop(stack, line_number);

  (*stack)->n = sub;
}

/**
 * f_mul - mul top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
  int aux;

  if (*stack == NULL || (*stack)->next == NULL)
    {
      fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
      free(var_global.buffer);
      fclose(var_global.file);
      free_dlistint(*stack);
      exit(EXIT_FAILURE);
    }
  else
    {
      aux = (*stack)->n;
      m_pop(stack, line_number);
      (*stack)->n *= aux;
    }
}

/**
 * f_div - div top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void f_div(stack_t **stack, unsigned int line_number)
{
  int div = 0;

  if (*stack == NULL || (*stack)->next == NULL)
    {
      fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
      free(var_global.buffer);
      fclose(var_global.file);
      free_dlistint(*stack);
      exit(EXIT_FAILURE);
    }
  else if ((*stack)->n == 0)
    {
      fprintf(stderr, "L%d: division by zero\n", line_number);
      free(var_global.buffer);
      fclose(var_global.file);
      free_dlistint(*stack);
      exit(EXIT_FAILURE);
    }
  else
    {
      div = (*stack)->n;
      m_pop(stack, line_number);
      (*stack)->n /= div;
    }
}

/**
 * f_mod - mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
  int mod = 0;

  if (*stack == NULL || (*stack)->next == NULL)
    {
      fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
      free(var_global.buffer);
      fclose(var_global.file);
      free_dlistint(*stack);
      exit(EXIT_FAILURE);
    }
  else if ((*stack)->n == 0)
    {
      fprintf(stderr, "L%d: division by zero\n", line_number);
      free(var_global.buffer);
      fclose(var_global.file);
      free_dlistint(*stack);
      exit(EXIT_FAILURE);
    }
  else
    {
      mod = (*stack)->n;
      m_pop(stack, line_number);
      (*stack)->n %= mod;
    }
}