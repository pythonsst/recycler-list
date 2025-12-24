import { useEffect, useState } from 'react';

// Hook that will later read visible slots from native
export function useRecyclerListSlots() {
  const [slots, setSlots] = useState<number[]>([]);

  useEffect(() => {
    // Placeholder: native will push slot updates later
    setSlots([]);
  }, []);

  return slots;
}
