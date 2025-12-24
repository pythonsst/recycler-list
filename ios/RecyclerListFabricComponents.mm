#import <react/renderer/core/ComponentDescriptorProvider.h>
#import "RecyclerListScrollViewComponentDescriptor.h"

using namespace facebook::react;

std::vector<ComponentDescriptorProvider>
RecyclerListComponentDescriptors() {
  return {
    concreteComponentDescriptorProvider<
      RecyclerListScrollViewComponentDescriptor
    >(),
  };
}
