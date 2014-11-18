Arduino-Debounce
================

Button debounce library for Arduino. This library does not use interrupts so it needs to be 'checked' every loop.

Usage
----------------
```
#include <Debounce.h>
// declare global variable
Debounce debounced(pin, delay_ms);

void loop(){
...
// poll every loop cycle
int val = debounced.state();

}
```
