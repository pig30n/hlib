#ifndef H_LIB_STACK_H
#include <hlib/data/types.h>

typedef struct stack Stack;

struct stack *alloc_Stack(const Int64 max);
Void free_stack(Stack **stack);
Int8 peak_stack(const Stack *stack, Void** data);
Int8 pop_stack(Stack *stack, Void **data);
Int8 push_stack(Stack *stack, const Void *data);
Int8 print_stack(File *stream, Stack *stack, const Char *format);
Int64 stack_get_cnt(const Stack *stack);
Int64 stack_get_max(const Stack *stack);

#define H_LIB_STACK_H
#endif /*H_LIB_STACK_H*/
