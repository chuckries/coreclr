// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

.assembly extern System.Console
{
  .publickeytoken = (B0 3F 5F 7F 11 D5 0A 3A )
  .ver 4:0:0:0
}

.assembly Conv_test {}
.assembly extern mscorlib{auto}
.class Conv_test {
.method static int32 Main_test() {
.maxstack	5

//     ldc.i4.2
     ldc.i4.0
     ldc.i4.2
    sub
     dup
     call       void [System.Console]System.Console::WriteLine(int32)




conv.ovf.i1.un
     call       void [System.Console]System.Console::WriteLine(int32)

// this is to make the errorlevel 100 if the answer is right ( ie 0)
IL_02:
    ldc.i4 1
    ret
IL_01: 
   ldstr "pass"
   call       void [System.Console]System.Console::WriteLine(string)
   ldc.i4 100

 ret
}
.method static int32 Main() {
.entrypoint
.maxstack	5
    .try
    {
      call int32 Conv_test::Main_test()
      pop
      leave.s    failed
    }  
    catch [mscorlib]System.OverflowException
    {
        IL_0023:  leave.s    passed
    }
failed:
   ldstr "failed"
   call       void [System.Console]System.Console::WriteLine(string)

   ldc.i4.1
   ret
passed:
   ldstr "Passed"
   call       void [System.Console]System.Console::WriteLine(string)
   ldc.i4 100
   ret
}
}
