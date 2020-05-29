CC                  = emcc

CDFLAGS             = -g \
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

CRPFLAGS            = -O3 -DNDEBUG \
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

CFLAGS              = -O3 -DNDEBUG \
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
                      -s BINARYEN_TRAP_MODE=clamp \
                      -DFMT_HEADER_ONLY

INCLUDES            = -Isrc \
                      -Iexternal \
					  -Iexternal/glad/include \
					  -Iexternal/fmt

SOURCES            := resources.cpp \
                      $(shell find src -name '*.cpp')

BUILD_RESOURCE_GENERATOR  = @echo "\033[0;32mBuilding ResourceGenerator...\033[0m" \
					        && cd external/resourceGenerator \
					        && make \
					        && cd -

GENERATE_RESOURCES  = @echo "\033[0;32mGenerating resources.cpp...\033[0m" \
					  && ./external/resourceGenerator/resourceGenerator \
					  resources.cpp \
					  -tsrc/core/render/shader/glsl/color.vertex.default.glsl \
                      -tsrc/core/render/shader/glsl/color.fragment.default.glsl \
                      -tsrc/core/render/shader/glsl/texture.vertex.default.glsl \
                      -tsrc/core/render/shader/glsl/texture.fragment.default.glsl \
                      -tsrc/core/render/shader/glsl/texture.fragment.grayscale.glsl \
                      -bresource/aquarelle_damien_square.png \
                      -bresource/aquarelle_damien_square_alpha.png

BUILD_LIB_IMGUI     = @echo "\033[0;32mBuilding ImGui...\033[0m" \
                      && cd external/imgui \
                      && make \
                      && cd -

BUILD_JACKBENGINE   = @echo "\033[0;32mBuilding Jackbengine...\033[0m"

LIB_IMGUI           = external/imgui/libimgui.bc

OUT                 = libjackbengine.bc

debug:
	$(BUILD_RESOURCE_GENERATOR)
	$(BUILD_LIB_IMGUI)
	$(GENERATE_RESOURCES)
	$(BUILD_JACKBENGINE)
	$(CC) $(CDFLAGS) $(INCLUDES) $(LIB_IMGUI) $(SOURCES) -o $(OUT)

release_profile:
	$(BUILD_RESOURCE_GENERATOR)
	$(BUILD_LIB_IMGUI)
	$(GENERATE_RESOURCES)
	$(BUILD_JACKBENGINE)
	$(CC) $(CRPFLAGS) $(INCLUDES) $(LIB_IMGUI) $(SOURCES) -o $(OUT)

release:
	$(BUILD_RESOURCE_GENERATOR)
	$(BUILD_LIB_IMGUI)
	$(GENERATE_RESOURCES)
	$(BUILD_JACKBENGINE)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB_IMGUI) $(SOURCES) -o $(OUT)

clean:
	cd external/imgui && make clean && cd -
	cd external/resourceGenerator && make clean && cd -
	rm -rf libjackbengine.bc resources.cpp
