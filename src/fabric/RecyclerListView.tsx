import { requireNativeComponent } from 'react-native';

// Typed wrapper so DTS generation is stable
type RecyclerListViewNativeProps = Record<string, never>;

export const NativeRecyclerListView =
  requireNativeComponent<RecyclerListViewNativeProps>('RecyclerListView');
