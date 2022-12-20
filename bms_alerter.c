#include <stdio.h>

#include "bms_common.h"
#include "bms_limits.h"
#include "bms_languages.h"
#include "checker.h"

static limitCategory_en findAlertCategory(bmsParameterType_en paramType, limitType_en limitType)
{
    limits_st *paramLimits = (limits_st *)Bms_limitsDataBase[paramType];
    limitCategory_en limitCategory = BMS_VALID;

    if(limitType != BMS_LIMIT_VALID)
    {
        limitCategory = paramLimits[limitType].limitCategory;
    }

    return limitCategory;
}

char *findAlertMessage(bmsParameterType_en paramType, limitType_en limitType)
{
    char **languageSet = (char **)languageDictionary[checkerDatabase[paramType].language];
    char *alertmsg = languageSet[(paramType + 1) * (limitType + 1) - 1];

    return alertmsg;
}

void alertLimit(bmsParameterType_en paramType, limitType_en limitType, void (*alerter)(limitCategory_en, char *))
{
    limitCategory_en limitCategory = findAlertCategory(paramType, limitType);

    if(limitCategory == BMS_VALID)
    {
        // Do nothing
    }
    else
    {
        alerter(limitCategory, findAlertMessage(paramType, limitType));
    }
}
