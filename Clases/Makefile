ifndef MSYSTEM
$(error La variable de entorno MSYSTEM no está definida. No es un entorno MinGW32.)
else

# Continuar con makefile si estamos en un entorno de MINGW32.
ifeq ($(MSYSTEM),MINGW32)
# Directorios y herramientas.
SRCDIR=./
BUILDDIR=build
EXTRASDIR=../Extras
ALLEGRODIR=../allegro-4.4.2-mingw-4.5.2
MSYS_BIN_PATH=/d/Msys64/Mingw32/bin/

CXX=g++
RM=rm -f
WGET=wget
UNZIP=unzip
PACMAN=pacman

# Configuración para estático o dinámico.
#LINK_MODE=DYNAMIC
LINK_MODE=STATIC

# Rutas librerías e includes de Allegro según el tipo de compilación.
ifeq ($(LINK_MODE),STATIC)
    CPPFLAGS=-g -I../allegro-4.4.2-mingw-4.5.2/include -static -DALLEGRO_STATICLINK
    LDFLAGS=-static -L../allegro-4.4.2-mingw-4.5.2/lib
    LDLIBS=../allegro-4.4.2-mingw-4.5.2/lib/liballegro-4.4.2-monolith-static-mt.a \
           -ldinput8 -ldxguid -lddraw -lole32 -luuid -ldsound \
           -lwinmm -lgdi32 -lcomdlg32 -luser32 -lkernel32 -lopengl32 -lz -lm
    BUILD_SUBDIR=static
else ifeq ($(LINK_MODE),DYNAMIC)
    CPPFLAGS=-g -I../allegro-4.4.2-mingw-4.5.2/include
    LDFLAGS=-L../allegro-4.4.2-mingw-4.5.2/lib
    LDLIBS=../allegro-4.4.2-mingw-4.5.2/lib/liballegro-4.4.2-monolith-mt.a
    BUILD_SUBDIR=dynamic
endif

# Comprobación presencia Allegro.
CHECK_ALLEGRO=$(ALLEGRODIR)/lib

# Fuentes y Objetos.
SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/$(BUILD_SUBDIR)/%.o,$(SOURCES))

.PHONY: all
all: check_allegro dirs juegocpp.exe prepare run

# Comprobar existencia de Allegro o descargar.
.PHONY: check_allegro
check_allegro:
	@if [ ! -d $(CHECK_ALLEGRO) ]; then \
		echo "[info] Allegro no encontrado. Instalando wget y unzip si hace falta..."; \
		if ! command -v $(WGET) > /dev/null; then \
			$(PACMAN) -S --needed --noconfirm wget; \
		fi; \
		if ! command -v $(UNZIP) > /dev/null; then \
			$(PACMAN) -S --needed --noconfirm unzip; \
		fi; \
		echo "[info] Descargando Allegro 4.4.2..."; \
		$(WGET) http://cdn.allegro.cc/file/library/allegro/4.4.2/allegro-4.4.2-mingw-4.5.2.zip -O allegro.zip; \
		echo "[info] Descomprimiendo..."; \
		$(UNZIP) allegro.zip -d ../; \
		rm allegro.zip; \
	fi

# Crear directorios «build».
.PHONY: dirs
dirs:
	@mkdir -p $(BUILDDIR)/$(BUILD_SUBDIR)

# Compilar fuentes en OBJ en carpeta «build».
$(BUILDDIR)/$(BUILD_SUBDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

# Construir ejecutable.
juegocpp.exe: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(BUILDDIR)/$(BUILD_SUBDIR)/juegocpp.exe $^ $(LDFLAGS_LIBS) $(LDLIBS)

# Preparar recursos y copiar ejecutable.
.PHONY: prepare
prepare: juegocpp.exe
	cp $(EXTRASDIR)/sprites3.dat $(BUILDDIR)/$(BUILD_SUBDIR)/; \
	cp $(EXTRASDIR)/actores.txt $(BUILDDIR)/$(BUILD_SUBDIR)/; \
	cp $(EXTRASDIR)/test2.txt $(BUILDDIR)/$(BUILD_SUBDIR)/;
ifeq ($(LINK_MODE),DYNAMIC)
	cp $(ALLEGRODIR)/bin/allegro-4.4.2-monolith-mt.dll $(BUILDDIR)/$(BUILD_SUBDIR)/;
endif

.PHONY: run
run: prepare
	@echo "[info] Ejecutando el programa..."
	@bash -c "cd $(BUILDDIR)/$(BUILD_SUBDIR); ./juegocpp.exe"

.PHONY: clean
clean:
ifeq ($(LINK_MODE),STATIC)
	$(RM) -r $(BUILDDIR)/static
else ifeq ($(LINK_MODE),DYNAMIC)
	$(RM) -r $(BUILDDIR)/dynamic
endif
# Si no estamos en entorno MinGW32, salimos.
else
$(error Este Makefile solo funciona en entorno MinGW32.)
endif
endif