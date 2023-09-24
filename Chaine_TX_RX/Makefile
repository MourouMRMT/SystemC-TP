SYSCINC=/usr/include
SYSCLIB=/usr/lib/x86_64-linux-gnu
CXX         = g++
LD	    = g++
CXXFLAGS    = -Wall  -I. -I$(SYSCINC) -Wno-deprecated
LDFLAGS	    =  -L$(SYSCLIB)
SOURCES     = $(wildcard *.cpp)
OBJS        = $(SOURCES:.cpp=.o)
EXE	    = a.out
VCDVIEWER   = gtkwave

all: $(EXE)

$(EXE) : $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@  -lsystemc  2>&1 | c++filt

run: a.out
	./a.out

view: tb.vcd
	$(VCDVIEWER) -f $< -a tb.vcd

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean :
	-rm -f *.o *~ *_old $(EXE)
	-rm -f a.out
	-rm -f core
	-rm -f *.vcd
