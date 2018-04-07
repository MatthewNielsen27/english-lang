#!/bin/bash

#Interpret and compile .english code
if [ $1 == "compile" ]; then
  ./compile $2
  FILE=$2
  BASE=${FILE%.*}
  g++ ${BASE}.cpp -o ${BASE}
fi

#Run executable
if [ $1 == "run" ]; then
  FILE=$2
  BASE=${FILE%.*}
  ./${BASE}
fi

#Help script
if [ $1 == "help" ]; then
  echo "./english.sh compile filename.english"
  echo "./english.sh run filename.english"
fi