/*
 * File: platform_defs.h
 * Author: Tudor David <tudor.david@epfl.ch>
 *
 * Description: 
 *      Platform specific definitions and parameters
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013 Tudor David
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */




#ifndef _PLATFORM_DEFS_H_INCLUDED_
#define _PLATFORM_DEFS_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif
    /*
     * For each machine that is used, one needs to define
     *  NUMBER_OF_SOCKETS: the number of sockets the machine has
     *  CORES_PER_SOCKET: the number of cores per socket
     *  CACHE_LINE_SIZE
     *  NOP_DURATION: the duration in cycles of a noop instruction (generally 1 cycle on most small machines)
     *  the_cores - a mapping from the core ids as configured in the OS to physical cores (the OS might not alwas be configured corrrectly)
     *  get_cluster - a function that given a core id returns the socket number ot belongs to
     */


#ifdef DEFAULT
#  define NUMBER_OF_SOCKETS 1
#  define CORES_PER_SOCKET CORE_NUM
#  define CACHE_LINE_SIZE 64
# define NOP_DURATION 2
  static uint8_t  __attribute__ ((unused)) the_cores[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 
        8, 9, 10, 11, 12, 13, 14, 15, 
        16, 17, 18, 19, 20, 21, 22, 23, 
        24, 25, 26, 27, 28, 29, 30, 31, 
        32, 33, 34, 35, 36, 37, 38, 39, 
        40, 41, 42, 43, 44, 45, 46, 47  
    };
#endif

#ifdef SPARC
#  define NUMBER_OF_SOCKETS 8
#  define CORES_PER_SOCKET 8
#  define CACHE_LINE_SIZE 64
# define NOP_DURATION 9

#define ALTERNATE_SOCKETS
#ifdef ALTERNATE_SOCKETS
    static uint8_t  __attribute__ ((unused)) the_cores[] = {
        0, 8, 16, 24, 32, 40, 48, 56, 
        1, 9, 17, 25, 33, 41, 49, 57, 
        2, 10, 18, 26, 34, 42, 50, 58, 
        3, 11, 19, 27, 35, 43, 51, 59, 
        4, 12, 20, 28, 36, 44, 52, 60, 
        5, 13, 21, 29, 37, 45, 53, 61, 
        6, 14, 22, 30, 38, 46, 54, 62, 
        7, 15, 23, 31, 39, 47, 55, 63 
    };

    static uint8_t the_sockets[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 
        1, 1, 1, 1, 1, 1, 1, 1, 
        2, 2, 2, 2, 2, 2, 2, 2, 
        3, 3, 3, 3, 3, 3, 3, 3, 
        4, 4, 4, 4, 4, 4, 4, 4, 
        5, 5, 5, 5, 5, 5, 5, 5, 
        6, 6, 6, 6, 6, 6, 6, 6, 
        7, 7, 7, 7, 7, 7, 7, 7 
    };

#else
    static uint8_t  __attribute__ ((unused)) the_cores[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 
        8, 9, 10, 11, 12, 13, 14, 15, 
        16, 17, 18, 19, 20, 21, 22, 23, 
        24, 25, 26, 27, 28, 29, 30, 31, 
        32, 33, 34, 35, 36, 37, 38, 39, 
        40, 41, 42, 43, 44, 45, 46, 47, 
        48, 49, 50, 51, 52, 53, 54, 55, 
        56, 57, 58, 59, 60, 61, 62, 63 
    };
    static uint8_t the_sockets[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 
        1, 1, 1, 1, 1, 1, 1, 1, 
        2, 2, 2, 2, 2, 2, 2, 2, 
        3, 3, 3, 3, 3, 3, 3, 3, 
        4, 4, 4, 4, 4, 4, 4, 4, 
        5, 5, 5, 5, 5, 5, 5, 5, 
        6, 6, 6, 6, 6, 6, 6, 6, 
        7, 7, 7, 7, 7, 7, 7, 7 
    };

