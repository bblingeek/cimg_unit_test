IDIR=.
CXXFLAGS=-I$(IDIR)
DEPS=CImg.h
OBJ=CImgTest.o
LIBS=-lX11 -lpthread -lcpptest
COVFLAGS=--coverage

ENABLE_COVERAGE=0

CImgTest: $(OBJ)
ifneq ($(ENABLE_COVERAGE), 1)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)
else
	$(CXX) $(COVFLAGS) -o $@ $^ $(CXXFLAGS) $(LIBS)
endif

%.o: %.cpp $(DEPS)
ifneq ($(ENABLE_COVERAGE), 1)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
else
	$(CXX) $(COVFLAGS) -c -o $@ $< $(CXXFLAGS)
endif

clean: 
	$(RM) -v CImgTest *.o output.html *.gcno *.gcda *.gcov
