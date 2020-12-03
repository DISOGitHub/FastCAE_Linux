
#ifndef VTKRENDERINGVOLUMEOPENGL2_EXPORT_H
#define VTKRENDERINGVOLUMEOPENGL2_EXPORT_H

#ifdef VTKRENDERINGVOLUMEOPENGL2_STATIC_DEFINE
#  define VTKRENDERINGVOLUMEOPENGL2_EXPORT
#  define VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT
#else
#  ifndef VTKRENDERINGVOLUMEOPENGL2_EXPORT
#    ifdef RenderingVolumeOpenGL2_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGVOLUMEOPENGL2_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKRENDERINGVOLUMEOPENGL2_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT
#    define VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKRENDERINGVOLUMEOPENGL2_DEPRECATED
#  define VTKRENDERINGVOLUMEOPENGL2_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKRENDERINGVOLUMEOPENGL2_DEPRECATED_EXPORT
#  define VTKRENDERINGVOLUMEOPENGL2_DEPRECATED_EXPORT VTKRENDERINGVOLUMEOPENGL2_EXPORT VTKRENDERINGVOLUMEOPENGL2_DEPRECATED
#endif

#ifndef VTKRENDERINGVOLUMEOPENGL2_DEPRECATED_NO_EXPORT
#  define VTKRENDERINGVOLUMEOPENGL2_DEPRECATED_NO_EXPORT VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT VTKRENDERINGVOLUMEOPENGL2_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKRENDERINGVOLUMEOPENGL2_NO_DEPRECATED
#    define VTKRENDERINGVOLUMEOPENGL2_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingOpenGL2Module.h"
#include "vtkRenderingVolumeModule.h"


/* AutoInit implementations. */
#ifdef vtkRenderingVolumeOpenGL2_AUTOINIT_INCLUDE
#include vtkRenderingVolumeOpenGL2_AUTOINIT_INCLUDE
#endif
#ifdef vtkRenderingVolumeOpenGL2_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkRenderingVolumeOpenGL2)
#endif

#endif /* VTKRENDERINGVOLUMEOPENGL2_EXPORT_H */
