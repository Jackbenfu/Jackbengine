CC                  = emcc

CFLAGS              = -O3 -DNDEBUG \
                      -std=c++17 \
                      -s USE_SDL=2 \
					  -s DEMANGLE_SUPPORT=1 \
                      -s WARN_ON_UNDEFINED_SYMBOLS=1 \
                      -s BINARYEN_TRAP_MODE=clamp

SOURCES             = imgui_widgets.cpp \
                      imgui_draw.cpp \
                      imgui_demo.cpp \
                      imgui.cpp \
                      imgui_impl_sdl.cpp \
                      imgui_impl_opengl3.cpp

OUT                 = libimgui.bc

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUT)

clean:
	rm -rf libimgui.bc
