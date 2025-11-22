# Compilador y flags comunes
CXX = g++
CXXFLAGS = -g -std=c++17 -MMD -MP

# Include paths para Allegro y SDL2
ALLEGRO_INCLUDES = -I../../allegro-4.4.2-mingw-4.5.2/include -static -DALLEGRO_STATICLINK
SDL2_INCLUDES = -I/mingw32/include/SDL2

# Librerías en enlace para Allegro y SDL2
ALLEGRO_LDFLAGS = -L../../allegro-4.4.2-mingw-4.5.2/lib -lallegro-4.4.2-monolith-static-mt-debug \
    -lddraw -ldinput8 -ldsound -lwinmm -lcomctl32 -lgdi32 -lwsock32 \
    -lmsimg32 -ldxguid -lole32 -luuid -luser32 -lkernel32 -lopengl32 -lz -lm \
    -static -static-libgcc -static-libstdc++

SDL2_LDFLAGS = -L/mingw32/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -mwindows

# Archivos fuente Allegro y SDL2
ALLEGRO_SOURCES = AllegroRenderer.cpp Control.cpp Dialog.cpp testAllegro.cpp Menu.cpp SliderCtrl.cpp VectorCtrl.cpp
SDL2_SOURCES = SDL2Input.cpp SDL2Renderer.cpp testSDL.cpp

# Archivos objeto correspondientes
ALLEGRO_OBJECTS = $(ALLEGRO_SOURCES:.cpp=.o)
SDL2_OBJECTS = $(SDL2_SOURCES:.cpp=.o)

# Objetivo por defecto (Allegro)
all: allegro

# Construye ejecutable Allegro
allegro: $(ALLEGRO_OBJECTS)
	$(CXX) $^ -o testAllegro.exe $(ALLEGRO_LDFLAGS)

# Construye ejecutable SDL2
sdl: $(SDL2_OBJECTS)
	$(CXX) $^ -o testSDL.exe $(SDL2_LDFLAGS)

# Regla genérica para compilar con Allegro includes
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(ALLEGRO_INCLUDES) -c $< -o $@

# Regla específica para archivos SDL2 que usan SDL includes
SDL2Input.o SDL2Renderer.o testSDL.o: %.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SDL2_INCLUDES) -c $< -o $@

# Limpieza de objetos y ejecutables
clean:
	rm -f $(ALLEGRO_OBJECTS) $(SDL2_OBJECTS) testAllegro.exe testSDL.exe *.d

# Incluir archivos .d para dependencias automáticas
-include $(ALLEGRO_OBJECTS:.o=.d)
-include $(SDL2_OBJECTS:.o=.d)
