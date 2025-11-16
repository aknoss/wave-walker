RAYLIB_VERSION = 5.0

all: raylib game

raylib:
	git clone https://github.com/raysan5/raylib vendor/raylib 
	cd vendor/raylib && git checkout $(RAYLIB_VERSION)
	$(MAKE) -C vendor/raylib/src PLATFORM=PLATFORM_DESKTOP 

game:
	mkdir build
	gcc src/*.c \
		-Ivendor/raylib/src \
		-Lvendor/raylib/src \
		-lraylib \
		-lm -lpthread -ldl -lrt -lX11 \
		-o build/rayne

clean:
	rm -rf build vendor
