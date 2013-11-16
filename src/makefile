CXX = g++
## Update these paths to match your installation
## You may also need to update the linker option rpath, which sets where to look for
## the SDL2 libraries at runtime to match your install
SDL_LIB = -L/usr/local/lib -lSDL -lSDL_image -Wl,-rpath=/usr/local/lib
SDL_INCLUDE = -I/usr/local/include
# You may need to change -std=c++11 to -std=c++0x if your compiler is a bit older
CXXFLAGS = -Wall -c $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
EXE = main

OBJECTS = Block.o Sprite.o mSDL.o 
all: $(EXE)

$(EXE): main.cpp $(OBJECTS)
	$(CXX) $< $(OBJECTS) $(LDFLAGS) -o $@

Block.o: Block.cpp Block.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -o $@

Sprite.o: Sprite.cpp Sprite.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -o $@

mSDL.o: mSDL.cpp mSDL.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)

