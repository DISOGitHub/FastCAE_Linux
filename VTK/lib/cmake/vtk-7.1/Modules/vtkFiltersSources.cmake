set(vtkFiltersSources_LOADED 1)
set(vtkFiltersSources_DEPENDS "vtkCommonComputationalGeometry;vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonTransforms;vtkFiltersCore;vtkFiltersGeneral")
set(vtkFiltersSources_LIBRARIES "vtkFiltersSources")
set(vtkFiltersSources_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-7.1")
set(vtkFiltersSources_LIBRARY_DIRS "")
set(vtkFiltersSources_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/lib")
set(vtkFiltersSources_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkFiltersSourcesHierarchy.txt")
set(vtkFiltersSources_KIT "vtkFilters")

