#include "hlib/incl/data/types.h"
#include "hlib/incl/data/stack.h"
#include "hlib/incl/util/new.h"

int main(int argc, char *argv[])
{
     Stack stack = new(Stack(1024));
     Int8 a = 3, b = 4;
     Int8 *c = NULL, *d = NULL;
     push_stack(stack, &a);
     push_stack(stack, &b);
     pop_stack(stack, &c);
     pop_stack(stack, &d);
     printf("Value of c = %d\n", *c);
     printf("Value of d = %d\n", *d);

     return 0;
}
