all:compile combine run
compile:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Node.cpp -o ./lib/Node.o
	g++ -c -I "./include" ./src/AvlTree.cpp -o ./lib/AvlTree.o	
	g++ -c -I "./include" ./src/Stack.cpp -o ./lib/Stack.o

	g++ -c -I "./include" ./src/List.cpp -o ./lib/List.o
	g++ -c -I "./include" ./src/FileReader.cpp -o ./lib/FileReader.o	
	
			
combine:
	g++ ./lib/main.o ./lib/Node.o ./lib/AvlTree.o ./lib/Stack.o ./lib/List.o ./lib/FileReader.o -o ./bin/program
run:
	./bin/program