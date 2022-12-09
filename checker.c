#include <stdio.h>
#include "checker_common.h"
#include "checker_functions.h"

returnCode batteryIsOk(float temperature, float soc, float chargeRate) 
{
  returnCode return_code = RET_SUCCESS;
  return_code = checkTemperatureRange(temperature);
  if(return_code == RET_SUCCESS)
  {
    return_code = checkSocRange(soc);
    if(return_code == RET_SUCCESS)
    {
      return checkChargeRateRange(chargeRate);
    }
  }

  return return_code;
}
