#include "boolCast.h"
#include <stdio.h>
#include <string.h>

typedef enum TYPE_T
{
    EIGHT_BIT,
    SIXTEEN_BIT,
    THIRTY_TWO_BIT,
    SIXTY_FOUR_BIT
}TYPE;

/**
 * @brief main
 *  Test for a PC to understand the library
 * @return
 */
int main(void);

/**
 * @brief setFlags
 * @param flagData
 * @param shift
 */
void setFlags(uint8_t shift);

/**
 * @brief printFlags
 */
void printFlags(void);

union bool flags8;
union bool flags16;
union bool flags32;
union bool flags64;
int shift = 1;

int main(void)
{
    flags8.flags8_t = 0u;
    flags16.flags16_t = 0u;
    flags32.flags32_t = 0u;
    flags64.flags64_t = 0u;

    // Print before
    printFlags();

    for(shift; shift < 64; ++shift)
    {
        setFlags(shift);
        printFlags();
    }

    return 0;

}


void printBinary(uint8_t* bin, TYPE dataType)
{
    uint8_t n8 = 0;
    uint8_t n16 = 0;
    uint8_t n32 = 0;
    uint8_t n64 = 0;

    switch(dataType)
    {
    case EIGHT_BIT:
        n8 = *(uint8_t*)bin;
        printf("Hex Value 0x%02X ", n8);
        printf("8-Bit Flags:  ");
        for (uint32_t i = 1 << 8; i > 0; i = i / 2)
            (n8 & i)? printf("1"): printf("0");
        break;
    case SIXTEEN_BIT:
        n16 = *(uint16_t*)bin;
        printf("Hex Value 0x%04X ", n16);
        printf("16-Bit Flags: ");
        for (uint32_t i = 1 << 16; i > 0; i = i / 2)
            (n16 & i)? printf("1"): printf("0");
        break;
    case THIRTY_TWO_BIT:
        n32 = *(uint32_t*)bin;
        printf("Hex Value 0x%08X ", n32);
        printf("32-Bit Flags: ");
        for (uint32_t i = 1 << 32; i > 0; i = i / 2)
            (n32 & i)? printf("1"): printf("0");
        break;
    case SIXTY_FOUR_BIT:
        n64 = *(uint64_t*)bin;
        printf("Hex Value 0x%016X ", n64);
        printf("64-Bit Flags: ");
        for (uint64_t i = 1 << 64; i > 0; i = i / 2)
            (n64 & i)? printf("1"): printf("0");
        break;
    default:
        // Do nothing
        break;
    }
    printf("\n");
}

void printFlags(void)
{

    // Print out bits before
    uint8_t printBuf[8] = "";

    memcpy(printBuf, &flags8.flags8_t, 1);
    printBinary(printBuf, EIGHT_BIT);

    memcpy(printBuf, &flags16.flags16_t, 2);
    printBinary(printBuf, SIXTEEN_BIT);

    memcpy(printBuf, &flags16.flags32_t, 4);
    printBinary(printBuf, THIRTY_TWO_BIT);

    memcpy(printBuf, &flags16.flags64_t, 8);
    printBinary(printBuf, SIXTY_FOUR_BIT);
}

void setFlags(uint8_t shift)
{
    // Change Bits
    BC_SET_FLAG(flags8.flags8_t, shift);
    BC_SET_FLAG(flags16.flags16_t, shift);
    BC_SET_FLAG(flags32.flags32_t, shift);
    BC_SET_FLAG(flags64.flags64_t, shift);
}
