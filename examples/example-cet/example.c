#include <stdio.h>

int hello()
{
  printf("Return address corruption worked!\n");
  return 0;
}

// "Smash" the stack to execute hello instead of returning directly. This
// should not work with shadow stacks.
int foo();
asm ("foo: mov $hello, %rax; push %rax; ret");

int main()
{
  foo();
  return 0;
}
