CImgTest : CImgTest.o
	g++ --coverage -o CImgTest CImgTest.o -lcpptest -lX11 -lpthread

CImgTest.o : CImgTest.cpp CImg.h
	g++ --coverage -c CImgTest.cpp

clean : 
	rm -vf CImgTest CImgTest.o output.html
