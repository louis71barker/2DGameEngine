isEqual(QT_MAJOR_VERSION, 5) {cache() }
TARGET=2DEngine
cache()
SOURCES+=src/main.cpp\
         src/ball.cpp\
         src/box.cpp\
         src/ground.cpp\
         src/plank.cpp\
         src/window.cpp\
         src/Enviroment.cpp\
         src/NCCA/GLFunctions.cpp\
         src/NCCA/Mat4.cpp\
         src/NCCA/Vec4.cpp\
         src/NCCA/World.cpp

HEADERS+=header/ball.h\
         header/box.h\
         header/ground.h\
         header/plank.h\
         header/window.h\
         header/scene.h\
         header/Enviroment.h\
         header/NCCA/GLFunctions.h\
         header/NCCA/Mat4.h\
         header/NCCA/Vec4.h\
         header/NCCA/World.h

QT += core
QT +=opengl
CONFIG-=app_bundle
DESTDIR=./
OBJECTS_DIR=obj

INCLUDEPATH += header
INCLUDEPATH += header/NCCA
INCLUDEPATH +=usr/local/lib

QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64
linux-g++:QMAKE_CXXFLAGS +=  -march=native
linux-g++-64:QMAKE_CXXFLAGS +=  -march=native

QMAKE_CXXFLAGS+=$$system(sdl2-config  --cflags)
message(output from sdl2-config --cflags added to CXXFLAGS= $$QMAKE_CXXFLAGS)

LIBS+=$$system(sdl2-config  --libs)
message(output from sdl2-config --libs added to LIB=$$LIBS)



LIBS += -L/usr/local/lib
macx:LIBS+= -framework OpenGL
macx:DEFINES+=DARWIN
# now if we are under unix and not on a Mac (i.e. linux) define GLEW
linux-* {
    DEFINES += LINUX
    LIBS+= -lGLEW
}
linux-clang {
    DEFINES += LINUX
    LIBS+= -lGLEW
}
