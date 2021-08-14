> :warning: **All the code present in this repository must be run preferably on a virtual machine as there is a possibility the code can harm the machine!Any how a force reboot should fix it.**

<b><p>Note : This project is also a part of UE20CS152 course</p></b>
# Perf-test



## Project Contributors:

* [Rahul Samal](https://github.com/*add_your_link_here*)
* [P K Navin Shrinivas ](https://github.com/NavinShrinivas)
* [Praneeth K L](https://github.com/praneethk002)


# Project Info:
To build this project , you CMake , as of yet this may seem like over engineering but , we plan on including Vcpkg , that would solve all our package problems at once.

## Usage:
### Linux
  If on linux there is no need to add external libraries and simply do :
  ```
  $ git clone https://github.com/NavinShrinivas/perf-test
  $ cd perf-test
  $ chmod +x install.sh
  $ install.sh
  $ ./perftool
  ```
  before executing the above commands make sure cmake is installed in your system
## Acess style:
  the entire program is fully acessible through commands in the terminal , but also can be used as a menu driven program with 
  ```./perftool menu```

## Intresting problems encountered during this project :
and how we solved em :
*  Multithreading was one of the most major one's , deciding where the controls flow ,etc. , etc.We figured it out mainly by asking people in stack overflows
and seeing other multithreaded application.
*  Race conditions , due to multiples IO's on a single memory due to multi threading and rapid while loops we ran into the ever infamous race condition problem.Of course our workaround was eventually consistency by using various buffers and adding them up in the end.

