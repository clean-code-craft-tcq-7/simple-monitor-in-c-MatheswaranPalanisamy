#include <stdio.h>

#include "bms_common.h"

const char *alertMessagesEnglish[BMS_MAX_PARAMTERS * BMS_MAX_LIMITS] = {
    "Temperature is below lower limit!",
    "Temperature is about to cross below lower limit!",
    "Temperature is about to cross above higher limit!",
    "Temperature is above higher limit!",
    "SOC is below lower limit!",
    "SOC is about to cross below lower limit!",
    "SOC is about to cross above higher limit!",
    "SOC is above higher limit!",
    "Charge Rate is below lower limit!",
    "Charge Rate is about to cross below lower limit!",
    "Charge Rate is about to cross above higher limit!",
    "Charge Rate is above higher limit!",
};

const char *alertMessagesGerman[BMS_MAX_PARAMTERS * BMS_MAX_LIMITS] = {
    "Temperatur unter Untergrenze!",
    "Die Temperatur ist dabei, die untere Grenze zu unterschreiten!",
    "Die Temperatur ist dabei, die obere Grenze zu überschreiten!",
    "Temperatur liegt über oberer Grenze!",
    "SOC ist unter Untergrenze!",
    "SOC ist dabei, die untere Grenze zu unterschreiten!",
    "SOC ist dabei, die obere Grenze zu überschreiten!",
    "SOC liegt über der oberen Grenze!",
    "Laderate liegt unter dem unteren Limit!",
    "Laderate ist dabei, die untere Grenze zu unterschreiten!",
    "Die Laderate ist dabei, die obere Grenze zu überschreiten!",
    "Gebührenrate liegt über dem oberen Limit!",
};

const char **languageDictionary[LANGUAGE_MAX] = 
{
    alertMessagesEnglish,
    alertMessagesGerman
};

