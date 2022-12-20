#ifndef BMS_ALERTER_H
#define BMS_ALERTER_H

void alertLimit(bmsParameterType_en paramType, limitType_en limitType, void (*alerter)(bmsParameterType_en, limitCategory_en, char *));

#endif
