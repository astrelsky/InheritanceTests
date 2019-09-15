
OBJECTS = main.o
EXEC  = main 
STRIPPED  = main_stripped
CXXFLAGS = -Wall -static -gdwarf-3 -g3
CXX = clang++


all: $(STRIPPED)

$(OBJECTS): ../../main.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC) $(STRIPPED)

remake: clean all

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

$(STRIPPED): $(EXEC)
	strip $< -o $(STRIPPED)
