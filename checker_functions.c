#include <stdio.h>

#include "bms_common.h"
#include "bms_alerter.h"
#include "checker.h"

static int checkRange(float value, float minVal, float maxVal)
{
  if(value >= minVal && value < maxVal)
  {
    return 1;
  }

  return 0;
}

static limitType_en findValueRange(float value, const limits_st *limits)
{
  int limitCnt = 0;
  for(limitCnt = 0; limitCnt < BMS_MAX_LIMITS; limitCnt++)
  {
    if(checkRange(value, limits[limitCnt].minVal, limits[limitCnt].maxVal))
    {
      return (limitType_en)limitCnt;
    }
  }

  return BMS_LIMIT_VALID;
}

static limitCategory_en getLimitCategory(limitType_en limitType, const limits_st *paramLimits)
{
  if(limitType == BMS_LIMIT_VALID)
  {
    return BMS_VALID;
  }
  else
  {
    return paramLimits[limitType].limitCategory;
  }
} 

int checkAndAlertParameters(float *parameters, void (*alerter)(limitCategory_en, char *))
{
  int paramCount;
  const limits_st *paramLimits;
  limitType_en limitType;
  for(paramCount = 0; paramCount < BMS_MAX_PARAMTERS; paramCount++)
  {
    paramLimits = checkerDatabase[paramCount].limits;
    limitType = findValueRange(parameters[paramCount], paramLimits);
    alertLimit(paramCount, limitType, alerter);

    if(getLimitCategory(limitType, paramLimits) == BMS_ERROR)
    {
      return 0;
    }
  }
  return 1;
}
