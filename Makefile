all:
	clang++ *.cpp -std=c++11 -o a.out

debug:
	lldb ./a.out

run:
	./a.out ${ARGS}

clean:
	rm -f a.out
