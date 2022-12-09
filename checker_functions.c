#include <stdio.h>
#include "checker_common.h"
#include "checker_functions.h"

void printError(const char *error_string)
{
    printf("%s\n", error_string);
}

returnCode checkTemperatureRange(float temperature)
{
  if(temperature < 0 || temperature > 45) 
  {
    printError("Temperature out of range!");
    return RET_TEMP_ERROR;
  }

  return RET_SUCCESS;
}

returnCode checkSocRange(float soc)
{
  if(soc < 20 || soc > 80) 
  {
    printError("State of Charge out of range!");
    return RET_SOC_ERROR;
  }

  return RET_SUCCESS;
}

returnCode checkChargeRateRange(float chargeRate)
{
  if(chargeRate > 0.8) 
  {
    printError("Charge Rate out of range!");
    return RET_CHRG_RATE_ERROR;
  }

  return RET_SUCCESS;
}

