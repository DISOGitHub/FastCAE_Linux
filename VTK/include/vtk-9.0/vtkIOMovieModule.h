
#ifndef VTKIOMOVIE_EXPORT_H
#define VTKIOMOVIE_EXPORT_H

#ifdef VTKIOMOVIE_STATIC_DEFINE
#  define VTKIOMOVIE_EXPORT
#  define VTKIOMOVIE_NO_EXPORT
#else
#  ifndef VTKIOMOVIE_EXPORT
#    ifdef IOMovie_EXPORTS
        /* We are building this library */
#      define VTKIOMOVIE_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKIOMOVIE_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKIOMOVIE_NO_EXPORT
#    define VTKIOMOVIE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKIOMOVIE_DEPRECATED
#  define VTKIOMOVIE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKIOMOVIE_DEPRECATED_EXPORT
#  define VTKIOMOVIE_DEPRECATED_EXPORT VTKIOMOVIE_EXPORT VTKIOMOVIE_DEPRECATED
#endif

#ifndef VTKIOMOVIE_DEPRECATED_NO_EXPORT
#  define VTKIOMOVIE_DEPRECATED_NO_EXPORT VTKIOMOVIE_NO_EXPORT VTKIOMOVIE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOMOVIE_NO_DEPRECATED
#    define VTKIOMOVIE_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOMOVIE_EXPORT_H */