#endif
#elif defined __tile__
#define NUMBER_OF_SOCKETS 1
#define CORES_PER_SOCKET 36
#define CACHE_LINE_SIZE 64
# define NOP_DURATION 4
    static uint8_t  __attribute__ ((unused)) the_cores[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 
        8, 9, 10, 11, 12, 13, 14, 15, 
        16, 17, 18, 19, 20, 21, 22, 23, 
        24, 25, 26, 27, 28, 29, 30, 31, 
        32, 33, 34, 35 
    };

#elif defined(OPTERON)
#  define NUMBER_OF_SOCKETS 8
#  define CORES_PER_SOCKET 6
#  define CACHE_LINE_SIZE 64
# define NOP_DURATION 2
    static uint8_t   __attribute__ ((unused)) the_cores[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 
        8, 9, 10, 11, 12, 13, 14, 15, 
        16, 17, 18, 19, 20, 21, 22, 23, 
        24, 25, 26, 27, 28, 29, 30, 31, 
        32, 33, 34, 35, 36, 37, 38, 39, 
        40, 41, 42, 43, 44, 45, 46, 47  
    };

#elif defined(XEON)
#  define CACHE_LINE_SIZE 64
#  define NOP_DURATION 1
#ifdef R730
#  define NUMBER_OF_SOCKETS 2
#  define CORES_PER_SOCKET 6
#ifdef SCATTER
  static uint8_t __attribute__ ((unused)) the_cores[] = {
		   0,1,2,3,4,5,
		    6,7,8,9,10,11,
			12,13,14,15,16,17,
			18,19,20,21,22,23,

  };
  static uint8_t __attribute__ ((unused)) the_sockets[] =
  {
   0,1,0,1,0,1,
   0,1,0,1,0,1,
   0,1,0,1,0,1,
   0,1,0,1,0,1,
  };
#endif
#ifdef COMPACT //default compact mode
  static uint8_t __attribute__ ((unused)) the_cores[] = {
		   0,2,4,6,8,10,	/* 0 */
		    1,3,5,7,9,11,/* 1 */
  };
  static uint8_t __attribute__ ((unused)) the_sockets[] =
  {
   0,1,0,1,0,1,
   0,1,0,1,0,1,
  };
#endif
#endif
#ifdef CHAN_INTEL
#  define NUMBER_OF_SOCKETS 2
#  define CORES_PER_SOCKET 8
#ifdef BALANCED
  static uint8_t __attribute__ ((unused)) the_cores[] = {
  	0,1,2,3,4,5,6,7,
  	8,9,10,11,12,13,14,15,
  	16,17,18,19,20,21,22,23,
  	24,25,26,27,28,29,30,31,
  };
static uint8_t __attribute__ ((unused)) the_sockets[] ={
	0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,
};
#endif
#ifdef COMPACT
  static uint8_t __attribute__ ((unused)) the_cores[] = {
  	0,1,2,3,4,5,6,7,
	16,17,18,19,20,21,22,23,
  	8,9,10,11,12,13,14,15,
  	24,25,26,27,28,29,30,31,
  };
static uint8_t __attribute__ ((unused)) the_sockets[] ={
	0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,
};
#endif
#endif
#elif defined(MIC)
#  define NUMBER_OF_SOCKETS 1
#  define CORES_PER_SOCKET 228
#  define CACHE_LINE_SIZE 64
#  define NOP_DURATION 1
#ifdef SCATTER
  static uint8_t __attribute__ ((unused)) the_cores[] =
    {
    	1,5,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81,85,89,93,97,101,105,109,113,117,121,125,129,133,137,141,145,149,153,157,161,165,169,173,177,181,185,189,193,197,201,205,209,213,217,221,225,
  2,6,10,14,18,22,26,30,34,38,42,46,50,54,58,62,66,70,74,78,82,86,90,94,98,102,106,110,114,118,122,126,130,134,138,142,146,150,154,158,162,166,170,174,178,182,186,190,194,198,202,206,210,214,218,222,226,
  3,7,11,15,19,23,27,31,35,39,43,47,51,55,59,63,67,71,75,79,83,87,91,95,99,103,107,111,115,119,123,127,131,135,139,143,147,151,155,159,163,167,171,175,179,183,187,191,195,199,203,207,211,215,219,223,227,
  4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184,188,192,196,200,204,208,212,216,220,224,0,
    };
