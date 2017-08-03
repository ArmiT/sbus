#include <stdio.h>
#include <stdlib.h>
#include <sbus.h>
#ifndef UNIT_TEST
int main(void) 
{
    printf("initied!!!");
    sbus_init();
}
#endif