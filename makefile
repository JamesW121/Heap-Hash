
all: main.cpp node.cpp node.hpp prog1.cpp prog1.hpp
	g++ -Wall main.cpp node.cpp node.hpp prog1.cpp prog1.hpp

Clean:
	rm -f main