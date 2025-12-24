#include "Recycler.h"

Recycler::Recycler() : nextSlotId(0) {}

ViewSlot Recycler::acquireSlot(int index, ItemKind kind) {
  auto& pool =
    (kind == ItemKind::Header)
      ? recycledHeaders
      : recycledRows;

  if (!pool.empty()) {
    ViewSlot slot = pool.back();
    pool.pop_back();
    slot.boundIndex = index;
    slot.kind = kind;
    slot.attached = true;
    return slot;
  }

  return ViewSlot{
    nextSlotId++,
    index,
    kind,
    true
  };
}

void Recycler::recycleSlot(const ViewSlot& slot) {
  ViewSlot recycled = slot;
  recycled.attached = false;

  if (slot.kind == ItemKind::Header) {
    recycledHeaders.push_back(recycled);
  } else {
    recycledRows.push_back(recycled);
  }
}

std::vector<ViewSlot> Recycler::reconcile(
  int firstIndex,
  int lastIndex,
  const std::vector<ItemKind>& kinds
) {
  std::unordered_map<int, ViewSlot> nextActive;
  std::vector<ViewSlot> result;

  for (int i = firstIndex; i <= lastIndex; i++) {
    auto it = activeByIndex.find(i);
    if (it != activeByIndex.end()) {
      nextActive[i] = it->second;
      result.push_back(it->second);
    } else {
      ViewSlot slot = acquireSlot(i, kinds[i]);
      nextActive[i] = slot;
      result.push_back(slot);
    }
  }

  for (auto& pair : activeByIndex) {
    int index = pair.first;
    if (index < firstIndex || index > lastIndex) {
      recycleSlot(pair.second);
    }
  }

  activeByIndex = nextActive;
  return result;
}
