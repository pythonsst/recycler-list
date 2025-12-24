#pragma once
#include "../windowing/WindowCalculator.h"
#include "../layout/LayoutMetrics.h"
#include "../measurement/MeasurementTracker.h"
#include "../headers/ItemKind.h"
#include "../sticky/StickyHeaderState.h"
#include "../sticky/StickyHeaderCalculator.h"
#include "../inversion/InversionConfig.h"
#include "../orientation/ListOrientation.h"
#include "Recycler.h"

class RecyclerListEngine {
public:
  RecyclerListEngine();

  void onScroll(double offset);
  void onItemMeasured(int index, double size);

  void setItemKinds(const std::vector<ItemKind>& kinds);
  void setInverted(bool inverted);
  void setHorizontal(bool horizontal);

  std::vector<ViewSlot> getVisibleSlots();
  int getPinnedHeaderSlotId();

private:
  Recycler recycler;
  WindowCalculator windowCalculator;
  MeasurementTracker measurementTracker;
  StickyHeaderCalculator stickyCalculator;
  StickyHeaderState stickyState;
  InversionConfig inversion;
  LayoutMetrics layout;

  std::vector<ItemKind> itemKinds;
  double lastScrollOffset;
};
