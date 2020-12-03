
#ifndef LOGURU_EXPORT_H
#define LOGURU_EXPORT_H

#ifdef LOGURU_STATIC_DEFINE
#  define LOGURU_EXPORT
#  define LOGURU_NO_EXPORT
#else
#  ifndef LOGURU_EXPORT
#    ifdef loguru_EXPORTS
        /* We are building this library */
#      define LOGURU_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define LOGURU_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef LOGURU_NO_EXPORT
#    define LOGURU_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef LOGURU_DEPRECATED
#  define LOGURU_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef LOGURU_DEPRECATED_EXPORT
#  define LOGURU_DEPRECATED_EXPORT LOGURU_EXPORT LOGURU_DEPRECATED
#endif

#ifndef LOGURU_DEPRECATED_NO_EXPORT
#  define LOGURU_DEPRECATED_NO_EXPORT LOGURU_NO_EXPORT LOGURU_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LOGURU_NO_DEPRECATED
#    define LOGURU_NO_DEPRECATED
#  endif
#endif

#endif /* LOGURU_EXPORT_H */
