#!/bin/bash

g++ -fPIC -fno-stack-protector -c src/mypam.cpp

sudo ld -x --shared -o /lib/x86_64-linux-gnu/security/mypam.so mypam.o

rm mypam.o
