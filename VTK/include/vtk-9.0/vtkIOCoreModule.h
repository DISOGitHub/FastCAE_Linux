
#ifndef VTKIOCORE_EXPORT_H
#define VTKIOCORE_EXPORT_H

#ifdef VTKIOCORE_STATIC_DEFINE
#  define VTKIOCORE_EXPORT
#  define VTKIOCORE_NO_EXPORT
#else
#  ifndef VTKIOCORE_EXPORT
#    ifdef IOCore_EXPORTS
        /* We are building this library */
#      define VTKIOCORE_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKIOCORE_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKIOCORE_NO_EXPORT
#    define VTKIOCORE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKIOCORE_DEPRECATED
#  define VTKIOCORE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKIOCORE_DEPRECATED_EXPORT
#  define VTKIOCORE_DEPRECATED_EXPORT VTKIOCORE_EXPORT VTKIOCORE_DEPRECATED
#endif

#ifndef VTKIOCORE_DEPRECATED_NO_EXPORT
#  define VTKIOCORE_DEPRECATED_NO_EXPORT VTKIOCORE_NO_EXPORT VTKIOCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOCORE_NO_DEPRECATED
#    define VTKIOCORE_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOCORE_EXPORT_H */
