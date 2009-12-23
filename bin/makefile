GCC=gcc
E=.exe
C=.c
INCLUDE=../include/
TESTDIR=../test/
LOG=.log

SRCFILES=../src/linkedlist$(C)
TESTFILES=$(TESTDIR)test_init_and_free$(C)\
          $(TESTDIR)test_one_element$(C)\
          $(TESTDIR)test_many_element$(C)\
          $(TESTDIR)test_readfile$(C)
LOGFILES=test_init_and_free$(LOG)\
         test_one_element$(LOG)\
         test_many_element$(LOG)\
         test_readfile$(LOG)

help:
	@(echo "" \
	;echo "Choose a target:" \
	;echo "" \
	;echo "make [help]                  -- print this help screen" \
	;echo "make [test_init_and_free.exe]   -- build test_init_and_free.exe" \
	;echo "make [test]   -- build all tests" \
	)

test_init_and_free$(E): $(SRCFILES) $(TESTDIR)test_init_and_free$(C)
	$(GCC) -I $(INCLUDE) $(TESTDIR)test_init_and_free$(C) $(SRCFILES) -o test_init_and_free$(E)
	test_init_and_free$(E) > test_init_and_free$(LOG)
test_one_element$(E): $(SRCFILES) $(TESTDIR)test_one_element$(C)
	$(GCC) -I $(INCLUDE) $(TESTDIR)test_one_element$(C) $(SRCFILES) -o test_one_element$(E)
	test_one_element$(E) > test_one_element$(LOG)
test_many_element$(E): $(SRCFILES) $(TESTDIR)test_many_element$(C)
	$(GCC) -I $(INCLUDE) $(TESTDIR)test_many_element$(C) $(SRCFILES) -o test_many_element$(E)
	test_many_element$(E) > test_many_element$(LOG)
test_readfile$(E): $(SRCFILES) $(TESTDIR)test_readfile$(C)
	$(GCC) -I $(INCLUDE) $(TESTDIR)test_readfile$(C) $(SRCFILES) -o test_readfile$(E)
	test_readfile$(E) > test_readfile$(LOG)

test: test_init_and_free$(E) test_one_element$(E) test_many_element$(E) test_readfile$(E)
	@if test `cat $(LOGFILES) | grep 'Cui Error' | wc -l` -gt 0; then \
	  echo "";\
	  echo "Cui Errors found! try  grep 'Cui Error' *.log"; \
	  echo "";\
	else \
	  echo "All tests completed successfully"; \
	fi
clean:
	rm -f *$(E) *$(LOG)