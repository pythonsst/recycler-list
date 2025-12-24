#pragma once

#include <react/renderer/components/view/ViewShadowNode.h>

namespace facebook::react {

/**
 * ShadowNode for RecyclerListScrollView
 */
class RecyclerListScrollViewShadowNode final : public ViewShadowNode {
 public:
  using ViewShadowNode::ViewShadowNode;
};

} // namespace facebook::react
