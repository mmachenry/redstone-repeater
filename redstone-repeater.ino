#include <TrinketMouse.h>

void setup() {
  TrinketMouse.begin();
}

void loop() {
  TrinketMouse.move(0, 0, 0, MOUSEBTN_RIGHT_MASK);
  pollDelay(400);
}

// According to USB protocols, a mouse or keyboard must communicate
// with the computer every 10 miliseconds or it will be considered
// disconnected. In order to comply with this, the move function must
// be called at least once every 10 ms, but with all zero arguments
// so that it does nothing. Any usage of Arduino's built-in delay()
// should probably be replaced with this function when using the
// TrinketMouse library.
void pollDelay (int milliseconds) {
  int pollFrequency = 10;
  for (int i = 0; i < milliseconds / pollFrequency; i++) {
    delay(pollFrequency);
    TrinketMouse.move(0, 0, 0, 0);
  }
  delay(milliseconds % pollFrequency);
  TrinketMouse.move(0, 0, 0, 0);
}

