
#ifndef BMS_IO_H
#define BMS_IO_H

extern char testPrintMessages[BMS_MAX_PARAMTERS][100];
extern limitCategory_en limitCategory[BMS_MAX_PARAMTERS];

void printMessage(bmsParameterType_en paramType, limitCategory_en limitcategory, char *msg);

#endif
