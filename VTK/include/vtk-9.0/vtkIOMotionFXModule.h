
#ifndef VTKIOMOTIONFX_EXPORT_H
#define VTKIOMOTIONFX_EXPORT_H

#ifdef VTKIOMOTIONFX_STATIC_DEFINE
#  define VTKIOMOTIONFX_EXPORT
#  define VTKIOMOTIONFX_NO_EXPORT
#else
#  ifndef VTKIOMOTIONFX_EXPORT
#    ifdef IOMotionFX_EXPORTS
        /* We are building this library */
#      define VTKIOMOTIONFX_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKIOMOTIONFX_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKIOMOTIONFX_NO_EXPORT
#    define VTKIOMOTIONFX_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKIOMOTIONFX_DEPRECATED
#  define VTKIOMOTIONFX_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKIOMOTIONFX_DEPRECATED_EXPORT
#  define VTKIOMOTIONFX_DEPRECATED_EXPORT VTKIOMOTIONFX_EXPORT VTKIOMOTIONFX_DEPRECATED
#endif

#ifndef VTKIOMOTIONFX_DEPRECATED_NO_EXPORT
#  define VTKIOMOTIONFX_DEPRECATED_NO_EXPORT VTKIOMOTIONFX_NO_EXPORT VTKIOMOTIONFX_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOMOTIONFX_NO_DEPRECATED
#    define VTKIOMOTIONFX_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOMOTIONFX_EXPORT_H */
