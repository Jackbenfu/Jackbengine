CC                  = emcc

CFLAGS_D            = -g \
				      -D__DEBUG__ \
                      -Wall -Wextra -Wpedantic \
                      -std=c++2a \
                      -s USE_SDL=2 \
                      -s USE_SDL_TTF=2 \
                      -s USE_SDL_MIXER=2 \
                      -s USE_SDL_IMAGE=2 \
                      -s SDL2_IMAGE_FORMATS='["png"]' \
                      -s DEMANGLE_SUPPORT=1 \
                      -s WARN_ON_UNDEFINED_SYMBOLS=1 \
                      -s DISABLE_EXCEPTION_CATCHING=0 \
                      -s USE_WEBGL2=1 \
                      -s ALLOW_MEMORY_GROWTH=1 \
                      -DFMT_HEADER_ONLY

CFLAGS_RP           = -O3 -DNDEBUG \
				      -D__RELEASE_PROFILE__ \
                      -Wall -Wextra -Wpedantic \
                      -std=c++2a \
                      -s USE_SDL=2 \
                      -s USE_SDL_TTF=2 \
                      -s USE_SDL_MIXER=2 \
                      -s USE_SDL_IMAGE=2 \
                      -s SDL2_IMAGE_FORMATS='["png"]' \
                      -s DEMANGLE_SUPPORT=1 \
                      -s WARN_ON_UNDEFINED_SYMBOLS=1 \
                      -s DISABLE_EXCEPTION_CATCHING=0 \
                      -s USE_WEBGL2=1 \
                      -s ALLOW_MEMORY_GROWTH=1 \
                      --profiling \
                      -DFMT_HEADER_ONLY

CFLAGS              = -DNDEBUG \
				      -D__RELEASE__ \
                      -Wall -Wextra -Wpedantic \
                      -std=c++2a \
                      -s USE_SDL=2 \
                      -s USE_SDL_TTF=2 \
                      -s USE_SDL_MIXER=2 \
                      -s USE_SDL_IMAGE=2 \
                      -s SDL2_IMAGE_FORMATS='["png"]' \
                      -s DEMANGLE_SUPPORT=1 \
                      -s WARN_ON_UNDEFINED_SYMBOLS=1 \
                      -s DISABLE_EXCEPTION_CATCHING=0 \
                      -s USE_WEBGL2=1 \
                      -s ALLOW_MEMORY_GROWTH=1 \
                      -DFMT_HEADER_ONLY

INCLUDES            = -Isandbox/src \
					  -Ijackbengine/src \
					  -Ijackbengine/external

SOURCES             = $(shell find sandbox -name '*.cpp')

BUILD_JACKBENGINE_D  = cd jackbengine \
 					   && make debug \
 					   && cd ..

BUILD_JACKBENGINE_RP = cd jackbengine \
 					   && make release_profile \
 					   && cd ..

BUILD_JACKBENGINE    = cd jackbengine \
 					   && make release \
 					   && cd ..

BUILD_APPLICATION   = @echo "\033[0;32mBuilding application...\033[0m"

LIB_JACKBENGINE     = jackbengine/libjackbengine.bc

OUT                 = export/sandbox.js

debug:
	$(BUILD_JACKBENGINE_D)
	$(BUILD_APPLICATION)
	$(CC) $(CFLAGS_D) $(INCLUDES) $(LIB_JACKBENGINE) $(SOURCES) -o $(OUT)

release_profile:
	$(BUILD_JACKBENGINE_RP)
	$(BUILD_APPLICATION)
	$(CC) $(CFLAGS_RP) $(INCLUDES) $(LIB_JACKBENGINE) $(SOURCES) -o $(OUT)

release:
	$(BUILD_JACKBENGINE)
	$(BUILD_APPLICATION)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB_JACKBENGINE) $(SOURCES) -o $(OUT)

clean:
	cd jackbengine && make clean && cd -
	rm -rf export/sandbox.js export/sandbox.wasm export/sandbox.wasm.map export/sandbox.wast
