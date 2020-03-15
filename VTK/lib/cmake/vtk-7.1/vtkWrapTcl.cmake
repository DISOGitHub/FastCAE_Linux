#
# a cmake implementation of the Wrap Tcl command
# it takes an optional VERSION parameter that will be output
# to the .data file as VERSION ${VERSION}.
# vtkWrapTclInit will then recognize the VERSION keyword, extract the version
# and make sure the corresponding Tcl package is 'provided' with that version.
#

MACRO(VTK_WRAP_TCL2 TARGET)
  # convert to the WRAP3 signature
  SET(MODE SOURCE_LIST)
  SET(SOURCES)
  FOREACH(ARG ${ARGN})
    SET (MODE_CHANGED 0)
    IF ("${ARG}" MATCHES SOURCES)
      SET (MODE SOURCE_LIST)
      SET(MODE_CHANGED 1)
    ENDIF ()
    IF ("${ARG}" MATCHES COMMANDS)
      SET (MODE COMMANDS)
      SET(MODE_CHANGED 1)
    ENDIF ()
    IF (NOT MODE_CHANGED)
      IF (MODE MATCHES SOURCES)
        SET(SOURCES ${SOURCES} ${ARG})
      ENDIF ()
      IF (MODE MATCHES COMMANDS)
        SET(COMMANDS ${COMMANDS} ${ARG})
      ENDIF ()
      IF (MODE MATCHES SOURCE_LIST)
        SET(SOURCE_LIST_NAME "${ARG}")
        SET (MODE SOURCES)
      ENDIF ()
    ENDIF ()
  ENDFOREACH()

  VTK_WRAP_TCL3(${TARGET} ${SOURCE_LIST_NAME} "${SOURCES}" "${COMMANDS}")
ENDMACRO()

