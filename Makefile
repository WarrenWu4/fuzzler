all: main

main:
	g++ main.cpp algos/* -o build/main

run: main
	./build/main

clean:
	rm ./build/main
