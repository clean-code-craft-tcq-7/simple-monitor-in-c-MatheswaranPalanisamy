#include <assert.h>
#include "checker_common.h"
#include "checker.h"
#include "checker_functions.h"

int main() {
  // Test batterOk for success
  assert(batteryIsOk(25, 70, 0.7) == RET_SUCCESS);

  // Test batterOk for temperature failure, soc fail and chargeRate fail
  assert(batteryIsOk(50, 90, 0.9) == RET_TEMP_ERROR);
  // Test batterOk for temperature failure, soc fail and chargeRate success
  assert(batteryIsOk(50, 88, 0.3) == RET_TEMP_ERROR);
  // Test batterOk for temperature failure, soc success and chargeRate fail
  assert(batteryIsOk(50, 40, 1.2) == RET_TEMP_ERROR);
// Test batterOk for temperature failure, soc success and chargeRate success
  assert(batteryIsOk(50, 32, 0.6) == RET_TEMP_ERROR);

  // Test batterOk for temperature success, soc fail and chargeRate fail
  assert(batteryIsOk(30, 85, 1.8) == RET_SOC_ERROR);
  // Test batterOk for temperature success, soc fail and chargeRate success
  assert(batteryIsOk(30, 85, 0.4) == RET_SOC_ERROR);

  // Test batterOk for temperature and soc success, chargeRate fail
  assert(batteryIsOk(30, 43, 1) == RET_CHRG_RATE_ERROR);

  // Test temperature range for out of lower boundary
  assert(checkTemperatureRange(-0.1) == RET_TEMP_ERROR);
  // Test temperature range for lower boundary
  assert(checkTemperatureRange(0) == RET_SUCCESS);
  // Test temperature range for just in lower boundary
  assert(checkTemperatureRange(0.1) == RET_SUCCESS);
  // Test temperature range for within boundary
  assert(checkTemperatureRange(17.5) == RET_SUCCESS);
  // Test temperature range for just in upper boundary
  assert(checkTemperatureRange(44.9) == RET_SUCCESS);
  // Test temperature range for upper boundary
  assert(checkTemperatureRange(45) == RET_SUCCESS);
  // Test temperature range for out of upper boundary
  assert(checkTemperatureRange(45.1) == RET_TEMP_ERROR);

  // Test soc range for out of lower boundary
  assert(checkSocRange(19.9) == RET_SOC_ERROR);
  // Test soc range for lower boundary
  assert(checkSocRange(20) == RET_SUCCESS);
  // Test soc range for just in lower boundary
  assert(checkSocRange(20.1) == RET_SUCCESS);
  // Test soc range for within boundary
  assert(checkSocRange(60) == RET_SUCCESS);
  // Test soc range for just in upper boundary
  assert(checkSocRange(79.9) == RET_SUCCESS);
  // Test soc range for upper boundary
  assert(checkSocRange(80) == RET_SUCCESS);
  // Test soc range for out of upper boundary
  assert(checkSocRange(80.1) == RET_SOC_ERROR);

  // Test chargerRate range for well within boundary
  assert(checkChargeRateRange(0.1) == RET_SUCCESS);
  // Test chargerRate range for just in the boundary
  assert(checkChargeRateRange(0.79) == RET_SUCCESS);
  // Test chargerRate range for upper boundary
  assert(checkChargeRateRange(0.8) == RET_CHRG_RATE_ERROR);
  // Test chargerRate range for out of boundary
  assert(checkChargeRateRange(0.9) == RET_CHRG_RATE_ERROR);

  return 0;
}
