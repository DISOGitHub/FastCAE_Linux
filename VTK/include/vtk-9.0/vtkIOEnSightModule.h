
#ifndef VTKIOENSIGHT_EXPORT_H
#define VTKIOENSIGHT_EXPORT_H

#ifdef VTKIOENSIGHT_STATIC_DEFINE
#  define VTKIOENSIGHT_EXPORT
#  define VTKIOENSIGHT_NO_EXPORT
#else
#  ifndef VTKIOENSIGHT_EXPORT
#    ifdef IOEnSight_EXPORTS
        /* We are building this library */
#      define VTKIOENSIGHT_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKIOENSIGHT_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKIOENSIGHT_NO_EXPORT
#    define VTKIOENSIGHT_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKIOENSIGHT_DEPRECATED
#  define VTKIOENSIGHT_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKIOENSIGHT_DEPRECATED_EXPORT
#  define VTKIOENSIGHT_DEPRECATED_EXPORT VTKIOENSIGHT_EXPORT VTKIOENSIGHT_DEPRECATED
#endif

#ifndef VTKIOENSIGHT_DEPRECATED_NO_EXPORT
#  define VTKIOENSIGHT_DEPRECATED_NO_EXPORT VTKIOENSIGHT_NO_EXPORT VTKIOENSIGHT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOENSIGHT_NO_DEPRECATED
#    define VTKIOENSIGHT_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOENSIGHT_EXPORT_H */
