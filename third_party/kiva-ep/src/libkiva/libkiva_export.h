
#ifndef LIBKIVA_EXPORT_H
#define LIBKIVA_EXPORT_H

#ifdef LIBKIVA_STATIC_DEFINE
#  define LIBKIVA_EXPORT
#  define LIBKIVA_NO_EXPORT
#else
#  ifndef LIBKIVA_EXPORT
#    ifdef libkiva_EXPORTS
        /* We are building this library */
#      define LIBKIVA_EXPORT 
#    else
        /* We are using this library */
#      define LIBKIVA_EXPORT 
#    endif
#  endif

#  ifndef LIBKIVA_NO_EXPORT
#    define LIBKIVA_NO_EXPORT 
#  endif
#endif

#ifndef LIBKIVA_DEPRECATED
#  define LIBKIVA_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef LIBKIVA_DEPRECATED_EXPORT
#  define LIBKIVA_DEPRECATED_EXPORT LIBKIVA_EXPORT LIBKIVA_DEPRECATED
#endif

#ifndef LIBKIVA_DEPRECATED_NO_EXPORT
#  define LIBKIVA_DEPRECATED_NO_EXPORT LIBKIVA_NO_EXPORT LIBKIVA_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LIBKIVA_NO_DEPRECATED
#    define LIBKIVA_NO_DEPRECATED
#  endif
#endif

#endif /* LIBKIVA_EXPORT_H */
