import { NitroModules } from 'react-native-nitro-modules';

/**
 * 🔒 PUBLIC NATIVE CONTRACT
 * This MUST be exported so bob uses it for DTS
 */
export interface RecyclerListNativeSpec {
  // scrolling
  onScroll(offset: number): void;
  setHorizontal(horizontal: boolean): void;
  setInverted(inverted: boolean): void;

  // measurement
  onItemMeasured(index: number, height: number): void;

  // edges
  shouldFireEndReached(itemCount: number): boolean;
  shouldFireStartReached(): boolean;

  // slots
  getVisibleSlotIds(): number[];
}

/**
 * 🔒 INTERNAL VALUE (intentionally untyped at runtime)
 */
const NativeModule = NitroModules as unknown as {
  RecyclerList: unknown;
};

/**
 * 🔒 EXPLICITLY TYPE THE EXPORT
 * This prevents bob from narrowing the type
 */
export const RecyclerListNative: RecyclerListNativeSpec =
  NativeModule.RecyclerList as RecyclerListNativeSpec;
