
#ifndef VTKIOIMPORT_EXPORT_H
#define VTKIOIMPORT_EXPORT_H

#ifdef VTKIOIMPORT_STATIC_DEFINE
#  define VTKIOIMPORT_EXPORT
#  define VTKIOIMPORT_NO_EXPORT
#else
#  ifndef VTKIOIMPORT_EXPORT
#    ifdef IOImport_EXPORTS
        /* We are building this library */
#      define VTKIOIMPORT_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKIOIMPORT_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKIOIMPORT_NO_EXPORT
#    define VTKIOIMPORT_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKIOIMPORT_DEPRECATED
#  define VTKIOIMPORT_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKIOIMPORT_DEPRECATED_EXPORT
#  define VTKIOIMPORT_DEPRECATED_EXPORT VTKIOIMPORT_EXPORT VTKIOIMPORT_DEPRECATED
#endif

#ifndef VTKIOIMPORT_DEPRECATED_NO_EXPORT
#  define VTKIOIMPORT_DEPRECATED_NO_EXPORT VTKIOIMPORT_NO_EXPORT VTKIOIMPORT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOIMPORT_NO_DEPRECATED
#    define VTKIOIMPORT_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOIMPORT_EXPORT_H */
