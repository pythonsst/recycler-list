#pragma once

#include <react/renderer/components/view/ViewProps.h>

namespace facebook::react {

/**
 * Props for RecyclerListScrollView
 * Keep minimal initially
 */
struct RecyclerListScrollViewProps final : public ViewProps {
  RecyclerListScrollViewProps() = default;

  RecyclerListScrollViewProps(
    const PropsParserContext& context,
    const RecyclerListScrollViewProps& sourceProps,
    const RawProps& rawProps
  ) : ViewProps(context, sourceProps, rawProps) {}
};

} // namespace facebook::react
