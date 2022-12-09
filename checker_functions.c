#include <stdio.h>

void printError(const char *error_string)
{
    printf("%s\n", error_string);
}

int checkTemperatureRange(float temperature)
{
  if(temperature < 0 || temperature > 45) 
  {
    printError("Temperature out of range!");
    return 0;
  }

  return 1;
}

int checkSocRange(float soc)
{
  if(soc < 20 || soc > 80) 
  {
    printError("State of Charge out of range!");
    return 0;
  }

  return 1;
}

int checkChargeRateRange(float chargeRate)
{
  if(chargeRate > 0.8) 
  {
    printError("Charge Rate out of range!");
    return 0;
  }

  return 1;
}

