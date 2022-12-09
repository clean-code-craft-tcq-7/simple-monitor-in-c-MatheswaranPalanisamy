#include <stdio.h>
#include "checker_functions.h"

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  if(checkTemperatureRange(temperature))
  {
    if(checkSocRange(soc))
    {
      return checkChargeRateRange(chargeRate);
    }
  }

  return 0;
}
