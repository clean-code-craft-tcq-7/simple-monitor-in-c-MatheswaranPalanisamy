#ifndef BMS_FUNCTIONS_H
#define BMS_FUNCTIONS_H
/*
int checkTemperatureRange(float temperature);
int checkSocRange(float soc);
int checkChargeRateRange(float chargeRate); */
int checkAndAlertParameters(float *parameters, void (*alerter)(limitCategory_en, char *));
#endif
