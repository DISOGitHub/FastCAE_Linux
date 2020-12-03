
#ifndef VTKIONETCDF_EXPORT_H
#define VTKIONETCDF_EXPORT_H

#ifdef VTKIONETCDF_STATIC_DEFINE
#  define VTKIONETCDF_EXPORT
#  define VTKIONETCDF_NO_EXPORT
#else
#  ifndef VTKIONETCDF_EXPORT
#    ifdef IONetCDF_EXPORTS
        /* We are building this library */
#      define VTKIONETCDF_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKIONETCDF_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKIONETCDF_NO_EXPORT
#    define VTKIONETCDF_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKIONETCDF_DEPRECATED
#  define VTKIONETCDF_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKIONETCDF_DEPRECATED_EXPORT
#  define VTKIONETCDF_DEPRECATED_EXPORT VTKIONETCDF_EXPORT VTKIONETCDF_DEPRECATED
#endif

#ifndef VTKIONETCDF_DEPRECATED_NO_EXPORT
#  define VTKIONETCDF_DEPRECATED_NO_EXPORT VTKIONETCDF_NO_EXPORT VTKIONETCDF_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIONETCDF_NO_DEPRECATED
#    define VTKIONETCDF_NO_DEPRECATED
#  endif
#endif

/* AutoInit implementations. */
#ifdef vtkIONetCDF_AUTOINIT_INCLUDE
#include vtkIONetCDF_AUTOINIT_INCLUDE
#endif
#ifdef vtkIONetCDF_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkIONetCDF)
#endif

#endif /* VTKIONETCDF_EXPORT_H */
