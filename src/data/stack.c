#include <hlib/data/stack.h>
#include <hlib/data/types.h>
#include <stdlib.h>

struct stack{
     Int64 max, cnt;
     Void **data;
};

struct stack *alloc_Stack(const Int64 max)
{
     struct stack *stack = malloc(sizeof(struct stack));
     stack->data = malloc(sizeof(Void*));
     stack->cnt = 0;
     stack->max = max;
     return stack;
}

Void free_stack(struct stack **stack)
{
     if(*stack)
          free((*stack)->data);
     free(*stack);
     *stack = NULL;
}

Int8 peak_stack(const struct stack *stack, Void** data)
{
     if(!stack) return 1;
     if(stack->cnt>=stack->max) return 2;
     if(!data) return 3;

     *data = stack->data[stack->cnt];
     return 0;
}

Int8 pop_stack(struct stack *stack, Void **data)
{
     if(!stack) return 1;
     if(stack->cnt>=stack->max) return 2;
     if(!data) return 3;

     *data = stack->data[(stack->cnt)--];
     return 0;
}

Int8 push_stack(struct stack *stack, const Void *data)
{
     if(!stack) return 1;
     if(stack->cnt>=stack->max) return 2;
     if(!data) return 3;

     stack->data[(stack->cnt)++] = (Void *)data;
     return 0;
}

Int8 print_stack(File *stream, struct stack *stack, const Char *format)
{
     if(!stack) return  1;
     for(Int64 i=0; i<stack->cnt; i++)
          if(fprintf(stream, format, *stack->data[i])<0) return 4;
     return 0;
}

Int64 stack_get_cnt(const struct stack *stack)
{
     if(stack)
          return stack->cnt;
     return 0;
}

Int64 stack_get_max(const struct stack *stack)
{
     if(stack)
          return stack->max;
     return 0;
}
