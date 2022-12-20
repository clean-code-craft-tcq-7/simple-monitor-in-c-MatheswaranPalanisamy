#include <assert.h>
#include "bms_common.h"
#include "checker.h"
#include "checker_functions.h"
#include "bms_io.h"

int main() {
  int enableWarning[BMS_MAX_PARAMTERS] = {1, 1, 1};
  assert(checkerInit(GERMAN, enableWarning) == 0);
  
  // Test batterOk for success
  //assert(batteryIsOk(25, 70, 0.7, printError) == 1);
/*
  assert(batteryIsOk(-3.5, 43, 0.4, printMessage) == 0);
  assert(batteryIsOk(0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.1, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(5.0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(40.0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(44.9, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(45.0, 70, 0.7, printMessage) == 0);
  assert(batteryIsOk(47.0, 70, 0.7, printMessage) == 0);
  */// Test batterOk for temperature failure, soc fail and chargeRate fail
  //assert(batteryIsOk(3, 70, 0.7, printError) == 1);
  // Test batterOk for temperature failure, soc fail and chargeRate success
 // assert(batteryIsOk(50, 88, 0.3, printError) == 0);
  // Test batterOk for temperature failure, soc success and chargeRate fail
 // assert(batteryIsOk(50, 40, 1.2, printError) == 0);
  // Test batterOk for temperature failure, soc success and chargeRate success
 // assert(batteryIsOk(50, 32, 0.6, printError) == 0);

  // Test batterOk for temperature success, soc fail and chargeRate fail
  //assert(batteryIsOk(30, 85, 1.8, printError) == 0);
  // Test batterOk for temperature success, soc fail and chargeRate success
 // assert(batteryIsOk(30, 85, 0.4, printError) == 0);

  // Test batterOk for temperature and soc success, chargeRate fail
 // assert(batteryIsOk(30, 43, 1, printError) == 0);
/*
  // Test temperature range for out of lower boundary
  assert(checkTemperatureRange(-0.1) == 0);
  // Test temperature range for lower boundary
  assert(checkTemperatureRange(0) == 1);
  // Test temperature range for just in lower boundary
  assert(checkTemperatureRange(0.1) == 1);
  // Test temperature range for within boundary
  assert(checkTemperatureRange(17.5) == 1);
  // Test temperature range for just in upper boundary
  assert(checkTemperatureRange(44.9) == 1);
  // Test temperature range for upper boundary
  assert(checkTemperatureRange(45) == 1);
  // Test temperature range for out of upper boundary
  assert(checkTemperatureRange(45.1) == 0);

  // Test soc range for out of lower boundary
  assert(checkSocRange(19.9) == 0);
  // Test soc range for lower boundary
  assert(checkSocRange(20) == 1);
  // Test soc range for just in lower boundary
  assert(checkSocRange(20.1) == 1);
  // Test soc range for within boundary
  assert(checkSocRange(60) == 1);
  // Test soc range for just in upper boundary
  assert(checkSocRange(79.9) == 1);
  // Test soc range for upper boundary
  assert(checkSocRange(80) == 1);
  // Test soc range for out of upper boundary
  assert(checkSocRange(80.1) == 0);

  // Test chargerRate range for well within boundary
  assert(checkChargeRateRange(0.1) == 1);
  // Test chargerRate range for just in the boundary
  assert(checkChargeRateRange(0.79) == 1);
  // Test chargerRate range for upper boundary
  assert(checkChargeRateRange(0.8) == 1);
  // Test chargerRate range for out of boundary
  assert(checkChargeRateRange(0.9) == 0);
*/
  return 0;
}
