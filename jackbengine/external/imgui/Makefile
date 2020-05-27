CC                  = emcc

CFLAGS              = -O3 -DNDEBUG \
                      -std=c++17 \
                      -s USE_SDL=2 \
					  -s DEMANGLE_SUPPORT=1 \
                      -s WARN_ON_UNDEFINED_SYMBOLS=1 \
                      -s BINARYEN_TRAP_MODE=clamp

SOURCES             = $(wildcard *.cpp)

OUT                 = libimgui.bc

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUT)

clean:
	rm -rf libimgui.bc
