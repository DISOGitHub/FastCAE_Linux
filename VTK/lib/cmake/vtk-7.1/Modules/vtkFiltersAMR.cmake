set(vtkFiltersAMR_LOADED 1)
set(vtkFiltersAMR_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonMath;vtkCommonSystem;vtkFiltersCore;vtkIOXML;vtkParallelCore")
set(vtkFiltersAMR_LIBRARIES "vtkFiltersAMR")
set(vtkFiltersAMR_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-7.1")
set(vtkFiltersAMR_LIBRARY_DIRS "")
set(vtkFiltersAMR_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/lib")
set(vtkFiltersAMR_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkFiltersAMRHierarchy.txt")
set(vtkFiltersAMR_KIT "vtkParallel")

