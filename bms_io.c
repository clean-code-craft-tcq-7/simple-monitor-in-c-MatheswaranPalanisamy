#include <stdio.h>
#include "bms_common.h"

char testPrintMessages[BMS_MAX_PARAMTERS][100];
limitCategory_en limitCategory[BMS_MAX_PARAMTERS];

void printMessage(bmsParameterType_en paramType, limitCategory_en limitcategory, char *msg)
{
    limitCategory[paramType] = limitcategory;
    sprintf(testPrintMessages[paramType], "%s", msg);
    printf("%d - %s\n", limitcategory, msg);
}
