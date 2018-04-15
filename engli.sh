#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
PURPLE='\033[0;35m'
LPURPLE='\033[1;35m'
NC='\033[0m' # No Color

#Interpret and compile .english code
if [ $1 == "compile" ]; then
  ./compile $2
  RESULT=$?

  # If the interpretation succeeded
  if [ $RESULT -eq 0 ]; then
    echo -e "${NC}@English - ${GREEN}Interpretation complete"
    FILE=$2
    BASE=${FILE%.*}
    g++ ${BASE}.cpp -o ${BASE} -std=c++11
    RESULT=$?

    # If the compilation succeded
    if [ $RESULT -eq 0 ]; then
      echo -e "${NC}@Plain-English: ${GREEN}Compilation complete"
      echo -e "${NC}@Plain-English: To run use ${PURPLE}english ${LPURPLE}run ${NC}$2"

    # If the compilation failed
    else
      echo -e "${NC}@Plain-English: Error: ${RED}Compilation failed, see errors above"
    fi

  # if the interpretation failed
  else
    echo -e "${NC}@Plain-English: Error: ${RED}Interpretation failed"
  fi
  rm ${BASE}.cpp
fi

#Run executable
if [ $1 == "run" ]; then
  FILE=$2
  BASE=${FILE%.*}
  ./${BASE}
fi

#Help script
if [ $1 == "help" ]; then
  echo -e "${GREEN}english compile ${NC}filename.english"
  echo -e "${GREEN}english run ${NC}filename.english"
fi