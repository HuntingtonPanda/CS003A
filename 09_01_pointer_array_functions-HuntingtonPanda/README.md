
# Work Report

## Name: <ins> your name goes here </ins>

## Features:

- Not Implemented:
  - Deletion of dynamic array in reallocate

<br><br>

- Implemented:
  - pointer array functions

<br><br>

- Partly implemented:
  - N/A

<br><br>

- Bugs
  - I couldn't delete the dynamic array after reallocate

<br><br>

# Reflections:

- I thought this project was for vectors not arrays and it took
  me and embarrasingly long time to find out

# **output**
<pre>
<br/><br/><br/><br/>
## Delete this line and paste the output of your basic test and then testB here
</pre>


<br/><br/>

# basic_test.cpp output:
----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from POINTER_ARRAY_FUNCS
[ RUN      ] POINTER_ARRAY_FUNCS.PointerArrayFuncsTest


 -- allocate(), print_array() -----
[ 7/10] [   0  10  20  30  40  50  60]


 -- search_entry() -----
30 was found: 30
35 was not found


 -- search() -----
30 was found: 30
35 was not found


 -- copy function()  (@@)-----
 void copy_array(dest, src, size):  [   0  10  20  30  40  50  60]
 T* copy_array(src, siae):       [ 7/7] [   0  10  20  30  40  50  60]



 -- shift_right()
 - shift right at 30:[ 8/10] [   0  10  20  30  30  40  50  60]
 - shift right at 60:[ 9/10] [   0  10  20  30  30  40  50  60  60]
 - shift right at  0:[10/10] [   0   0  10  20  30  30  40  50  60  60]


 -- reallocate()
 --- after reallocation: [10/20] [   0   0  10  20  30  30  40  50  60  60]
 - one more shift at 20: [11/20] [   0   0  10  20  20  30  30  40  50  60  60]


 -- shift_left()
        array now:  [11/20] [   0   0  10  20  20  30  30  40  50  60  60]
 - shift left at 60:[10/20] [   0   0  10  20  20  30  30  40  50  60]
 - shift left at 60:[ 9/20] [   0   0  10  20  20  30  30  40  50]
 - shift left at 20:[ 8/20] [   0   0  10  20  30  30  40  50]
 - shift left at 20:[ 7/20] [   0   0  10  30  30  40  50]


 -- array_string()
        array now:  [ 7/20] [   0   0  10  30  30  40  50]
  array to string: [0 0 10 30 30 40 50 ][7]
 Feel free to change the way the string is constructed:
                          commas, better spacing, etc.




 ==========  end basic test  =================
