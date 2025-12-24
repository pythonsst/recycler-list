#pragma once
#include <vector>
#include <unordered_map>
#include "../types/ViewSlot.h"

// Recycler with header-aware reuse
class Recycler {
public:
  Recycler();

  std::vector<ViewSlot> reconcile(
    int firstIndex,
    int lastIndex,
    const std::vector<ItemKind>& kinds
  );

private:
  int nextSlotId;

  std::unordered_map<int, ViewSlot> activeByIndex;
  std::vector<ViewSlot> recycledRows;
  std::vector<ViewSlot> recycledHeaders;

  ViewSlot acquireSlot(int index, ItemKind kind);
  void recycleSlot(const ViewSlot& slot);
};
