> :warning: **All the code present in this repository must be run preferably on a virtual machine as there is a possibility the code can harm the machine!Any how a force reboot should fix it.**
# Perf-test

<p>This project got its life as part of UE20CS152 course</p>

# Project Contributors:

* [Rahul Samal](https://github.com/*add_your_link_here*)
* [P K Navin Shrinivas ](https://github.com/NavinShrinivas)
* [Praneeth K L](https://github.com/praneethk002)


# Project Info:
## Usage:
  If on linux there is no need to add external libraries and simply do :
  ```
  $ git clone https://github.com/NavinShrinivas/perf-test
  
  $ cd perf-test/src
  
  $ make all 
  
  $ cd .. && cd build/executables
  
  $ ./tester.o
  ```
  If on windows 10 , I ask you to google and add pthread h and dll files to mingw path and do :
  ```
  git clone https://github.com/NavinShrinivas/perf-test
  
  cd perf-test/src
  
  make winall
  
  cd .. && cd build/executables
  
  tester.exe
  ```
 To see all the possible modules you must execute
 ```
 ./tester.exe help
 ```
## Acess style:
  the entire program is fully acessible through commands in the terminal , but also can be used as a menu driven program with 
  ```./tester.o menu```

