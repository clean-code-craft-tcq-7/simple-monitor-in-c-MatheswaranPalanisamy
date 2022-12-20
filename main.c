#include <assert.h>
#include "bms_common.h"
#include "checker.h"
#include "bms_io.h"
#include "bms_test.h"

int main() {
  int enableWarning[BMS_MAX_PARAMTERS] = {1, 1, 1};

  checkerInit(ENGLISH, enableWarning);
  testBmsChecker(25, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(-3.5, 43, 0.4, printMessage, fillExpectedOutput(0, "Temperature is below lower limit!", "", "", 2, 0, 0));
  testBmsChecker(0, 70, 0.7, printMessage, fillExpectedOutput(1, "Temperature is about to cross below lower limit!", "", "", 1, 0, 0));
  testBmsChecker(0.1, 70, 0.7, printMessage, fillExpectedOutput(1, "Temperature is about to cross below lower limit!", "", "", 1, 0, 0));
  testBmsChecker(5, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(40, 70, 0.7, printMessage, fillExpectedOutput(1, "Temperature is about to cross above higher limit!", "", "", 1, 0, 0));
  testBmsChecker(44.9, 70, 0.7, printMessage, fillExpectedOutput(1, "Temperature is about to cross above higher limit!", "", "", 1, 0, 0));
  testBmsChecker(45, 70, 0.7, printMessage, fillExpectedOutput(0, "Temperature is above higher limit!", "", "", 2, 0, 0));
  testBmsChecker(47, 70, 0.7, printMessage, fillExpectedOutput(0, "Temperature is above higher limit!", "", "", 2, 0, 0));
  testBmsChecker(25, -10, 0.7, printMessage, fillExpectedOutput(0, "", "SOC is below lower limit!", "", 0, 2, 0));
  testBmsChecker(2, 19.9, 0.4, printMessage, fillExpectedOutput(0, "Temperature is about to cross below lower limit!", "SOC is below lower limit!", "", 1, 2, 0));
  testBmsChecker(42, 20, 0.4, printMessage, fillExpectedOutput(1, "Temperature is about to cross above higher limit!", "SOC is about to cross below lower limit!", "", 1, 1, 0));
  testBmsChecker(2, 20.1, 0.4, printMessage, fillExpectedOutput(1, "Temperature is about to cross below lower limit!", "SOC is about to cross below lower limit!", "", 1, 1, 0));
  testBmsChecker(5, 24.9, 0.4, printMessage, fillExpectedOutput(1, "", "SOC is about to cross below lower limit!", "", 0, 1, 0));
  testBmsChecker(39, 25, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(44.9, 25.1, 0.4, printMessage, fillExpectedOutput(1, "Temperature is about to cross above higher limit!", "", "", 1, 0, 0));
  testBmsChecker(43.9, 74.9, 0.4, printMessage, fillExpectedOutput(1, "Temperature is about to cross above higher limit!", "", "", 1, 0, 0));
  testBmsChecker(41, 75, 0.4, printMessage, fillExpectedOutput(1, "Temperature is about to cross above higher limit!", "SOC is about to cross above higher limit!", "", 1, 1, 0));
  testBmsChecker(9, 75.1, 0.4, printMessage, fillExpectedOutput(1, "", "SOC is about to cross above higher limit!", "", 0, 1, 0));
  testBmsChecker(20, 79.9, 0.4, printMessage, fillExpectedOutput(1, "", "SOC is about to cross above higher limit!", "", 0, 1, 0));
  testBmsChecker(0.5, 80, 0.4, printMessage, fillExpectedOutput(0, "Temperature is about to cross below lower limit!", "SOC is above higher limit!", "", 1, 2, 0));
  testBmsChecker(27, 80.1, 0.4, printMessage, fillExpectedOutput(0, "", "SOC is above higher limit!", "", 0, 2, 0));
  testBmsChecker(27, 21, -0.4, printMessage, fillExpectedOutput(1, "", "SOC is about to cross below lower limit!", "", 0, 1, 0));
  testBmsChecker(2, 22, 0.74, printMessage, fillExpectedOutput(1, "Temperature is about to cross below lower limit!", "SOC is about to cross below lower limit!", "", 1, 1, 0));
  testBmsChecker(29.5, 25, 0.75, printMessage, fillExpectedOutput(1, "", "", "Charge Rate is about to cross above higher limit!", 0, 0, 1));
  testBmsChecker(20, 26, 0.76, printMessage, fillExpectedOutput(1, "", "", "Charge Rate is about to cross above higher limit!", 0, 0, 1));
  testBmsChecker(3, 25, 0.79, printMessage, fillExpectedOutput(1, "Temperature is about to cross below lower limit!", "", "Charge Rate is about to cross above higher limit!", 1, 0, 1));
  testBmsChecker(6, 25, 0.8, printMessage, fillExpectedOutput(0, "", "", "Charge Rate is above higher limit!", 0, 0, 2));
  testBmsChecker(6, 25, 0.81, printMessage, fillExpectedOutput(0, "", "", "Charge Rate is above higher limit!", 0, 0, 2));
  testBmsChecker(6, 25, 0.85, printMessage, fillExpectedOutput(0, "", "", "Charge Rate is above higher limit!", 0, 0, 2));
  
  checkerInit(GERMAN, enableWarning);
  testBmsChecker(25, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(-3.5, 43, 0.4, printMessage, fillExpectedOutput(0, "Temperatur unter Untergrenze!", "", "", 2, 0, 0));
  testBmsChecker(0, 70, 0.7, printMessage, fillExpectedOutput(1, "Die Temperatur ist dabei, die untere Grenze zu unterschreiten!", "", "", 1, 0, 0));
  testBmsChecker(0.1, 70, 0.7, printMessage, fillExpectedOutput(1, "Die Temperatur ist dabei, die untere Grenze zu unterschreiten!", "", "", 1, 0, 0));
  testBmsChecker(5, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(40, 70, 0.7, printMessage, fillExpectedOutput(1, "Die Temperatur ist dabei, die obere Grenze zu überschreiten!", "", "", 1, 0, 0));
  testBmsChecker(44.9, 70, 0.7, printMessage, fillExpectedOutput(1, "Die Temperatur ist dabei, die obere Grenze zu überschreiten!", "", "", 1, 0, 0));
  testBmsChecker(45, 70, 0.7, printMessage, fillExpectedOutput(0, "Temperatur liegt über oberer Grenze!", "", "", 2, 0, 0));
  testBmsChecker(47, 70, 0.7, printMessage, fillExpectedOutput(0, "Temperatur liegt über oberer Grenze!", "", "", 2, 0, 0));
  testBmsChecker(25, -10, 0.7, printMessage, fillExpectedOutput(0, "", "SOC ist unter Untergrenze!", "", 0, 2, 0));
  testBmsChecker(2, 19.9, 0.4, printMessage, fillExpectedOutput(0, "Die Temperatur ist dabei, die untere Grenze zu unterschreiten!", "SOC ist unter Untergrenze!", "", 1, 2, 0));
  testBmsChecker(42, 20, 0.4, printMessage, fillExpectedOutput(1, "Die Temperatur ist dabei, die obere Grenze zu überschreiten!", "SOC ist dabei, die untere Grenze zu unterschreiten!", "", 1, 1, 0));
  testBmsChecker(2, 20.1, 0.4, printMessage, fillExpectedOutput(1, "Die Temperatur ist dabei, die untere Grenze zu unterschreiten!", "SOC ist dabei, die untere Grenze zu unterschreiten!", "", 1, 1, 0));
  testBmsChecker(5, 24.9, 0.4, printMessage, fillExpectedOutput(1, "", "SOC ist dabei, die untere Grenze zu unterschreiten!", "", 0, 1, 0));
  testBmsChecker(39, 25, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(44.9, 25.1, 0.4, printMessage, fillExpectedOutput(1, "Die Temperatur ist dabei, die obere Grenze zu überschreiten!", "", "", 1, 0, 0));
  testBmsChecker(43.9, 74.9, 0.4, printMessage, fillExpectedOutput(1, "Die Temperatur ist dabei, die obere Grenze zu überschreiten!", "", "", 1, 0, 0));
  testBmsChecker(41, 75, 0.4, printMessage, fillExpectedOutput(1, "Die Temperatur ist dabei, die obere Grenze zu überschreiten!", "SOC ist dabei, die obere Grenze zu überschreiten!", "", 1, 1, 0));
  testBmsChecker(9, 75.1, 0.4, printMessage, fillExpectedOutput(1, "", "SOC ist dabei, die obere Grenze zu überschreiten!", "", 0, 1, 0));
  testBmsChecker(20, 79.9, 0.4, printMessage, fillExpectedOutput(1, "", "SOC ist dabei, die obere Grenze zu überschreiten!", "", 0, 1, 0));
  testBmsChecker(0.5, 80, 0.4, printMessage, fillExpectedOutput(0, "Die Temperatur ist dabei, die untere Grenze zu unterschreiten!", "SOC liegt über der oberen Grenze!", "", 1, 2, 0));
  testBmsChecker(27, 80.1, 0.4, printMessage, fillExpectedOutput(0, "", "SOC liegt über der oberen Grenze!", "", 0, 2, 0));
  testBmsChecker(27, 21, -0.4, printMessage, fillExpectedOutput(1, "", "SOC ist dabei, die untere Grenze zu unterschreiten!", "", 0, 1, 0));
  testBmsChecker(2, 22, 0.74, printMessage, fillExpectedOutput(1, "Die Temperatur ist dabei, die untere Grenze zu unterschreiten!", "SOC ist dabei, die untere Grenze zu unterschreiten!", "", 1, 1, 0));
  testBmsChecker(29.5, 25, 0.75, printMessage, fillExpectedOutput(1, "", "", "Die Laderate ist dabei, die obere Grenze zu überschreiten!", 0, 0, 1));
  testBmsChecker(20, 26, 0.76, printMessage, fillExpectedOutput(1, "", "", "Die Laderate ist dabei, die obere Grenze zu überschreiten!", 0, 0, 1));
  testBmsChecker(3, 25, 0.79, printMessage, fillExpectedOutput(1, "Die Temperatur ist dabei, die untere Grenze zu unterschreiten!", "", "Die Laderate ist dabei, die obere Grenze zu überschreiten!", 1, 0, 1));
  testBmsChecker(6, 25, 0.8, printMessage, fillExpectedOutput(0, "", "", "Gebührenrate liegt über dem oberen Limit!", 0, 0, 2));
  testBmsChecker(6, 25, 0.81, printMessage, fillExpectedOutput(0, "", "", "Gebührenrate liegt über dem oberen Limit!", 0, 0, 2));
  testBmsChecker(6, 25, 0.85, printMessage, fillExpectedOutput(0, "", "", "Gebührenrate liegt über dem oberen Limit!", 0, 0, 2));
  
  enableWarning[BMS_TEMPERATURE] = 0;
  enableWarning[BMS_SOC] = 0;
  enableWarning[BMS_CHARGE_RATE] = 0;
  
  checkerInit(ENGLISH, enableWarning);
  testBmsChecker(25, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(-3.5, 43, 0.4, printMessage, fillExpectedOutput(0, "Temperature is below lower limit!", "", "", 2, 0, 0));
  testBmsChecker(0, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(0.1, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(5, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(40, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(44.9, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(45, 70, 0.7, printMessage, fillExpectedOutput(0, "Temperature is above higher limit!", "", "", 2, 0, 0));
  testBmsChecker(47, 70, 0.7, printMessage, fillExpectedOutput(0, "Temperature is above higher limit!", "", "", 2, 0, 0));
  testBmsChecker(25, -10, 0.7, printMessage, fillExpectedOutput(0, "", "SOC is below lower limit!", "", 0, 2, 0));
  testBmsChecker(2, 19.9, 0.4, printMessage, fillExpectedOutput(0, "", "SOC is below lower limit!", "", 0, 2, 0));
  testBmsChecker(42, 20, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(2, 20.1, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(5, 24.9, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(39, 25, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(44.9, 25.1, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(43.9, 74.9, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(41, 75, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(9, 75.1, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(20, 79.9, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(0.5, 80, 0.4, printMessage, fillExpectedOutput(0, "", "SOC is above higher limit!", "", 0, 2, 0));
  testBmsChecker(27, 80.1, 0.4, printMessage, fillExpectedOutput(0, "", "SOC is above higher limit!", "", 0, 2, 0));
  testBmsChecker(27, 21, -0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(2, 22, 0.74, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(29.5, 25, 0.75, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(20, 26, 0.76, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(3, 25, 0.79, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(6, 25, 0.8, printMessage, fillExpectedOutput(0, "", "", "Charge Rate is above higher limit!", 0, 0, 2));
  testBmsChecker(6, 25, 0.81, printMessage, fillExpectedOutput(0, "", "", "Charge Rate is above higher limit!", 0, 0, 2));
  testBmsChecker(6, 25, 0.85, printMessage, fillExpectedOutput(0, "", "", "Charge Rate is above higher limit!", 0, 0, 2));
  
  checkerInit(GERMAN, enableWarning);
  testBmsChecker(25, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(-3.5, 43, 0.4, printMessage, fillExpectedOutput(0, "Temperatur unter Untergrenze!", "", "", 2, 0, 0));
  testBmsChecker(0, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(0.1, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(5, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(40, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(44.9, 70, 0.7, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(45, 70, 0.7, printMessage, fillExpectedOutput(0, "Temperatur liegt über oberer Grenze!", "", "", 2, 0, 0));
  testBmsChecker(47, 70, 0.7, printMessage, fillExpectedOutput(0, "Temperatur liegt über oberer Grenze!", "", "", 2, 0, 0));
  testBmsChecker(25, -10, 0.7, printMessage, fillExpectedOutput(0, "", "SOC ist unter Untergrenze!", "", 0, 2, 0));
  testBmsChecker(2, 19.9, 0.4, printMessage, fillExpectedOutput(0, "", "SOC ist unter Untergrenze!", "", 0, 2, 0));
  testBmsChecker(42, 20, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(2, 20.1, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(5, 24.9, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(39, 25, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(44.9, 25.1, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(43.9, 74.9, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(41, 75, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(9, 75.1, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(20, 79.9, 0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(0.5, 80, 0.4, printMessage, fillExpectedOutput(0, "", "SOC liegt über der oberen Grenze!", "", 0, 2, 0));
  testBmsChecker(27, 80.1, 0.4, printMessage, fillExpectedOutput(0, "", "SOC liegt über der oberen Grenze!", "", 0, 2, 0));
  testBmsChecker(27, 21, -0.4, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(2, 22, 0.74, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(29.5, 25, 0.75, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(20, 26, 0.76, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(3, 25, 0.79, printMessage, fillExpectedOutput(1, "", "", "", 0, 0, 0));
  testBmsChecker(6, 25, 0.8, printMessage, fillExpectedOutput(0, "", "", "Gebührenrate liegt über dem oberen Limit!", 0, 0, 2));
  testBmsChecker(6, 25, 0.81, printMessage, fillExpectedOutput(0, "", "", "Gebührenrate liegt über dem oberen Limit!", 0, 0, 2));
  testBmsChecker(6, 25, 0.85, printMessage, fillExpectedOutput(0, "", "", "Gebührenrate liegt über dem oberen Limit!", 0, 0, 2));
  
  return 0;
}
