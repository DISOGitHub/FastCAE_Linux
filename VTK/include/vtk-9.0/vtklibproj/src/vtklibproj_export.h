
#ifndef vtklibproj_EXPORT_H
#define vtklibproj_EXPORT_H

#ifdef LIBPROJ_STATIC_DEFINE
#  define vtklibproj_EXPORT
#  define LIBPROJ_NO_EXPORT
#else
#  ifndef vtklibproj_EXPORT
#    ifdef libproj_EXPORTS
        /* We are building this library */
#      define vtklibproj_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define vtklibproj_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef LIBPROJ_NO_EXPORT
#    define LIBPROJ_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef LIBPROJ_DEPRECATED
#  define LIBPROJ_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef LIBPROJ_DEPRECATED_EXPORT
#  define LIBPROJ_DEPRECATED_EXPORT vtklibproj_EXPORT LIBPROJ_DEPRECATED
#endif

#ifndef LIBPROJ_DEPRECATED_NO_EXPORT
#  define LIBPROJ_DEPRECATED_NO_EXPORT LIBPROJ_NO_EXPORT LIBPROJ_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LIBPROJ_NO_DEPRECATED
#    define LIBPROJ_NO_DEPRECATED
#  endif
#endif

#endif /* vtklibproj_EXPORT_H */
