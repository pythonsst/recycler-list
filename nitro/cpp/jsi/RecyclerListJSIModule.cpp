#include "RecyclerListJSIModule.h"

static RecyclerListEngine engine;

RecyclerListJSIModule::RecyclerListJSIModule()
  : NitroModule("RecyclerList") {}

void RecyclerListJSIModule::setHorizontal(bool horizontal) {
  engine.setHorizontal(horizontal);
}

std::vector<int> RecyclerListJSIModule::getVisibleSlotIds() {
  auto slots = engine.getVisibleSlots();
  std::vector<int> ids;
  for (auto& slot : slots) {
    ids.push_back(slot.slotId);
  }
  return ids;
}
