#include <assert.h>
#include "checker.h"

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));

  return 0;
}
