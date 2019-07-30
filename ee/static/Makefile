EE_OBJS = main.o
EE_BIN  = main.elf
STRIPPED  = main_stripped.elf
EE_CXXFLAGS = -Wall -gdwarf-2 -g3


all: $(STRIPPED)

$(EE_OBJS): ../../main.cc
	$(EE_CXX) $(EE_CXXFLAGS) $(EE_INCS) -c $< -o $@

$(STRIPPED): $(EE_BIN)
	$(EE_STRIP) --strip-unneeded $< -o $(STRIPPED)

clean:
	rm -f $(EE_BIN) $(EE_OBJS) $(STRIPPED)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal_cpp
