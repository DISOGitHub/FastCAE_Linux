
#ifndef VTKVIEWSINFOVIS_EXPORT_H
#define VTKVIEWSINFOVIS_EXPORT_H

#ifdef VTKVIEWSINFOVIS_STATIC_DEFINE
#  define VTKVIEWSINFOVIS_EXPORT
#  define VTKVIEWSINFOVIS_NO_EXPORT
#else
#  ifndef VTKVIEWSINFOVIS_EXPORT
#    ifdef ViewsInfovis_EXPORTS
        /* We are building this library */
#      define VTKVIEWSINFOVIS_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKVIEWSINFOVIS_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKVIEWSINFOVIS_NO_EXPORT
#    define VTKVIEWSINFOVIS_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKVIEWSINFOVIS_DEPRECATED
#  define VTKVIEWSINFOVIS_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKVIEWSINFOVIS_DEPRECATED_EXPORT
#  define VTKVIEWSINFOVIS_DEPRECATED_EXPORT VTKVIEWSINFOVIS_EXPORT VTKVIEWSINFOVIS_DEPRECATED
#endif

#ifndef VTKVIEWSINFOVIS_DEPRECATED_NO_EXPORT
#  define VTKVIEWSINFOVIS_DEPRECATED_NO_EXPORT VTKVIEWSINFOVIS_NO_EXPORT VTKVIEWSINFOVIS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKVIEWSINFOVIS_NO_DEPRECATED
#    define VTKVIEWSINFOVIS_NO_DEPRECATED
#  endif
#endif

#endif /* VTKVIEWSINFOVIS_EXPORT_H */
