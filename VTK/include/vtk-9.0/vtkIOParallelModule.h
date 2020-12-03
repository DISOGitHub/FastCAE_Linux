
#ifndef VTKIOPARALLEL_EXPORT_H
#define VTKIOPARALLEL_EXPORT_H

#ifdef VTKIOPARALLEL_STATIC_DEFINE
#  define VTKIOPARALLEL_EXPORT
#  define VTKIOPARALLEL_NO_EXPORT
#else
#  ifndef VTKIOPARALLEL_EXPORT
#    ifdef IOParallel_EXPORTS
        /* We are building this library */
#      define VTKIOPARALLEL_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKIOPARALLEL_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKIOPARALLEL_NO_EXPORT
#    define VTKIOPARALLEL_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKIOPARALLEL_DEPRECATED
#  define VTKIOPARALLEL_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKIOPARALLEL_DEPRECATED_EXPORT
#  define VTKIOPARALLEL_DEPRECATED_EXPORT VTKIOPARALLEL_EXPORT VTKIOPARALLEL_DEPRECATED
#endif

#ifndef VTKIOPARALLEL_DEPRECATED_NO_EXPORT
#  define VTKIOPARALLEL_DEPRECATED_NO_EXPORT VTKIOPARALLEL_NO_EXPORT VTKIOPARALLEL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOPARALLEL_NO_DEPRECATED
#    define VTKIOPARALLEL_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkIOGeometryModule.h"
#include "vtkIOImageModule.h"


/* AutoInit implementations. */
#ifdef vtkIOParallel_AUTOINIT_INCLUDE
#include vtkIOParallel_AUTOINIT_INCLUDE
#endif
#ifdef vtkIOParallel_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkIOParallel)
#endif

#endif /* VTKIOPARALLEL_EXPORT_H */
