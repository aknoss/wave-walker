RAYLIB_VERSION = 5.0

all: raylib game

raylib:
	git clone https://github.com/raysan5/raylib vendor/raylib | true 
	cd vendor/raylib && git checkout $(RAYLIB_VERSION)
	$(MAKE) -C vendor/raylib/src PLATFORM=PLATFORM_DESKTOP GLFW_LINUX_ENABLE_WAYLAND=TRUE

game:
	mkdir -p build
	gcc src/*.c \
		-Ivendor/raylib/src \
		-Lvendor/raylib/src \
		-lraylib \
		-lGL -lm -lpthread -ldl -lrt -lX11 \
		-o build/rayne

clean:
	rm -rf build vendor
