#ifndef _MONTY_H
#define _MONTY_H
#define STACK_ 1
#define QUEUE_ 0
#define BUF_SIZE 265
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>/*POSIX API*/
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - global structure to use in the functions
 * @working_ident:  stack or queue
 * @cc: current line var
 * @holder: second parameter inside the current line
 * @head: doubly linked list
 * @monty_f: file descriptor for monty file
 * @buf: input text buffer
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_var
{
	int working_ident;
	unsigned int cc;
	char *holder;
	stack_t *head;
	FILE *monty_f;
	char *buf;
} global_var_t;
extern global_var_t gl;
/* opcode function */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **doubly, unsigned int cline);
void pop(stack_t **doubly, unsigned int cline);
void swap(stack_t **doubly, unsigned int cline);
void queue(stack_t **doubly, unsigned int cline);
void stack(stack_t **doubly, unsigned int cline);
void add(stack_t **doubly, unsigned int cline);
void nop(stack_t **doubly, unsigned int cline); 
/* workin on it
 void sub(stack_t **doubly, unsigned int cline);
 void div_stack(stack_t **doubly, unsigned int cline);
 void mul(stack_t **doubly, unsigned int cline);
 void mod(stack_t **doubly, unsigned int cline);
 void pchar(stack_t **doubly, unsigned int cline);
 void pstr(stack_t **doubly, unsigned int cline);
 void rotl(stack_t **doubly, unsigned int cline);
 void rotr(stack_t **doubly, unsigned int cline);
 */
/* opcode function */

/*  use define function */
void (*getopcodes(char *opccode))(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);
int monty_check_arg(int argc);
void free_all_gl_var(void);
void init_gl(FILE *fd);
void conver(char *);
void clean_spac(char *str);
/*  use define function */
#endif
