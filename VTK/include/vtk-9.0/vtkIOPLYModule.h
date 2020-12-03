
#ifndef VTKIOPLY_EXPORT_H
#define VTKIOPLY_EXPORT_H

#ifdef VTKIOPLY_STATIC_DEFINE
#  define VTKIOPLY_EXPORT
#  define VTKIOPLY_NO_EXPORT
#else
#  ifndef VTKIOPLY_EXPORT
#    ifdef IOPLY_EXPORTS
        /* We are building this library */
#      define VTKIOPLY_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKIOPLY_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKIOPLY_NO_EXPORT
#    define VTKIOPLY_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKIOPLY_DEPRECATED
#  define VTKIOPLY_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKIOPLY_DEPRECATED_EXPORT
#  define VTKIOPLY_DEPRECATED_EXPORT VTKIOPLY_EXPORT VTKIOPLY_DEPRECATED
#endif

#ifndef VTKIOPLY_DEPRECATED_NO_EXPORT
#  define VTKIOPLY_DEPRECATED_NO_EXPORT VTKIOPLY_NO_EXPORT VTKIOPLY_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOPLY_NO_DEPRECATED
#    define VTKIOPLY_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOPLY_EXPORT_H */