#endif
#ifdef COMPACT
  static uint8_t __attribute__ ((unused)) the_cores[] = {
 1,2,3,4,
 5,6,7,8,
 9,10,11,12,
 13,14,15,16,
 17,18,19,20,
 21,22,23,24,
 25,26,27,28,
 29,30,31,32,
 33,34,35,36,
 37,38,39,40,
 41,42,43,44,
 45,46,47,48,
 49,50,51,52,
 53,54,55,56,
 57,58,59,60,
 61,62,63,64,
 65,66,67,68,
 69,70,71,72,
 73,74,75,76,
 77,78,79,80,
 81,82,83,84,
 85,86,87,88,
 89,90,91,92,
 93,94,95,96,
 97,98,99,100,
 101,102,103,104,
 105,106,107,108,
 109,110,111,112,
 113,114,115,116,
 117,118,119,120,
 121,122,123,124,
 125,126,127,128,
 129,130,131,132,
 133,134,135,136,
 137,138,139,140,
 141,142,143,144,
 145,146,147,148,
 149,150,151,152,
 153,154,155,156,
 157,158,159,160,
 161,162,163,164,
 165,166,167,168,
 169,170,171,172,
 173,174,175,176,
 177,178,179,180,
 181,182,183,184,
 185,186,187,188,
 189,190,191,192,
 193,194,195,196,
 197,198,199,200,
 201,202,203,204,
 205,206,207,208,
 209,210,211,212,
 213,214,215,216,
 217,218,219,220,
 221,222,223,224,
 225,226,227,0,
   };
#endif
#ifdef BALANCED
  static uint8_t __attribute__ ((unused)) the_cores[] =
   {
  1,2,5,6,
 9,10,13,14,
 17,18,21,22,
 25,26,29,30,
 33,34,37,38,
 41,42,45,46,
 49,50,53,54,
 57,58,61,62,
 65,66,69,70,
 73,74,77,78,
 81,82,85,86,
 89,90,93,94,
 97,98,101,102,
 105,106,109,110,
 113,114,117,118,
 121,122,125,126,
 129,130,133,134,
 137,138,141,142,
 145,146,149,150,
 153,154,157,158,
 161,162,165,166,
 169,170,173,174,
 177,178,181,182,
 185,186,189,190,
 193,194,197,198,
 201,202,205,206,
 209,210,213,214,
 217,218,221,222,
 225,226,
 3,4,7,8,
 11,12,15,16,
 19,20,23,24,
 27,28,31,32,
 35,36,39,40,
 43,44,47,48,
 51,52,55,56,
 59,60,63,64,
 67,68,71,72,
 75,76,79,80,
 83,84,87,88,
 91,92,95,96,
 99,100,103,104,
 107,108,111,112,
 115,116,119,120,
 123,124,127,128,
 131,132,135,136,
 139,140,143,144,
 147,148,151,152,
 155,156,159,160,
 163,164,167,168,
 171,172,175,176,
 179,180,183,184,
 187,188,191,192,
 195,196,199,200,
 203,204,207,208,
 211,212,215,216,
 219,220,223,224,
 227,0,
   };
#endif
#endif

#if defined(OPTERON)
#  define PREFETCHW(x)		     asm volatile("prefetchw %0" :: "m" (*(unsigned long *)x))
#elif defined(__sparc__)
#  define PREFETCHW(x)		
#elif defined(XEON)
#  define PREFETCHW(x)		
#else
#  define PREFETCHW(x)		
#endif

    static inline int get_cluster(int thread_id) {
#ifdef __solaris__
        if (thread_id>64){
            perror("Thread id too high");
            return 0;
        }
        return thread_id/CORES_PER_SOCKET;
#elif XEON
        if (thread_id>=80){
            perror("Thread id too high");
            return 0;
        }
        return the_sockets[thread_id];
#elif defined(__tile__)
        return 0;
#else
        return thread_id/CORES_PER_SOCKET;
#endif
    }

#ifdef __cplusplus
}

#endif


#endif
