import { getHostComponent } from 'react-native-nitro-modules';
const RecyclerlistConfig = require('../nitrogen/generated/shared/json/RecyclerlistConfig.json');
import type {
  RecyclerlistMethods,
  RecyclerlistProps,
} from './Recyclerlist.nitro';

export const RecyclerlistView = getHostComponent<
  RecyclerlistProps,
  RecyclerlistMethods
>('Recyclerlist', () => RecyclerlistConfig);
