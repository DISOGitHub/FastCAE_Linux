
#ifndef VTKCOMMONCOLOR_EXPORT_H
#define VTKCOMMONCOLOR_EXPORT_H

#ifdef VTKCOMMONCOLOR_STATIC_DEFINE
#  define VTKCOMMONCOLOR_EXPORT
#  define VTKCOMMONCOLOR_NO_EXPORT
#else
#  ifndef VTKCOMMONCOLOR_EXPORT
#    ifdef CommonColor_EXPORTS
        /* We are building this library */
#      define VTKCOMMONCOLOR_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKCOMMONCOLOR_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKCOMMONCOLOR_NO_EXPORT
#    define VTKCOMMONCOLOR_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKCOMMONCOLOR_DEPRECATED
#  define VTKCOMMONCOLOR_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKCOMMONCOLOR_DEPRECATED_EXPORT
#  define VTKCOMMONCOLOR_DEPRECATED_EXPORT VTKCOMMONCOLOR_EXPORT VTKCOMMONCOLOR_DEPRECATED
#endif

#ifndef VTKCOMMONCOLOR_DEPRECATED_NO_EXPORT
#  define VTKCOMMONCOLOR_DEPRECATED_NO_EXPORT VTKCOMMONCOLOR_NO_EXPORT VTKCOMMONCOLOR_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKCOMMONCOLOR_NO_DEPRECATED
#    define VTKCOMMONCOLOR_NO_DEPRECATED
#  endif
#endif

#endif /* VTKCOMMONCOLOR_EXPORT_H */
