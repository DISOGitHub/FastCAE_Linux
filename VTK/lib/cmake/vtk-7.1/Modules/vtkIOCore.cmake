set(vtkIOCore_LOADED 1)
set(vtkIOCore_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonMisc;vtksys;vtkzlib")
set(vtkIOCore_LIBRARIES "vtkIOCore")
set(vtkIOCore_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-7.1")
set(vtkIOCore_LIBRARY_DIRS "")
set(vtkIOCore_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/lib")
set(vtkIOCore_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkIOCoreHierarchy.txt")
set(vtkIOCore_KIT "vtkIO")

