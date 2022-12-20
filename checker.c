#include <stdio.h>

#include "bms_common.h"
#include "bms_limits.h"
#include "checker_functions.h"
#include "checker.h"

bmsChecker_st checkerDatabase[BMS_MAX_PARAMTERS] = {
  {
    .limits = Bms_TemperatureLimits,
    .language = ENGLISH,
    .enableWarning = 1,
  },
  {
    .limits = Bms_SocLimits,
    .language = ENGLISH,
    .enableWarning = 1,
  },
  {
    .limits = Bms_ChargeLimits,
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
 
  return checkAndAlertParameters(parameterArray, alerter);
}
