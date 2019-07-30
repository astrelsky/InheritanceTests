EE_OBJS = main.o
MY_ERL  = main.erl
EE_ERL  = main_stripped.erl
EE_CXXFLAGS = -Wall -gdwarf-2 -g3


all: $(MY_ERL) $(EE_ERL)

$(EE_OBJS): ../../main.cc
	$(EE_CXX) $(EE_CXXFLAGS) $(EE_INCS) -c $< -o $@

$(MY_ERL): $(EE_OBJS)
	$(EE_CC) $(EE_NO_CRT) -o $(MY_ERL) $(EE_OBJS) $(EE_CFLAGS) $(EE_LDFLAGS) -Wl,-r -Wl,-d

clean:
	rm -f $(MY_ERL) $(EE_OBJS) $(EE_ERL)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal_cpp
