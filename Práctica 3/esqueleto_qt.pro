HEADERS += \
  glwidget.h \
  window.h \
  O3DS.h \
  O3D.h \
  O3DPLY.h \
  Cubo.h \
  Tetraedro.h \
  file_ply_stl.h \
  O3DR.h \
  Peon.h \
  Cilindro.h \
  Vaso.h \
  VasoInv.h \
  Cono.h \
  Tubo.h \
  RelojArena.h \
  Esfera.h \
  Base.h \
    Varilla.h \
    Brazo.h \
    ReguladorWatt.h \


SOURCES += \
  main.cc \
  glwidget.cc \
  window.cc \
  O3DS.cc \
  O3D.cc \
  Cubo.cc \
  Tetraedro.cc \
  O3DPLY.cc \
  file_ply_stl.cc \
  O3DR.cc \
  Peon.cc \
  Cilindro.cc \
  Vaso.cc \
  VasoInv.cc \
  Cono.cc \
  Tubo.cc \
  RelojArena.cc \
  Esfera.cc \
    Base.cpp \
    Varilla.cpp \
    Brazo.cpp \
    ReguladorWatt.cc

INCLUDEPATH += "../include/"

LIBS += -L/usr/X11R6/lib64 -lGL \
        -L/usr/include/GL -lGLEW

CONFIG += c++11
QT += widgets

