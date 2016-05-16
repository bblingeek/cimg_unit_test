CImgTest : CImgTest.o
	g++ -o CImgTest CImgTest.o -lcpptest -lX11 -lpthread

CImgTest.o : CImgTest.cpp CImg.h
	g++ -c CImgTest.cpp -lcpptest -lX11 -lpthread

clean : 
	rm -vf CImgTest CImgTest.o output.html
