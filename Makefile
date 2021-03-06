OBJECTS = utilities/ColourReader.o \
          utilities/DatabaseReader.o \
          utilities/DatabaseMessageConnection.o \
          utilities/SocketQueuer.o \
          utilities/Threadable.o \
          twoD_view/TwoDPlot.o \
          twoD_view/PacketConverter.o \
          glut_framework/GlutFramework.o \
          glut_framework/PerformanceTimer.o \
          glut_framework/Keyboard.o \
          main.o
   
OBJS=$(OBJECTS:%=build/%)

vis.exe: $(OBJS)
	g++ -o $@ $^ -fno-use-linker-plugin -lfreeglut_static -lopengl32 -lwinmm -lgdi32 -lglu32 -lpthread -lws2_32 -lsqlite3

build/%.o: %.cpp
	-mkdir -p $(dir $@)
	g++ -D FREEGLUT_STATIC -D WINVER=0x501 -D WIN32_LEAN_AND_MEAN -fpermissive -o $@ -c $<

clean:
	rm -rf build vis.exe
