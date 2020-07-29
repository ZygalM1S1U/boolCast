# boolCast
Type #include "boolCast.h" to use Booleans in the N64 library, but as bits, rather than bytes.
The N64 is rather precious when it comes to memory and saving space and time by using bits is desired.
These are build notes for 1.0.6

This library is intended to be used with the branchless programming technique which generally plays nicer with RISC systems.
Sometimes, pipeline hazards (structural, or data) which can potentially manifest as pipeline stalls, can occur through branch instruction sequences that the compiler cannot avoid.
These bubbles can be avoided by using arithmetic instructions instead.  Using bits not only saves memory, but also in most cases, speeds up the logic.

# CAUTION
This library is aimed to be used with the N64, on a MIPS 64 system.  The C99 Standard is not defined, so the type names will not conflict.
Make sure that there are no conflicting name types for the name "bool".

### Prerequisites
Unless you want to build the test file, there is nothing you need.
If you want to try it out on the PC first, GCC and make are required.

### Getting Started
Make sure to have this in the include chain of your program
```c
#include "boolCast.h"
```
This will include the library of boolCast.  No building is needed to use this library.

To use this in your N64 source:
Create an instance of "bool" in your program.
```c

bool flags32;
```
There are 3 types that the bool can take on, an 8-bit type, 16-bit type, 32-bit type, and a 64-bit type
Only **ONE** type can be used per instance at a time, so one instance can be either 8, 16, 32, or 64 bit; however,
make sure to only use one at a time.  Declare another instance if more are needed.
```c
flags32.flags32_t = 0u;
```
To set a bit, use the 
```c 
BC_SET_FLAG(FLAG, POS)
``` 
macro.
The first argument is the bool definition, second is the position of the bit to set
Let's say we want to set the 32nd bit in the 32 bit flag data type.
```c
 // Change 0000 0000 0000 0000 0000 0000 0000 0000
 // to     1000 0000 0000 0000 0000 0000 0000 0000
 BC_SET_FLAG(flags32.flags32_t, 32);
 ```
***CAUTION***
Make sure the bit position being set is compatible with the data type being used.
For example, you cannot set the 9th bit in an 8-bit data type.  Be cognizant of choices
with the flags as this will result in nothing other than potential stack corruption
```c
// DO !!NOT!! do this!!
bool flags8;
BC_SET_FLAG(flags8.flags8_t, 9);
```

The same rules apply to clearing a flag.  To clear a flag, use the 
```c 
BC_CLEAR_FLAG(FLAG, POS)
``` 
macro.
The first parameter is the flag type and the second is the position of the bit to clear.
Let's say we want to clear the 32nd bit in the 32 bit flag data type.
```c
 flags32.flags32_t = 0x80000000;
 // Change 1000 0000 0000 0000 0000 0000 0000 0000
 // to     0000 0000 0000 0000 0000 0000 0000 0000
 BC_CLEAR_FLAG(flags32.flags32_t, 32);
 ```
 ## Test File Built With

* [GCC Make](https://gcc.gnu.org/onlinedocs/gccint/Makefile.html) - build tool

## Contributing

Currently a WIP, but make pull requests and I will approve ones I see as okay.

## Versioning

For the versions available, see the [tags on this repository](https://github.com/ZygalM1S1U/boolCast/releases). 

## Authors

* **James Novorita** - *All Development* - [ZygalM1S1U](https://github.com/ZygalM1S1U), [Professional Website](https://zygalsplayground.com/)

