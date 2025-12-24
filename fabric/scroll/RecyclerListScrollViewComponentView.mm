#import "RecyclerListScrollViewComponentView.h"

#import <react/renderer/components/recyclerlist/ComponentDescriptors.h>
#import <react/renderer/components/recyclerlist/Props.h>
#import <react/renderer/components/scrollview/RCTScrollViewComponentView.h>

using namespace facebook::react;

@implementation RecyclerListScrollViewComponentView {
  RCTScrollViewComponentView *_scrollView;
}

- (instancetype)initWithFrame:(CGRect)frame
{
  if (self = [super initWithFrame:frame]) {
    _scrollView = [[RCTScrollViewComponentView alloc] initWithFrame:frame];
    _scrollView.autoresizingMask =
      UIViewAutoresizingFlexibleWidth |
      UIViewAutoresizingFlexibleHeight;
    [self addSubview:_scrollView];
  }
  return self;
}

- (void)updateProps:(const Props::Shared &)props
           oldProps:(const Props::Shared &)oldProps
{
  [super updateProps:props oldProps:oldProps];
  [_scrollView updateProps:props oldProps:oldProps];
}

+ (ComponentDescriptorProvider)componentDescriptorProvider
{
  return concreteComponentDescriptorProvider<
    RecyclerListScrollViewComponentDescriptor
  >();
}

@end
