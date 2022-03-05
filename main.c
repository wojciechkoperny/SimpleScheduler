#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

#include "SchM.h"

#ifndef NULL_PTR
#define NULL_PTR     ((void *)0u)
#endif
#define DEFAULT_TIMER 1U
#define DBUDOWANIETESTOWE
static pthread_t thread_fun1, thread_fun2;
int Timer = DEFAULT_TIMER;

void SigintHandler(int a)
{
    printf("\033[0;31m\nBYE World : TERMINATION : %d\n ",a);
    (void)pthread_cancel(thread_fun1);
    (void)pthread_cancel(thread_fun2);
    pthread_exit(NULL);
}

void* fun1 (void *arg)
{
    static int ilosc=0;
    while(1)
    {
        printf ("\e[1;32mMILISECONDS PASSED: %d\e[0m\n", ilosc);
        SchM_Tick();
        ilosc++;     
       // (void)pthread_join(thread_fun2, NULL_PTR);
       // printf("thread 2 joined\n");
        usleep(10000);
    }
}
void* fun2 (void *arg)
{
    static int ilosc=0;
    printf ("\e[1;33mThis is TASK 2 call number: %d\e[0m\n", ilosc);
    SchM_Main();
  /*   while(1)
    {
        ilosc++;
        sleep(1);
    } */
}

void taskFunction2ms(void)
{
    printf ("\e[1;33mThis is TASK 2ms call number\e[0m\n");
}

void taskFunction4ms(void)
{
    printf ("\e[1;34mThis is TASK 4ms call number\e[0m\n");
}

void taskFunction5ms(void)
{
    printf ("\e[1;35mThis is TASK 5ms call number\e[0m\n");
}

void taskFunction10ms(void)
{
    printf ("\e[1;36mThis is TASK 10ms call number\e[0m\n");
}



int main(int argc, char *argv[])
{
     if (argc >1)
    {
        Timer = atoi(argv[1]);
    } 
    printf("Hello World\n");

    #ifdef TEST_BUILD
        printf("\033[0;31mTEST_BUILD SET!\n");
    #endif

    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = SigintHandler;

    (void)sigaction(SIGINT, &sa, NULL);
    printf("call init function\n");
     SchM_Init();
    sleep(2);

    (void)pthread_create(&thread_fun1, NULL, &fun1, NULL);
    usleep(1000);
    (void)pthread_create(&thread_fun2, NULL_PTR, &fun2, NULL_PTR);

    printf("threads create\n");

    (void)pthread_join(thread_fun1, NULL_PTR);
    printf("thread 1 joined\n");
    (void)pthread_join(thread_fun2, NULL_PTR);
    printf("thread 2 joined\n");  

    return 0;
}
