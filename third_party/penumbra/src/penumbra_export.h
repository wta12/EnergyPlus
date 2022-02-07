
#ifndef PENUMBRA_EXPORT_H
#define PENUMBRA_EXPORT_H

#ifdef PENUMBRA_STATIC_DEFINE
#  define PENUMBRA_EXPORT
#  define PENUMBRA_NO_EXPORT
#else
#  ifndef PENUMBRA_EXPORT
#    ifdef penumbra_EXPORTS
        /* We are building this library */
#      define PENUMBRA_EXPORT 
#    else
        /* We are using this library */
#      define PENUMBRA_EXPORT 
#    endif
#  endif

#  ifndef PENUMBRA_NO_EXPORT
#    define PENUMBRA_NO_EXPORT 
#  endif
#endif

#ifndef PENUMBRA_DEPRECATED
#  define PENUMBRA_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef PENUMBRA_DEPRECATED_EXPORT
#  define PENUMBRA_DEPRECATED_EXPORT PENUMBRA_EXPORT PENUMBRA_DEPRECATED
#endif

#ifndef PENUMBRA_DEPRECATED_NO_EXPORT
#  define PENUMBRA_DEPRECATED_NO_EXPORT PENUMBRA_NO_EXPORT PENUMBRA_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PENUMBRA_NO_DEPRECATED
#    define PENUMBRA_NO_DEPRECATED
#  endif
#endif

#endif /* PENUMBRA_EXPORT_H */
