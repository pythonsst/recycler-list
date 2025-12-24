#pragma once
#include <react/renderer/components/view/ViewComponentDescriptor.h>
#include "RecyclerListShadowNode.h"

namespace facebook::react {

// Registers RecyclerList with Fabric
using RecyclerListComponentDescriptor =
  ViewComponentDescriptor<RecyclerListShadowNode>;

} // namespace facebook::react
