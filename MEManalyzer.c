/*the implementation for memory test will completley not take
into the prsence of pages and implementation just a HUGEPAGES will be missing*/

#include<stdio.h>
#include<string.h>
#include "FLOPanalyzer.h"
#ifdef _WIN32 || WIN32 //trying portable clrscr()
#include "mman.h"
#else
#include <sys/mman.h>
#endif