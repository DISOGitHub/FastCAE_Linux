
#ifndef VTKCOMMONCORE_EXPORT_H
#define VTKCOMMONCORE_EXPORT_H

#ifdef VTKCOMMONCORE_STATIC_DEFINE
#  define VTKCOMMONCORE_EXPORT
#  define VTKCOMMONCORE_NO_EXPORT
#else
#  ifndef VTKCOMMONCORE_EXPORT
#    ifdef CommonCore_EXPORTS
        /* We are building this library */
#      define VTKCOMMONCORE_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKCOMMONCORE_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKCOMMONCORE_NO_EXPORT
#    define VTKCOMMONCORE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKCOMMONCORE_DEPRECATED
#  define VTKCOMMONCORE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKCOMMONCORE_DEPRECATED_EXPORT
#  define VTKCOMMONCORE_DEPRECATED_EXPORT VTKCOMMONCORE_EXPORT VTKCOMMONCORE_DEPRECATED
#endif

#ifndef VTKCOMMONCORE_DEPRECATED_NO_EXPORT
#  define VTKCOMMONCORE_DEPRECATED_NO_EXPORT VTKCOMMONCORE_NO_EXPORT VTKCOMMONCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKCOMMONCORE_NO_DEPRECATED
#    define VTKCOMMONCORE_NO_DEPRECATED
#  endif
#endif

#endif /* VTKCOMMONCORE_EXPORT_H */
