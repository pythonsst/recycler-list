#include "MeasurementTracker.h"

MeasurementTracker::MeasurementTracker()
  : runningAverage(80.0), count(0) {}

void MeasurementTracker::reportMeasurement(int, double height) {
  // Incremental average (stable + cheap)
  runningAverage =
    (runningAverage * count + height) / (count + 1);
  count++;
}

double MeasurementTracker::getEstimatedItemHeight() const {
  return runningAverage;
}
