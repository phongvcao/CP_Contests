#include <stdio.h>
#include <stdint.h>
#include <string.h>

void memcpynew(void* dest, void* src, int size) {
    // Copy memory byte-by-byte
    uint8_t *pDest = (uint8_t*)dest;
    uint8_t *pSrc = (uint8_t*)src;

    int loops = size / sizeof(uint32_t);

    int i = 0;
    for (i = 0; i != loops; ++i) {
        *((uint32_t*)pDest) = *((uint32_t*)pSrc);
        pDest += sizeof(uint32_t);
        pSrc += sizeof(uint32_t);
    }

    loops = size % sizeof(uint32_t);
    for (i = 0; i != loops; ++i) {
        *pDest = *pSrc;
        ++pDest;
        ++pSrc;
    }
}


void memmovenew(void* dest, void* src, int size) {
    uint8_t *pDest = (uint8_t*)dest;
    uint8_t *pSrc = (uint8_t*)src;

    int quotientLoops = size / sizeof(uint32_t);
    int remainderLoops = size % sizeof(uint32_t);

    int i = 0;

    // Copy forward
    if ((uint8_t*)dest < (uint8_t*)src) {
        for (i = 0; i != quotientLoops; ++i) {
            *((uint32_t*)pDest) = *((uint32_t*)pSrc);
            pDest += sizeof(uint32_t);
            pSrc += sizeof(uint32_t);
        }

        for (i = 0; i != remainderLoops; ++i) {
            *pDest = *pSrc;
            ++pDest;
            ++pSrc;
        }
    }

    // Copy backward
    else {
        pSrc = pSrc + size - 1;
        pDest = pDest + size - 1;

        for (i = 0; i != quotientLoops; ++i) {
            *((uint32_t*)pDest) = *((uint32_t*)pSrc);
            pDest -= sizeof(uint32_t);
            pSrc -= sizeof(uint32_t);
        }

        for (i = 0; i != remainderLoops; ++i) {
            *pDest = *pSrc;
            --pDest;
            --pSrc;
        }
    }
}


int main(int argc, char *argv) {
    int intArr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int intArr2[15];

    memcpynew(intArr2, intArr1, sizeof(intArr1));

    int i = 0;
    for (i = 0; i != sizeof(intArr1)/sizeof(int); ++i) {
        printf("%d ", intArr2[i]);
    }
    printf("\n");


    int intArr3[15];

    memcpy(intArr3, intArr1, sizeof(intArr1));
    for (i = 0; i != sizeof(intArr1)/sizeof(int); ++i) {
        printf("%d ", intArr3[i]);
    }
    printf("\n");

    int intArr4[15];
    int intArr5[15];

    memcpy(intArr4, intArr1, sizeof(intArr1));
    memcpy(intArr5, intArr1, sizeof(intArr1));


    memmovenew(intArr2, intArr2 + 5, 5);
    memmovenew(intArr3 + 5, intArr3, 5);

    for (i = 0; i != sizeof(intArr2)/sizeof(int); ++i) {
        printf("%d ", intArr2[i]);
    }
    printf("\n");

    for (i = 0; i != sizeof(intArr3)/sizeof(int); ++i) {
        printf("%d ", intArr3[i]);
    }
    printf("\n");

    memmove(intArr4, intArr4 + 5, 5);
    memmove(intArr5 + 5, intArr5, 5);

    for (i = 0; i != sizeof(intArr4)/sizeof(int); ++i) {
        printf("%d ", intArr4[i]);
    }
    printf("\n");

    for (i = 0; i != sizeof(intArr5)/sizeof(int); ++i) {
        printf("%d ", intArr5[i]);
    }
    printf("\n");


    return 0;
}
