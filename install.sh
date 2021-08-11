#!/bin/bash


echo "==========PERF-TOOL=========="
echo "This is a command line installer for our tool."
echo "This script will install the following packages and libaries"
echo "1.Vcpkg [Package]"
echo "2.Curl [Libaries]"
echo "3.Pthreads [Library]" echo "" echo ""
read -p $'\n\nContinue with installation [Y/n] :' option
if [[ "$option" == "n" ]]; then
    echo "See you later , bye bye :)"
else
    echo "Starting install process"
    mkdir buildenv
    git clone https://github.com/Microsoft/vcpkg.git ./buildenv/vcpkg
    # ./buildenv/vcpkg/bootstrap-vcpkg.sh
    cd ./buildenv/vcpkg/
    ./vcpkg install curl
    # vcpkg install pthreads "not needed for linux , i.e a shell script"
    cd .. && cd ..
    cmake . -DCMAKE_TOOLCHAIN_FILE=./buildenv/vcpkg/scripts/buildsystems/vcpkg.cmake
fi