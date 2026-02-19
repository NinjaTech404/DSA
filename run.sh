#!/bin/bash
CMAKE_COLOR_DIAGS=ON
CURRENT_DIR=$(pwd)
LOG_FILE=".main.cpp.log.md5"

if [ ! -e ${CURRENT_DIR}/build ]; then
  cmake -S $CURRENT_DIR -B build -G Ninja -Wdev
fi

execute() {
  echo -e "\e[1;32m==> \e[0mProcessing the target..."
  sleep 0.2
  if cmake --build build --target run 2>/dev/null; then
    echo -e "\e[1;32m==> \e[0mTarget executed successfully!"
  else
    echo -e "\e[1;31m==> \e[0mFaild to execute the target!"
  fi
}

gen_hash() {
  enc dgst --md5 -fi ${CURRENT_DIR}/src/main.cpp >$LOG_FILE
  sleep 0.2
  echo -e "\e[1;32m==> \e[0mNew Hash Generated!"
}

clear
echo -e "\e[1;35m==> \e[0mEnvironment initialized!"
sleep 0.2
echo -e "\e[1;34m==> \e[0mWaiting..."
sleep 0.2

while $true; do
  if [ -e $LOG_FILE ]; then
    str_old="$(cat $LOG_FILE)"
    str_new="$(enc dgst --md5 -fi ${CURRENT_DIR}/src/main.cpp)"
    if [[ $str_old != $str_new ]]; then
      clear
      echo -e "\e[1;32m==> \e[0mNew Changes Discovered!"
      gen_hash
      sleep 0.2
      execute
    fi
  else
    clear
    gen_hash
    sleep 0.2
    execute
  fi
  sleep 1
done
