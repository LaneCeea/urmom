# urmom

urmom

### what

basically the following but with maximum care to detail
```c
#include <stdio.h>
int main() {
  long x = 470020878965;
  puts((void*)&x);
  return 0;
}
```

### inspiration
watch [Mults' video](https://youtu.be/sm_ecfMeTno?si=CIav1egVEsVJl1LJ)

## actual detail
1. `long` is bad here. The C Standard only requires `long` to be at least 32 bits, but we need more than that to store the value `470020878965`. This issue is mentioned in Mults' video, but it does not present a solution. When working with integers with expectation of any specific size, one should always use the type `(u)intN_t` defined in `<stdint.h>`. In this case, `(u)int64_t` is prefered.

2. According to [this](https://en.cppreference.com/w/c/language/object.html) cppreference page, type punning (reinterpreting the data of one type to a different type) is generally not allowed due to the rule of strict aliasing. In this case though, aliasing through a character type is permitted. We take the address of this integer, and dereference it as a string of character, which is `"urmom\0\0\0"` on a little-endian architecture. The project provides several proper and readable ways to do this.
