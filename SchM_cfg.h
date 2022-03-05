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
 * @file    SchM_cfg.h
 * @brief   Config header of SchM
 * @author  Wojciech Koperny
 * @}
 *********************************************************************************************************

 * @page misra_violations MISRA-C:2012 violations
 *
 * @section SCHM_CFG_H SchM_cfg.h
 *
 * \addtogroup SchM
 * @{
 ********************************************************************************************************/

#ifndef SCHM_CFG_H
#define SCHM_CFG_H

#include "SchM.h"

void TaskDummy(void)
{
}

const VAR(SchM_TasksList_t, SCHM_CODE)  SchM_TaskListInitFunctions[] =
{
    { TaskDummy },
};

const VAR(SchM_TasksList_t, SCHM_CODE)  SchM_TaskListFunctions1ms[] =
{
    { TaskDummy },
};

const VAR(SchM_TasksList_t, SCHM_CODE)  SchM_TaskListFunctions2ms[] =
{
    { taskFunction2ms },
};

const VAR(SchM_TasksList_t, SCHM_CODE)   SchM_TaskListFunctions4ms[] =
{
    { taskFunction4ms },
};

const VAR(SchM_TasksList_t, SCHM_CODE)  SchM_TaskListFunctions5ms[] =
{
    { taskFunction5ms },
};
const VAR(SchM_TasksList_t, SCHM_CODE)   SchM_TaskListFunctions10ms[] =
{
    { taskFunction10ms },
};
const VAR(SchM_TasksList_t, SCHM_CODE)   SchM_TaskListFunctions100ms[] =
{
    { TaskDummy },
};
const VAR(SchM_TasksList_t, SCHM_CODE)   SchM_TaskListFunctions512ms[] =
{
    { TaskDummy },
};
#endif /* SCHM_CFG_H */
/** @} */
