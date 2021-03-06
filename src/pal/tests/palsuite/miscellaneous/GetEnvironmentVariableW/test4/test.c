// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

/*============================================================
**
** Source : test.c
**
** Purpose: Test for GetEnvironmentVariable() function
**
**
**=========================================================*/

/* Depends on SetEnvironmentVariableW (because we're implmenting the wide 
   version) and strcmp() */

#define UNICODE
#include <palsuite.h>

int __cdecl main(int argc, char *argv[]) {

    /* Define some buffers needed for the function */
    WCHAR * pResultBuffer = NULL;
    WCHAR SomeEnvironmentVariable[] = {'P','A','L','T','E','S','T','\0'};
    WCHAR TheEnvironmentValue[] = {'T','E','S','T','\0'};
    int size;
  
    /*
     * Initialize the PAL and return FAILURE if this fails
     */

    if(0 != (PAL_Initialize(argc, argv)))
    {
        return FAIL;
    }
  
    SetEnvironmentVariable(SomeEnvironmentVariable,
                           TheEnvironmentValue);
  
  
    /* Normal case, PATH should fit into this buffer */
    size = GetEnvironmentVariable(convert("PALTEST"),   // Variable Name
                                  pResultBuffer,        // Buffer for Value
                                  0);                   // Buffer size
  
    pResultBuffer = malloc(size*sizeof(WCHAR));
  
    GetEnvironmentVariable(convert("PALTEST"),
                           pResultBuffer,
                           size);
  
    if(wcsncmp(pResultBuffer,convert("TEST"),wcslen(pResultBuffer) * 2) != 0) 
    {
        Fail("ERROR: The value in the buffer should have been 'TEST' but was "
             "really '%s'.",convertC(pResultBuffer));
    }
    
    free(pResultBuffer);  
    
    PAL_Terminate();
    return PASS;
}

