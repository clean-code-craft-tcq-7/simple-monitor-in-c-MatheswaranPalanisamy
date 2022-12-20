#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "bms_common.h"
#include "checker.h"
#include "checker_functions.h"
#include "bms_io.h"
#include "bms_test.h"

void resetTestvariables()
{
  int lpCnt;
  for(lpCnt = 0; lpCnt < BMS_MAX_PARAMTERS; lpCnt++)
  {
    limitCategory[lpCnt] = BMS_VALID;
    memset(testPrintMessages[lpCnt], 0, 100);
  }
}

bms_testData fillExpectedOutput(int retSts, char *tempAlertMsg, char *socAlertMsg,char *chargeStateAlertMsg, limitCategory_en tempAlrtType, limitCategory_en socAlrtType, limitCategory_en chargeAlrtType)
{
    bms_testData testData;

    testData.retSts = retSts;
    testData.tempAlertMsg = tempAlertMsg;
    testData.socAlertMsg = socAlertMsg;
    testData.chargeStateAlertMsg = chargeStateAlertMsg;
    testData.tempAlrtType = tempAlrtType;
    testData.socAlrtType = socAlrtType;
    testData.chargeAlrtType = chargeAlrtType;

    return testData;
}

void testBmsChecker(float temperature, float soc, float chargeRate, void (*alerter)(bmsParameterType_en, limitCategory_en, char *), bms_testData testData)
{
    resetTestvariables();
    assert(batteryIsOk(temperature, soc, chargeRate, alerter) == testData.retSts);
    assert(testData.tempAlrtType == limitCategory[BMS_TEMPERATURE]);
    assert(testData.socAlrtType == limitCategory[BMS_SOC]);
    assert(testData.chargeAlrtType == limitCategory[BMS_CHARGE_RATE]);

    assert(strcmp(testData.tempAlertMsg, testPrintMessages[BMS_TEMPERATURE]) == 0);
    assert(strcmp(testData.socAlertMsg, testPrintMessages[BMS_SOC]) == 0);
    assert(strcmp(testData.chargeStateAlertMsg, testPrintMessages[BMS_CHARGE_RATE]) == 0);

}
