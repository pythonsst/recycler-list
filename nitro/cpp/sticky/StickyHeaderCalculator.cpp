#include "StickyHeaderCalculator.h"

// Find the closest header at or before first visible item
int StickyHeaderCalculator::computePinnedHeader(
  int firstVisibleIndex,
  const std::vector<ItemKind>& kinds
) {
  for (int i = firstVisibleIndex; i >= 0; i--) {
    if (kinds[i] == ItemKind::Header) {
      return i;
    }
  }
  return -1;
}
