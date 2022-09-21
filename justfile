set windows-powershell := true

type := "Debug"
dir := if type == "Debug" { "cmake-build-debug" } else { "cmake-build-release" }

setup *FLAGS: && build
    cmake -DCMAKE_BUILD_TYPE={{type}} -DCMAKE_MAKE_PROGRAM=ninja -DCMAKE_C_COMPILER=gcc -G Ninja -S . -B ./{{dir}} {{FLAGS}}

build *FLAGS="-j 6":
    cmake --build ./{{dir}} --config {{type}} {{FLAGS}}

test *FLAGS="--output-on-failure": build
    ctest -C {{type}} --test-dir ./{{dir}} {{FLAGS}}

run *FLAGS="main": build
    ./cmake-build-debug/{{FLAGS}}

clean:
    -rm .\cmake-build-debug\, .\cmake-build-release\, .\build\, .\.idea\, .\.vscode\ -ErrorAction SilentlyContinue -Recurse -Force -Confirm:$false
