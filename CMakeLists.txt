
#cmake_minimum_required(VERSION 3.21)
project (pertool)


#[[Source for local programmer written libaries]]
file(GLOB floatfuncsrc "./src/floatfuncs/*.c")
file(GLOB simpledbsrc "./src/SimpleDB/*.c")

#[[adding libaries]]
add_library(floatfunc STATIC ${floatfuncsrc})
add_library(simpledb STATIC ${simpledbsrc})

#Vcpkg libaries
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
find_package(Threads REQUIRED)


add_executable(perftool "./src/main.c") #building main src

#[[Linking libaries to main object file]]
target_link_libraries(perftool floatfunc simpledb) #two programmer written
target_link_libraries(perftool ${CMAKE_THREAD_LIBS_INIT} ${CURL_LIBRARIES}) #two imported libaries



