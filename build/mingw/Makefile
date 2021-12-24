source_dir := ../../
include_dir := ../../
to_link := -lkernel32 -lgdi32 -ld2d1 -lole32 -loleaut32 -lWindowscodecs -lShlwapi
outut_path := ../../
outut_name := WASP

all: debug

debug:
	g++ -std=c++17 $(wildcard $(source_dir)*.cpp) -Wall -g3 -I:$(include_dir) $(to_link) -municode -o $(outut_path)$(outut_name)
