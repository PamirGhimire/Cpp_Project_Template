# C_Project_Template
Abstract : 
Scalable template for a C++-based project with support for unit testing, and CI (Jenkins) integration

Introduction : 
If you would like to start working on a C++ project with a small team in a professional setting, 
you may find this template useful. 
  The Build system used is cmake-make (CMake Version >= 3.15), and testing support is available
through googletest(gtest) testing library (source included). A template for a jenkinsfile is also included
so that you can easily setup a jenkins-CI for this project. 
  This template was derrived from the experience of working on a commercial grade project in a 
demanding industry with a medium-sized team, and it served the team well. 

Requirements : 
You will need the following things installed to be able to work with this template : 
  - CMake (Version >= 3.15)
    https://cmake.org/download/
    
  - Make (MinGW on Windows, GCC on Linux)
    https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/
    
  - GDB for debugging :
    If you want to use GDB with VS Code, best to use the GDB binary that comes with the MinGW installation. You can find it at :             path/to/MinGW/bin/gdb.exe
    
  - Git (Version 2.25 or greater recommended)
    https://gitforwindows.org/
    
  - Clang (Version 9.0 or greater recommended)
    https://releases.llvm.org/
    
  - VSCode (Recommended but not necessary)
    https://code.visualstudio.com/download

You will find the instructions to execute the build process in commands_for_compilation/compile.bat.
These instructions are meant for a Windows environment, but will be similar on Linux. 

To learn more about how to setup a development environment for this template on Windows 10, 
you can refer this article : https://medium.com/@pamirghimire/setting-up-a-professional-c-development-environment-in-windows-10-3486cd395a47


The template implements the following architecture : 
![Template Architecture](/C_Project_Template_Architecture.png)