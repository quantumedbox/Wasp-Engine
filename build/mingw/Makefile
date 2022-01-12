SRCDIR := ../../src
INCDIR := ../../inc
OUTDIR := ../..

CXX_FLAGS := -Wall -std=c++17
CXX_LINKFLAGS := -municode -static -lkernel32 -lgdi32 -ld2d1 -lole32 -loleaut32 -lWindowscodecs -lShlwapi -lDwrite -lWinmm -Wl,-Bstatic -static-libstdc++	 -static-libgcc

SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := ${SRCS:.cpp=.o}
DEPS = $(wildcard $(OBJS:%=%.d))

.PHONY: all debug clean

all: debug

debug: CXX_FLAGS += -g3
debug: wasp.exe

wasp.exe: $(OBJS)
	g++ $^ -o $(OUTDIR)/$@ $(CXX_FLAGS) -I $(INCDIR) $(CXX_LINKFLAGS)

%.o: %.cpp
	g++ -MD -MP -MF $@.d -c $< -o $@ $(CXX_FLAGS) -I $(INCDIR) $(CXX_LINKFLAGS)

clean:
	$(RM) $(OBJS) $(DEPS)

include $(DEPS)
