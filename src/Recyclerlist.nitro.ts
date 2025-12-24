import type {
  HybridView,
  HybridViewMethods,
  HybridViewProps,
} from 'react-native-nitro-modules';

export interface RecyclerlistProps extends HybridViewProps {
  color: string;
}
export interface RecyclerlistMethods extends HybridViewMethods {}

export type Recyclerlist = HybridView<
  RecyclerlistProps,
  RecyclerlistMethods
>;
