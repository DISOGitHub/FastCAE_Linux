set(vtkRenderingImage_LOADED 1)
set(vtkRenderingImage_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonMath;vtkCommonTransforms;vtkImagingCore;vtkRenderingCore")
set(vtkRenderingImage_LIBRARIES "vtkRenderingImage")
set(vtkRenderingImage_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-7.1")
set(vtkRenderingImage_LIBRARY_DIRS "")
set(vtkRenderingImage_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/lib")
set(vtkRenderingImage_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkRenderingImageHierarchy.txt")
set(vtkRenderingImage_KIT "vtkRendering")

