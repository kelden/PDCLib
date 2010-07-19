/* $Id$ */

/* printf( const char *, ... )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>
#include <stdarg.h>

#ifndef REGTEST

int printf( const char * _PDCLIB_restrict format, ... )
{
    int rc;
    va_list ap;
    va_start( ap, format );
    rc = vfprintf( stdout, format, ap );
    va_end( ap );
    return rc;
}

#endif

#ifdef TEST
#include <limits.h>
#include <string.h>
#include <_PDCLIB_test.h>

#define testprintf( stream, n, format, ... ) printf( format, __VA_ARGS__ )

#define TESTCASE_SPRINTF( x )

int main( void )
{
    FILE * buffer;
    TESTCASE( ( buffer = freopen( testfile, "wb", stdout ) ) != NULL );
#include "printf_testcases.incl"
    TESTCASE( fclose( buffer ) == 0 );
#include "fprintf_reftest.incl"
    TESTCASE( remove( testfile ) == 0 );
    return TEST_RESULTS;
}

#endif
