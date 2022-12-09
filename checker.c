#include <stdio.h>
#include "checker_functions.h"

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  int temperature_ret_val = checkTemperatureRange(temperature);
  int soc_ret_val = checkSocRange(soc);
  int charge_rate_ret_val = checkChargeRateRange(chargeRate);

  return temperature_ret_val & soc_ret_val & charge_rate_ret_val;
}
