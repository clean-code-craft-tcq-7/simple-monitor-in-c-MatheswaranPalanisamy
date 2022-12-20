#include <stdio.h>
#include "bms_common.h"

void printMessage(limitCategory_en limitcategory, char *msg)
{
    printf("%d - %s\n", limitcategory, msg);
}
