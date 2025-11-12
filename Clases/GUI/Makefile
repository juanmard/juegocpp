CXX = g++
CXXFLAGS = -std=c++17 -I../../allegro-4.4.2-mingw-4.5.2/include -static -DALLEGRO_STATICLINK
LDFLAGS = -L../../allegro-4.4.2-mingw-4.5.2/lib -lallegro-4.4.2-monolith-static-mt \
          -lddraw -ldinput8 -ldsound -lwinmm -lcomctl32 -lgdi32 -lwsock32 \
          -lmsimg32 -ldxguid -lole32 -luuid -luser32 -lkernel32 -lopengl32 -lz -lm \
          -static -static-libgcc -static-libstdc++

SOURCES = main.cpp Menu.cpp Control.cpp Dialog.cpp AllegroRenderer.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = menu

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
