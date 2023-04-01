compile: LL_test.cpp 
	 g++  NODE.cpp LL.cpp LL_test.cpp -o LL

run: LL
	 ./LL Mint 200 10 view 300 5


clean: LL
	 rm LL
