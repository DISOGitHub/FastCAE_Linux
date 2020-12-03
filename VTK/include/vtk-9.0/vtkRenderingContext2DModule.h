
#ifndef VTKRENDERINGCONTEXT2D_EXPORT_H
#define VTKRENDERINGCONTEXT2D_EXPORT_H

#ifdef VTKRENDERINGCONTEXT2D_STATIC_DEFINE
#  define VTKRENDERINGCONTEXT2D_EXPORT
#  define VTKRENDERINGCONTEXT2D_NO_EXPORT
#else
#  ifndef VTKRENDERINGCONTEXT2D_EXPORT
#    ifdef RenderingContext2D_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGCONTEXT2D_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKRENDERINGCONTEXT2D_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKRENDERINGCONTEXT2D_NO_EXPORT
#    define VTKRENDERINGCONTEXT2D_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKRENDERINGCONTEXT2D_DEPRECATED
#  define VTKRENDERINGCONTEXT2D_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKRENDERINGCONTEXT2D_DEPRECATED_EXPORT
#  define VTKRENDERINGCONTEXT2D_DEPRECATED_EXPORT VTKRENDERINGCONTEXT2D_EXPORT VTKRENDERINGCONTEXT2D_DEPRECATED
#endif

#ifndef VTKRENDERINGCONTEXT2D_DEPRECATED_NO_EXPORT
#  define VTKRENDERINGCONTEXT2D_DEPRECATED_NO_EXPORT VTKRENDERINGCONTEXT2D_NO_EXPORT VTKRENDERINGCONTEXT2D_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKRENDERINGCONTEXT2D_NO_DEPRECATED
#    define VTKRENDERINGCONTEXT2D_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkRenderingCoreModule.h"


/* AutoInit implementations. */
#ifdef vtkRenderingContext2D_AUTOINIT_INCLUDE
#include vtkRenderingContext2D_AUTOINIT_INCLUDE
#endif
#ifdef vtkRenderingContext2D_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkRenderingContext2D)
#endif

#endif /* VTKRENDERINGCONTEXT2D_EXPORT_H */
