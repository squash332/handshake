.PHONY: build test clean testone

build:
	cmake -S . -B build && cmake --build build --target handshake_exe -j$(nproc) && ./build/handshake

test:
	cmake -S . -B build -Dhandshake_DEVELOPER_MODE=ON -DBUILD_TESTING=ON && cmake --build build -j$(nproc) && cd build && ctest --output-on-failure

testone:
	cd build && ctest -R $(T) --output-on-failure

clean:
	rm -rf build