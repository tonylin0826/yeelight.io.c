# yeelight.io.c

C Implementation for controlling Xiao Mi Yeelight.

# Usage
```c
#include <stdio.h>
#include "yeelight.h"

int main() {
  toggle("192.168.1.157");
  on("192.168.1.157");
  off("192.168.1.157");
  brightness("192.168.1.157", 100);
  color("192.168.1.157", 255, 0, 0);
  return 0;
}
```

# License
MIT