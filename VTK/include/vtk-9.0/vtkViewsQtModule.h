
#ifndef VTKVIEWSQT_EXPORT_H
#define VTKVIEWSQT_EXPORT_H

#ifdef VTKVIEWSQT_STATIC_DEFINE
#  define VTKVIEWSQT_EXPORT
#  define VTKVIEWSQT_NO_EXPORT
#else
#  ifndef VTKVIEWSQT_EXPORT
#    ifdef ViewsQt_EXPORTS
        /* We are building this library */
#      define VTKVIEWSQT_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKVIEWSQT_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKVIEWSQT_NO_EXPORT
#    define VTKVIEWSQT_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKVIEWSQT_DEPRECATED
#  define VTKVIEWSQT_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKVIEWSQT_DEPRECATED_EXPORT
#  define VTKVIEWSQT_DEPRECATED_EXPORT VTKVIEWSQT_EXPORT VTKVIEWSQT_DEPRECATED
#endif

#ifndef VTKVIEWSQT_DEPRECATED_NO_EXPORT
#  define VTKVIEWSQT_DEPRECATED_NO_EXPORT VTKVIEWSQT_NO_EXPORT VTKVIEWSQT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKVIEWSQT_NO_DEPRECATED
#    define VTKVIEWSQT_NO_DEPRECATED
#  endif
#endif

#endif /* VTKVIEWSQT_EXPORT_H */
