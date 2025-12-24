import type * as React from 'react';

export type RecyclerListRenderItem<T> = (info: {
  item: T;
  index: number;
}) => React.ReactElement | null;
