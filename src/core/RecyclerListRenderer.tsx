import { View, StyleSheet } from 'react-native';

interface Slot {
  slotId: number;
  index: number;
}

interface RendererProps<T> {
  data: readonly T[];
  slots: readonly Slot[];
  renderItem: (info: { item: T; index: number }) => React.ReactElement | null;
  estimatedItemSize: number;
}

export function RecyclerListRenderer<T>({
  data,
  slots,
  renderItem,
  estimatedItemSize,
}: RendererProps<T>) {
  return (
    <>
      {slots.map(({ slotId, index }) => {
        const item = data[index];

        // 🔒 HARD GUARANTEE FOR TYPE SAFETY
        if (item === undefined) {
          return null;
        }

        return (
          <View
            key={slotId}
            style={[styles.itemContainer, { top: index * estimatedItemSize }]}
          >
            {renderItem({ item, index })}
          </View>
        );
      })}
    </>
  );
}

const styles = StyleSheet.create({
  itemContainer: {
    position: 'absolute',
    left: 0,
    right: 0,
  },
});
