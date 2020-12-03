
#ifndef VTKGEOVISCORE_EXPORT_H
#define VTKGEOVISCORE_EXPORT_H

#ifdef VTKGEOVISCORE_STATIC_DEFINE
#  define VTKGEOVISCORE_EXPORT
#  define VTKGEOVISCORE_NO_EXPORT
#else
#  ifndef VTKGEOVISCORE_EXPORT
#    ifdef GeovisCore_EXPORTS
        /* We are building this library */
#      define VTKGEOVISCORE_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKGEOVISCORE_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKGEOVISCORE_NO_EXPORT
#    define VTKGEOVISCORE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKGEOVISCORE_DEPRECATED
#  define VTKGEOVISCORE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKGEOVISCORE_DEPRECATED_EXPORT
#  define VTKGEOVISCORE_DEPRECATED_EXPORT VTKGEOVISCORE_EXPORT VTKGEOVISCORE_DEPRECATED
#endif

#ifndef VTKGEOVISCORE_DEPRECATED_NO_EXPORT
#  define VTKGEOVISCORE_DEPRECATED_NO_EXPORT VTKGEOVISCORE_NO_EXPORT VTKGEOVISCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKGEOVISCORE_NO_DEPRECATED
#    define VTKGEOVISCORE_NO_DEPRECATED
#  endif
#endif

#endif /* VTKGEOVISCORE_EXPORT_H */
