#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define URMOM 0x6D6F6D7275ull

static void urmom1(void) {
    const uint64_t urmom = URMOM;
    printf("%.5s\n", (unsigned char*)&urmom);
}

static void urmom2(void) {
    union byte8_t {
        uint64_t as_uint;
        unsigned char as_str[8];
    };
    const union byte8_t urmom = { .as_uint = URMOM };
    printf("%.5s\n", urmom.as_str);
}

static void urmom3(void) {
    const uint64_t urmom = URMOM;
    unsigned char to_str[8] = { 0 };
    memcpy(to_str, &urmom, sizeof(unsigned char) * 8);
    printf("%.5s\n", to_str);
}

static void urmom4(void) {
    const uint64_t urmom = URMOM;
    fwrite(&urmom, sizeof(unsigned char), 5, stdout);
    putchar('\n');
}

int main(void) {
    urmom1();
    urmom2();
    urmom3();
    urmom4();
    return 0;
}
