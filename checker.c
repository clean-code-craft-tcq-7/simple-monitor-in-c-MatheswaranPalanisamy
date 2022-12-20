#include <stdio.h>

#include "bms_common.h"
#include "bms_limits.h"
#include "checker_functions.h"
#include "checker.h"

bmsChecker_st checkerDatabase[BMS_MAX_PARAMTERS] = {
  {
    .limits = (limits_st *)&Bms_limitsDataBase[BMS_TEMPERATURE],
    .language = ENGLISH,
    .enableWarning = 1,
  },
  {
    .limits = (limits_st *)&Bms_limitsDataBase[BMS_SOC],
    .language = ENGLISH,
    .enableWarning = 1,
  },
  {
    .limits = (limits_st *)&Bms_limitsDataBase[BMS_CHARGE_RATE],
    .language = ENGLISH,
    .enableWarning = 1,
  }
};

int checkerInit(languages_en language, int *warningEnable)
{
  int paramCount = 0;
  for(paramCount = 0; paramCount < BMS_MAX_PARAMTERS; paramCount++)
  {
    // select Language
    checkerDatabase[paramCount].language = language;
    // Enable or disable warning  levels
    checkerDatabase[paramCount].enableWarning = warningEnable[paramCount];
  }

  return 0;
}

int batteryIsOk(float temperature, float soc, float chargeRate, void (*alerter)(limitCategory_en, char *)) 
{
  float parameterArray[BMS_MAX_PARAMTERS] = {temperature, soc, chargeRate};
  printf("Inputs : %f, %f, %f\n", temperature, soc, chargeRate);
 
  return checkAndAlertParameters(parameterArray, alerter);
}
