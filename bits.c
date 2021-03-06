/* 
 * CS:APP Data Lab 
 * 
 * <Casey Pelz>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
       //returns x&y as defined by De Morgan's law
       return ~((~x)|(~y));
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  //returns x^y by implementing De Morgan's law
  return (~((~x)&(~y))) & (~(x&y));
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  //creates the desired word by adding together 8 bit sections and shifting 8 between each addition
  //the shifting is necessary to avoid changing the previously added 8 bit section
  return ((((((73<<8)+36)<<8)+146)<<8)+73);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  //shifts x right nx8 times in order to position the desired byte at the far right
  //&ing it with 255, then returns the bits in the last byte only, as 255 in binary is 11111111
  return (x>>(n<<3))&255;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  //((~(!n)+1) checks for the zero case, and makes a mask of all 1's if n=0 or all 0's otherwise
  //the 'zero mask' is then or'd with a mask of 32-n 0's and n 1's
  //this ensures the mask is all 0's if n=0, but is the desired mask if n!=0
  //finally, the mask is &'d with x right-shifted n, which will return the desired result
  return ((~(!n)+1) | (~(~0<<(32+(~n+1))))) & (x>>n);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  //makes a mask of 0001 8 times
  int mask = ((((((17<<8)+17)<<8)+17)<<8)+17);

  //creates an int to keep track of the sums of 1's in each 4-bit chunk
  int sums = 0;
  
  //makes an int to store the total number of bits
  int total = 0;

  //sums together existing sum and the current sum of 1's in x, then right-shifts x 1
  sums += (x&mask);
  x = x>>1;
  sums += (x&mask);
  x = x>>1;
  sums += (x&mask);
  x = x>>1;
  sums += (x&mask);

  //isolates each 4-bit chunk in the sums int and adds together their values
  total += (sums<<28)>>28;
  total += (sums<<24)>>28;
  total += (sums<<20)>>28;
  total += (sums<<16)>>28;
  total += (sums<<12)>>28;
  total += (sums<<8)>>28;
  total += (sums<<4)>>28;
  total += sums>>28;

  //returns the total number of 1's
  return total;
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
  //checks if the leftmost 17 bits are the same and then logical not's the result to retyurn the desired 1 or 0
  return !((x>>15)^(x>>16));
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  //isolates the rightmost n bits, thus filling the leftmost 32-n bits with either all 1's or all 0's
  //then, by &ing this new value with the original x, you can determine if the first 32-n bits of the original are the same
  //finally, logical not-ing the value returns the desired 1 or 0
  return !(((x<<(32+(~n+1)))>>(32+(~n+1)))^x);
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  //shifts x right 31, then or's it with the original to turn any negative number into all 1's
  //Then, by logical not-ing it twice and or-ing it with x right shifted 31, the desired values are returned
  return (!(!((x>>31)|x)))|(x>>31);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  //logical negates x to make it a negative value, then adds 1 to restore it to its original value, but now negative
  return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
   //shifts x right 31, then or's it with the original to turn any negative number into all 1's
  //^'s the value with x right-shifted 31 to isolate the sign
  //logical not's it twice to return the desired 1 or 0
  return !(!(((x>>31)|x) ^ (x>>31)));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  //returns all 0's except when y is negative and x is positive
  int signNeg = ((x>>31)^(y>>31))&(y>>31);
  //returns all 1's except when y is positive and x is negative
  int signPos = ~(((x>>31)^(y>>31))&~(y>>31));
  //calculates the sign of the difference between x and y
  int dif = (y+(~x+1))>>31;

  //overrides the difference if y is negative and x is positive (to avoid edge cases)
  //&'s with signPos to avoid the egde case but return the difference otherwise
  //logical not's the result ot return the desired 1 or 0
  return !((signNeg|dif)&signPos);

  
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  //first checks if x is a power of 2
  //then checks if x is zero
  //finally, checks if x is negative
  //or's together the results of the tests and then logical not's them to return 1 if x is a power of 2 > 0, and 0 otherwise
  return !(((x&(x+(~0)))) | (!x) | (!(!(x>>31))));
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  //shifts uf to disregard sign bit
  int shiftUf = uf << 1;

  //returns uf if uf is NaN
  if(shiftUf > 4278190080)
    return uf;

  //flips the sign bit of uf and returns the newly negative value
  return uf^(~0<<31);
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  //isolates frac value
  int frac = uf & 8388607;
  //isolates exp value
  int exp = (uf & 2139095040)>>23;
  //uf without frac value
  int noFrac = uf & 4286578688;
  //sign bit of uf followed by 31 0's
  int sign = uf & 2147483648;

  //chacks for NaN and infinity
  if(((uf<<1)==0) || (uf<<1) >= (255<<24))
    return uf;

  //multiplies frac by 2 if exp = 0
  else if(exp == 0)
     return noFrac + (frac << 1);

  //otherwise adds one to exp
  else return sign + ((exp + 1)<<23) + frac;

}
