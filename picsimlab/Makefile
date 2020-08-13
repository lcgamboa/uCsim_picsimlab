include Makefile.Common

CXX=g++
AR=ar

prefix = /usr/local
includedir = ${prefix}/include/ucsim
libdir = ${prefix}/lib

LIBHEADERFILES := ucsimlib.h

all:  ${PICSIMLAB_OBJECTS}
	-rm -f libucsim.a
	$(AR) rcvs libucsim.a ${ALL_OBJECTS}
	$(CXX) -shared -Wl,-soname,libucsim.so -o libucsim.so  ${ALL_OBJECTS}
	$(CXX) $(CPPFLAGS) s51_alone.cc libucsim.a -o s51_alone
	

clean:
	rm -rf *.o s51_alone libucsim.o libucsim.so 

install: all
	strip libucsim.so
	cp -dvf libucsim.so ${libdir}
	mkdir -p ${includedir}
	cp -dvf $(LIBHEADERFILES) ${includedir}
	chmod 644 ${includedir}/*
