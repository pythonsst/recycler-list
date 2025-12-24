#include "WindowCalculator.h"
#include <cmath>

WindowCalculator::WindowCalculator() {
  overscan.before = 5;
  overscan.after = 10;
}

VisibleWindow WindowCalculator::compute(
  double scrollOffset,
  double viewportSize,
  double estimatedItemSize,
  ListOrientation
) {
  int firstVisible =
    std::floor(scrollOffset / estimatedItemSize);

  int visibleCount =
    std::ceil(viewportSize / estimatedItemSize);

  int start =
    std::max(0, firstVisible - overscan.before);

  int end =
    firstVisible + visibleCount + overscan.after;

  return { start, end };
}
