CC  = $(shell fltk-config --cc)
CXX = $(shell fltk-config --cxx)

CFLAGS   = $(shell fltk-config --cflags) -Wall -O3 -I/other/include/paths...
CXXFLAGS = $(shell fltk-config --cxxflags) -Wall -O3 -I/other/include/paths...

LINKFLTK = $(shell fltk-config --ldstaticflags)
LINKFLTK_GL = $(shell fltk-config --use-gl --ldstaticflags)
LINKFLTK_IMG = $(shell fltk-config --use-images --ldstaticflags)

STRIP      = strip
POSTBUILD  = fltk-config --post

all: MyApp

main.o: main.cpp main.h
	$(CXX) -c $< $(CCFLAGS)

view.o: view.cpp main.h view.h
	$(CXX) -c $< $(CXXFLAGS)

Parts.o: Parts.cpp main.h view.h Parts.h
	$(CXX) -c $< $(CXXFLAGS)

Models.o: Models.cpp main.h view.h  Models.h
	$(CXX) -c $< $(CXXFLAGS)

MyApp:  main.o view.o Parts.o Models.o
	$(CXX) -o $@ main.o view.o Parts.o Models.o $(LINKFLTK_IMG) $(LINKFLTK_GL)
	$(STRIP) $@
	$(POSTBUILD) $@