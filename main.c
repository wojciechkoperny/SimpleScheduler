#include <stdio.h>
#include "header.h"

int GlobalVarA = 11;

int main() {
    GlobalVarA++;
    StaticVarA++;
   printf("Hello, World \n GlobalVar: %d\n StaticVar %d!\n\n", GlobalVarA,StaticVarA);
   test_interface();
   return 0;
}