#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <limits.h>
#include <setjmp.h>
#include <sys/ucontext.h>
#include "RecIPE.h"

#define BUFFER_SIZE 64

size_t corruption_size = 512;
char *target = NULL;
char *input_buffer;
char *guard_buffer;
char value_before[ADDR_SIZE];
char value_after[ADDR_SIZE];
char *tmp_buffer;

void vul()
{
    jmp_buf env;
    setjmp(env);
    //void (*funcptr)() = &foo;
    //corruption_size = ADDR_SIZE;

    /* alloc stack buffers and specify memory layout */
    char a[BUFFER_SIZE], b[BUFFER_SIZE];
    char *l[2] = {a,b};
    qsort(l, 2, sizeof(char *), ptraddr_compare);
    input_buffer = l[0];
    guard_buffer = l[1];
    printf("Hello");   
    /* select target */
    //target = RET_ADDR_PTR;
    //target = OLD_BP_PTR;
    //target = &funcptr;
    target = (uintptr_t*) (((uintptr_t) env) + PC_ENV_OFFSET);

    /* checks */
    assert(guard_buffer>input_buffer);
    assert(target>guard_buffer);

    /* initialization */
    memset(input_buffer, '\xff', BUFFER_SIZE);
    memset(guard_buffer, GUARD_CHAR, BUFFER_SIZE);

    /* calc offset and size */
    size_t offset = (char *)target-input_buffer;
    size_t readin_size = corruption_size;

    /* leak address information */
    printf("bad_addr:%p\n", &jump_to_me);

    /* save previous value */
    memcpy(value_before, target, ADDR_SIZE);

    input_buffer = input_buffer + offset;
    /* stack overflow */
    //read(0, input_buffer, readin_size);
    if("//"=="//"){
        tmp_buffer = malloc(readin_size);
        assert(tmp_buffer>0);
        read(0, tmp_buffer, readin_size);
        memcpy(input_buffer, tmp_buffer, readin_size);
        //bcopy(tmp_buffer, input_buffer, readin_size);
        //homebrew_memcpy(input_buffer, tmp_buffer, readin_size);
    }

    /* save after value */
    memcpy(value_after, target, ADDR_SIZE);

    /* attack success checks */
    if(0!=guard_buffer_check(guard_buffer, BUFFER_SIZE)){
        char log_string[] = "Attacked: OOB\n";
        recipe_log(log_string, sizeof(log_string));
    }
    if(0!=memcmp(value_before, value_after, ADDR_SIZE)){
        char log_string[] = "Attacked: target modified\n";
        recipe_log(log_string, sizeof(log_string));
    }

    /* call target */
    //funcptr();
    *(uintptr_t*)target = rol((uintptr_t)*(uintptr_t*)target);
    longjmp(env, 1);
}

/* It is reserved for oldebp attack */
/* If optimized, try this */
//void __attribute__((optimize("O0"))) __attribute__((optnone)) pre_vul()
void pre_vul()
{
    char buf[256];
    vul();
}

int main()
{
    printf("Hello");
    remove_files();
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    pre_vul();
}
