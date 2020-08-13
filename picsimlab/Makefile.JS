include Makefile.Common

CXX=em++
AR=emar

all:  ${PICSIMLAB_OBJECTS}
	-rm -f libucsim.a
	$(AR) rcvs libucsim.a  ${s51_OBJECTS_SHARED} ${stm8_OBJECTS_SHARED} ${z80_OBJECTS_SHARED} \
	${GUI_OBJECTS} ${CMD_OBJECTS} ${SIM_OBJECTS} ${MAIN_OBJECTS} ${PICSIMLAB_OBJECTS}
	mv -f libucsim.a libucsim.ajs
	$(CXX) $(CPPFLAGS) s51_alone.cc libucsim.ajs -o s51_alone.html 
		

clean:
	rm -rf *.o libucsim.a s51_alone libucsim.o *.html *.js *.wasm
