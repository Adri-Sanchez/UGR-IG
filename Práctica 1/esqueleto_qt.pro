HEADERS += \
  glwidget.h \
  window.h \
  O3DS.h \
  O3D.h \
  Cubo.h \
  Tetraedro.h \

SOURCES += \
  main.cc \
  glwidget.cc \
  window.cc \
  O3DS.cc \
  O3D.cc \
  Cubo.cc \
  Tetraedro.cc \


INCLUDEPATH += /casa/dmartin/codigo/funciontecas/glew/include

LIBS += -L/usr/X11R6/lib64 -lGL \
        -L/usr/include/GL -lGLEW

CONFIG += c++11
QT += widgets
