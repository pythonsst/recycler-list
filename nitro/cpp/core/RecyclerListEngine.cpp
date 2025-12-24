#include "RecyclerListEngine.h"

RecyclerListEngine::RecyclerListEngine() {
  layout.estimatedItemSize = 80;
  layout.viewportSize = 600;
  layout.orientation = ListOrientation::Vertical;
  lastScrollOffset = 0;
}

void RecyclerListEngine::setHorizontal(bool horizontal) {
  layout.orientation =
    horizontal
      ? ListOrientation::Horizontal
      : ListOrientation::Vertical;
}

void RecyclerListEngine::setItemKinds(
  const std::vector<ItemKind>& kinds
) {
  itemKinds = kinds;
}

void RecyclerListEngine::setInverted(bool inverted) {
  inversion.enabled = inverted;
}

void RecyclerListEngine::onScroll(double offset) {
  lastScrollOffset = offset;
}

void RecyclerListEngine::onItemMeasured(int index, double size) {
  measurementTracker.reportMeasurement(index, size);
  layout.estimatedItemSize =
    measurementTracker.getEstimatedItemHeight();
}

std::vector<ViewSlot> RecyclerListEngine::getVisibleSlots() {
  double effectiveOffset = lastScrollOffset;

  if (inversion.enabled) {
    effectiveOffset =
      std::max(0.0, layout.viewportSize - lastScrollOffset);
  }

  auto window = windowCalculator.compute(
    effectiveOffset,
    layout.viewportSize,
    layout.estimatedItemSize,
    layout.orientation
  );

  auto slots = recycler.reconcile(
    window.firstIndex,
    window.lastIndex,
    itemKinds
  );

  int pinnedIndex =
    stickyCalculator.computePinnedHeader(
      window.firstIndex,
      itemKinds
    );

  if (pinnedIndex >= 0) {
    for (auto& slot : slots) {
      if (slot.boundIndex == pinnedIndex) {
        stickyState.pinnedSlotId = slot.slotId;
        break;
      }
    }
  }

  return slots;
}

int RecyclerListEngine::getPinnedHeaderSlotId() {
  return stickyState.pinnedSlotId;
}
