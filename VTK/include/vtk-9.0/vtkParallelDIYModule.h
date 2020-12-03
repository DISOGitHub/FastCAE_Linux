
#ifndef VTKPARALLELDIY_EXPORT_H
#define VTKPARALLELDIY_EXPORT_H

#ifdef VTKPARALLELDIY_STATIC_DEFINE
#  define VTKPARALLELDIY_EXPORT
#  define VTKPARALLELDIY_NO_EXPORT
#else
#  ifndef VTKPARALLELDIY_EXPORT
#    ifdef ParallelDIY_EXPORTS
        /* We are building this library */
#      define VTKPARALLELDIY_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKPARALLELDIY_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKPARALLELDIY_NO_EXPORT
#    define VTKPARALLELDIY_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKPARALLELDIY_DEPRECATED
#  define VTKPARALLELDIY_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKPARALLELDIY_DEPRECATED_EXPORT
#  define VTKPARALLELDIY_DEPRECATED_EXPORT VTKPARALLELDIY_EXPORT VTKPARALLELDIY_DEPRECATED
#endif

#ifndef VTKPARALLELDIY_DEPRECATED_NO_EXPORT
#  define VTKPARALLELDIY_DEPRECATED_NO_EXPORT VTKPARALLELDIY_NO_EXPORT VTKPARALLELDIY_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKPARALLELDIY_NO_DEPRECATED
#    define VTKPARALLELDIY_NO_DEPRECATED
#  endif
#endif

#endif /* VTKPARALLELDIY_EXPORT_H */
