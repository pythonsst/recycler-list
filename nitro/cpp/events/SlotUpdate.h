#pragma once
#include <vector>

// Payload sent from native to JS describing visible indices
struct SlotUpdate {
  std::vector<int> visibleIndices;
};
