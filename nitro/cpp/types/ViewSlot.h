#pragma once
#include "../headers/ItemKind.h"

// A physical reusable view slot
struct ViewSlot {
  int slotId;            // Stable physical identity
  int boundIndex;        // Logical data index
  ItemKind kind;         // Row or Header
  bool attached;
};