MACRO(VTK_WRAP_TCL3 TARGET SRC_LIST_NAME SOURCES COMMANDS)
  if(NOT VTK_WRAP_TCL_INIT_EXE)
    if(TARGET vtkWrapTclInit)
      set(VTK_WRAP_TCL_INIT_EXE vtkWrapTclInit)
    else()
      message(SEND_ERROR
        "VTK_WRAP_TCL_INIT_EXE not specified when calling VTK_WRAP_TCL3")
    endif()
  endif()
  if(NOT VTK_WRAP_TCL_EXE)
    if(TARGET vtkWrapTcl)
      set(VTK_WRAP_TCL_EXE vtkWrapTcl)
    else()
      message(SEND_ERROR
        "VTK_WRAP_TCL_EXE not specified when calling VTK_WRAP_TCL3")
    endif()
  endif()

  # Initialize the custom target counter.
  IF(VTK_WRAP_TCL_NEED_CUSTOM_TARGETS)
    SET(VTK_WRAP_TCL_CUSTOM_COUNT "")
    SET(VTK_WRAP_TCL_CUSTOM_NAME ${TARGET})
    SET(VTK_WRAP_TCL_CUSTOM_LIST)
  ENDIF()

  # start writing the input file for the init file
  SET(VTK_WRAPPER_INIT_DATA "${TARGET}")
  IF (${ARGC} GREATER 4)
    SET(VTK_WRAPPER_INIT_DATA
      "${VTK_WRAPPER_INIT_DATA}\nVERSION ${ARGV4}")
  ENDIF ()

  # collect the common wrapper-tool arguments
  set(_common_args)
  if(VTK_WRAP_HINTS)
    set(_common_args "${_common_args}--hints \"${VTK_WRAP_HINTS}\"\n")
  endif()
  if(KIT_HIERARCHY_FILE)
    set(_common_args "${_common_args}--types \"${KIT_HIERARCHY_FILE}\"\n")
  endif()

  if(NOT CMAKE_VERSION VERSION_LESS 3.1 AND NOT VTK_ENABLE_KITS)
    # write wrapper-tool arguments to a file
    set(_args_file ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.$<CONFIGURATION>.args)
    file(GENERATE OUTPUT ${_args_file} CONTENT "${_common_args}
$<$<BOOL:$<TARGET_PROPERTY:${TARGET},COMPILE_DEFINITIONS>>:
-D\"$<JOIN:$<TARGET_PROPERTY:${TARGET},COMPILE_DEFINITIONS>,\"
-D\">\">
$<$<BOOL:$<TARGET_PROPERTY:${TARGET},INCLUDE_DIRECTORIES>>:
-I\"$<JOIN:$<TARGET_PROPERTY:${TARGET},INCLUDE_DIRECTORIES>,\"
-I\">\">
")
  else()
    # all the include directories
    if(VTK_WRAP_INCLUDE_DIRS)
      set(TMP_INCLUDE_DIRS ${VTK_WRAP_INCLUDE_DIRS})
    else()
      set(TMP_INCLUDE_DIRS ${VTK_INCLUDE_DIRS})
    endif()
    foreach(INCLUDE_DIR ${TMP_INCLUDE_DIRS})
      set(_common_args "${_common_args}-I\"${INCLUDE_DIR}\"\n")
    endforeach()
    get_directory_property(_def_list DEFINITION COMPILE_DEFINITIONS)
    foreach(TMP_DEF ${_def_list})
      set(_common_args "${_common_args}-D${TMP_DEF}\n")
    endforeach()
    # write wrapper-tool arguments to a file
    string(STRIP "${_common_args}" CMAKE_CONFIGURABLE_FILE_CONTENT)
    set(_args_file ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.args)
    configure_file(${CMAKE_ROOT}/Modules/CMakeConfigurableFile.in
                   ${_args_file} @ONLY)
  endif()

  # for each class
  FOREACH(FILE ${SOURCES})
    # should we wrap the file?
    GET_SOURCE_FILE_PROPERTY(TMP_WRAP_EXCLUDE ${FILE} WRAP_EXCLUDE)

    # if we should wrap it
    IF (NOT TMP_WRAP_EXCLUDE)

      # what is the filename without the extension
      GET_FILENAME_COMPONENT(TMP_FILENAME ${FILE} NAME_WE)

      # the input file might be full path so handle that
      GET_FILENAME_COMPONENT(TMP_FILEPATH ${FILE} PATH)

      # compute the input filename
      IF (TMP_FILEPATH)
        SET(TMP_INPUT ${TMP_FILEPATH}/${TMP_FILENAME}.h)
      ELSE ()
        SET(TMP_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/${TMP_FILENAME}.h)
      ENDIF ()

      # add the info to the init file
      SET(VTK_WRAPPER_INIT_DATA
        "${VTK_WRAPPER_INIT_DATA}\n${TMP_FILENAME}")

      # new source file is nameTcl.cxx, add to resulting list
      SET(${SRC_LIST_NAME} ${${SRC_LIST_NAME}}
        ${TMP_FILENAME}Tcl.cxx)

      # add custom command to output
      ADD_CUSTOM_COMMAND(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${TMP_FILENAME}Tcl.cxx
        DEPENDS ${VTK_WRAP_TCL_EXE}
                ${VTK_WRAP_HINTS}
                ${TMP_INPUT}
                ${_args_file}
                ${KIT_HIERARCHY_FILE}
        COMMAND ${VTK_WRAP_TCL_EXE}
                ${TMP_HINTS}
                @${_args_file}
                -o ${CMAKE_CURRENT_BINARY_DIR}/${TMP_FILENAME}Tcl.cxx
                ${TMP_INPUT}
        COMMENT "Tcl Wrapping - generating ${TMP_FILENAME}Tcl.cxx"
        VERBATIM
        )

      # Add this output to a custom target if needed.
      IF(VTK_WRAP_TCL_NEED_CUSTOM_TARGETS)
        SET(VTK_WRAP_TCL_CUSTOM_LIST ${VTK_WRAP_TCL_CUSTOM_LIST}
          ${CMAKE_CURRENT_BINARY_DIR}/${TMP_FILENAME}Tcl.cxx)
        SET(VTK_WRAP_TCL_CUSTOM_COUNT ${VTK_WRAP_TCL_CUSTOM_COUNT}x)
        IF(VTK_WRAP_TCL_CUSTOM_COUNT MATCHES "^${VTK_WRAP_TCL_CUSTOM_LIMIT}$")
          SET(VTK_WRAP_TCL_CUSTOM_NAME ${VTK_WRAP_TCL_CUSTOM_NAME}Hack)
          ADD_CUSTOM_TARGET(${VTK_WRAP_TCL_CUSTOM_NAME} DEPENDS ${VTK_WRAP_TCL_CUSTOM_LIST})
          SET(KIT_TCL_DEPS ${VTK_WRAP_TCL_CUSTOM_NAME})
          SET(VTK_WRAP_TCL_CUSTOM_LIST)
          SET(VTK_WRAP_TCL_CUSTOM_COUNT)
        ENDIF()
      ENDIF()
    ENDIF ()
  ENDFOREACH()

  # finish the data file for the init file
  FOREACH(CMD ${COMMANDS})
    SET(VTK_WRAPPER_INIT_DATA
      "${VTK_WRAPPER_INIT_DATA}\nCOMMAND ${CMD}")
  ENDFOREACH()

  SET(dir ${CMAKE_CURRENT_SOURCE_DIR})
  CONFIGURE_FILE(
    ${VTK_CMAKE_DIR}/vtkWrapperInit.data.in
    ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}Init.data
    @ONLY
    )

  ADD_CUSTOM_COMMAND(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}Init.cxx
    DEPENDS ${VTK_WRAP_TCL_INIT_EXE}
            ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}Init.data
    COMMAND ${VTK_WRAP_TCL_INIT_EXE}
            ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}Init.data
            ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}Init.cxx
    COMMENT "Tcl Wrapping - generating ${TARGET}Init.cxx"
    VERBATIM
    )

  # Create the Init File
  SET(${SRC_LIST_NAME} ${${SRC_LIST_NAME}} ${TARGET}Init.cxx)
