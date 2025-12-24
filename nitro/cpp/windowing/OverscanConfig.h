#pragma once

// Controls how much extra content is rendered outside viewport
struct OverscanConfig {
  int before; // items before visible window
  int after;  // items after visible window
};
