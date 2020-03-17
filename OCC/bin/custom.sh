#!/bin/bash


if [ -e "${aScriptPath}/custom_gcc_64.sh" ]; then
  source "${aScriptPath}/custom_gcc_64.sh" "$1" "$2" 
fi

