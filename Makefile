.PHONY: all
all: init clean build_engine build_sandbox

init:
	mkdir -p bin

clean:
	rm -rf bin/*

# '-j2' says we want to use 2 threads for compiling
build_engine:
	make -C engine build_engine -j2

# '-j2' says we want to use 2 threads for compiling
build_sandbox:
	make -C sandbox build_sandbox -j2