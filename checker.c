#include <stdio.h>
#include "checker_common.h"
#include "checker_functions.h"

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  int return_code = 0;
  return_code = checkTemperatureRange(temperature) & checkSocRange(soc) & checkChargeRateRange(chargeRate);
  return return_code;
}
