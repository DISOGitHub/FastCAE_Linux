
#ifndef VTKIOVERAOUT_EXPORT_H
#define VTKIOVERAOUT_EXPORT_H

#ifdef VTKIOVERAOUT_STATIC_DEFINE
#  define VTKIOVERAOUT_EXPORT
#  define VTKIOVERAOUT_NO_EXPORT
#else
#  ifndef VTKIOVERAOUT_EXPORT
#    ifdef IOVeraOut_EXPORTS
        /* We are building this library */
#      define VTKIOVERAOUT_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKIOVERAOUT_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKIOVERAOUT_NO_EXPORT
#    define VTKIOVERAOUT_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKIOVERAOUT_DEPRECATED
#  define VTKIOVERAOUT_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKIOVERAOUT_DEPRECATED_EXPORT
#  define VTKIOVERAOUT_DEPRECATED_EXPORT VTKIOVERAOUT_EXPORT VTKIOVERAOUT_DEPRECATED
#endif

#ifndef VTKIOVERAOUT_DEPRECATED_NO_EXPORT
#  define VTKIOVERAOUT_DEPRECATED_NO_EXPORT VTKIOVERAOUT_NO_EXPORT VTKIOVERAOUT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOVERAOUT_NO_DEPRECATED
#    define VTKIOVERAOUT_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOVERAOUT_EXPORT_H */
