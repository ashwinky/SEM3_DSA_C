set windows-powershell := true

setup:
  cmake -G Ninja "-DCMAKE_MAKE_PROGRAM=ninja.exe" -S . -DCMAKE_BUILD_TYPE=Debug -B ./cmake-build-debug

setup-release:
  cmake -G Ninja "-DCMAKE_MAKE_PROGRAM=ninja.exe" -S . -DCMAKE_BUILD_TYPE=Release -B ./cmake-build-release

build:
  cmake --build ./cmake-build-debug --target main

build-release:
  cmake --build ./cmake-build-release --target main

test:
  ctest --extra-verbose --test-dir ./cmake-build-debug

test-release:
  ctest --extra-verbose --test-dir ./cmake-build-release

run:
  ./cmake-build-debug/main.exe

run-release:
  ./cmake-build-release/main.exe
