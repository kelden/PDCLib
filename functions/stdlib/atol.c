/* $Id$ */

/* Release $Name$ */

/* atol( const char * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <_PDCLIB_int.h>
#include <stdlib.h>

#ifndef REGTEST

long int atol( const char * s )
{
    return (long int) _PDCLIB_atomax( s );
}

#endif

#ifdef TEST
#include <_PDCLIB_test.h>

int main()
{
    BEGIN_TESTS;
    /* no tests for a simple wrapper */
    return TEST_RESULTS;
}

#endif