all:
	g++ -o main main.cpp BST.cpp Node.cpp
win:
	cl /EHsc main.cpp BST.cpp Node.cpp
