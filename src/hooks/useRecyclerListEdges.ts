import { useEffect } from 'react';
import { RecyclerListNative } from '../native/RecyclerListNative';

export function useRecyclerListEdges(
  itemCount: number,
  onEndReached?: () => void,
  onStartReached?: () => void
) {
  useEffect(() => {
    if (onEndReached && RecyclerListNative.shouldFireEndReached(itemCount)) {
      onEndReached();
    }

    if (onStartReached && RecyclerListNative.shouldFireStartReached()) {
      onStartReached();
    }
  });
}
