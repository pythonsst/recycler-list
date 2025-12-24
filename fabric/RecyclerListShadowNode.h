#pragma once
#include <react/renderer/components/view/ViewShadowNode.h>

namespace facebook::react {

// ShadowNode represents RecyclerList in Fabric tree
class RecyclerListShadowNode final : public ViewShadowNode {
public:
  using ViewShadowNode::ViewShadowNode;
};

} // namespace facebook::react
