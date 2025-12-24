import { useCallback } from 'react';
import { RecyclerListNative } from '../native/RecyclerListNative';

// Reports real item size to native for refinement
export function useItemMeasurement(index: number) {
  return useCallback(
    (height: number) => {
      RecyclerListNative.onItemMeasured(index, height);
    },
    [index]
  );
}
