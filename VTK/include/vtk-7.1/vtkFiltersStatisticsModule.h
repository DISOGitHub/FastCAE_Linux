
#ifndef VTKFILTERSSTATISTICS_EXPORT_H
#define VTKFILTERSSTATISTICS_EXPORT_H

#ifdef VTKFILTERSSTATISTICS_STATIC_DEFINE
#  define VTKFILTERSSTATISTICS_EXPORT
#  define VTKFILTERSSTATISTICS_NO_EXPORT
#else
#  ifndef VTKFILTERSSTATISTICS_EXPORT
#    ifdef vtkFiltersStatistics_EXPORTS
        /* We are building this library */
#      define VTKFILTERSSTATISTICS_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKFILTERSSTATISTICS_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKFILTERSSTATISTICS_NO_EXPORT
#    define VTKFILTERSSTATISTICS_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKFILTERSSTATISTICS_DEPRECATED
#  define VTKFILTERSSTATISTICS_DEPRECATED __attribute__ ((__deprecated__))
#  define VTKFILTERSSTATISTICS_DEPRECATED_EXPORT VTKFILTERSSTATISTICS_EXPORT __attribute__ ((__deprecated__))
#  define VTKFILTERSSTATISTICS_DEPRECATED_NO_EXPORT VTKFILTERSSTATISTICS_NO_EXPORT __attribute__ ((__deprecated__))
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSSTATISTICS_NO_DEPRECATED
#endif

/* AutoInit implementations.  */
#if defined(vtkFiltersStatistics_INCLUDE)
# include vtkFiltersStatistics_INCLUDE
#endif
#if defined(vtkFiltersStatistics_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkFiltersStatistics)
#endif

#endif
