
#ifndef vtkogg_EXPORT_H
#define vtkogg_EXPORT_H

#ifdef OGG_STATIC_DEFINE
#  define vtkogg_EXPORT
#  define OGG_NO_EXPORT
#else
#  ifndef vtkogg_EXPORT
#    ifdef ogg_EXPORTS
        /* We are building this library */
#      define vtkogg_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define vtkogg_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef OGG_NO_EXPORT
#    define OGG_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef OGG_DEPRECATED
#  define OGG_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef OGG_DEPRECATED_EXPORT
#  define OGG_DEPRECATED_EXPORT vtkogg_EXPORT OGG_DEPRECATED
#endif

#ifndef OGG_DEPRECATED_NO_EXPORT
#  define OGG_DEPRECATED_NO_EXPORT OGG_NO_EXPORT OGG_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef OGG_NO_DEPRECATED
#    define OGG_NO_DEPRECATED
#  endif
#endif

#endif /* vtkogg_EXPORT_H */
