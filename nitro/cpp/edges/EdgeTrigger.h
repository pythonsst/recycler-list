#pragma once

// Tracks whether edge callbacks have fired
struct EdgeTrigger {
  bool startReached = false;
  bool endReached = false;
};
