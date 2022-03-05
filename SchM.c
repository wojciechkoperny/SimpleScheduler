/*******************************************************************************************************
 *                                           ${CompanyName}
 *                                         ${Company Address}
 *
 *                                (c) Copyright ${year}, ${CompanyName}
 *                                         All rights reserved
 *
 *****************************************************************************************************//**
 * \addtogroup SchM
 * @{
 * @file    SchM.c
 * @brief   Scheduler main file
 * @author  Wojciech Koperny
 * @}
 *********************************************************************************************************

 * @page misra_violations MISRA-C:2012 violations
 *
 * @section SCHM_C SchM.c
 *
 * \addtogroup SchM
 * @{
 ********************************************************************************************************/

#ifndef SCHM_C
#define SCHM_C


#include "SchM.h"
#include "SchM_cfg.h"

#define SCHM_TASK_TYPE_NO 7U

static volatile VAR(boolean, SCHM_CODE) SchM_Trigger = 0U;
static VAR(SchM_InitTable_t, SCHM_CODE) SchM_InitTab =
{
    .ptrsFun = SchM_TaskListInitFunctions, .NumOfTasks = sizeof(SchM_TaskListInitFunctions) / sizeof(SchM_TaskListInitFunctions[0])
};
static VAR(SchM_ScheduleTable_t, SCHM_CODE) SchM_SchTab[SCHM_TASK_TYPE_NO] =
{
    { .ptrsFun = SchM_TaskListFunctions1ms, .NumOfTasks = sizeof(SchM_TaskListFunctions1ms) / sizeof(SchM_TaskListFunctions1ms[0]), .ExecuteTime = 1, .TimeTillExecute = 0},
    { .ptrsFun = SchM_TaskListFunctions2ms, .NumOfTasks = sizeof(SchM_TaskListFunctions2ms) / sizeof(SchM_TaskListFunctions2ms[0]), .ExecuteTime = 2, .TimeTillExecute = 1 },
    { .ptrsFun = SchM_TaskListFunctions4ms, .NumOfTasks = sizeof(SchM_TaskListFunctions4ms) / sizeof(SchM_TaskListFunctions4ms[0]), .ExecuteTime = 4, .TimeTillExecute = 2 },
    { .ptrsFun = SchM_TaskListFunctions5ms, .NumOfTasks = sizeof(SchM_TaskListFunctions4ms) / sizeof(SchM_TaskListFunctions5ms[0]), .ExecuteTime = 5, .TimeTillExecute = 2 },
    { .ptrsFun = SchM_TaskListFunctions10ms, .NumOfTasks = sizeof(SchM_TaskListFunctions10ms) / sizeof(SchM_TaskListFunctions10ms[0]), .ExecuteTime = 10, .TimeTillExecute = 1 },
    { .ptrsFun = SchM_TaskListFunctions100ms, .NumOfTasks = sizeof(SchM_TaskListFunctions100ms) / sizeof(SchM_TaskListFunctions100ms[0]), .ExecuteTime = 100, .TimeTillExecute = 3 },
    { .ptrsFun = SchM_TaskListFunctions512ms, .NumOfTasks = sizeof(SchM_TaskListFunctions512ms) / sizeof(SchM_TaskListFunctions512ms[0]), .ExecuteTime = 512, .TimeTillExecute = 3 }
};

/**************************************************************************************************************//**
 * @fn             void SchM_Init(void)
 * @brief          FunctionTest just for example.
 *******************************************************************************************************************
 * @return         void.
 *******************************************************************************************************************
 * @pre            none
 * @details        perform init of listed funcitons
 */
FUNC(void, SCHM_CODE) SchM_Init()
{
    uint8_t i = 0;

    for (i = 0; i < SchM_InitTab.NumOfTasks; i++)
    {
        (SchM_InitTab.ptrsFun[i].task)();
    }
}

/**************************************************************************************************************//**
 * @fn             void SchM_Main(void)
 * @brief          perform scheduling
 *******************************************************************************************************************
 * @return         void.
 *******************************************************************************************************************
 * @pre            none
 * @details        perform scheduling
 */
FUNC(void, SCHM_CODE) SchM_Main()
{
    uint8_t i = 0;
    uint8_t j = 0;

    while (TRUE) //intended endless loop
    {
        if (TRUE == SchM_Trigger)
        {
            for (i = 0; i < SCHM_TASK_TYPE_NO; i++)
            {
                if (SchM_SchTab[i].TimeTillExecute == 0)
                {
                    for (j = 0; j < SchM_SchTab[i].NumOfTasks; j++)
                    {
                        (SchM_SchTab[i].ptrsFun[j].task)();
                    }
                }
                SchM_SchTab[i].TimeTillExecute = (SchM_SchTab[i].TimeTillExecute + SchM_SchTab[i].ExecuteTime - 1) % SchM_SchTab[i].ExecuteTime;
            }
            SchM_Trigger = FALSE;
        }
    }
}

/**************************************************************************************************************//**
 * @fn             void SchM_Tick(void)
 * @brief          Function tick trigger
 *******************************************************************************************************************
 * @return         void
 *******************************************************************************************************************
 * @pre            none
 * @details        Set milisecond tick
 */
FUNC(void, SCHM_CODE) SchM_Tick()
{
    SchM_Trigger = TRUE;
}

#endif /* SCHM_C */
