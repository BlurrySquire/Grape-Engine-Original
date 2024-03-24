.PHONY: init clean build_engine build_sandbox

init:
	mkdir -p bin

clean:
	rm bin/*

# '-j2' says we want to use 2 threads for compiling
build_engine:
	$(MAKE) -C engine -j2

# '-j2' says we want to use 2 threads for compiling
build_sandbox:
	$(MAKE) -C sandbox -j2