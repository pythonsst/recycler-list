#pragma once

#include <react/renderer/core/ConcreteComponentDescriptor.h>
#include "RecyclerListScrollViewShadowNode.h"

namespace facebook::react {

/**
 * Concrete ComponentDescriptor
 * REQUIRED for Fabric registration
 */
class RecyclerListScrollViewComponentDescriptor final
  : public ConcreteComponentDescriptor<RecyclerListScrollViewShadowNode> {
 public:
  using ConcreteComponentDescriptor::ConcreteComponentDescriptor;
};

} // namespace facebook::react
