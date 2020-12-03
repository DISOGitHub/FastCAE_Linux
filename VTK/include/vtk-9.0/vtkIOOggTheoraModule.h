
#ifndef VTKIOOGGTHEORA_EXPORT_H
#define VTKIOOGGTHEORA_EXPORT_H

#ifdef VTKIOOGGTHEORA_STATIC_DEFINE
#  define VTKIOOGGTHEORA_EXPORT
#  define VTKIOOGGTHEORA_NO_EXPORT
#else
#  ifndef VTKIOOGGTHEORA_EXPORT
#    ifdef IOOggTheora_EXPORTS
        /* We are building this library */
#      define VTKIOOGGTHEORA_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKIOOGGTHEORA_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKIOOGGTHEORA_NO_EXPORT
#    define VTKIOOGGTHEORA_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKIOOGGTHEORA_DEPRECATED
#  define VTKIOOGGTHEORA_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKIOOGGTHEORA_DEPRECATED_EXPORT
#  define VTKIOOGGTHEORA_DEPRECATED_EXPORT VTKIOOGGTHEORA_EXPORT VTKIOOGGTHEORA_DEPRECATED
#endif

#ifndef VTKIOOGGTHEORA_DEPRECATED_NO_EXPORT
#  define VTKIOOGGTHEORA_DEPRECATED_NO_EXPORT VTKIOOGGTHEORA_NO_EXPORT VTKIOOGGTHEORA_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOOGGTHEORA_NO_DEPRECATED
#    define VTKIOOGGTHEORA_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOOGGTHEORA_EXPORT_H */
