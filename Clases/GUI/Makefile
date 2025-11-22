CXX = g++
CXXFLAGS = -g -std=c++17 -I../../allegro-4.4.2-mingw-4.5.2/include -static -DALLEGRO_STATICLINK -MMD -MP
LDFLAGS = -L../../allegro-4.4.2-mingw-4.5.2/lib -lallegro-4.4.2-monolith-static-mt-debug \
          -lddraw -ldinput8 -ldsound -lwinmm -lcomctl32 -lgdi32 -lwsock32 \
          -lmsimg32 -ldxguid -lole32 -luuid -luser32 -lkernel32 -lopengl32 -lz -lm \
          -static -static-libgcc -static-libstdc++

SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)
TARGET = menu

SDL_CXXFLAGS = -g -std=c++17 -I/mingw32/include/SDL2
SDL_LDFLAGS = -L/mingw32/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -mwindows

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) *.d testSDL.o testSDL.exe testSDL.d

-include $(OBJECTS:.o=.d)

# Regla para SDL2
sdl: testSDL.exe

testSDL.o: testSDL.cpp SDL2Renderer.h
	$(CXX) $(SDL_CXXFLAGS) -c $< -o $@

SDL2Renderer.o: SDL2Renderer.cpp SDL2Renderer.h IRenderer.h
	$(CXX) $(SDL_CXXFLAGS) -c $< -o $@

testSDL.exe: testSDL.o SDL2Renderer.o
	$(CXX) $^ -o $@ $(SDL_LDFLAGS)

# Incluir dependencias automáticas de testSDL.o
-include testSDL.d
