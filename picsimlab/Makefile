include Makefile.Common

CXX=g++
AR=ar
OS := $(shell uname)

DESTDIR ?= /usr/local
prefix = $(DESTDIR)
includedir = ${prefix}/include/ucsim
libdir = ${prefix}/lib

LIBHEADERFILES := ucsimlib.h

LIBNAME := libucsim
ifeq ($(OS),Darwin)
	LIBFILE := ${LIBNAME}.dylib
	SHLIB_OPT := -install_name
else
	LIBFILE := ${LIBNAME}.so
	SHLIB_OPT := -soname
endif

all:  ${PICSIMLAB_OBJECTS}
	-rm -f ${LIBNAME}.a
	$(AR) rcvs ${LIBNAME}.a ${ALL_OBJECTS}
	$(CXX) -shared -Wl,${SHLIB_OPT},${LIBFILE} -o ${LIBFILE}  ${ALL_OBJECTS}
	$(CXX) $(CPPFLAGS) s51_alone.cc ${LIBNAME}.a -o s51_alone
	

clean:
	rm -rf *.o s51_alone libucsim.o ${LIBFILE}

install: all
	#strip ${LIBFILE}
	install -d ${libdir}
	install -m 755 ${LIBFILE} ${libdir}
	install -d ${includedir}
	install -m 644 ${LIBHEADERFILES} ${includedir}
