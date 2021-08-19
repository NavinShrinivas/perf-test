#!/bin/bash

#If build is failing we are adding an extra optin that cleans the bulidenv to start from scratch

if [[ "$1" == "--reset" ]]; then
    sudo rm -r ./buildenv
elif [[ "$1" == "--install" ]]; then
    echo "==========PERF-TOOL=========="
    echo "This is a command line installer for our tool."
    echo "This script will install the following packages and libaries"
    echo "1.Vcpkg [Package]"
    echo "2.Curl [Libaries]"
    echo "3.Pthreads [Library]"
    read -p $'\n\nContinue with installation [Y/n] :' option
    if [[ "$option" == "n" ]]; then
        echo "See you later , bye bye :)"
    else
        if [[ "$2" == "--apt" ]]; then
            sudo apt-get install build-essential tar zip unzip cmake
        else
            sudo pacman -S base-devel tar zip unzip cmake
        fi
        echo "Starting install process"
        mkdir buildenv
        git clone https://github.com/Microsoft/vcpkg.git ./buildenv/vcpkg
        ./buildenv/vcpkg/bootstrap-vcpkg.sh
        cd ./buildenv/vcpkg/
        ./vcpkg install curl
        ./vcpkg install pthreads
        cd .. && cd ..
        cmake . -DCMAKE_TOOLCHAIN_FILE=./buildenv/vcpkg/scripts/buildsystems/vcpkg.cmake
        make
    fi
else
    echo "Please enter a valid argument!"
fi

#shell script , disctors package manager to get basic program , Vcpkg to get more specific needed 
#packaged , cmake to tie up C and Vcpkg , it compies the program to give "perftool"
