#include <assert.h>
#include "bms_common.h"
#include "checker.h"
#include "checker_functions.h"
#include "bms_io.h"

int main() {
  int enableWarning[BMS_MAX_PARAMTERS] = {1, 1, 1};
  assert(checkerInit(ENGLISH, enableWarning) == 0);
  
  // Test batterOk for success
  assert(batteryIsOk(25, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(-3.5, 43, 0.4, printMessage) == 0);
  assert(batteryIsOk(0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.1, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(5.0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(40.0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(44.9, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(45.0, 70, 0.7, printMessage) == 0);
  assert(batteryIsOk(47.0, 70, 0.7, printMessage) == 0);

  assert(batteryIsOk(25, -10, 0.7, printMessage) == 0);
  assert(batteryIsOk(2, 19.9, 0.4, printMessage) == 0);
  assert(batteryIsOk(42, 20, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.1, 20.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(5.0, 24.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(40.0, 25, 0.7, printMessage) == 1);
  assert(batteryIsOk(44.9, 25.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(40, 74.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 75, 0.7, printMessage) == 1);
  assert(batteryIsOk(40, 75.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 79.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 80, 0.7, printMessage) == 0);
  assert(batteryIsOk(0.7, 80.1, 0.7, printMessage) == 0);

  assert(batteryIsOk(25, 21, -0.7, printMessage) == 1);
  assert(batteryIsOk(2, 22, 0.74, printMessage) == 1);
  assert(batteryIsOk(42, 20.2, 0.75, printMessage) == 1);
  assert(batteryIsOk(0.1, 20.1, 0.76, printMessage) == 1);
  assert(batteryIsOk(5.0, 24.9, 0.79, printMessage) == 1);
  assert(batteryIsOk(40.0, 25, 0.8, printMessage) == 0);
  assert(batteryIsOk(44.9, 25.1, 0.81, printMessage) == 0);
  assert(batteryIsOk(40, 74.9, 0.85, printMessage) == 0);

  assert(checkerInit(GERMAN, enableWarning) == 0);
  
  // Test batterOk for success
  assert(batteryIsOk(25, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(-3.5, 43, 0.4, printMessage) == 0);
  assert(batteryIsOk(0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.1, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(5.0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(40.0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(44.9, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(45.0, 70, 0.7, printMessage) == 0);
  assert(batteryIsOk(47.0, 70, 0.7, printMessage) == 0);

  // Test batterOk for success
  assert(batteryIsOk(25, -10, 0.7, printMessage) == 0);
  assert(batteryIsOk(2, 19.9, 0.4, printMessage) == 0);
  assert(batteryIsOk(45, 20, 0.7, printMessage) == 0);
  assert(batteryIsOk(0.1, 20.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(5.0, 24.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(40.0, 25, 0.7, printMessage) == 1);
  assert(batteryIsOk(44.9, 25.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(40, 74.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 75, 0.7, printMessage) == 1);
  assert(batteryIsOk(40, 75.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 79.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 80, 0.7, printMessage) == 0);
  assert(batteryIsOk(0.7, 80.1, 0.7, printMessage) == 0);

  assert(batteryIsOk(25, 21, -0.7, printMessage) == 1);
  assert(batteryIsOk(2, 22, 0.74, printMessage) == 1);
  assert(batteryIsOk(42, 20.2, 0.75, printMessage) == 1);
  assert(batteryIsOk(0.1, 20.1, 0.76, printMessage) == 1);
  assert(batteryIsOk(5.0, 24.9, 0.79, printMessage) == 1);
  assert(batteryIsOk(40.0, 25, 0.8, printMessage) == 0);
  assert(batteryIsOk(44.9, 25.1, 0.81, printMessage) == 0);
  assert(batteryIsOk(40, 74.9, 0.85, printMessage) == 0);

  enableWarning[BMS_TEMPERATURE] = 0;
  enableWarning[BMS_SOC] = 0;
  enableWarning[BMS_CHARGE_RATE] = 0;
  
  assert(checkerInit(ENGLISH, enableWarning) == 0);
  
  // Test batterOk for success
  assert(batteryIsOk(25, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(-3.5, 43, 0.4, printMessage) == 0);
  assert(batteryIsOk(0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.1, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(5.0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(40.0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(44.9, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(45.0, 70, 0.7, printMessage) == 0);
  assert(batteryIsOk(47.0, 70, 0.7, printMessage) == 0);

  assert(batteryIsOk(25, -10, 0.7, printMessage) == 0);
  assert(batteryIsOk(2, 19.9, 0.4, printMessage) == 0);
  assert(batteryIsOk(42, 20, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.1, 20.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(5.0, 24.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(40.0, 25, 0.7, printMessage) == 1);
  assert(batteryIsOk(44.9, 25.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(40, 74.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 75, 0.7, printMessage) == 1);
  assert(batteryIsOk(40, 75.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 79.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 80, 0.7, printMessage) == 0);
  assert(batteryIsOk(0.7, 80.1, 0.7, printMessage) == 0);

  assert(batteryIsOk(25, 21, -0.7, printMessage) == 1);
  assert(batteryIsOk(2, 22, 0.74, printMessage) == 1);
  assert(batteryIsOk(42, 20.2, 0.75, printMessage) == 1);
  assert(batteryIsOk(0.1, 20.1, 0.76, printMessage) == 1);
  assert(batteryIsOk(5.0, 24.9, 0.79, printMessage) == 1);
  assert(batteryIsOk(40.0, 25, 0.8, printMessage) == 0);
  assert(batteryIsOk(44.9, 25.1, 0.81, printMessage) == 0);
  assert(batteryIsOk(40, 74.9, 0.85, printMessage) == 0);

  assert(checkerInit(GERMAN, enableWarning) == 0);
  
  // Test batterOk for success
  assert(batteryIsOk(25, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(-3.5, 43, 0.4, printMessage) == 0);
  assert(batteryIsOk(0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.1, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(5.0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(40.0, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(44.9, 70, 0.7, printMessage) == 1);
  assert(batteryIsOk(45.0, 70, 0.7, printMessage) == 0);
  assert(batteryIsOk(47.0, 70, 0.7, printMessage) == 0);

  // Test batterOk for success
  assert(batteryIsOk(25, -10, 0.7, printMessage) == 0);
  assert(batteryIsOk(2, 19.9, 0.4, printMessage) == 0);
  assert(batteryIsOk(45, 20, 0.7, printMessage) == 0);
  assert(batteryIsOk(0.1, 20.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(5.0, 24.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(40.0, 25, 0.7, printMessage) == 1);
  assert(batteryIsOk(44.9, 25.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(40, 74.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 75, 0.7, printMessage) == 1);
  assert(batteryIsOk(40, 75.1, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 79.9, 0.7, printMessage) == 1);
  assert(batteryIsOk(0.7, 80, 0.7, printMessage) == 0);
  assert(batteryIsOk(0.7, 80.1, 0.7, printMessage) == 0);

  assert(batteryIsOk(25, 21, -0.7, printMessage) == 1);
  assert(batteryIsOk(2, 22, 0.74, printMessage) == 1);
  assert(batteryIsOk(42, 20.2, 0.75, printMessage) == 1);
  assert(batteryIsOk(0.1, 20.1, 0.76, printMessage) == 1);
  assert(batteryIsOk(5.0, 24.9, 0.79, printMessage) == 1);
  assert(batteryIsOk(40.0, 25, 0.8, printMessage) == 0);
  assert(batteryIsOk(44.9, 25.1, 0.81, printMessage) == 0);
  assert(batteryIsOk(40, 74.9, 0.85, printMessage) == 0);
  return 0;
}
