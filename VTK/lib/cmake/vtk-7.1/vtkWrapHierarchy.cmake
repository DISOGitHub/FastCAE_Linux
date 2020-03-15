#
# a cmake macro to generate a text file with the class hierarchy
#
macro(VTK_WRAP_HIERARCHY module_name OUTPUT_DIR SOURCES)
  if(NOT VTK_WRAP_HIERARCHY_EXE)
    if(TARGET vtkWrapHierarchy)
      set(VTK_WRAP_HIERARCHY_EXE vtkWrapHierarchy)
    else()
      message(SEND_ERROR "VTK_WRAP_HIERARCHY_EXE not specified when calling VTK_WRAP_HIERARCHY")
    endif()
  endif()

  # collect the common wrapper-tool arguments
  if(NOT CMAKE_VERSION VERSION_LESS 3.1 AND NOT VTK_ENABLE_KITS)
    # write wrapper-tool arguments to a file
    set(_args_file ${module_name}Hierarchy.$<CONFIGURATION>.args)
    file(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${_args_file} CONTENT "
$<$<BOOL:$<TARGET_PROPERTY:${module_name},COMPILE_DEFINITIONS>>:
-D\"$<JOIN:$<TARGET_PROPERTY:${module_name},COMPILE_DEFINITIONS>,\"
-D\">\">
$<$<BOOL:$<TARGET_PROPERTY:${module_name},INCLUDE_DIRECTORIES>>:
-I\"$<JOIN:$<TARGET_PROPERTY:${module_name},INCLUDE_DIRECTORIES>,\"
-I\">\">
")
  else()
    set(_common_args)
    get_directory_property(_def_list DEFINITION COMPILE_DEFINITIONS)
    foreach(TMP_DEF ${_def_list})
      set(_common_args "${_common_args}-D${TMP_DEF}\n")
    endforeach()

    # all the include directories
    if(VTK_WRAP_INCLUDE_DIRS)
      set(TMP_INCLUDE_DIRS ${VTK_WRAP_INCLUDE_DIRS})
    else()
      set(TMP_INCLUDE_DIRS ${VTK_INCLUDE_DIRS})
    endif()
    foreach(INCLUDE_DIR ${TMP_INCLUDE_DIRS})
      set(_common_args "${_common_args}-I\"${INCLUDE_DIR}\"\n")
    endforeach()

    # write wrapper-tool arguments to a file
    set(_args_file ${module_name}Hierarchy.args)
    string(STRIP "${_common_args}" CMAKE_CONFIGURABLE_FILE_CONTENT)
    configure_file(${CMAKE_ROOT}/Modules/CMakeConfigurableFile.in
      ${_args_file} @ONLY)
  endif()

  # list of all files to wrap
  set(VTK_WRAPPER_INIT_DATA)
  # list of used files
  set(INPUT_FILES)

  # For each class
  foreach(FILE ${SOURCES})

    # file properties to include in the hierarchy file
    get_property(TMP_WRAP_EXCLUDE SOURCE ${FILE} PROPERTY WRAP_EXCLUDE)
    get_source_file_property(TMP_ABSTRACT ${FILE} ABSTRACT)
    get_source_file_property(TMP_EXCLUDE_PYTHON ${FILE} WRAP_EXCLUDE_PYTHON)

    # what is the filename without the extension
    get_filename_component(TMP_FILENAME ${FILE} NAME_WE)

    # get the absolute path to the file
    get_filename_component(TMP_FULLPATH ${FILE} ABSOLUTE)

    # get the directory
    get_filename_component(TMP_FILEPATH ${TMP_FULLPATH} PATH)

    # assume header file is in the same directory
    set(TMP_INPUT ${TMP_FILEPATH}/${TMP_FILENAME}.h)

    # include all non-private headers in the hierarchy files
    set(TMP_EXCLUDE_FROM_HIERARCHY OFF)
    get_source_file_property(TMP_SKIP ${FILE} SKIP_HEADER_INSTALL)
    if(TMP_SKIP)
      set(TMP_EXCLUDE_FROM_HIERARCHY ON)
    endif()

    # ensure that header exists (assume it exists if it is marked as wrapped)
    if(TMP_WRAP_EXCLUDE)
      if(NOT EXISTS ${TMP_INPUT})
        set(TMP_EXCLUDE_FROM_HIERARCHY ON)
      endif()
    endif()

    # Exclude this huge generated header file
    if("${TMP_FILENAME}" STREQUAL "vtkgl")
      set(TMP_EXCLUDE_FROM_HIERARCHY ON)
    endif()

    if(NOT TMP_EXCLUDE_FROM_HIERARCHY)
      # add to the INPUT_FILES
      list(APPEND INPUT_FILES ${TMP_INPUT})

      # add the info to the init file
      set(VTK_WRAPPER_INIT_DATA
        "${VTK_WRAPPER_INIT_DATA}${TMP_INPUT};${module_name}")

      if(TMP_ABSTRACT)
        set(VTK_WRAPPER_INIT_DATA "${VTK_WRAPPER_INIT_DATA};ABSTRACT")
      endif()

      if(TMP_WRAP_EXCLUDE)
        set(VTK_WRAPPER_INIT_DATA "${VTK_WRAPPER_INIT_DATA};WRAP_EXCLUDE")
      endif()

      if(TMP_EXCLUDE_PYTHON)
        set(VTK_WRAPPER_INIT_DATA "${VTK_WRAPPER_INIT_DATA};WRAP_EXCLUDE_PYTHON")
      endif()

      set(VTK_WRAPPER_INIT_DATA "${VTK_WRAPPER_INIT_DATA}\n")

    endif()
  endforeach()

  # finish the data file for the init file
  configure_file(
    ${VTK_CMAKE_DIR}/vtkWrapperInit.data.in
    ${module_name}Hierarchy.data
    @ONLY
    )

  # search through the deps to find modules we depend on
  set(OTHER_HIERARCHY_FILES)
  # Don't use ${module_name}_DEPENDS. That list also includes COMPILE_DEPENDS,
  # which aren't library dependencies, merely dependencies for generators and
  # such. Instead, use _WRAP_DEPENDS which includes the DEPENDS and the
  # PRIVATE_DEPENDS from module.cmake, but not COMPILE_DEPENDS.
  foreach(dep ${${module_name}_WRAP_DEPENDS})
    if(NOT "${module_name}" STREQUAL "${dep}")
      if(NOT ${dep}_EXCLUDE_FROM_WRAPPING)
        list(APPEND OTHER_HIERARCHY_FILES "${${dep}_WRAP_HIERARCHY_FILE}")
      endif()
    endif()
  endforeach()

  # Ninja does not wait for order-only dependencies before enforcing the
  # existence of explicit dependencies that those order-only dependencies
  # might have produced.  Specify the real output to help it out.
  if(CMAKE_GENERATOR MATCHES "Ninja")
    set(help_ninja ${OUTPUT_DIR}/${module_name}Hierarchy.txt)
  else()
    set(help_ninja "")
  endif()

  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${module_name}Hierarchy.stamp.txt
           ${help_ninja}
    COMMAND ${VTK_WRAP_HIERARCHY_EXE}
            @${_args_file} -o ${OUTPUT_DIR}/${module_name}Hierarchy.txt
            ${module_name}Hierarchy.data
            ${OTHER_HIERARCHY_FILES}
    COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/${module_name}Hierarchy.stamp.txt
    COMMENT "For ${module_name} - updating ${module_name}Hierarchy.txt"
    DEPENDS ${VTK_WRAP_HIERARCHY_EXE}
            ${CMAKE_CURRENT_BINARY_DIR}/${_args_file}
            ${CMAKE_CURRENT_BINARY_DIR}/${module_name}Hierarchy.data
            ${OTHER_HIERARCHY_FILES}
            ${INPUT_FILES}
    VERBATIM
    )

endmacro()
