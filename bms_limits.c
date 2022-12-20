#include <stdio.h>
#include <float.h>

#include "bms_common.h"
#include "bms_limits.h"

const limits_st Bms_TemperatureLimits[BMS_MAX_LIMITS] = 
{
    {
        .minVal = -FLT_MAX,
        .maxVal = 0,
        .limitType = BMS_LOWER_LIMIT_ERROR,
        .limitCategory = BMS_ERROR
    },
    {
        .minVal = 0,
        .maxVal = 5,
        .limitType = BMS_LOWER_LIMIT_WARNING,
        .limitCategory = BMS_WARNING
    },
    {
        .minVal = 40,
        .maxVal = 45,
        .limitType = BMS_UPPER_LIMIT_WARNING,
        .limitCategory = BMS_WARNING
    },
    {
        .minVal = 45,
        .maxVal = FLT_MAX,
        .limitType = BMS_UPPER_LIMIT_ERROR,
        .limitCategory = BMS_ERROR
    },
};

const limits_st Bms_SocLimits[BMS_MAX_LIMITS] = 
{
    {
        .minVal = -FLT_MAX,
        .maxVal = 20,
        .limitType = BMS_LOWER_LIMIT_ERROR,
        .limitCategory = BMS_ERROR
    },
    {
        .minVal = 20,
        .maxVal = 25,
        .limitType = BMS_LOWER_LIMIT_WARNING,
        .limitCategory = BMS_WARNING
    },
    {
        .minVal = 75,
        .maxVal = 80,
        .limitType = BMS_UPPER_LIMIT_WARNING,
        .limitCategory = BMS_WARNING
    },
    {
        .minVal = 80,
        .maxVal = FLT_MAX,
        .limitType = BMS_UPPER_LIMIT_ERROR,
        .limitCategory = BMS_ERROR
    },
};

const limits_st Bms_ChargeLimits[BMS_MAX_LIMITS] = 
{
    {
        .minVal = -FLT_MAX,
        .maxVal = -FLT_MAX,
        .limitType = BMS_LOWER_LIMIT_ERROR,
        .limitCategory = BMS_ERROR
    },
    {
        .minVal = -FLT_MAX,
        .maxVal = -FLT_MAX,
        .limitType = BMS_LOWER_LIMIT_WARNING,
        .limitCategory = BMS_WARNING
    },
    {
        .minVal = 0.75,
        .maxVal = 0.8,
        .limitType = BMS_UPPER_LIMIT_WARNING,
        .limitCategory = BMS_WARNING
    },
    {
        .minVal = 0.8,
        .maxVal = FLT_MAX,
        .limitType = BMS_UPPER_LIMIT_ERROR,
        .limitCategory = BMS_ERROR
    },
};

const limits_st *Bms_limitsDataBase[BMS_MAX_PARAMTERS] = 
{
    Bms_TemperatureLimits,
    Bms_SocLimits,
    Bms_ChargeLimits
};
