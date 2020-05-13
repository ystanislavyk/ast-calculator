all:
	bash bootstrap.sh
	mkdir build && cd build && cmake ../ && make

clean:
	rm -rf build
	rm -rf Lexer/gen
