#pragma once
#include "VisibleWindow.h"
#include "OverscanConfig.h"
#include "../orientation/ListOrientation.h"

// Converts scroll offset into visible indices along chosen axis
class WindowCalculator {
public:
  WindowCalculator();

  VisibleWindow compute(
    double scrollOffset,
    double viewportSize,
    double estimatedItemSize,
    ListOrientation orientation
  );

private:
  OverscanConfig overscan;
};
