# Simple Makefile para compilar el juegocpp.
# sudo apt-get install liballegro4-dev (Debian/Ubuntu)
#
# v0.1: Modificado para ser usado bajo entorno MinGW32.
#
BASE=/d/Proyectos/Games/juegocpp
CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -I../allegro-4.4.2-mingw-4.5.0/include
LDFLAGS=-g -L../allegro-4.4.2-mingw-4.5.0/lib 
LDLIBS= ../allegro-4.4.2-mingw-4.5.0/lib/liballegro-4.4.2-monolith-mt.a

SRC=Actor.cpp Ben.cpp ControllableActor.cpp Escenario.cpp GUIVector.cpp Mago.cpp Pelota.cpp Sprite.cpp \
    VentanaALG.cpp ActorGraphic.cpp Bitmap.cpp ControlManager.cpp EscenarioGUI.cpp Herny.cpp Mapa.cpp \
    Peripheral.cpp StageManager.cpp ActorGUI.cpp Bloque.cpp DatFile.cpp Formulario.cpp ItemALG.cpp \
    Mask.cpp PhysicObject.cpp Suelo.cpp ActorManager.cpp BoxALG.cpp DialogALG.cpp Frame.cpp Juego2.cpp \
    MenuALG.cpp Plataforma.cpp Tesela.cpp AirCraft.cpp CollisionManager.cpp Dialog.cpp Game.cpp \
    Keyboard.cpp Menu.cpp PrintableObject.cpp TextALG.cpp Almacen.cpp ContadorGUI.cpp DirectorActor.cpp \
    GUIContador.cpp Ladrillo.cpp Mosaico.cpp ReadableObject.cpp Vector2Df.cpp AlmacenGUI.cpp ControlALG.cpp \
    DlgActor.cpp GUIControl.cpp LadrilloGUI.cpp Nombres.cpp Vector2Di.cpp BaseALG.cpp Control.cpp \
    EditorManager.cpp GUIEscenario.cpp Loro.cpp Paleta.cpp SoundManager.cpp VectorGUI.cpp

#OBJS=$(subst .cpp,.o,$(SRCS))
OBJS=Actor.o Ben.o ControllableActor.o Escenario.o GUIVector.o Mago.o Pelota.o Sprite.o \
    VentanaALG.o ActorGraphic.o Bitmap.o ControlManager.o EscenarioGUI.o Herny.o Mapa.o \
    Peripheral.o StageManager.o ActorGUI.o Bloque.o DatFile.o Formulario.o ItemALG.o \
    Mask.o PhysicObject.o Suelo.o ActorManager.o BoxALG.o DialogALG.o Frame.o Juego2.o \
    MenuALG.o Plataforma.o Tesela.o AirCraft.o CollisionManager.o Dialog.o Game.o \
    Keyboard.o Menu.o PrintableObject.o TextALG.o Almacen.o ContadorGUI.o DirectorActor.o \
    GUIContador.o Ladrillo.o Mosaico.o ReadableObject.o Vector2Df.o AlmacenGUI.o ControlALG.o \
    DlgActor.o GUIControl.o LadrilloGUI.o Nombres.o Vector2Di.o BaseALG.o Control.o \
    EditorManager.o GUIEscenario.o Loro.o Paleta.o SoundManager.o VectorGUI.o

# TODO: Comprobar si existe el subdirectorio de bibliotecas Allegro 4.4.2
# if [../allegro-4.4.2-mingw-4.5.0/]
# Si no existe, descargarlo y descomprimirlo (comprobar si wget y unzip están instalados).
# wget http://cdn.allegro.cc/file/library/allegro/4.4.2/allegro-4.4.2-mingw-4.5.0.zip
# unzip -q allegro-4.4.2-mingw-4.5.0.zip
#

all: juegocpp.exe

juegocpp.exe: $(OBJS)
	echo "Ficheros: $(OBJS)"
	$(CXX) $(LDFLAGS) -o juegocpp.exe $(OBJS) $(LDLIBS) 

install: juegocpp.exe
	mv juegocpp.exe ../Extras

clean:
	$(RM) $(OBJS)
	$(RM) ../Extras/juegocpp.exe

run: install
	bash -c "cd $(BASE)/Extras; chmod +x ./juegocpp.exe; exec ./juegocpp.exe"

