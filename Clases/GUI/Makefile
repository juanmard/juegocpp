# Variables generales
CXX = g++
CXXFLAGS = -g -std=c++17 -MMD -MP

# Includes y libs Allegro
ALLEGRO_INCLUDES = -I../../allegro-4.4.2-mingw-4.5.2/include -static -DALLEGRO_STATICLINK
ALLEGRO_LDFLAGS = -L../../allegro-4.4.2-mingw-4.5.2/lib -lallegro-4.4.2-monolith-static-mt-debug \
     -lddraw -ldinput8 -ldsound -lwinmm -lcomctl32 -lgdi32 -lwsock32 \
     -lmsimg32 -ldxguid -lole32 -luuid -luser32 -lkernel32 -lopengl32 -lz -lm \
     -static -static-libgcc -static-libstdc++

# Leer flags estáticas SDL2 dinámicamente
SDL2_STATIC_CXXFLAGS := $(shell sdl2-config --cflags)
#SDL2_STATIC_CXXFLAGS := -ID:/msys64/mingw32/include/SDL2 -Dmain=SDL_main
SDL2_STATIC_LDFLAGS := $(shell sdl2-config --static-libs) -lSDL2_ttf -lfreetype -lz
#SDL2_STATIC_LDFLAGS := -LD:/msys64/mingw32/lib -lmingw32 -lSDL2main D:/msys64/mingw32/lib/libSDL2.a -lSDL2_ttf -lfreetype -lz -lm -lkernel32 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lversion -luuid -ladvapi32 -lsetupapi -lshell32 -ldinput8

# Fuentes y objetos de Allegro y SDL2
ALLEGRO_SOURCES = AllegroRenderer.cpp Control.cpp Dialog.cpp Menu.cpp SliderCtrl.cpp VectorCtrl.cpp testAllegro.cpp
ALLEGRO_OBJECTS = $(ALLEGRO_SOURCES:.cpp=.o)

SDL2_SOURCES = SDL2Input.cpp SDL2Renderer.cpp Control.cpp SliderCtrl.cpp testSDL.cpp 
SDL2_OBJECTS = $(SDL2_SOURCES:.cpp=.o)

# Objetivo por defecto (Allegro)
all: allegro

# Regla para compilar Allegro
allegro: $(ALLEGRO_OBJECTS)
	$(CXX) $^ -o testAllegro.exe $(ALLEGRO_LDFLAGS)

# Regla para compilar SDL2 estático
sdl: $(SDL2_OBJECTS)
	$(CXX) $^ -o testSDL.exe $(SDL2_STATIC_LDFLAGS)

# Compilar objetos Allegro
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(ALLEGRO_INCLUDES) -c $< -o $@

# Compilar objetos SDL2 con flags SDL estáticas
SDL2Input.o SDL2Renderer.o testSDL.o: %.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SDL2_STATIC_CXXFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(ALLEGRO_OBJECTS) $(SDL2_OBJECTS) menu testSDL.exe *.d

# Incluir dependencias automáticas
-include $(ALLEGRO_OBJECTS:.o=.d)
-include $(SDL2_OBJECTS:.o=.d)
