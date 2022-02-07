/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
   Write your code in this editor and press "Run" button to compile and execute it.

 *******************************************************************************/

#include <stdio.h>

//test

void taks2ms1(void)
{
    static int vtaks2ms1 = 0;

    vtaks2ms1++;
    printf("task 2ms 1\n");
}
void taks2ms2(void)
{
    static int vtaks2ms2 = 0;

    vtaks2ms2++;
    printf("task 2ms 2\n");
}

void taks4ms1(void)
{
    printf("task 4ms 1\n");
}

void taks4ms2(void)
{
    printf("task 4ms 2\n");
}

typedef struct {
    void  (*task)(void);  /*! pointer to runnable         */
} SchM_TasksFunctions;

static const SchM_TasksFunctions SchM_TaskFunctions2ms[] =
{
    { taks2ms1 },
    { taks2ms2 },
};

static const SchM_TasksFunctions SchM_TaskFunctions4ms[] =
{
    { taks4ms1 },
    { taks4ms2 },
};

typedef struct {
    const SchM_TasksFunctions const* ptrsFun;/*! pointer to runnables         */
    const int NumOfTasks;
    const int ExecuteTime;
    int TimeTillExecute;
} SchM_Task_t;

SchM_Task_t SchM_Task[2] =
{
    { .ptrsFun = SchM_TaskFunctions2ms, .NumOfTasks = sizeof(SchM_TaskFunctions2ms) / sizeof(SchM_TaskFunctions2ms[0]), .ExecuteTime = 20, .TimeTillExecute = 0 },
    { .ptrsFun = SchM_TaskFunctions4ms, .NumOfTasks = sizeof(SchM_TaskFunctions4ms) / sizeof(SchM_TaskFunctions4ms[0]), .ExecuteTime = 40, .TimeTillExecute = 10 }
};

int main()
{
    int liczbaObiegow = 0;
    int i = 0;
    int j = 0;
    int ucCounter = 20;

    printf("Hello World\n");

    //printf("ilosc taskow %d", task2ms.NumOfTasks);

    while (liczbaObiegow < 100)//niepotrzebna petla - docelowo nieskonczona powinna byc
    {
        for (i = 0; i < 2; i++)
        {
            SchM_Task[i].TimeTillExecute = (SchM_Task[i].TimeTillExecute + SchM_Task[i].ExecuteTime - 1) % SchM_Task[i].ExecuteTime;
            if (SchM_Task[i].TimeTillExecute == 0)
            {
                printf("JEST TASK %d\n", SchM_Task[i].ExecuteTime);
                for (j = 0; j < SchM_Task[i].NumOfTasks; j++)
                {
                    (SchM_Task[i].ptrsFun[j].task)();
                }
            }
        }
        //printf("time2ms %d\n", task2ms.TimeTillExecute);

        liczbaObiegow++;
    }

    return 0;
}
