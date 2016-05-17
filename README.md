# cimg_unit_test
Automated Unit Tests for CImg library (v1.7.1). Based on cpptest.

Minimum Requirements
--------------------
1. libcpptest
2. libX11
3. libpthread

Execution Steps
---------------
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

> ./CImgTest tt

  ![Alt text](images/tt.png?raw=true "Run Test with Terse Text output argument")

> ./CImgTest vt

  ![Alt text](images/tt.png?raw=true "Run Test with Verbose Text output argument")

> ./CImgTest ct

  No output. Output only seen in case of test failures.

> ./CImgTest ht

  ![Alt text](images/ht.png?raw=true "Run Test with HTML output argument")

Code Coverage
-------------
In case you need to use gcov for generating code coverage reports,  
execute make with an argument ENABLE_COVERAGE=1

> make ENABLE_COVERAGE=1

TODO
----
1. Organize the tests and name them meaningfully.  
   For eg. Tests for constructors, Tests for getter methods, Tests for setter methods, etc.  
2. Document the test code.  
3. Improve code coverage.  
  
*NOTE: When executed in HTML output mode, file named "output.html" is generated in the same directory.
