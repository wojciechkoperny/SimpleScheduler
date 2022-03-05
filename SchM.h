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
 * @file    SchM.h
 * @brief   Header for SchM
 * @author  Wojciech Koperny
 * @}
 *********************************************************************************************************

 * @page misra_violations MISRA-C:2012 violations
 *
 * @section SCHM_H SchM.h
 *
 * \addtogroup SchM
 * @{
 ********************************************************************************************************/

#ifndef SCHM_H
#define SCHM_H


#include "main.h"

typedef struct {
    void  (*task)(void);
} SchM_TasksList_t;

typedef struct {
    const SchM_TasksList_t *const ptrsFun;
    const uint16_t NumOfTasks;
    const uint16_t ExecuteTime;
    uint16_t TimeTillExecute;
} SchM_ScheduleTable_t;

typedef struct {
    const SchM_TasksList_t *const ptrsFun;
    const uint8_t NumOfTasks;
} SchM_InitTable_t;

FUNC(void, SCHM_CODE) SchM_Main(void);
FUNC(void, SCHM_CODE) SchM_Tick(void);
FUNC(void, SCHM_CODE) SchM_Init(void);

/** MotorCtrl velocity setup for Control Loop */ 
FUNC(void, SCHM_CODE) SchM_Caller_MotorCtrlDrv_SetVelocity(void);

#endif /* SCHM_H */
