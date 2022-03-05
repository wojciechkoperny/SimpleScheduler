# SimpleScheduler
Simple time based scheduler 

Files started as SchM are necessary to run a scheduler.
Main logic is located in SchM.c, SchM.h is providing datatypes, SchM_cfg.h is for confuguration of scheduling.

TEST RUNNUNG ON LINUX OR WSL OR VIRTUAL MACHINE

For testing i used unix pthread and all logic to run those are located inside main.c file
to run test run commands 

> mkdir build


> cd build

 
> cmake ..

> make
 
> ./test_proj1

ctrl+c to quit running test

Additional data:

This SimpleScheduler project was created to have simple support of time base scheduling in embdedded MCU. SchM_Tick shall normally be triggered in periodic time interrupt interval every 1ms like PIT(periodic interupt trigger)

This SimpleScheduler also supports SchM_Init functions that provides init functionality and shall be called before SchM_Main


