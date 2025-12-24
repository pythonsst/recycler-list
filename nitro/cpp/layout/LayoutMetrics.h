#pragma once
#include "../orientation/ListOrientation.h"

// Tracks layout-related measurements
struct LayoutMetrics {
  double estimatedItemSize;
  double viewportSize;
  ListOrientation orientation = ListOrientation::Vertical;
};
