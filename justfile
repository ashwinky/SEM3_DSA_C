set windows-powershell := true

setup:
  cmake -DCMAKE_BUILD_TYPE=Debug "-DCMAKE_MAKE_PROGRAM=ninja.exe" -G Ninja -S . -B ./cmake-build-debug

setup-release:
  cmake -DCMAKE_BUILD_TYPE=Release "-DCMAKE_MAKE_PROGRAM=ninja.exe" -G Ninja -S . -B ./cmake-build-release

build:
  cmake --build ./cmake-build-debug --config Debug

build-release:
  cmake --build ./cmake-build-release --config Release

test: build
  ctest --output-on-failure -C Debug --test-dir ./cmake-build-debug

test-release: build-release
  ctest --output-on-failure -C Release --test-dir ./cmake-build-release

run: build
  ./cmake-build-debug/main.exe

run-release: build-release
  ./cmake-build-release/main.exe
