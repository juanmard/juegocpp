##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=juegocpp
ConfigurationName      :=Debug
WorkspacePath          :=/home/juanma/Proyectos/juego-framework/CodeLite
ProjectPath            :=/home/juanma/Proyectos/juego-framework/CodeLite
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Juan Manuel Rico
Date                   :=17/12/19
CodeLitePath           :=/home/juanma/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="juegocpp.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -L/usr/lib/i386-linux-gnu -lalleg
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)../../guichan/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimageloader.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_ActorGraphic.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_CollisionManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_ControlManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_DatFile.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Control.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Escenario.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Frame.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Joystick.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Mapa.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Clases_Mask.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_allegro_allegrofont.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Nombres.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Peripheral.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_PrintableObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_SoundManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Sprite.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_allegro_allegroinput.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Tesela.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Vector2Df.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_up_guichan_src_actionevent.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_ActorManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_defaultfont.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_event.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_font.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_containerevent.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_selectionevent.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_genericinput.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_gui.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_ControlALG.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_up_guichan_src_image.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_BaseALG.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_inputevent.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_PhysicObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_ReadableObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Actor.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_key.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_mouseevent.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Plataforma.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_keyinput.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Clases_DialogALG.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_EditorManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_LadrilloGUI.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_graphics.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Pelota.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_text.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_GUIContador.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_MenuALG.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_guichan.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_keyevent.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Clases_VentanaALG.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_GUIVector.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_color.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Suelo.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_allegro_TimerAllegro.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Loro.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_allegro_JoystickAllegro.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_AlmacenGUI.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_focushandler.cpp$(ObjectSuffix) \
	

Objects1=$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimage.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_StageManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Ben.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_allegro_allegrographics.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_rectangle.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Herny.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_cliprectangle.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_VectorGUI2.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_imagefont.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_AirCraft.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Clases_Bitmap.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Paleta.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Mago.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_ControllableActor.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Timer.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_allegro_SpriteAllegro.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Ladrillo.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Dialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Menu.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Almacen.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Clases_Juego2.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Vector2Di.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_ItemALG.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_DirectorActor.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_exception.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_widget.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_BoxALG.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_GUIEscenario.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_GUIControl.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_EscenarioGUI2.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Clases_Mosaico.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_allegro_allegro.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Formulario.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_DlgActor.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_guichan_src_mouseinput.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_ContadorGUI.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Keyboard.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_TextALG.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_Bloque.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Clases_ActorGUI2.cpp$(ObjectSuffix) \
	



