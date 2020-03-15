set(vtkImagingCore_LOADED 1)
set(vtkImagingCore_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonMath;vtkCommonTransforms")
set(vtkImagingCore_LIBRARIES "vtkImagingCore")
set(vtkImagingCore_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-7.1")
set(vtkImagingCore_LIBRARY_DIRS "")
set(vtkImagingCore_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/lib")
set(vtkImagingCore_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkImagingCoreHierarchy.txt")
set(vtkImagingCore_KIT "vtkImaging")

