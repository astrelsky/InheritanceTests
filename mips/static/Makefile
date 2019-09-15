PREFIX = mipsel-linux-gnu-
OBJECTS = main.o
EXEC  = main 
STRIPPED  = main_stripped
CXXFLAGS = -Wall -fvar-tracking-assignments -static -gdwarf-3 -g3
CXX = $(addprefix $(PREFIX),g++-9)
STRIP = $(addprefix $(PREFIX),strip)


all: $(STRIPPED)

$(OBJECTS): ../../main.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

$(STRIPPED): $(EXEC)
	$(STRIP) $< -o $(STRIPPED)

clean:
	rm -f $(OBJECTS) $(EXEC) $(STRIPPED)
