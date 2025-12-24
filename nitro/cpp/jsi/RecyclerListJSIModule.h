#pragma once
#include <nitromodules/NitroModule.h>
#include "../core/RecyclerListEngine.h"

class RecyclerListJSIModule : public NitroModule {
public:
  RecyclerListJSIModule();

  void setHorizontal(bool horizontal);
  std::vector<int> getVisibleSlotIds();
};
