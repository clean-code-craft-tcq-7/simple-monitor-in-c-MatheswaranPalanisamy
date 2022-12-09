#include <stdio.h>
#include "checker_functions.h"

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  int temperature_ret_val = checkTemperatureRange(temperature);
  int soc_ret_val = checkSocRange(soc);
  int charge_rate_ret_val = checkChargeRateRange(chargeRate);

  if(temperature_ret_val == 1 && soc_ret_val == 1 && charge_rate_ret_val == 1)
  {
    return 1;
  }

  return 0;
}
