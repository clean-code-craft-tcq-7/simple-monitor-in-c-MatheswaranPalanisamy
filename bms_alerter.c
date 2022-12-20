#include <stdio.h>

#include "bms_common.h"
#include "bms_limits.h"
#include "bms_languages.h"
#include "checker.h"

static limitCategory_en findAlertCategory(bmsParameterType_en paramType, limitType_en limitType)
{
    const limits_st *paramLimits = checkerDatabase[paramType].limits;
    limitCategory_en limitCategory = BMS_VALID;

    if(limitType != BMS_LIMIT_VALID)
    {
        limitCategory = paramLimits[limitType].limitCategory;
    }

    return limitCategory;
}

static char *findAlertMessage(bmsParameterType_en paramType, limitType_en limitType)
{
    char **languageSet = (char **)languageDictionary[checkerDatabase[paramType].language];
    char *alertmsg = languageSet[(paramType * BMS_MAX_LIMITS) + limitType];

    return alertmsg;
}

static int isWarningAlertReqired(bmsParameterType_en paramType, limitCategory_en limitCategory)
{
    if(limitCategory == BMS_WARNING)
    {
        return checkerDatabase[paramType].enableWarning;
    }

    return 1;
}

void alertLimit(bmsParameterType_en paramType, limitType_en limitType, void (*alerter)(bmsParameterType_en, limitCategory_en, char *))
{
    limitCategory_en limitCategory = findAlertCategory(paramType, limitType);

    if(limitCategory == BMS_VALID)
    {
        // Do nothing
    }
    else
    {
        if(isWarningAlertReqired(paramType, limitCategory))
        {
            alerter(paramType, limitCategory, findAlertMessage(paramType, limitType));
        }
    }
}
