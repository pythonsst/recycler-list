#pragma once

// Tracks which header should currently be pinned
struct StickyHeaderState {
  int pinnedHeaderIndex = -1;   // logical index of pinned header
  int pinnedSlotId = -1;        // physical slot ID
};
