#!/bin/bash

if [ "$1" == "" ]; then
  if [ "$2" == "64" ]; then
    # set environment variables used by OCCT
    export CSF_FPE=0

    export TCL_DIR="/usr/lib/x86_64-linux-gnu"
    export TK_DIR="/usr/lib/x86_64-linux-gnu"
    export FREETYPE_DIR="/usr/lib/x86_64-linux-gnu"
    export FREEIMAGE_DIR=""
    export TBB_DIR=""
    export VTK_DIR="/home/libaojun/桌面/VTK/lib"
    export FFMPEG_DIR=""

    if [ "x" != "x" ]; then
      export QTDIR=""
    fi

    export TCL_VERSION_WITH_DOT=""
    export TK_VERSION_WITH_DOT=""

    export CSF_OCCTBinPath="${CASROOT}/bin"
    export CSF_OCCTLibPath="${CASROOT}/lib"
    export CSF_OCCTIncludePath="${CASROOT}/include/opencascade"
    export CSF_OCCTResourcePath="${CASROOT}/share/opencascade/resources"
    export CSF_OCCTDataPath="${CASROOT}/share/opencascade/data"
    export CSF_OCCTSamplesPath="${CASROOT}/share/opencascade/samples"
    export CSF_OCCTTestsPath="${CASROOT}/share/opencascade/tests"
    export CSF_OCCTDocPath="${CASROOT}/share/doc/opencascade"
  fi
fi

