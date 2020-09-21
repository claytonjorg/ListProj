all: listproj.x

listproj.x: test_list.cpp List.hpp
	g++ -std=c++11 test_list.cpp -o listproj.x

clean: rm -f listproj.x
