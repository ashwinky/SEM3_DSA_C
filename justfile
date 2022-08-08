setup:
  cmake -DCMAKE_BUILD_TYPE=Debug "-DCMAKE_MAKE_PROGRAM=ninja.exe" -G Ninja -S . -B ./cmake-build-debug

setup-release:
  cmake -DCMAKE_BUILD_TYPE=Release "-DCMAKE_MAKE_PROGRAM=ninja.exe" -G Ninja -S . -B ./cmake-build-release

build:
  cmake --build ./cmake-build-debug --target main -j 6

build-release:
  cmake --build ./cmake-build-release --target main -j 6

run:
  ./cmake-build-debug/main.exe

run-release:
  ./cmake-build-release/main.exe

test:
  ctest --extra-verbose
