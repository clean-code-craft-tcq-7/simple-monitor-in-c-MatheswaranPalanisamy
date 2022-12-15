#include <stdio.h>
#include "checker_functions.h"

const float minTemperatureRange = 0;
const float maxTemperatureRange = 45;
const float minSocRange = 20;
const float maxSocRange = 80;
const float maxChargeRateRange = 0.8;

void printError(const char *error_string)
{
    printf("%s\n", error_string);
}

int checkOutOfRange(float value, float minVal, float maxVal)
{
  if(value < minVal || value > maxVal)
  {
    return 1;
  }

  return 0;
}

int checkTemperatureRange(float temperature)
{
  if(checkOutOfRange(temperature, minTemperatureRange, maxTemperatureRange))
  {
    printError("Temperature out of range!");
    return 0;
  }
  return 1;
}

int checkSocRange(float soc)
{
  if(checkOutOfRange(soc, minSocRange, maxSocRange))
  {
    printError("State of Charge out of range!");
    return 0;
  }

  return 1;
}

int checkChargeRateRange(float chargeRate)
{
  if(chargeRate > maxChargeRateRange) 
  {
    printError("Charge Rate out of range!");
    return 0;
  }

  return 1;
}
