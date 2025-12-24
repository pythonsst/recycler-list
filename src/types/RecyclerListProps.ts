import type * as React from 'react';

export interface RecyclerListProps<T = any> {
  data: readonly T[];

  renderItem: (info: { item: T; index: number }) => React.ReactElement | null;

  estimatedItemSize: number;

  horizontal?: boolean;
  inverted?: boolean;
}
