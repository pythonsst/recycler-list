#pragma once
#include <vector>
#include "../headers/ItemKind.h"

// Determines which header should be sticky
class StickyHeaderCalculator {
public:
  int computePinnedHeader(
    int firstVisibleIndex,
    const std::vector<ItemKind>& kinds
  );
};
