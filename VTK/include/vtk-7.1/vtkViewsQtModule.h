
#ifndef VTKVIEWSQT_EXPORT_H
#define VTKVIEWSQT_EXPORT_H

#ifdef VTKVIEWSQT_STATIC_DEFINE
#  define VTKVIEWSQT_EXPORT
#  define VTKVIEWSQT_NO_EXPORT
#else
#  ifndef VTKVIEWSQT_EXPORT
#    ifdef vtkViewsQt_EXPORTS
        /* We are building this library */
#      define VTKVIEWSQT_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKVIEWSQT_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKVIEWSQT_NO_EXPORT
#    define VTKVIEWSQT_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKVIEWSQT_DEPRECATED
#  define VTKVIEWSQT_DEPRECATED __attribute__ ((__deprecated__))
#  define VTKVIEWSQT_DEPRECATED_EXPORT VTKVIEWSQT_EXPORT __attribute__ ((__deprecated__))
#  define VTKVIEWSQT_DEPRECATED_NO_EXPORT VTKVIEWSQT_NO_EXPORT __attribute__ ((__deprecated__))
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKVIEWSQT_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkGUISupportQtModule.h"
#include "vtkViewsCoreModule.h"
#include "vtkViewsInfovisModule.h"

#endif
