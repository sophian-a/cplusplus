CXX=g++
CXXFLAGS=-Wall -ggdb
RM=rm -f

test : test-intlist.o intlist.h
	$(CXX) $(CXXFLAGS) $^ -o $@
test-intlist.o : test-intlist.cpp intlist.h

%.o:%.cpp; $(CXX) $(CXXFLAGS) -o $@ -c $<

clean :
	$(RM) test-intlist.o test