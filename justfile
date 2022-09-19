set windows-powershell := true

setup: && build
    cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -G Ninja -S . -B ./cmake-build-debug

setup-release: && build-release
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -G Ninja -S . -B ./cmake-build-release

build:
    cmake --build ./cmake-build-debug --config Debug --clean-first

build-release:
    cmake --build ./cmake-build-release --config Release --clean-first

test: build
    ctest --output-on-failure -C Debug --test-dir ./cmake-build-debug

test-release: build-release
    ctest --output-on-failure -C Release --test-dir ./cmake-build-release

run target='main': build
    ./cmake-build-debug/{{target}}

run-release target='main': build-release
    ./cmake-build-release/{{target}}

clean:
    rm .\cmake-build-debug\,.\cmake-build-release\,.\build\,.\.idea\,.\.vscode\ -ErrorAction SilentlyContinue