Objects=$(Objects0) $(Objects1) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	@echo $(Objects1) >> $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimageloader.cpp$(ObjectSuffix): ../../guichan/src/allegro/allegroimageloader.cpp $(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimageloader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/allegro/allegroimageloader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimageloader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimageloader.cpp$(DependSuffix): ../../guichan/src/allegro/allegroimageloader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimageloader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimageloader.cpp$(DependSuffix) -MM ../../guichan/src/allegro/allegroimageloader.cpp

$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimageloader.cpp$(PreprocessSuffix): ../../guichan/src/allegro/allegroimageloader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimageloader.cpp$(PreprocessSuffix) ../../guichan/src/allegro/allegroimageloader.cpp

$(IntermediateDirectory)/up_Clases_ActorGraphic.cpp$(ObjectSuffix): ../Clases/ActorGraphic.cpp $(IntermediateDirectory)/up_Clases_ActorGraphic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/ActorGraphic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_ActorGraphic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_ActorGraphic.cpp$(DependSuffix): ../Clases/ActorGraphic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_ActorGraphic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_ActorGraphic.cpp$(DependSuffix) -MM ../Clases/ActorGraphic.cpp

$(IntermediateDirectory)/up_Clases_ActorGraphic.cpp$(PreprocessSuffix): ../Clases/ActorGraphic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_ActorGraphic.cpp$(PreprocessSuffix) ../Clases/ActorGraphic.cpp

$(IntermediateDirectory)/up_Clases_CollisionManager.cpp$(ObjectSuffix): ../Clases/CollisionManager.cpp $(IntermediateDirectory)/up_Clases_CollisionManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/CollisionManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_CollisionManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_CollisionManager.cpp$(DependSuffix): ../Clases/CollisionManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_CollisionManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_CollisionManager.cpp$(DependSuffix) -MM ../Clases/CollisionManager.cpp

$(IntermediateDirectory)/up_Clases_CollisionManager.cpp$(PreprocessSuffix): ../Clases/CollisionManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_CollisionManager.cpp$(PreprocessSuffix) ../Clases/CollisionManager.cpp

$(IntermediateDirectory)/up_Clases_ControlManager.cpp$(ObjectSuffix): ../Clases/ControlManager.cpp $(IntermediateDirectory)/up_Clases_ControlManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/ControlManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_ControlManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_ControlManager.cpp$(DependSuffix): ../Clases/ControlManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_ControlManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_ControlManager.cpp$(DependSuffix) -MM ../Clases/ControlManager.cpp

$(IntermediateDirectory)/up_Clases_ControlManager.cpp$(PreprocessSuffix): ../Clases/ControlManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_ControlManager.cpp$(PreprocessSuffix) ../Clases/ControlManager.cpp

$(IntermediateDirectory)/up_Clases_DatFile.cpp$(ObjectSuffix): ../Clases/DatFile.cpp $(IntermediateDirectory)/up_Clases_DatFile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/DatFile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_DatFile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_DatFile.cpp$(DependSuffix): ../Clases/DatFile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_DatFile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_DatFile.cpp$(DependSuffix) -MM ../Clases/DatFile.cpp

$(IntermediateDirectory)/up_Clases_DatFile.cpp$(PreprocessSuffix): ../Clases/DatFile.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_DatFile.cpp$(PreprocessSuffix) ../Clases/DatFile.cpp

$(IntermediateDirectory)/up_Clases_Control.cpp$(ObjectSuffix): ../Clases/Control.cpp $(IntermediateDirectory)/up_Clases_Control.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Control.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Control.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Control.cpp$(DependSuffix): ../Clases/Control.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Control.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Control.cpp$(DependSuffix) -MM ../Clases/Control.cpp

$(IntermediateDirectory)/up_Clases_Control.cpp$(PreprocessSuffix): ../Clases/Control.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Control.cpp$(PreprocessSuffix) ../Clases/Control.cpp

$(IntermediateDirectory)/up_Clases_Escenario.cpp$(ObjectSuffix): ../Clases/Escenario.cpp $(IntermediateDirectory)/up_Clases_Escenario.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Escenario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Escenario.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Escenario.cpp$(DependSuffix): ../Clases/Escenario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Escenario.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Escenario.cpp$(DependSuffix) -MM ../Clases/Escenario.cpp

$(IntermediateDirectory)/up_Clases_Escenario.cpp$(PreprocessSuffix): ../Clases/Escenario.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Escenario.cpp$(PreprocessSuffix) ../Clases/Escenario.cpp

$(IntermediateDirectory)/up_Clases_Frame.cpp$(ObjectSuffix): ../Clases/Frame.cpp $(IntermediateDirectory)/up_Clases_Frame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Frame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Frame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Frame.cpp$(DependSuffix): ../Clases/Frame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Frame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Frame.cpp$(DependSuffix) -MM ../Clases/Frame.cpp

$(IntermediateDirectory)/up_Clases_Frame.cpp$(PreprocessSuffix): ../Clases/Frame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Frame.cpp$(PreprocessSuffix) ../Clases/Frame.cpp

$(IntermediateDirectory)/up_Clases_Joystick.cpp$(ObjectSuffix): ../Clases/Joystick.cpp $(IntermediateDirectory)/up_Clases_Joystick.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Joystick.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Joystick.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Joystick.cpp$(DependSuffix): ../Clases/Joystick.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Joystick.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Joystick.cpp$(DependSuffix) -MM ../Clases/Joystick.cpp

$(IntermediateDirectory)/up_Clases_Joystick.cpp$(PreprocessSuffix): ../Clases/Joystick.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Joystick.cpp$(PreprocessSuffix) ../Clases/Joystick.cpp

$(IntermediateDirectory)/up_Clases_Mapa.cpp$(ObjectSuffix): ../Clases/Mapa.cpp $(IntermediateDirectory)/up_Clases_Mapa.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Mapa.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Mapa.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Mapa.cpp$(DependSuffix): ../Clases/Mapa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Mapa.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Mapa.cpp$(DependSuffix) -MM ../Clases/Mapa.cpp

$(IntermediateDirectory)/up_Clases_Mapa.cpp$(PreprocessSuffix): ../Clases/Mapa.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Mapa.cpp$(PreprocessSuffix) ../Clases/Mapa.cpp

$(IntermediateDirectory)/up_Clases_Mask.cpp$(ObjectSuffix): ../Clases/Mask.cpp $(IntermediateDirectory)/up_Clases_Mask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Mask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Mask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Mask.cpp$(DependSuffix): ../Clases/Mask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Mask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Mask.cpp$(DependSuffix) -MM ../Clases/Mask.cpp

$(IntermediateDirectory)/up_Clases_Mask.cpp$(PreprocessSuffix): ../Clases/Mask.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Mask.cpp$(PreprocessSuffix) ../Clases/Mask.cpp

$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrofont.cpp$(ObjectSuffix): ../../guichan/src/allegro/allegrofont.cpp $(IntermediateDirectory)/up_up_guichan_src_allegro_allegrofont.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/allegro/allegrofont.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrofont.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrofont.cpp$(DependSuffix): ../../guichan/src/allegro/allegrofont.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrofont.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrofont.cpp$(DependSuffix) -MM ../../guichan/src/allegro/allegrofont.cpp

$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrofont.cpp$(PreprocessSuffix): ../../guichan/src/allegro/allegrofont.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_allegro_allegrofont.cpp$(PreprocessSuffix) ../../guichan/src/allegro/allegrofont.cpp

$(IntermediateDirectory)/up_Clases_Nombres.cpp$(ObjectSuffix): ../Clases/Nombres.cpp $(IntermediateDirectory)/up_Clases_Nombres.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Nombres.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Nombres.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Nombres.cpp$(DependSuffix): ../Clases/Nombres.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Nombres.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Nombres.cpp$(DependSuffix) -MM ../Clases/Nombres.cpp

$(IntermediateDirectory)/up_Clases_Nombres.cpp$(PreprocessSuffix): ../Clases/Nombres.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Nombres.cpp$(PreprocessSuffix) ../Clases/Nombres.cpp

$(IntermediateDirectory)/up_Clases_Peripheral.cpp$(ObjectSuffix): ../Clases/Peripheral.cpp $(IntermediateDirectory)/up_Clases_Peripheral.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Peripheral.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Peripheral.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Peripheral.cpp$(DependSuffix): ../Clases/Peripheral.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Peripheral.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Peripheral.cpp$(DependSuffix) -MM ../Clases/Peripheral.cpp

$(IntermediateDirectory)/up_Clases_Peripheral.cpp$(PreprocessSuffix): ../Clases/Peripheral.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Peripheral.cpp$(PreprocessSuffix) ../Clases/Peripheral.cpp

$(IntermediateDirectory)/up_Clases_PrintableObject.cpp$(ObjectSuffix): ../Clases/PrintableObject.cpp $(IntermediateDirectory)/up_Clases_PrintableObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/PrintableObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_PrintableObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_PrintableObject.cpp$(DependSuffix): ../Clases/PrintableObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_PrintableObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_PrintableObject.cpp$(DependSuffix) -MM ../Clases/PrintableObject.cpp

$(IntermediateDirectory)/up_Clases_PrintableObject.cpp$(PreprocessSuffix): ../Clases/PrintableObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_PrintableObject.cpp$(PreprocessSuffix) ../Clases/PrintableObject.cpp

$(IntermediateDirectory)/up_Clases_SoundManager.cpp$(ObjectSuffix): ../Clases/SoundManager.cpp $(IntermediateDirectory)/up_Clases_SoundManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/SoundManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_SoundManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_SoundManager.cpp$(DependSuffix): ../Clases/SoundManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_SoundManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_SoundManager.cpp$(DependSuffix) -MM ../Clases/SoundManager.cpp

$(IntermediateDirectory)/up_Clases_SoundManager.cpp$(PreprocessSuffix): ../Clases/SoundManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_SoundManager.cpp$(PreprocessSuffix) ../Clases/SoundManager.cpp

$(IntermediateDirectory)/up_Clases_Sprite.cpp$(ObjectSuffix): ../Clases/Sprite.cpp $(IntermediateDirectory)/up_Clases_Sprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Sprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Sprite.cpp$(DependSuffix): ../Clases/Sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Sprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Sprite.cpp$(DependSuffix) -MM ../Clases/Sprite.cpp

$(IntermediateDirectory)/up_Clases_Sprite.cpp$(PreprocessSuffix): ../Clases/Sprite.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Sprite.cpp$(PreprocessSuffix) ../Clases/Sprite.cpp

$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroinput.cpp$(ObjectSuffix): ../../guichan/src/allegro/allegroinput.cpp $(IntermediateDirectory)/up_up_guichan_src_allegro_allegroinput.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/allegro/allegroinput.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroinput.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroinput.cpp$(DependSuffix): ../../guichan/src/allegro/allegroinput.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroinput.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroinput.cpp$(DependSuffix) -MM ../../guichan/src/allegro/allegroinput.cpp

$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroinput.cpp$(PreprocessSuffix): ../../guichan/src/allegro/allegroinput.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_allegro_allegroinput.cpp$(PreprocessSuffix) ../../guichan/src/allegro/allegroinput.cpp

$(IntermediateDirectory)/up_Clases_Tesela.cpp$(ObjectSuffix): ../Clases/Tesela.cpp $(IntermediateDirectory)/up_Clases_Tesela.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Tesela.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Tesela.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Tesela.cpp$(DependSuffix): ../Clases/Tesela.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Tesela.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Tesela.cpp$(DependSuffix) -MM ../Clases/Tesela.cpp

$(IntermediateDirectory)/up_Clases_Tesela.cpp$(PreprocessSuffix): ../Clases/Tesela.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Tesela.cpp$(PreprocessSuffix) ../Clases/Tesela.cpp

$(IntermediateDirectory)/up_Clases_Vector2Df.cpp$(ObjectSuffix): ../Clases/Vector2Df.cpp $(IntermediateDirectory)/up_Clases_Vector2Df.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Vector2Df.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Vector2Df.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Vector2Df.cpp$(DependSuffix): ../Clases/Vector2Df.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Vector2Df.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Vector2Df.cpp$(DependSuffix) -MM ../Clases/Vector2Df.cpp

$(IntermediateDirectory)/up_Clases_Vector2Df.cpp$(PreprocessSuffix): ../Clases/Vector2Df.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Vector2Df.cpp$(PreprocessSuffix) ../Clases/Vector2Df.cpp

$(IntermediateDirectory)/up_up_guichan_src_actionevent.cpp$(ObjectSuffix): ../../guichan/src/actionevent.cpp $(IntermediateDirectory)/up_up_guichan_src_actionevent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/actionevent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_actionevent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_actionevent.cpp$(DependSuffix): ../../guichan/src/actionevent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_actionevent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_actionevent.cpp$(DependSuffix) -MM ../../guichan/src/actionevent.cpp

$(IntermediateDirectory)/up_up_guichan_src_actionevent.cpp$(PreprocessSuffix): ../../guichan/src/actionevent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_actionevent.cpp$(PreprocessSuffix) ../../guichan/src/actionevent.cpp

$(IntermediateDirectory)/up_Clases_ActorManager.cpp$(ObjectSuffix): ../Clases/ActorManager.cpp $(IntermediateDirectory)/up_Clases_ActorManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/ActorManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_ActorManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_ActorManager.cpp$(DependSuffix): ../Clases/ActorManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_ActorManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_ActorManager.cpp$(DependSuffix) -MM ../Clases/ActorManager.cpp

$(IntermediateDirectory)/up_Clases_ActorManager.cpp$(PreprocessSuffix): ../Clases/ActorManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_ActorManager.cpp$(PreprocessSuffix) ../Clases/ActorManager.cpp

$(IntermediateDirectory)/up_up_guichan_src_defaultfont.cpp$(ObjectSuffix): ../../guichan/src/defaultfont.cpp $(IntermediateDirectory)/up_up_guichan_src_defaultfont.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/defaultfont.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_defaultfont.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_defaultfont.cpp$(DependSuffix): ../../guichan/src/defaultfont.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_defaultfont.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_defaultfont.cpp$(DependSuffix) -MM ../../guichan/src/defaultfont.cpp

$(IntermediateDirectory)/up_up_guichan_src_defaultfont.cpp$(PreprocessSuffix): ../../guichan/src/defaultfont.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_defaultfont.cpp$(PreprocessSuffix) ../../guichan/src/defaultfont.cpp

$(IntermediateDirectory)/up_up_guichan_src_event.cpp$(ObjectSuffix): ../../guichan/src/event.cpp $(IntermediateDirectory)/up_up_guichan_src_event.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_event.cpp$(DependSuffix): ../../guichan/src/event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_event.cpp$(DependSuffix) -MM ../../guichan/src/event.cpp

$(IntermediateDirectory)/up_up_guichan_src_event.cpp$(PreprocessSuffix): ../../guichan/src/event.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_event.cpp$(PreprocessSuffix) ../../guichan/src/event.cpp

$(IntermediateDirectory)/up_up_guichan_src_font.cpp$(ObjectSuffix): ../../guichan/src/font.cpp $(IntermediateDirectory)/up_up_guichan_src_font.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/font.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_font.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_font.cpp$(DependSuffix): ../../guichan/src/font.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_font.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_font.cpp$(DependSuffix) -MM ../../guichan/src/font.cpp

$(IntermediateDirectory)/up_up_guichan_src_font.cpp$(PreprocessSuffix): ../../guichan/src/font.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_font.cpp$(PreprocessSuffix) ../../guichan/src/font.cpp

$(IntermediateDirectory)/up_up_guichan_src_containerevent.cpp$(ObjectSuffix): ../../guichan/src/containerevent.cpp $(IntermediateDirectory)/up_up_guichan_src_containerevent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/containerevent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_containerevent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_containerevent.cpp$(DependSuffix): ../../guichan/src/containerevent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_containerevent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_containerevent.cpp$(DependSuffix) -MM ../../guichan/src/containerevent.cpp

$(IntermediateDirectory)/up_up_guichan_src_containerevent.cpp$(PreprocessSuffix): ../../guichan/src/containerevent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_containerevent.cpp$(PreprocessSuffix) ../../guichan/src/containerevent.cpp

$(IntermediateDirectory)/up_up_guichan_src_selectionevent.cpp$(ObjectSuffix): ../../guichan/src/selectionevent.cpp $(IntermediateDirectory)/up_up_guichan_src_selectionevent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/selectionevent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_selectionevent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_selectionevent.cpp$(DependSuffix): ../../guichan/src/selectionevent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_selectionevent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_selectionevent.cpp$(DependSuffix) -MM ../../guichan/src/selectionevent.cpp

$(IntermediateDirectory)/up_up_guichan_src_selectionevent.cpp$(PreprocessSuffix): ../../guichan/src/selectionevent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_selectionevent.cpp$(PreprocessSuffix) ../../guichan/src/selectionevent.cpp

$(IntermediateDirectory)/up_up_guichan_src_genericinput.cpp$(ObjectSuffix): ../../guichan/src/genericinput.cpp $(IntermediateDirectory)/up_up_guichan_src_genericinput.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/genericinput.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_genericinput.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_genericinput.cpp$(DependSuffix): ../../guichan/src/genericinput.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_genericinput.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_genericinput.cpp$(DependSuffix) -MM ../../guichan/src/genericinput.cpp

$(IntermediateDirectory)/up_up_guichan_src_genericinput.cpp$(PreprocessSuffix): ../../guichan/src/genericinput.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_genericinput.cpp$(PreprocessSuffix) ../../guichan/src/genericinput.cpp

$(IntermediateDirectory)/up_up_guichan_src_gui.cpp$(ObjectSuffix): ../../guichan/src/gui.cpp $(IntermediateDirectory)/up_up_guichan_src_gui.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/gui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_gui.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_gui.cpp$(DependSuffix): ../../guichan/src/gui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_gui.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_gui.cpp$(DependSuffix) -MM ../../guichan/src/gui.cpp

$(IntermediateDirectory)/up_up_guichan_src_gui.cpp$(PreprocessSuffix): ../../guichan/src/gui.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_gui.cpp$(PreprocessSuffix) ../../guichan/src/gui.cpp

$(IntermediateDirectory)/up_Clases_ControlALG.cpp$(ObjectSuffix): ../Clases/ControlALG.cpp $(IntermediateDirectory)/up_Clases_ControlALG.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/ControlALG.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_ControlALG.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_ControlALG.cpp$(DependSuffix): ../Clases/ControlALG.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_ControlALG.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_ControlALG.cpp$(DependSuffix) -MM ../Clases/ControlALG.cpp

$(IntermediateDirectory)/up_Clases_ControlALG.cpp$(PreprocessSuffix): ../Clases/ControlALG.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_ControlALG.cpp$(PreprocessSuffix) ../Clases/ControlALG.cpp

$(IntermediateDirectory)/up_up_guichan_src_image.cpp$(ObjectSuffix): ../../guichan/src/image.cpp $(IntermediateDirectory)/up_up_guichan_src_image.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/image.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_image.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_image.cpp$(DependSuffix): ../../guichan/src/image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_image.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_image.cpp$(DependSuffix) -MM ../../guichan/src/image.cpp

$(IntermediateDirectory)/up_up_guichan_src_image.cpp$(PreprocessSuffix): ../../guichan/src/image.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_image.cpp$(PreprocessSuffix) ../../guichan/src/image.cpp

$(IntermediateDirectory)/up_Clases_BaseALG.cpp$(ObjectSuffix): ../Clases/BaseALG.cpp $(IntermediateDirectory)/up_Clases_BaseALG.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/BaseALG.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_BaseALG.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_BaseALG.cpp$(DependSuffix): ../Clases/BaseALG.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_BaseALG.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_BaseALG.cpp$(DependSuffix) -MM ../Clases/BaseALG.cpp

$(IntermediateDirectory)/up_Clases_BaseALG.cpp$(PreprocessSuffix): ../Clases/BaseALG.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_BaseALG.cpp$(PreprocessSuffix) ../Clases/BaseALG.cpp

$(IntermediateDirectory)/up_up_guichan_src_inputevent.cpp$(ObjectSuffix): ../../guichan/src/inputevent.cpp $(IntermediateDirectory)/up_up_guichan_src_inputevent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/inputevent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_inputevent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_inputevent.cpp$(DependSuffix): ../../guichan/src/inputevent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_inputevent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_inputevent.cpp$(DependSuffix) -MM ../../guichan/src/inputevent.cpp

$(IntermediateDirectory)/up_up_guichan_src_inputevent.cpp$(PreprocessSuffix): ../../guichan/src/inputevent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_inputevent.cpp$(PreprocessSuffix) ../../guichan/src/inputevent.cpp

$(IntermediateDirectory)/up_Clases_PhysicObject.cpp$(ObjectSuffix): ../Clases/PhysicObject.cpp $(IntermediateDirectory)/up_Clases_PhysicObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/PhysicObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_PhysicObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_PhysicObject.cpp$(DependSuffix): ../Clases/PhysicObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_PhysicObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_PhysicObject.cpp$(DependSuffix) -MM ../Clases/PhysicObject.cpp

$(IntermediateDirectory)/up_Clases_PhysicObject.cpp$(PreprocessSuffix): ../Clases/PhysicObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_PhysicObject.cpp$(PreprocessSuffix) ../Clases/PhysicObject.cpp

$(IntermediateDirectory)/up_Clases_ReadableObject.cpp$(ObjectSuffix): ../Clases/ReadableObject.cpp $(IntermediateDirectory)/up_Clases_ReadableObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/ReadableObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_ReadableObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_ReadableObject.cpp$(DependSuffix): ../Clases/ReadableObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_ReadableObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_ReadableObject.cpp$(DependSuffix) -MM ../Clases/ReadableObject.cpp

$(IntermediateDirectory)/up_Clases_ReadableObject.cpp$(PreprocessSuffix): ../Clases/ReadableObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_ReadableObject.cpp$(PreprocessSuffix) ../Clases/ReadableObject.cpp

$(IntermediateDirectory)/up_Clases_Actor.cpp$(ObjectSuffix): ../Clases/Actor.cpp $(IntermediateDirectory)/up_Clases_Actor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Actor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Actor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Actor.cpp$(DependSuffix): ../Clases/Actor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Actor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Actor.cpp$(DependSuffix) -MM ../Clases/Actor.cpp

$(IntermediateDirectory)/up_Clases_Actor.cpp$(PreprocessSuffix): ../Clases/Actor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Actor.cpp$(PreprocessSuffix) ../Clases/Actor.cpp

$(IntermediateDirectory)/up_up_guichan_src_key.cpp$(ObjectSuffix): ../../guichan/src/key.cpp $(IntermediateDirectory)/up_up_guichan_src_key.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/key.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_key.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_key.cpp$(DependSuffix): ../../guichan/src/key.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_key.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_key.cpp$(DependSuffix) -MM ../../guichan/src/key.cpp

$(IntermediateDirectory)/up_up_guichan_src_key.cpp$(PreprocessSuffix): ../../guichan/src/key.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_key.cpp$(PreprocessSuffix) ../../guichan/src/key.cpp

$(IntermediateDirectory)/up_up_guichan_src_mouseevent.cpp$(ObjectSuffix): ../../guichan/src/mouseevent.cpp $(IntermediateDirectory)/up_up_guichan_src_mouseevent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/mouseevent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_mouseevent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_mouseevent.cpp$(DependSuffix): ../../guichan/src/mouseevent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_mouseevent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_mouseevent.cpp$(DependSuffix) -MM ../../guichan/src/mouseevent.cpp

$(IntermediateDirectory)/up_up_guichan_src_mouseevent.cpp$(PreprocessSuffix): ../../guichan/src/mouseevent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_mouseevent.cpp$(PreprocessSuffix) ../../guichan/src/mouseevent.cpp

$(IntermediateDirectory)/up_Clases_Plataforma.cpp$(ObjectSuffix): ../Clases/Plataforma.cpp $(IntermediateDirectory)/up_Clases_Plataforma.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Plataforma.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Plataforma.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Plataforma.cpp$(DependSuffix): ../Clases/Plataforma.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Plataforma.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Plataforma.cpp$(DependSuffix) -MM ../Clases/Plataforma.cpp

$(IntermediateDirectory)/up_Clases_Plataforma.cpp$(PreprocessSuffix): ../Clases/Plataforma.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Plataforma.cpp$(PreprocessSuffix) ../Clases/Plataforma.cpp

$(IntermediateDirectory)/up_up_guichan_src_keyinput.cpp$(ObjectSuffix): ../../guichan/src/keyinput.cpp $(IntermediateDirectory)/up_up_guichan_src_keyinput.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/keyinput.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_keyinput.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_keyinput.cpp$(DependSuffix): ../../guichan/src/keyinput.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_keyinput.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_keyinput.cpp$(DependSuffix) -MM ../../guichan/src/keyinput.cpp

$(IntermediateDirectory)/up_up_guichan_src_keyinput.cpp$(PreprocessSuffix): ../../guichan/src/keyinput.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_keyinput.cpp$(PreprocessSuffix) ../../guichan/src/keyinput.cpp

$(IntermediateDirectory)/up_Clases_DialogALG.cpp$(ObjectSuffix): ../Clases/DialogALG.cpp $(IntermediateDirectory)/up_Clases_DialogALG.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/DialogALG.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_DialogALG.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_DialogALG.cpp$(DependSuffix): ../Clases/DialogALG.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_DialogALG.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_DialogALG.cpp$(DependSuffix) -MM ../Clases/DialogALG.cpp

$(IntermediateDirectory)/up_Clases_DialogALG.cpp$(PreprocessSuffix): ../Clases/DialogALG.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_DialogALG.cpp$(PreprocessSuffix) ../Clases/DialogALG.cpp

$(IntermediateDirectory)/up_Clases_EditorManager.cpp$(ObjectSuffix): ../Clases/EditorManager.cpp $(IntermediateDirectory)/up_Clases_EditorManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/EditorManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_EditorManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_EditorManager.cpp$(DependSuffix): ../Clases/EditorManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_EditorManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_EditorManager.cpp$(DependSuffix) -MM ../Clases/EditorManager.cpp

$(IntermediateDirectory)/up_Clases_EditorManager.cpp$(PreprocessSuffix): ../Clases/EditorManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_EditorManager.cpp$(PreprocessSuffix) ../Clases/EditorManager.cpp

$(IntermediateDirectory)/up_Clases_LadrilloGUI.cpp$(ObjectSuffix): ../Clases/LadrilloGUI.cpp $(IntermediateDirectory)/up_Clases_LadrilloGUI.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/LadrilloGUI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_LadrilloGUI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_LadrilloGUI.cpp$(DependSuffix): ../Clases/LadrilloGUI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_LadrilloGUI.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_LadrilloGUI.cpp$(DependSuffix) -MM ../Clases/LadrilloGUI.cpp

$(IntermediateDirectory)/up_Clases_LadrilloGUI.cpp$(PreprocessSuffix): ../Clases/LadrilloGUI.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_LadrilloGUI.cpp$(PreprocessSuffix) ../Clases/LadrilloGUI.cpp

$(IntermediateDirectory)/up_up_guichan_src_graphics.cpp$(ObjectSuffix): ../../guichan/src/graphics.cpp $(IntermediateDirectory)/up_up_guichan_src_graphics.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/graphics.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_graphics.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_graphics.cpp$(DependSuffix): ../../guichan/src/graphics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_graphics.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_graphics.cpp$(DependSuffix) -MM ../../guichan/src/graphics.cpp

$(IntermediateDirectory)/up_up_guichan_src_graphics.cpp$(PreprocessSuffix): ../../guichan/src/graphics.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_graphics.cpp$(PreprocessSuffix) ../../guichan/src/graphics.cpp

$(IntermediateDirectory)/up_Clases_Pelota.cpp$(ObjectSuffix): ../Clases/Pelota.cpp $(IntermediateDirectory)/up_Clases_Pelota.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Pelota.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Pelota.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Pelota.cpp$(DependSuffix): ../Clases/Pelota.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Pelota.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Pelota.cpp$(DependSuffix) -MM ../Clases/Pelota.cpp

$(IntermediateDirectory)/up_Clases_Pelota.cpp$(PreprocessSuffix): ../Clases/Pelota.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Pelota.cpp$(PreprocessSuffix) ../Clases/Pelota.cpp

$(IntermediateDirectory)/up_up_guichan_src_text.cpp$(ObjectSuffix): ../../guichan/src/text.cpp $(IntermediateDirectory)/up_up_guichan_src_text.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/text.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_text.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_text.cpp$(DependSuffix): ../../guichan/src/text.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_text.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_text.cpp$(DependSuffix) -MM ../../guichan/src/text.cpp

$(IntermediateDirectory)/up_up_guichan_src_text.cpp$(PreprocessSuffix): ../../guichan/src/text.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_text.cpp$(PreprocessSuffix) ../../guichan/src/text.cpp

$(IntermediateDirectory)/up_Clases_GUIContador.cpp$(ObjectSuffix): ../Clases/GUIContador.cpp $(IntermediateDirectory)/up_Clases_GUIContador.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/GUIContador.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_GUIContador.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_GUIContador.cpp$(DependSuffix): ../Clases/GUIContador.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_GUIContador.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_GUIContador.cpp$(DependSuffix) -MM ../Clases/GUIContador.cpp

$(IntermediateDirectory)/up_Clases_GUIContador.cpp$(PreprocessSuffix): ../Clases/GUIContador.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_GUIContador.cpp$(PreprocessSuffix) ../Clases/GUIContador.cpp

$(IntermediateDirectory)/up_Clases_MenuALG.cpp$(ObjectSuffix): ../Clases/MenuALG.cpp $(IntermediateDirectory)/up_Clases_MenuALG.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/MenuALG.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_MenuALG.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_MenuALG.cpp$(DependSuffix): ../Clases/MenuALG.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_MenuALG.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_MenuALG.cpp$(DependSuffix) -MM ../Clases/MenuALG.cpp

$(IntermediateDirectory)/up_Clases_MenuALG.cpp$(PreprocessSuffix): ../Clases/MenuALG.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_MenuALG.cpp$(PreprocessSuffix) ../Clases/MenuALG.cpp

$(IntermediateDirectory)/up_up_guichan_src_guichan.cpp$(ObjectSuffix): ../../guichan/src/guichan.cpp $(IntermediateDirectory)/up_up_guichan_src_guichan.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/guichan.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_guichan.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_guichan.cpp$(DependSuffix): ../../guichan/src/guichan.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_guichan.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_guichan.cpp$(DependSuffix) -MM ../../guichan/src/guichan.cpp

$(IntermediateDirectory)/up_up_guichan_src_guichan.cpp$(PreprocessSuffix): ../../guichan/src/guichan.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_guichan.cpp$(PreprocessSuffix) ../../guichan/src/guichan.cpp

$(IntermediateDirectory)/up_up_guichan_src_keyevent.cpp$(ObjectSuffix): ../../guichan/src/keyevent.cpp $(IntermediateDirectory)/up_up_guichan_src_keyevent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/keyevent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_keyevent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_keyevent.cpp$(DependSuffix): ../../guichan/src/keyevent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_keyevent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_keyevent.cpp$(DependSuffix) -MM ../../guichan/src/keyevent.cpp

$(IntermediateDirectory)/up_up_guichan_src_keyevent.cpp$(PreprocessSuffix): ../../guichan/src/keyevent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_keyevent.cpp$(PreprocessSuffix) ../../guichan/src/keyevent.cpp

$(IntermediateDirectory)/up_Clases_VentanaALG.cpp$(ObjectSuffix): ../Clases/VentanaALG.cpp $(IntermediateDirectory)/up_Clases_VentanaALG.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/VentanaALG.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_VentanaALG.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_VentanaALG.cpp$(DependSuffix): ../Clases/VentanaALG.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_VentanaALG.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_VentanaALG.cpp$(DependSuffix) -MM ../Clases/VentanaALG.cpp

$(IntermediateDirectory)/up_Clases_VentanaALG.cpp$(PreprocessSuffix): ../Clases/VentanaALG.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_VentanaALG.cpp$(PreprocessSuffix) ../Clases/VentanaALG.cpp

$(IntermediateDirectory)/up_Clases_GUIVector.cpp$(ObjectSuffix): ../Clases/GUIVector.cpp $(IntermediateDirectory)/up_Clases_GUIVector.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/GUIVector.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_GUIVector.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_GUIVector.cpp$(DependSuffix): ../Clases/GUIVector.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_GUIVector.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_GUIVector.cpp$(DependSuffix) -MM ../Clases/GUIVector.cpp

$(IntermediateDirectory)/up_Clases_GUIVector.cpp$(PreprocessSuffix): ../Clases/GUIVector.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_GUIVector.cpp$(PreprocessSuffix) ../Clases/GUIVector.cpp

$(IntermediateDirectory)/up_up_guichan_src_color.cpp$(ObjectSuffix): ../../guichan/src/color.cpp $(IntermediateDirectory)/up_up_guichan_src_color.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/color.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_color.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_color.cpp$(DependSuffix): ../../guichan/src/color.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_color.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_color.cpp$(DependSuffix) -MM ../../guichan/src/color.cpp

$(IntermediateDirectory)/up_up_guichan_src_color.cpp$(PreprocessSuffix): ../../guichan/src/color.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_color.cpp$(PreprocessSuffix) ../../guichan/src/color.cpp

$(IntermediateDirectory)/up_Clases_Suelo.cpp$(ObjectSuffix): ../Clases/Suelo.cpp $(IntermediateDirectory)/up_Clases_Suelo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Suelo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Suelo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Suelo.cpp$(DependSuffix): ../Clases/Suelo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Suelo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Suelo.cpp$(DependSuffix) -MM ../Clases/Suelo.cpp

$(IntermediateDirectory)/up_Clases_Suelo.cpp$(PreprocessSuffix): ../Clases/Suelo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Suelo.cpp$(PreprocessSuffix) ../Clases/Suelo.cpp

$(IntermediateDirectory)/up_Clases_allegro_TimerAllegro.cpp$(ObjectSuffix): ../Clases/allegro/TimerAllegro.cpp $(IntermediateDirectory)/up_Clases_allegro_TimerAllegro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/allegro/TimerAllegro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_allegro_TimerAllegro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_allegro_TimerAllegro.cpp$(DependSuffix): ../Clases/allegro/TimerAllegro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_allegro_TimerAllegro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_allegro_TimerAllegro.cpp$(DependSuffix) -MM ../Clases/allegro/TimerAllegro.cpp

$(IntermediateDirectory)/up_Clases_allegro_TimerAllegro.cpp$(PreprocessSuffix): ../Clases/allegro/TimerAllegro.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_allegro_TimerAllegro.cpp$(PreprocessSuffix) ../Clases/allegro/TimerAllegro.cpp

$(IntermediateDirectory)/up_Clases_Loro.cpp$(ObjectSuffix): ../Clases/Loro.cpp $(IntermediateDirectory)/up_Clases_Loro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Loro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Loro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Loro.cpp$(DependSuffix): ../Clases/Loro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Loro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Loro.cpp$(DependSuffix) -MM ../Clases/Loro.cpp

$(IntermediateDirectory)/up_Clases_Loro.cpp$(PreprocessSuffix): ../Clases/Loro.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Loro.cpp$(PreprocessSuffix) ../Clases/Loro.cpp

$(IntermediateDirectory)/up_Clases_allegro_JoystickAllegro.cpp$(ObjectSuffix): ../Clases/allegro/JoystickAllegro.cpp $(IntermediateDirectory)/up_Clases_allegro_JoystickAllegro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/allegro/JoystickAllegro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_allegro_JoystickAllegro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_allegro_JoystickAllegro.cpp$(DependSuffix): ../Clases/allegro/JoystickAllegro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_allegro_JoystickAllegro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_allegro_JoystickAllegro.cpp$(DependSuffix) -MM ../Clases/allegro/JoystickAllegro.cpp

$(IntermediateDirectory)/up_Clases_allegro_JoystickAllegro.cpp$(PreprocessSuffix): ../Clases/allegro/JoystickAllegro.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_allegro_JoystickAllegro.cpp$(PreprocessSuffix) ../Clases/allegro/JoystickAllegro.cpp

$(IntermediateDirectory)/up_Clases_Game.cpp$(ObjectSuffix): ../Clases/Game.cpp $(IntermediateDirectory)/up_Clases_Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Game.cpp$(DependSuffix): ../Clases/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Game.cpp$(DependSuffix) -MM ../Clases/Game.cpp

$(IntermediateDirectory)/up_Clases_Game.cpp$(PreprocessSuffix): ../Clases/Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Game.cpp$(PreprocessSuffix) ../Clases/Game.cpp

$(IntermediateDirectory)/up_Clases_AlmacenGUI.cpp$(ObjectSuffix): ../Clases/AlmacenGUI.cpp $(IntermediateDirectory)/up_Clases_AlmacenGUI.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/AlmacenGUI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_AlmacenGUI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_AlmacenGUI.cpp$(DependSuffix): ../Clases/AlmacenGUI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_AlmacenGUI.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_AlmacenGUI.cpp$(DependSuffix) -MM ../Clases/AlmacenGUI.cpp

$(IntermediateDirectory)/up_Clases_AlmacenGUI.cpp$(PreprocessSuffix): ../Clases/AlmacenGUI.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_AlmacenGUI.cpp$(PreprocessSuffix) ../Clases/AlmacenGUI.cpp

$(IntermediateDirectory)/up_up_guichan_src_focushandler.cpp$(ObjectSuffix): ../../guichan/src/focushandler.cpp $(IntermediateDirectory)/up_up_guichan_src_focushandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/focushandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_focushandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_focushandler.cpp$(DependSuffix): ../../guichan/src/focushandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_focushandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_focushandler.cpp$(DependSuffix) -MM ../../guichan/src/focushandler.cpp

$(IntermediateDirectory)/up_up_guichan_src_focushandler.cpp$(PreprocessSuffix): ../../guichan/src/focushandler.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_focushandler.cpp$(PreprocessSuffix) ../../guichan/src/focushandler.cpp

$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimage.cpp$(ObjectSuffix): ../../guichan/src/allegro/allegroimage.cpp $(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/allegro/allegroimage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimage.cpp$(DependSuffix): ../../guichan/src/allegro/allegroimage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimage.cpp$(DependSuffix) -MM ../../guichan/src/allegro/allegroimage.cpp

$(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimage.cpp$(PreprocessSuffix): ../../guichan/src/allegro/allegroimage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_allegro_allegroimage.cpp$(PreprocessSuffix) ../../guichan/src/allegro/allegroimage.cpp

$(IntermediateDirectory)/up_Clases_StageManager.cpp$(ObjectSuffix): ../Clases/StageManager.cpp $(IntermediateDirectory)/up_Clases_StageManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/StageManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_StageManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_StageManager.cpp$(DependSuffix): ../Clases/StageManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_StageManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_StageManager.cpp$(DependSuffix) -MM ../Clases/StageManager.cpp

$(IntermediateDirectory)/up_Clases_StageManager.cpp$(PreprocessSuffix): ../Clases/StageManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_StageManager.cpp$(PreprocessSuffix) ../Clases/StageManager.cpp

$(IntermediateDirectory)/up_Clases_Ben.cpp$(ObjectSuffix): ../Clases/Ben.cpp $(IntermediateDirectory)/up_Clases_Ben.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Ben.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Ben.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Ben.cpp$(DependSuffix): ../Clases/Ben.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Ben.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Ben.cpp$(DependSuffix) -MM ../Clases/Ben.cpp

$(IntermediateDirectory)/up_Clases_Ben.cpp$(PreprocessSuffix): ../Clases/Ben.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Ben.cpp$(PreprocessSuffix) ../Clases/Ben.cpp

$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrographics.cpp$(ObjectSuffix): ../../guichan/src/allegro/allegrographics.cpp $(IntermediateDirectory)/up_up_guichan_src_allegro_allegrographics.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/allegro/allegrographics.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrographics.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrographics.cpp$(DependSuffix): ../../guichan/src/allegro/allegrographics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrographics.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrographics.cpp$(DependSuffix) -MM ../../guichan/src/allegro/allegrographics.cpp

$(IntermediateDirectory)/up_up_guichan_src_allegro_allegrographics.cpp$(PreprocessSuffix): ../../guichan/src/allegro/allegrographics.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_allegro_allegrographics.cpp$(PreprocessSuffix) ../../guichan/src/allegro/allegrographics.cpp

$(IntermediateDirectory)/up_up_guichan_src_rectangle.cpp$(ObjectSuffix): ../../guichan/src/rectangle.cpp $(IntermediateDirectory)/up_up_guichan_src_rectangle.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/rectangle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_rectangle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_rectangle.cpp$(DependSuffix): ../../guichan/src/rectangle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_rectangle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_rectangle.cpp$(DependSuffix) -MM ../../guichan/src/rectangle.cpp

$(IntermediateDirectory)/up_up_guichan_src_rectangle.cpp$(PreprocessSuffix): ../../guichan/src/rectangle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_rectangle.cpp$(PreprocessSuffix) ../../guichan/src/rectangle.cpp

$(IntermediateDirectory)/up_Clases_Herny.cpp$(ObjectSuffix): ../Clases/Herny.cpp $(IntermediateDirectory)/up_Clases_Herny.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Herny.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Herny.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Herny.cpp$(DependSuffix): ../Clases/Herny.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Herny.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Herny.cpp$(DependSuffix) -MM ../Clases/Herny.cpp

$(IntermediateDirectory)/up_Clases_Herny.cpp$(PreprocessSuffix): ../Clases/Herny.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Herny.cpp$(PreprocessSuffix) ../Clases/Herny.cpp

$(IntermediateDirectory)/up_up_guichan_src_cliprectangle.cpp$(ObjectSuffix): ../../guichan/src/cliprectangle.cpp $(IntermediateDirectory)/up_up_guichan_src_cliprectangle.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/cliprectangle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_cliprectangle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_cliprectangle.cpp$(DependSuffix): ../../guichan/src/cliprectangle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_cliprectangle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_cliprectangle.cpp$(DependSuffix) -MM ../../guichan/src/cliprectangle.cpp

$(IntermediateDirectory)/up_up_guichan_src_cliprectangle.cpp$(PreprocessSuffix): ../../guichan/src/cliprectangle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_cliprectangle.cpp$(PreprocessSuffix) ../../guichan/src/cliprectangle.cpp

$(IntermediateDirectory)/up_Clases_VectorGUI2.cpp$(ObjectSuffix): ../Clases/VectorGUI2.cpp $(IntermediateDirectory)/up_Clases_VectorGUI2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/VectorGUI2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_VectorGUI2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_VectorGUI2.cpp$(DependSuffix): ../Clases/VectorGUI2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_VectorGUI2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_VectorGUI2.cpp$(DependSuffix) -MM ../Clases/VectorGUI2.cpp

$(IntermediateDirectory)/up_Clases_VectorGUI2.cpp$(PreprocessSuffix): ../Clases/VectorGUI2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_VectorGUI2.cpp$(PreprocessSuffix) ../Clases/VectorGUI2.cpp

$(IntermediateDirectory)/up_up_guichan_src_imagefont.cpp$(ObjectSuffix): ../../guichan/src/imagefont.cpp $(IntermediateDirectory)/up_up_guichan_src_imagefont.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/imagefont.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_imagefont.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_imagefont.cpp$(DependSuffix): ../../guichan/src/imagefont.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_imagefont.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_imagefont.cpp$(DependSuffix) -MM ../../guichan/src/imagefont.cpp

$(IntermediateDirectory)/up_up_guichan_src_imagefont.cpp$(PreprocessSuffix): ../../guichan/src/imagefont.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_imagefont.cpp$(PreprocessSuffix) ../../guichan/src/imagefont.cpp

$(IntermediateDirectory)/up_Clases_AirCraft.cpp$(ObjectSuffix): ../Clases/AirCraft.cpp $(IntermediateDirectory)/up_Clases_AirCraft.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/AirCraft.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_AirCraft.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_AirCraft.cpp$(DependSuffix): ../Clases/AirCraft.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_AirCraft.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_AirCraft.cpp$(DependSuffix) -MM ../Clases/AirCraft.cpp

$(IntermediateDirectory)/up_Clases_AirCraft.cpp$(PreprocessSuffix): ../Clases/AirCraft.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_AirCraft.cpp$(PreprocessSuffix) ../Clases/AirCraft.cpp

$(IntermediateDirectory)/up_Clases_Bitmap.cpp$(ObjectSuffix): ../Clases/Bitmap.cpp $(IntermediateDirectory)/up_Clases_Bitmap.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Bitmap.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Bitmap.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Bitmap.cpp$(DependSuffix): ../Clases/Bitmap.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Bitmap.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Bitmap.cpp$(DependSuffix) -MM ../Clases/Bitmap.cpp

$(IntermediateDirectory)/up_Clases_Bitmap.cpp$(PreprocessSuffix): ../Clases/Bitmap.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Bitmap.cpp$(PreprocessSuffix) ../Clases/Bitmap.cpp

$(IntermediateDirectory)/up_Clases_Paleta.cpp$(ObjectSuffix): ../Clases/Paleta.cpp $(IntermediateDirectory)/up_Clases_Paleta.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Paleta.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Paleta.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Paleta.cpp$(DependSuffix): ../Clases/Paleta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Paleta.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Paleta.cpp$(DependSuffix) -MM ../Clases/Paleta.cpp

$(IntermediateDirectory)/up_Clases_Paleta.cpp$(PreprocessSuffix): ../Clases/Paleta.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Paleta.cpp$(PreprocessSuffix) ../Clases/Paleta.cpp

$(IntermediateDirectory)/up_Clases_Mago.cpp$(ObjectSuffix): ../Clases/Mago.cpp $(IntermediateDirectory)/up_Clases_Mago.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Mago.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Mago.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Mago.cpp$(DependSuffix): ../Clases/Mago.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Mago.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Mago.cpp$(DependSuffix) -MM ../Clases/Mago.cpp

$(IntermediateDirectory)/up_Clases_Mago.cpp$(PreprocessSuffix): ../Clases/Mago.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Mago.cpp$(PreprocessSuffix) ../Clases/Mago.cpp

$(IntermediateDirectory)/up_Clases_ControllableActor.cpp$(ObjectSuffix): ../Clases/ControllableActor.cpp $(IntermediateDirectory)/up_Clases_ControllableActor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/ControllableActor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_ControllableActor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_ControllableActor.cpp$(DependSuffix): ../Clases/ControllableActor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_ControllableActor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_ControllableActor.cpp$(DependSuffix) -MM ../Clases/ControllableActor.cpp

$(IntermediateDirectory)/up_Clases_ControllableActor.cpp$(PreprocessSuffix): ../Clases/ControllableActor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_ControllableActor.cpp$(PreprocessSuffix) ../Clases/ControllableActor.cpp

$(IntermediateDirectory)/up_Clases_Timer.cpp$(ObjectSuffix): ../Clases/Timer.cpp $(IntermediateDirectory)/up_Clases_Timer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Timer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Timer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Timer.cpp$(DependSuffix): ../Clases/Timer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Timer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Timer.cpp$(DependSuffix) -MM ../Clases/Timer.cpp

$(IntermediateDirectory)/up_Clases_Timer.cpp$(PreprocessSuffix): ../Clases/Timer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Timer.cpp$(PreprocessSuffix) ../Clases/Timer.cpp

$(IntermediateDirectory)/up_Clases_allegro_SpriteAllegro.cpp$(ObjectSuffix): ../Clases/allegro/SpriteAllegro.cpp $(IntermediateDirectory)/up_Clases_allegro_SpriteAllegro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/allegro/SpriteAllegro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_allegro_SpriteAllegro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_allegro_SpriteAllegro.cpp$(DependSuffix): ../Clases/allegro/SpriteAllegro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_allegro_SpriteAllegro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_allegro_SpriteAllegro.cpp$(DependSuffix) -MM ../Clases/allegro/SpriteAllegro.cpp

$(IntermediateDirectory)/up_Clases_allegro_SpriteAllegro.cpp$(PreprocessSuffix): ../Clases/allegro/SpriteAllegro.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_allegro_SpriteAllegro.cpp$(PreprocessSuffix) ../Clases/allegro/SpriteAllegro.cpp

$(IntermediateDirectory)/up_Clases_Ladrillo.cpp$(ObjectSuffix): ../Clases/Ladrillo.cpp $(IntermediateDirectory)/up_Clases_Ladrillo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Ladrillo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Ladrillo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Ladrillo.cpp$(DependSuffix): ../Clases/Ladrillo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Ladrillo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Ladrillo.cpp$(DependSuffix) -MM ../Clases/Ladrillo.cpp

$(IntermediateDirectory)/up_Clases_Ladrillo.cpp$(PreprocessSuffix): ../Clases/Ladrillo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Ladrillo.cpp$(PreprocessSuffix) ../Clases/Ladrillo.cpp

$(IntermediateDirectory)/up_Clases_Dialog.cpp$(ObjectSuffix): ../Clases/Dialog.cpp $(IntermediateDirectory)/up_Clases_Dialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Dialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Dialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Dialog.cpp$(DependSuffix): ../Clases/Dialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Dialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Dialog.cpp$(DependSuffix) -MM ../Clases/Dialog.cpp

$(IntermediateDirectory)/up_Clases_Dialog.cpp$(PreprocessSuffix): ../Clases/Dialog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Dialog.cpp$(PreprocessSuffix) ../Clases/Dialog.cpp

$(IntermediateDirectory)/up_Clases_Menu.cpp$(ObjectSuffix): ../Clases/Menu.cpp $(IntermediateDirectory)/up_Clases_Menu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Menu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Menu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Menu.cpp$(DependSuffix): ../Clases/Menu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Menu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Menu.cpp$(DependSuffix) -MM ../Clases/Menu.cpp

$(IntermediateDirectory)/up_Clases_Menu.cpp$(PreprocessSuffix): ../Clases/Menu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Menu.cpp$(PreprocessSuffix) ../Clases/Menu.cpp

$(IntermediateDirectory)/up_Clases_Almacen.cpp$(ObjectSuffix): ../Clases/Almacen.cpp $(IntermediateDirectory)/up_Clases_Almacen.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Almacen.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Almacen.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Almacen.cpp$(DependSuffix): ../Clases/Almacen.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Almacen.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Almacen.cpp$(DependSuffix) -MM ../Clases/Almacen.cpp

$(IntermediateDirectory)/up_Clases_Almacen.cpp$(PreprocessSuffix): ../Clases/Almacen.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Almacen.cpp$(PreprocessSuffix) ../Clases/Almacen.cpp

$(IntermediateDirectory)/up_Clases_Juego2.cpp$(ObjectSuffix): ../Clases/Juego2.cpp $(IntermediateDirectory)/up_Clases_Juego2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Juego2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Juego2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Juego2.cpp$(DependSuffix): ../Clases/Juego2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Juego2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Juego2.cpp$(DependSuffix) -MM ../Clases/Juego2.cpp

$(IntermediateDirectory)/up_Clases_Juego2.cpp$(PreprocessSuffix): ../Clases/Juego2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Juego2.cpp$(PreprocessSuffix) ../Clases/Juego2.cpp

$(IntermediateDirectory)/up_Clases_Vector2Di.cpp$(ObjectSuffix): ../Clases/Vector2Di.cpp $(IntermediateDirectory)/up_Clases_Vector2Di.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Vector2Di.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Vector2Di.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Vector2Di.cpp$(DependSuffix): ../Clases/Vector2Di.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Vector2Di.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Vector2Di.cpp$(DependSuffix) -MM ../Clases/Vector2Di.cpp

$(IntermediateDirectory)/up_Clases_Vector2Di.cpp$(PreprocessSuffix): ../Clases/Vector2Di.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Vector2Di.cpp$(PreprocessSuffix) ../Clases/Vector2Di.cpp

$(IntermediateDirectory)/up_Clases_ItemALG.cpp$(ObjectSuffix): ../Clases/ItemALG.cpp $(IntermediateDirectory)/up_Clases_ItemALG.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/ItemALG.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_ItemALG.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_ItemALG.cpp$(DependSuffix): ../Clases/ItemALG.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_ItemALG.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_ItemALG.cpp$(DependSuffix) -MM ../Clases/ItemALG.cpp

$(IntermediateDirectory)/up_Clases_ItemALG.cpp$(PreprocessSuffix): ../Clases/ItemALG.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_ItemALG.cpp$(PreprocessSuffix) ../Clases/ItemALG.cpp

$(IntermediateDirectory)/up_Clases_DirectorActor.cpp$(ObjectSuffix): ../Clases/DirectorActor.cpp $(IntermediateDirectory)/up_Clases_DirectorActor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/DirectorActor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_DirectorActor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_DirectorActor.cpp$(DependSuffix): ../Clases/DirectorActor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_DirectorActor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_DirectorActor.cpp$(DependSuffix) -MM ../Clases/DirectorActor.cpp

$(IntermediateDirectory)/up_Clases_DirectorActor.cpp$(PreprocessSuffix): ../Clases/DirectorActor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_DirectorActor.cpp$(PreprocessSuffix) ../Clases/DirectorActor.cpp

$(IntermediateDirectory)/up_up_guichan_src_exception.cpp$(ObjectSuffix): ../../guichan/src/exception.cpp $(IntermediateDirectory)/up_up_guichan_src_exception.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_exception.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_exception.cpp$(DependSuffix): ../../guichan/src/exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_exception.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_exception.cpp$(DependSuffix) -MM ../../guichan/src/exception.cpp

$(IntermediateDirectory)/up_up_guichan_src_exception.cpp$(PreprocessSuffix): ../../guichan/src/exception.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_exception.cpp$(PreprocessSuffix) ../../guichan/src/exception.cpp

$(IntermediateDirectory)/up_up_guichan_src_widget.cpp$(ObjectSuffix): ../../guichan/src/widget.cpp $(IntermediateDirectory)/up_up_guichan_src_widget.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/widget.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_widget.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_widget.cpp$(DependSuffix): ../../guichan/src/widget.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_widget.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_widget.cpp$(DependSuffix) -MM ../../guichan/src/widget.cpp

$(IntermediateDirectory)/up_up_guichan_src_widget.cpp$(PreprocessSuffix): ../../guichan/src/widget.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_widget.cpp$(PreprocessSuffix) ../../guichan/src/widget.cpp

$(IntermediateDirectory)/up_Clases_BoxALG.cpp$(ObjectSuffix): ../Clases/BoxALG.cpp $(IntermediateDirectory)/up_Clases_BoxALG.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/BoxALG.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_BoxALG.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_BoxALG.cpp$(DependSuffix): ../Clases/BoxALG.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_BoxALG.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_BoxALG.cpp$(DependSuffix) -MM ../Clases/BoxALG.cpp

$(IntermediateDirectory)/up_Clases_BoxALG.cpp$(PreprocessSuffix): ../Clases/BoxALG.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_BoxALG.cpp$(PreprocessSuffix) ../Clases/BoxALG.cpp

$(IntermediateDirectory)/up_Clases_GUIEscenario.cpp$(ObjectSuffix): ../Clases/GUIEscenario.cpp $(IntermediateDirectory)/up_Clases_GUIEscenario.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/GUIEscenario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_GUIEscenario.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_GUIEscenario.cpp$(DependSuffix): ../Clases/GUIEscenario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_GUIEscenario.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_GUIEscenario.cpp$(DependSuffix) -MM ../Clases/GUIEscenario.cpp

$(IntermediateDirectory)/up_Clases_GUIEscenario.cpp$(PreprocessSuffix): ../Clases/GUIEscenario.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_GUIEscenario.cpp$(PreprocessSuffix) ../Clases/GUIEscenario.cpp

$(IntermediateDirectory)/up_Clases_GUIControl.cpp$(ObjectSuffix): ../Clases/GUIControl.cpp $(IntermediateDirectory)/up_Clases_GUIControl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/GUIControl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_GUIControl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_GUIControl.cpp$(DependSuffix): ../Clases/GUIControl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_GUIControl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_GUIControl.cpp$(DependSuffix) -MM ../Clases/GUIControl.cpp

$(IntermediateDirectory)/up_Clases_GUIControl.cpp$(PreprocessSuffix): ../Clases/GUIControl.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_GUIControl.cpp$(PreprocessSuffix) ../Clases/GUIControl.cpp

$(IntermediateDirectory)/up_Clases_EscenarioGUI2.cpp$(ObjectSuffix): ../Clases/EscenarioGUI2.cpp $(IntermediateDirectory)/up_Clases_EscenarioGUI2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/EscenarioGUI2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_EscenarioGUI2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_EscenarioGUI2.cpp$(DependSuffix): ../Clases/EscenarioGUI2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_EscenarioGUI2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_EscenarioGUI2.cpp$(DependSuffix) -MM ../Clases/EscenarioGUI2.cpp

$(IntermediateDirectory)/up_Clases_EscenarioGUI2.cpp$(PreprocessSuffix): ../Clases/EscenarioGUI2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_EscenarioGUI2.cpp$(PreprocessSuffix) ../Clases/EscenarioGUI2.cpp

$(IntermediateDirectory)/up_Clases_Mosaico.cpp$(ObjectSuffix): ../Clases/Mosaico.cpp $(IntermediateDirectory)/up_Clases_Mosaico.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Mosaico.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Mosaico.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Mosaico.cpp$(DependSuffix): ../Clases/Mosaico.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Mosaico.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Mosaico.cpp$(DependSuffix) -MM ../Clases/Mosaico.cpp

$(IntermediateDirectory)/up_Clases_Mosaico.cpp$(PreprocessSuffix): ../Clases/Mosaico.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Mosaico.cpp$(PreprocessSuffix) ../Clases/Mosaico.cpp

$(IntermediateDirectory)/up_up_guichan_src_allegro_allegro.cpp$(ObjectSuffix): ../../guichan/src/allegro/allegro.cpp $(IntermediateDirectory)/up_up_guichan_src_allegro_allegro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/allegro/allegro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_allegro_allegro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_allegro_allegro.cpp$(DependSuffix): ../../guichan/src/allegro/allegro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_allegro_allegro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_allegro_allegro.cpp$(DependSuffix) -MM ../../guichan/src/allegro/allegro.cpp

$(IntermediateDirectory)/up_up_guichan_src_allegro_allegro.cpp$(PreprocessSuffix): ../../guichan/src/allegro/allegro.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_allegro_allegro.cpp$(PreprocessSuffix) ../../guichan/src/allegro/allegro.cpp

$(IntermediateDirectory)/up_Clases_Formulario.cpp$(ObjectSuffix): ../Clases/Formulario.cpp $(IntermediateDirectory)/up_Clases_Formulario.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Formulario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Formulario.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Formulario.cpp$(DependSuffix): ../Clases/Formulario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Formulario.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Formulario.cpp$(DependSuffix) -MM ../Clases/Formulario.cpp

$(IntermediateDirectory)/up_Clases_Formulario.cpp$(PreprocessSuffix): ../Clases/Formulario.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Formulario.cpp$(PreprocessSuffix) ../Clases/Formulario.cpp

$(IntermediateDirectory)/up_Clases_DlgActor.cpp$(ObjectSuffix): ../Clases/DlgActor.cpp $(IntermediateDirectory)/up_Clases_DlgActor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/DlgActor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_DlgActor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_DlgActor.cpp$(DependSuffix): ../Clases/DlgActor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_DlgActor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_DlgActor.cpp$(DependSuffix) -MM ../Clases/DlgActor.cpp

$(IntermediateDirectory)/up_Clases_DlgActor.cpp$(PreprocessSuffix): ../Clases/DlgActor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_DlgActor.cpp$(PreprocessSuffix) ../Clases/DlgActor.cpp

$(IntermediateDirectory)/up_up_guichan_src_mouseinput.cpp$(ObjectSuffix): ../../guichan/src/mouseinput.cpp $(IntermediateDirectory)/up_up_guichan_src_mouseinput.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/guichan/src/mouseinput.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_guichan_src_mouseinput.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_guichan_src_mouseinput.cpp$(DependSuffix): ../../guichan/src/mouseinput.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_guichan_src_mouseinput.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_guichan_src_mouseinput.cpp$(DependSuffix) -MM ../../guichan/src/mouseinput.cpp

$(IntermediateDirectory)/up_up_guichan_src_mouseinput.cpp$(PreprocessSuffix): ../../guichan/src/mouseinput.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_guichan_src_mouseinput.cpp$(PreprocessSuffix) ../../guichan/src/mouseinput.cpp

$(IntermediateDirectory)/up_Clases_ContadorGUI.cpp$(ObjectSuffix): ../Clases/ContadorGUI.cpp $(IntermediateDirectory)/up_Clases_ContadorGUI.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/ContadorGUI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_ContadorGUI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_ContadorGUI.cpp$(DependSuffix): ../Clases/ContadorGUI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_ContadorGUI.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_ContadorGUI.cpp$(DependSuffix) -MM ../Clases/ContadorGUI.cpp

$(IntermediateDirectory)/up_Clases_ContadorGUI.cpp$(PreprocessSuffix): ../Clases/ContadorGUI.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_ContadorGUI.cpp$(PreprocessSuffix) ../Clases/ContadorGUI.cpp

$(IntermediateDirectory)/up_Clases_Keyboard.cpp$(ObjectSuffix): ../Clases/Keyboard.cpp $(IntermediateDirectory)/up_Clases_Keyboard.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Keyboard.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Keyboard.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Keyboard.cpp$(DependSuffix): ../Clases/Keyboard.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Keyboard.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Keyboard.cpp$(DependSuffix) -MM ../Clases/Keyboard.cpp

$(IntermediateDirectory)/up_Clases_Keyboard.cpp$(PreprocessSuffix): ../Clases/Keyboard.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Keyboard.cpp$(PreprocessSuffix) ../Clases/Keyboard.cpp

$(IntermediateDirectory)/up_Clases_TextALG.cpp$(ObjectSuffix): ../Clases/TextALG.cpp $(IntermediateDirectory)/up_Clases_TextALG.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/TextALG.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_TextALG.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_TextALG.cpp$(DependSuffix): ../Clases/TextALG.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_TextALG.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_TextALG.cpp$(DependSuffix) -MM ../Clases/TextALG.cpp

$(IntermediateDirectory)/up_Clases_TextALG.cpp$(PreprocessSuffix): ../Clases/TextALG.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_TextALG.cpp$(PreprocessSuffix) ../Clases/TextALG.cpp

$(IntermediateDirectory)/up_Clases_Bloque.cpp$(ObjectSuffix): ../Clases/Bloque.cpp $(IntermediateDirectory)/up_Clases_Bloque.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/Bloque.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_Bloque.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_Bloque.cpp$(DependSuffix): ../Clases/Bloque.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_Bloque.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_Bloque.cpp$(DependSuffix) -MM ../Clases/Bloque.cpp

$(IntermediateDirectory)/up_Clases_Bloque.cpp$(PreprocessSuffix): ../Clases/Bloque.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_Bloque.cpp$(PreprocessSuffix) ../Clases/Bloque.cpp

$(IntermediateDirectory)/up_Clases_ActorGUI2.cpp$(ObjectSuffix): ../Clases/ActorGUI2.cpp $(IntermediateDirectory)/up_Clases_ActorGUI2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/juanma/Proyectos/juego-framework/Clases/ActorGUI2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Clases_ActorGUI2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Clases_ActorGUI2.cpp$(DependSuffix): ../Clases/ActorGUI2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Clases_ActorGUI2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Clases_ActorGUI2.cpp$(DependSuffix) -MM ../Clases/ActorGUI2.cpp

$(IntermediateDirectory)/up_Clases_ActorGUI2.cpp$(PreprocessSuffix): ../Clases/ActorGUI2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Clases_ActorGUI2.cpp$(PreprocessSuffix) ../Clases/ActorGUI2.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


