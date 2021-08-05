> :warning: **All the code present in this repository must be run preferably on a virtual machine as there is a possibility the code can harm the machine!Any how a force reboot should fix it.**

<b><p>Note : This project is also a part of UE20CS152 course</p></b>
# Perf-test



## Project Contributors:

* [Rahul Samal](https://github.com/*add_your_link_here*)
* [P K Navin Shrinivas ](https://github.com/NavinShrinivas)
* [Praneeth K L](https://github.com/praneethk002)

## Usage:
  If on linux there is no need to add external libraries and simply do :
  ```
  $ git clone https://github.com/NavinShrinivas/perf-test
  
  $ cd perf-test/src
  
  $ make -f manualmake.mk 
  
  $ cd .. && cd build/executables
  
  $ ./tester.o
  ```
  If on windows 10 , I ask you to google and add pthread h and dll files to mingw path and do :
  ```
  git clone https://github.com/NavinShrinivas/perf-test
  
  cd perf-test/src
  
  make -f manualmake.mk 
  
  cd .. && cd build/executables
  
  tester.exe
  ```
 To see all the possible modules you must execute
 ```
 ./tester.exe help
 ```
## Acess style:
  the entire program is fully acessible through commands in the terminal , but also can be used as a menu driven program with <br>
  ```./tester.o menu```

## Some intresting problems we ran into during this project :
* Multithreading was one of the most major one's , deciding where the controls flow ,etc. , etc.
*  Race conditions , due to multiples IO's on a single memory due to multi threading and rapid while loops we ran into the ever infamous race condition problem.Of course our workaround was eventually consistency by using various buffers and adding them up in the end.

