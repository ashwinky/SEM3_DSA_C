set windows-powershell := true

default:
    just --choose

setup:
    cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -G Ninja -S . -B ./cmake-build-debug

setup-release:
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -G Ninja -S . -B ./cmake-build-release

build:
    cmake --build ./cmake-build-debug --config Debug --clean-first

build-release:
    cmake --build ./cmake-build-release --config Release --clean-first

test: build
    ctest --output-on-failure -C Debug --test-dir ./cmake-build-debug

test-release: build-release
    ctest --output-on-failure -C Release --test-dir ./cmake-build-release

run: build
    ./cmake-build-debug/main.exe

run-release: build-release
    ./cmake-build-release/main.exe
