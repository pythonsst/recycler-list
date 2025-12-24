#pragma once
#include <react/renderer/components/view/ViewProps.h>

namespace facebook::react {

// Props passed from JS to native Fabric view
struct RecyclerListViewProps final : public ViewProps {
  RecyclerListViewProps() = default;
  RecyclerListViewProps(
    const PropsParserContext& context,
    const RecyclerListViewProps& sourceProps,
    const RawProps& rawProps
  ) : ViewProps(context, sourceProps, rawProps) {}
};

} // namespace facebook::react
