import type { HostComponent, ViewProps } from 'react-native';
import type { DirectEventHandler } from 'react-native/Libraries/Types/CodegenTypes';
import { codegenNativeComponent } from 'react-native';

export interface NativeProps extends ViewProps {
  children?: React.ReactNode; // ✅ REQUIRED

  horizontal?: boolean;
  inverted?: boolean;
  scrollEventThrottle?: number;

  onScroll?: DirectEventHandler<{
    contentOffset: {
      x: number;
      y: number;
    };
  }>;
}

export default codegenNativeComponent<NativeProps>(
  'RecyclerListScrollView'
) as HostComponent<NativeProps>;
