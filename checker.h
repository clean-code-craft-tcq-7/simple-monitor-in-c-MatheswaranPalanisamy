#ifndef BMS_CHECKER_H
#define BMS_CHECKER_H

typedef struct
{
    const limits_st *limits;
    int enableWarning;
    languages_en language;

}bmsChecker_st;

int batteryIsOk(float temperature, float soc, float chargeRate, void (*alerter)(limitCategory_en, char *));
int checkerInit(languages_en language, int *warningEnable);

extern bmsChecker_st checkerDatabase[BMS_MAX_PARAMTERS];

#endif
