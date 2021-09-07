cmake_minimum_required(VERSION 3.16)

project(juegocpp)

add_executable(juegocpp)

include_directories(../allegro/include)

target_sources (juegocpp PUBLIC Actor.cpp Ben.cpp ControllableActor.cpp Escenario.cpp GUIVector.cpp Mago.cpp Pelota.cpp Sprite.cpp VentanaALG.cpp ActorGraphic.cpp Bitmap.cpp ControlManager.cpp EscenarioGUI.cpp Herny.cpp Mapa.cpp Peripheral.cpp StageManager.cpp ActorGUI.cpp Bloque.cpp DatFile.cpp Formulario.cpp ItemALG.cpp Mask.cpp PhysicObject.cpp Suelo.cpp ActorManager.cpp BoxALG.cpp DialogALG.cpp Frame.cpp Juego2.cpp MenuALG.cpp Plataforma.cpp Tesela.cpp AirCraft.cpp CollisionManager.cpp Dialog.cpp Game.cpp Keyboard.cpp Menu.cpp PrintableObject.cpp TextALG.cpp Almacen.cpp ContadorGUI.cpp DirectorActor.cpp GUIContador.cpp Ladrillo.cpp Mosaico.cpp ReadableObject.cpp Vector2Df.cpp AlmacenGUI.cpp ControlALG.cpp DlgActor.cpp GUIControl.cpp LadrilloGUI.cpp Nombres.cpp Vector2Di.cpp BaseALG.cpp Control.cpp EditorManager.cpp GUIEscenario.cpp Loro.cpp Paleta.cpp SoundManager.cpp VectorGUI.cpp)


install(TARGETS juegocpp)

enable_testing()
add_test(NAME juegocpp COMMAND juegocpp)