ENDMACRO()


IF (VTK_WRAP_TCL_FIND_LIBS)
  GET_FILENAME_COMPONENT(_CURRENT_DIR  "${CMAKE_CURRENT_LIST_FILE}" PATH)
  INCLUDE("${_CURRENT_DIR}/FindTCL.cmake")

  IF(VTK_WRAP_TCL AND NOT TCL_FOUND)
    MESSAGE(FATAL_ERROR "Tcl was not found. Install the Tcl development package (see http://tcl.tk or ActiveState Tcl) and set the appropriate variables (TCL_INCLUDE_PATH, TCL_LIBRARY, TCL_TCLSH) or disable VTK_WRAP_TCL.")
  ENDIF()

  IF(VTK_USE_TK AND NOT TK_FOUND)
    MESSAGE(FATAL_ERROR "Tk was not found. Install the Tk development package (see http://tcl.tk or ActiveState Tcl) and set the appropriate variables (TK_INCLUDE_PATH, TK_LIBRARY, TK_WISH) or disable VTK_USE_TK.")
  ENDIF()

  SET(VTK_TCL_LIBRARIES ${TCL_LIBRARY})
  IF(TCL_LIBRARY_DEBUG)
    SET(VTK_TCL_LIBRARIES optimized ${TCL_LIBRARY} debug ${TCL_LIBRARY_DEBUG})
  ENDIF()
  IF(UNIX)
    # The tcl library needs the math library on unix.
    SET(VTK_TCL_LIBRARIES ${VTK_TCL_LIBRARIES} m)
  ENDIF()
  IF(TK_FOUND)
    SET(VTK_TK_LIBRARIES ${TK_LIBRARY} ${VTK_TCL_LIBRARIES})
    IF(TK_LIBRARY_DEBUG)
      SET(VTK_TK_LIBRARIES optimized ${TK_LIBRARY} debug ${TK_LIBRARY_DEBUG} ${VTK_TCL_LIBRARIES})
    ENDIF()
  ENDIF()
  INCLUDE(${VTK_CMAKE_DIR}/vtkTclTkMacros.cmake)
  # Hide useless settings provided by FindTCL.
  FOREACH(entry
          TK_WISH)
    SET(${entry} "${${entry}}" CACHE INTERNAL "This value is not used by VTK.")
  ENDFOREACH()

  # Need Tk sources on windows
  IF(WIN32)
    FIND_PATH(TK_XLIB_PATH
              X11/Xlib.h ${TK_INCLUDE_PATH}
              ${TK_INCLUDE_PATH}/../xlib)
    MARK_AS_ADVANCED(TK_XLIB_PATH)
  ENDIF()

ENDIF ()


# VS 6 does not like needing to run a huge number of custom commands
# when building a single target.  Generate some extra custom targets
# that run the custom commands before the main target is built.  This
# is a hack to work-around the limitation.  The test to enable it is
# done here since it does not need to be done for every macro
# invocation.
IF(CMAKE_GENERATOR STREQUAL "Visual Studio 6")
  SET(VTK_WRAP_TCL_NEED_CUSTOM_TARGETS 1)
  SET(VTK_WRAP_TCL_CUSTOM_LIMIT x)
  # Limit the number of custom commands in each target
  # to 2^7.
  FOREACH(t 1 2 3 4 5 6 7)
    SET(VTK_WRAP_TCL_CUSTOM_LIMIT
      ${VTK_WRAP_TCL_CUSTOM_LIMIT}${VTK_WRAP_TCL_CUSTOM_LIMIT})
  ENDFOREACH()
ENDIF()
