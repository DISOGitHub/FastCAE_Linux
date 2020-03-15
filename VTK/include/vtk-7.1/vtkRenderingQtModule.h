
#ifndef VTKRENDERINGQT_EXPORT_H
#define VTKRENDERINGQT_EXPORT_H

#ifdef VTKRENDERINGQT_STATIC_DEFINE
#  define VTKRENDERINGQT_EXPORT
#  define VTKRENDERINGQT_NO_EXPORT
#else
#  ifndef VTKRENDERINGQT_EXPORT
#    ifdef vtkRenderingQt_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGQT_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKRENDERINGQT_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKRENDERINGQT_NO_EXPORT
#    define VTKRENDERINGQT_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKRENDERINGQT_DEPRECATED
#  define VTKRENDERINGQT_DEPRECATED __attribute__ ((__deprecated__))
#  define VTKRENDERINGQT_DEPRECATED_EXPORT VTKRENDERINGQT_EXPORT __attribute__ ((__deprecated__))
#  define VTKRENDERINGQT_DEPRECATED_NO_EXPORT VTKRENDERINGQT_NO_EXPORT __attribute__ ((__deprecated__))
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGQT_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingLabelModule.h"

#endif
