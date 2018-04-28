#ifndef BOOLCAST_H_   /* Include guard */
#define BOOLCAST_H_

#include <stdio.h>
#include <stdint.h>

#define MAX_BITS    8
//file contract
///@note a sample of what is needed!
//bool(x) mybool;
//bool(x) mybool = {00110011};
//bool(x) mybool = {8F};
//bool(x) mybool[0] = 1;
//bool(x) mybool = {FFTTFFTT};

///@brief typedef declarations
///@param Bool - a parameter to pass an unsigned 8-bit integer for a flag mask.
///@note 'Bool' is used as a typical defined function here, but then replaced in memory with a bit mask as a rudimentary form of compression
typedef uint8_t* Bool;

/*function prototypes*/
///Placeholder
static void instance(void);


#endif // BOOLCAST_H_
