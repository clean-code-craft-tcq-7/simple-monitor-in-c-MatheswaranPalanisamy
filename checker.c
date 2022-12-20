#include <stdio.h>

#include "bms_common.h"
#include "bms_limits.h"
#include "checker_functions.h"
#include "checker.h"

bmsChecker_st checkerDatabase[BMS_MAX_PARAMTERS];

int checkerInit(languages_en language, int *warningEnable)
{
  int paramCount = 0;
  for(paramCount = 0; paramCount < BMS_MAX_PARAMTERS; paramCount++)
  {
    checkerDatabase[paramCount].limits = (limits_st*)Bms_limitsDataBase[paramCount];
    // select Language
    checkerDatabase[paramCount].language = language;
    // Enable or disable warning  levels
    checkerDatabase[paramCount].enableWarning = warningEnable[paramCount];
  }

  return 0;
}

int batteryIsOk(float temperature, float soc, float chargeRate, void (*alerter)(limitCategory_en, char *)) 
{
  //int return_code = 0;
  float parameterArray[BMS_MAX_PARAMTERS] = {temperature, soc, chargeRate};

  return checkAndAlertParameters(parameterArray, alerter);
  //return_code = checkTemperatureRange(temperature) & checkSocRange(soc) & checkChargeRateRange(chargeRate);
  //return return_code;
}
