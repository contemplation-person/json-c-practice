testFileName := testExecProgram

all: 
	make -j7 test

compile:
	gcc *.c -o $(testFileName)

test: compile
	./$(testFileName)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(testFileName)

.PHONY: all compile test clean fclean
