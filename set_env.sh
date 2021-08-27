#!/bin/bash
#Compiler stuff

PKG_CONFIG_PATH="$HOME/usr/lib/pkgconfig:$HOME/usr/lib/x86_64-linux-gnu/pkgconfig:$HOME/usr/share/pkgconfig"

CPATH="$HOME/usr/include"

C_INCLUDE_PATH="$HOME/usr/include:$PWD/ant-core/src"

CPLUS_INCLUDE_PATH="$HOME/usr/include:$PWD/ant-core/src"



#Linker stuff
LD_LIBRARY_PATH="$HOME/usr/lib/x86_64-linux-gnu/:$HOME/usr/lib/:$PWD/deps:/home/prabhav/Desktop/Coding/ant/dependencies/lib"

PATH="$HOME/usr/bin:$PATH"

export PKG_CONFIG_PATH CPATH C_INCLUDE_PATH CPLUS_INCLUDE_PATH LD_LIBRARY_PATH PATH

#CPPFLAGS="-I$HOME/usr/include"
#LDFLAGS="-L$HOME/usr/lib"

