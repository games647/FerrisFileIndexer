# FerrisFileIndexer

## Description

This project aims to provide an easy to use command line utility for managing your file system. For home
pc you sometimes want to find your lost files, duplicates or even big files to free disk space. Then
this tool can be useful for you.

## Features

* List big files

## Planned

* Count folder sizes
* Index files using a SQLite database for fast finding of files
* Listen for files changes using fswatch
* Filter by date, modification date
* Find duplicate files

## Building

You can ignore the conanfile. It's not needed at the moment. 

### Requirements

* CMake
* A C/C++ Compiler that is supported by Cmake (i.e. MinGW, Cygwin, Visual Studio, XCode, Unix Makefiles) 
* GDB for debugging (included in most C/C++ bundles -> i.e. MinGW)

### Creating/Running

1. Run "cmake ."
  If your command line doesn't know this command make sure it's in your PATH environment variable 
  and restart your command line afterwards.
2. Run your platform specific make system on that created files
  (like opening Visual Studio, XCode, run the make command, ...)

### Example for Unix Makefiles

This example works for **Linux** and **Windows (with MinGW)**

1. Run "cmake ."
2. Run make or mingw32-make.exe
3. A new file should be created with the project name (i.e. Windows FerrisFileIndexer.exe)

### Forcing a cmake generator

Depending on your system cmake will automatically choose a generator, but sometimes you want to use only one specific 
generator. Then you could run ```cmake -G "GENERATOR"``` 

**GENERATOR** should be replaced with the system of your choice. For example if youhave MingGW installed:
```cmake -G "MinGW Makefiles"```

## Usage

Run the binary file. There are not file arguments at the moment

## Example output

    2372644 bytes ./FerrisFileIndexer.exe
    13906 bytes ./CMakeCache.txt
    6414 bytes ./FerrisFileIndexer.cbp
    5627 bytes ./Makefile
    1381 bytes ./cmake_install.cmake

## Credits/Dependencies

*
