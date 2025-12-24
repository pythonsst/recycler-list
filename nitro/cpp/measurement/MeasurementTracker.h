#pragma once
#include <unordered_map>

// Tracks and refines estimated item height over time
class MeasurementTracker {
public:
  MeasurementTracker();

  void reportMeasurement(int index, double height);
  double getEstimatedItemHeight() const;

private:
  std::unordered_map<int, double> measurements;
  double runningAverage;
  int count;
};
