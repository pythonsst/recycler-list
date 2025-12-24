import { Text, View, StyleSheet } from 'react-native';
import { SafeAreaView } from 'react-native-safe-area-context';
import { RecyclerList } from '../src/RecyclerList';

const DATA = Array.from({ length: 10_000 }, (_, i) => ({
  id: i,
  title: `Row ${i}`,
}));

function Row({ title }: { title: string }) {
  return (
    <View style={styles.row}>
      <Text>{title}</Text>
    </View>
  );
}

export default function App() {
  return (
    <SafeAreaView style={styles.container}>
      <RecyclerList
        data={DATA}
        estimatedItemSize={48}
        renderItem={({ item }) => <Row title={item.title} />}
      />
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  row: {
    height: 48,
    justifyContent: 'center',
    paddingHorizontal: 16,
    borderBottomWidth: StyleSheet.hairlineWidth,
  },
});
