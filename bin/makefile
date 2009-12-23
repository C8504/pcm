GCC=gcc
E=.exe
C=.c
SRCFILES=../src/linkedlist$(C)
LOG=.log
TESTFILES=../test/test_init_and_free$(C)\
          ../test/test_one_element$(C)\
          ../test/test_many_element$(C)\
          ../test/test_readfile$(C)
help:
	@(echo "" \
	;echo "Choose a target:" \
	;echo "" \
	;echo "make [help]                  -- print this help screen" \
	;echo "make [test_init_and_free.exe]   -- build test_init_and_free.exe" \
	)

test_init_and_free$(E): $(SRCFILES) $(TESTFILES)
	$(GCC) -I ../include/ ../test/test_init_and_free$(C) $(SRCFILES) -o test_init_and_free$(E)
	test_init_and_free$(E) > test_init_and_free$(LOG)
test_one_element$(E): $(SRCFILES) $(TESTFILES)
	$(GCC) -I ../include/ ../test/test_one_element$(C) $(SRCFILES) -o test_one_element$(E)
	test_one_element$(E) > test_one_element$(LOG)
test_many_element$(E): $(SRCFILES) $(TESTFILES)
	$(GCC) -I ../include/ ../test/test_many_element$(C) $(SRCFILES) -o test_many_element$(E)
	test_many_element$(E) > test_many_element$(LOG)
test_readfile$(E): $(SRCFILES) $(TESTFILES)
	$(GCC) -I ../include/ ../test/test_readfile$(C) $(SRCFILES) -o test_readfile$(E)
	test_readfile$(E) > test_readfile$(LOG)

test: test_init_and_free$(E) test_one_element$(E) test_many_element$(E) test_readfile$(E)
	grep error *.log
clean:
	rm -f *$(E) *$(LOG)