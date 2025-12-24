import type { HostComponent, ViewProps } from 'react-native';
import { codegenNativeComponent } from 'react-native';

export interface NativeProps extends ViewProps {
  horizontal?: boolean;
  inverted?: boolean;
}

export default codegenNativeComponent<NativeProps>(
  'RecyclerListScrollView'
) as HostComponent<NativeProps>;
