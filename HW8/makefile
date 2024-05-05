all: clean compile run

compile: main.c util.c util.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o a.out main.c util.c

run:
	@echo "-------------------------------------------"
	@echo "Running the program...."
	@echo "================================================================================="
	./a.out
	@echo "================================================================================="
	@echo "Completed the program...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f *.out