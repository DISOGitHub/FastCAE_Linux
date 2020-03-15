set(vtkInteractionImage_LOADED 1)
set(vtkInteractionImage_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkImagingColor;vtkImagingCore;vtkInteractionStyle;vtkInteractionWidgets;vtkRenderingCore")
set(vtkInteractionImage_LIBRARIES "vtkInteractionImage")
set(vtkInteractionImage_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-7.1")
set(vtkInteractionImage_LIBRARY_DIRS "")
set(vtkInteractionImage_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/lib")
set(vtkInteractionImage_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkInteractionImageHierarchy.txt")
set(vtkInteractionImage_KIT "vtkInteraction")

