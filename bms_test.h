typedef struct
{
    int retSts;
    char *tempAlertMsg;
    char *socAlertMsg;
    char *chargeStateAlertMsg;
    limitCategory_en tempAlrtType;
    limitCategory_en socAlrtType;
    limitCategory_en chargeAlrtType;
}bms_testData;

void resetTestvariables();
void testBmsChecker(float temperature, float soc, float chargeRate, void (*alerter)(bmsParameterType_en, limitCategory_en, char *), bms_testData testData);
bms_testData fillExpectedOutput(int retSts, char *tempAlertMsg, char *socAlertMsg,char *chargeStateAlertMsg, limitCategory_en tempAlrtType, limitCategory_en socAlrtType, limitCategory_en chargeAlrtType);

