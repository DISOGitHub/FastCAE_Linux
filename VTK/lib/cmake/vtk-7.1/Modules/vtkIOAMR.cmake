set(vtkIOAMR_LOADED 1)
set(vtkIOAMR_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonSystem;vtkFiltersAMR;vtkParallelCore;vtkhdf5;vtksys")
set(vtkIOAMR_LIBRARIES "vtkIOAMR")
set(vtkIOAMR_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-7.1")
set(vtkIOAMR_LIBRARY_DIRS "")
set(vtkIOAMR_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/lib")
set(vtkIOAMR_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkIOAMRHierarchy.txt")
set(vtkIOAMR_KIT "vtkParallel")

