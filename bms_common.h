#ifndef BMS_COMMON_H
#define BMS_COMMON_H

typedef enum
{
    ENGLISH = 0,
    GERMAN = 1,
    LANGUAGE_MAX = 2
}languages_en;

typedef enum
{
    BMS_TEMPERATURE = 0,
    BMS_SOC = 1,
    BMS_CHARGE_RATE = 2,
    BMS_MAX_PARAMTERS = 3
}bmsParameterType_en;

typedef enum
{
    BMS_LOWER_LIMIT_ERROR = 0,
    BMS_LOWER_LIMIT_WARNING = 1,
    BMS_UPPER_LIMIT_WARNING = 2,
    BMS_UPPER_LIMIT_ERROR = 3,

    BMS_MAX_LIMITS = 4,
    BMS_LIMIT_VALID = 0xFF
}limitType_en;

typedef enum
{
    BMS_VALID = 0,
    BMS_WARNING = 1,
    BMS_ERROR = 2,

}limitCategory_en;

typedef struct
{
    float minVal;
    float maxVal;
    limitType_en limitType;
    limitCategory_en limitCategory;
}limits_st;

#endif
