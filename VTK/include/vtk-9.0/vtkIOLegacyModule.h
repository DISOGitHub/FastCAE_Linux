
#ifndef VTKIOLEGACY_EXPORT_H
#define VTKIOLEGACY_EXPORT_H

#ifdef VTKIOLEGACY_STATIC_DEFINE
#  define VTKIOLEGACY_EXPORT
#  define VTKIOLEGACY_NO_EXPORT
#else
#  ifndef VTKIOLEGACY_EXPORT
#    ifdef IOLegacy_EXPORTS
        /* We are building this library */
#      define VTKIOLEGACY_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKIOLEGACY_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKIOLEGACY_NO_EXPORT
#    define VTKIOLEGACY_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKIOLEGACY_DEPRECATED
#  define VTKIOLEGACY_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKIOLEGACY_DEPRECATED_EXPORT
#  define VTKIOLEGACY_DEPRECATED_EXPORT VTKIOLEGACY_EXPORT VTKIOLEGACY_DEPRECATED
#endif

#ifndef VTKIOLEGACY_DEPRECATED_NO_EXPORT
#  define VTKIOLEGACY_DEPRECATED_NO_EXPORT VTKIOLEGACY_NO_EXPORT VTKIOLEGACY_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOLEGACY_NO_DEPRECATED
#    define VTKIOLEGACY_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOLEGACY_EXPORT_H */
