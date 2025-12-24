import { View, Text, StyleSheet } from 'react-native';
import { useRecyclerListVisibleIndices } from './hooks/useRecyclerListVisibleIndices';
import type { RecyclerListProps } from './types/RecyclerListProps';
import NativeRecyclerListScrollView from './fabric/NativeRecyclerListScrollView';
import { RecyclerListRenderer } from './core/RecyclerListRenderer';

export function RecyclerList<T>({
  data,
  renderItem,
  estimatedItemSize,
}: RecyclerListProps<T>) {
  const { slots } = useRecyclerListVisibleIndices();
  const itemSize = estimatedItemSize ?? 50;

  return (
    <View style={styles.container}>
      <Text style={styles.debugLabel}>RecyclerList mounted</Text>

      <NativeRecyclerListScrollView style={styles.scrollView}>
        <View style={{ height: data.length * itemSize }}>
          <RecyclerListRenderer
            data={data}
            slots={slots}
            estimatedItemSize={itemSize}
            renderItem={renderItem}
          />
        </View>
      </NativeRecyclerListScrollView>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: 'yellow',
  },
  debugLabel: {
    position: 'absolute',
    top: 100,
    left: 20,
    zIndex: 999,
  },
  scrollView: {
    flex: 1,
  },
});