[       OK ] POINTER_ARRAY_FUNCS.PointerArrayFuncsTest (16 ms)
[----------] 1 test from POINTER_ARRAY_FUNCS (17 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (18 ms total)
[  PASSED  ] 1 test.
<pre>
<br/><br/><br/><br/>
</pre>
# testB.cpp output:
----------running testB.cpp---------


[==========] Running 10 tests from 10 test suites.
[----------] Global test environment set-up.
[----------] 1 test from TEST_STUB
[ RUN      ] TEST_STUB.TestStub
[       OK ] TEST_STUB.TestStub (0 ms)
[----------] 1 test from TEST_STUB (0 ms total)

[----------] 1 test from TEST_PRINT_ARRAY
[ RUN      ] TEST_PRINT_ARRAY.TestPrintArray


-----------------------

[ 7/10] [   0  10  20  30  40  50  60]

-----------------------

[       OK ] TEST_PRINT_ARRAY.TestPrintArray (1 ms)
[----------] 1 test from TEST_PRINT_ARRAY (2 ms total)

[----------] 1 test from TEST_PRINT
[ RUN      ] TEST_PRINT.TestPrint


-----------------------

[   0  10  20  30  40]

-----------------------

[       OK ] TEST_PRINT.TestPrint (1 ms)
[----------] 1 test from TEST_PRINT (1 ms total)

[----------] 1 test from TEST_SEARCH_ENTRY
[ RUN      ] TEST_SEARCH_ENTRY.TestSearchEntry
[       OK ] TEST_SEARCH_ENTRY.TestSearchEntry (0 ms)
[----------] 1 test from TEST_SEARCH_ENTRY (0 ms total)

[----------] 1 test from TEST_SEARCH
[ RUN      ] TEST_SEARCH.TestSearch
[       OK ] TEST_SEARCH.TestSearch (0 ms)
[----------] 1 test from TEST_SEARCH (0 ms total)

[----------] 1 test from TEST_SHIFT_LEFT
[ RUN      ] TEST_SHIFT_LEFT.TestShiftLeft


array now:  [11/20] [   0   0  10  20  20  30  30  40  50  60  60]
 - shift left at 60:[10/20] [   0   0  10  20  20  30  30  40  50  60]
 - shift left at 60:[ 9/20] [   0   0  10  20  20  30  30  40  50]
 - shift left at 20:[ 8/20] [   0   0  10  20  30  30  40  50]
 - shift left at 20:[ 7/20] [   0   0  10  30  30  40  50]
[       OK ] TEST_SHIFT_LEFT.TestShiftLeft (5 ms)
[----------] 1 test from TEST_SHIFT_LEFT (5 ms total)

[----------] 1 test from TEST_SHIFT_RIGHT
[ RUN      ] TEST_SHIFT_RIGHT.TestShiftRight


array now:  [ 7/10] [   0  10  20  30  40  50  60]
 - shift right at 30:[ 8/10] [   0  10  20  30  30  40  50  60]
 - shift right at 60:[ 9/10] [   0  10  20  30  30  40  50  60  60]
 - shift right at  0:[10/10] [   0   0  10  20  30  30  40  50  60  60]
[       OK ] TEST_SHIFT_RIGHT.TestShiftRight (4 ms)
[----------] 1 test from TEST_SHIFT_RIGHT (4 ms total)

[----------] 1 test from TEST_ARRAY_STRING
[ RUN      ] TEST_ARRAY_STRING.TestArrayString
        array now:  [ 7/10] [   0  10  20  30  40  50  60]
  array to string: [0 10 20 30 40 50 60 ][7]
[       OK ] TEST_ARRAY_STRING.TestArrayString (1 ms)
[----------] 1 test from TEST_ARRAY_STRING (2 ms total)

[----------] 1 test from TEST_ALLOCATE
[ RUN      ] TEST_ALLOCATE.TestAllocate
[ 7/10] [   0  10  20  30  40  50  60]
[       OK ] TEST_ALLOCATE.TestAllocate (1 ms)
[----------] 1 test from TEST_COPY_ARRAY
[ RUN      ] TEST_COPY_ARRAY.TestCopyArray
[ 9/10] [   0  10  20  30  40  50  60  70  80]
[ 9/9] [   0  10  20  30  40  50  60  70  80]
[ 5/5] [   0  10  20  30  40]
[       OK ] TEST_COPY_ARRAY.TestCopyArray (2 ms)
[----------] 1 test from TEST_COPY_ARRAY (3 ms total)

[----------] Global test environment tear-down
[==========] 10 tests from 10 test suites ran. (21 ms total)
[  PASSED  ] 10 tests.
PS C:\Users\Huntington Co\Documents\GitHub\CS3A\09_01_pointer_array_functions-HuntingtonPanda\build\bin> ."C:/Users/Huntington Co/Documents/GitHub/CS3A/09_01_pointer_array_functions-HuntingtonPanda/build/bin/testB.exe" 


----------running testB.cpp---------


[==========] Running 10 tests from 10 test suites.
[----------] Global test environment set-up.
[----------] 1 test from TEST_STUB
[ RUN      ] TEST_STUB.TestStub
[       OK ] TEST_STUB.TestStub (0 ms)
[----------] 1 test from TEST_STUB (1 ms total)

[----------] 1 test from TEST_PRINT_ARRAY
[ RUN      ] TEST_PRINT_ARRAY.TestPrintArray


-----------------------

[ 7/10] [   0  10  20  30  40  50  60]

-----------------------

[       OK ] TEST_PRINT_ARRAY.TestPrintArray (1 ms)
[----------] 1 test from TEST_PRINT_ARRAY (1 ms total)

[----------] 1 test from TEST_PRINT
[ RUN      ] TEST_PRINT.TestPrint


-----------------------

[   0  10  20  30  40]

-----------------------

[       OK ] TEST_PRINT.TestPrint (0 ms)
[----------] 1 test from TEST_PRINT (1 ms total)

[----------] 1 test from TEST_SEARCH_ENTRY
[ RUN      ] TEST_SEARCH_ENTRY.TestSearchEntry
[       OK ] TEST_SEARCH_ENTRY.TestSearchEntry (0 ms)
[----------] 1 test from TEST_SEARCH_ENTRY (0 ms total)

[----------] 1 test from TEST_SEARCH
[ RUN      ] TEST_SEARCH.TestSearch
[       OK ] TEST_SEARCH.TestSearch (0 ms)
[----------] 1 test from TEST_SEARCH (0 ms total)

[----------] 1 test from TEST_SHIFT_LEFT
[ RUN      ] TEST_SHIFT_LEFT.TestShiftLeft


array now:  [11/20] [   0   0  10  20  20  30  30  40  50  60  60]
 - shift left at 60:[10/20] [   0   0  10  20  20  30  30  40  50  60]
 - shift left at 60:[ 9/20] [   0   0  10  20  20  30  30  40  50]
 - shift left at 20:[ 8/20] [   0   0  10  20  30  30  40  50]
 - shift left at 20:[ 7/20] [   0   0  10  30  30  40  50]
[       OK ] TEST_SHIFT_LEFT.TestShiftLeft (5 ms)
[----------] 1 test from TEST_SHIFT_LEFT (5 ms total)

[----------] 1 test from TEST_SHIFT_RIGHT
[ RUN      ] TEST_SHIFT_RIGHT.TestShiftRight


array now:  [ 7/10] [   0  10  20  30  40  50  60]
 - shift right at 30:[ 8/10] [   0  10  20  30  30  40  50  60]
 - shift right at 60:[ 9/10] [   0  10  20  30  30  40  50  60  60]
 - shift right at  0:[10/10] [   0   0  10  20  30  30  40  50  60  60]
[       OK ] TEST_SHIFT_RIGHT.TestShiftRight (4 ms)
[----------] 1 test from TEST_SHIFT_RIGHT (5 ms total)

[----------] 1 test from TEST_ARRAY_STRING
[ RUN      ] TEST_ARRAY_STRING.TestArrayString
        array now:  [ 7/10] [   0  10  20  30  40  50  60]
  array to string: [0 10 20 30 40 50 60 ][7]
[       OK ] TEST_ARRAY_STRING.TestArrayString (1 ms)
[----------] 1 test from TEST_ARRAY_STRING (1 ms total)

[----------] 1 test from TEST_ALLOCATE
[ RUN      ] TEST_ALLOCATE.TestAllocate
[ 7/10] [   0  10  20  30  40  50  60]
[       OK ] TEST_ALLOCATE.TestAllocate (1 ms)
[----------] 1 test from TEST_ALLOCATE (1 ms total)

[----------] 1 test from TEST_COPY_ARRAY
[ RUN      ] TEST_COPY_ARRAY.TestCopyArray
[ 9/10] [   0  10  20  30  40  50  60  70  80]
[ 9/9] [   0  10  20  30  40  50  60  70  80]
[ 5/5] [   0  10  20  30  40]
[       OK ] TEST_COPY_ARRAY.TestCopyArray (2 ms)
[----------] 1 test from TEST_COPY_ARRAY (2 ms total)

[----------] Global test environment tear-down
[==========] 10 tests from 10 test suites ran. (21 ms total)
[  PASSED  ] 10 tests.
<pre>
<br/><br/><br/><br/>
</pre>


