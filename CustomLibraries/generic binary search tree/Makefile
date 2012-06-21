all: dbg optimized

dbg:
	g++ -Wall -g -I. testBST.cpp -o testBST.outpp

optimized:
	g++ -I. -O3 testBST.cpp -o testBST.O3.outpp

clean:
	rm -f testBST.outpp
	rm -f testBST.O3.outpp
