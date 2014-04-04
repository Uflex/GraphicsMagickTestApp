TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7
QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++
QMAKE_LFLAGS += -stdlib=libc++
#QMAKE_CXXFLAGS += -std=c++11

__GRAPHICS_MAGIC=/usr/local/include/GraphicsMagick
INCLUDEPATH += $${__GRAPHICS_MAGIC}
INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib
LIBS += -lGraphicsMagick++ -lGraphicsMagick -llcms2 -ltiff -ljpeg -lpng16 -llzma -lz -lm -lpthread

SOURCES += main.cpp

