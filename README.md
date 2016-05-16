# cimg_unit_test
Automated Unit Tests for CImg library (v1.7.1). Based on cpptest.

Minimum Requirements
--------------------
1. libcpptest
2. libX11
3. libpthread

Execution
---------
1. Run make
> make

2. Run Tests
> ./CImgTest < output type >

  Output Types: -
  - tt : Terse Text output
  - vt : Verbose Text output
  - ct : Compiler output
  - ht : HTML output

Sample Run
----------
> make

  ![Alt text](images/make.png?raw=true "make")

> ./CImgTest

  ![Alt text](images/no_arg_run.png?raw=true "Run Test without arguments")
  
*NOTE: When executed in HTML output mode, file named "output.html" is generated in the same directory.
