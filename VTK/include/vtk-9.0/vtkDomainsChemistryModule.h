
#ifndef VTKDOMAINSCHEMISTRY_EXPORT_H
#define VTKDOMAINSCHEMISTRY_EXPORT_H

#ifdef VTKDOMAINSCHEMISTRY_STATIC_DEFINE
#  define VTKDOMAINSCHEMISTRY_EXPORT
#  define VTKDOMAINSCHEMISTRY_NO_EXPORT
#else
#  ifndef VTKDOMAINSCHEMISTRY_EXPORT
#    ifdef DomainsChemistry_EXPORTS
        /* We are building this library */
#      define VTKDOMAINSCHEMISTRY_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKDOMAINSCHEMISTRY_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKDOMAINSCHEMISTRY_NO_EXPORT
#    define VTKDOMAINSCHEMISTRY_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKDOMAINSCHEMISTRY_DEPRECATED
#  define VTKDOMAINSCHEMISTRY_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKDOMAINSCHEMISTRY_DEPRECATED_EXPORT
#  define VTKDOMAINSCHEMISTRY_DEPRECATED_EXPORT VTKDOMAINSCHEMISTRY_EXPORT VTKDOMAINSCHEMISTRY_DEPRECATED
#endif

#ifndef VTKDOMAINSCHEMISTRY_DEPRECATED_NO_EXPORT
#  define VTKDOMAINSCHEMISTRY_DEPRECATED_NO_EXPORT VTKDOMAINSCHEMISTRY_NO_EXPORT VTKDOMAINSCHEMISTRY_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKDOMAINSCHEMISTRY_NO_DEPRECATED
#    define VTKDOMAINSCHEMISTRY_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkRenderingCoreModule.h"


/* AutoInit implementations. */
#ifdef vtkDomainsChemistry_AUTOINIT_INCLUDE
#include vtkDomainsChemistry_AUTOINIT_INCLUDE
#endif
#ifdef vtkDomainsChemistry_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkDomainsChemistry)
#endif

#endif /* VTKDOMAINSCHEMISTRY_EXPORT_H */
