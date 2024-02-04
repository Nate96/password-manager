#!/bin/bash 

git pull
echo "hello world"

files="clInterface.cpp HardwareAbstract.cpp StateMachine.cpp"
echo "$files"

g++ "$files"
echo "Project Compiled 1011"
