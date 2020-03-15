/* zconf.h -- configuration of the zlib compression library
 * Copyright (C) 1995-2013 Jean-loup Gailly.
 * For conditions of distribution and use, see copyright notice in zlib.h
 */

/* @(#) $Id$ */

#ifndef ZCONF_H
#define ZCONF_H
#define Z_PREFIX
#define Z_HAVE_UNISTD_H

/*
 * If you *really* need a unique prefix for all types and library functions,
 * compile with -DZ_PREFIX. The "standard" zlib should be compiled without it.
 * Even better than compiling with -DZ_PREFIX would be to use configure to set
 * this permanently in zconf.h using "./configure --zprefix".
 */
#ifdef Z_PREFIX     /* may be set to #if 1 by ./configure */
#  define Z_PREFIX_SET

/* all linked symbols */
#  define _dist_code            vtk_zlib__dist_code
#  define _length_code          vtk_zlib__length_code
#  define _tr_align             vtk_zlib__tr_align
#  define _tr_flush_bits        vtk_zlib__tr_flush_bits
#  define _tr_flush_block       vtk_zlib__tr_flush_block
#  define _tr_init              vtk_zlib__tr_init
#  define _tr_stored_block      vtk_zlib__tr_stored_block
#  define _tr_tally             vtk_zlib__tr_tally
#  define adler32               vtk_zlib_adler32
#  define adler32_combine       vtk_zlib_adler32_combine
#  define adler32_combine64     vtk_zlib_adler32_combine64
#  ifndef Z_SOLO
#    define compress              vtk_zlib_compress
#    define compress2             vtk_zlib_compress2
#    define compressBound         vtk_zlib_compressBound
#  endif
#  define crc32                 vtk_zlib_crc32
#  define crc32_combine         vtk_zlib_crc32_combine
#  define crc32_combine64       vtk_zlib_crc32_combine64
#  define deflate               vtk_zlib_deflate
#  define deflateBound          vtk_zlib_deflateBound
#  define deflateCopy           vtk_zlib_deflateCopy
#  define deflateEnd            vtk_zlib_deflateEnd
#  define deflateInit2_         vtk_zlib_deflateInit2_
#  define deflateInit_          vtk_zlib_deflateInit_
#  define deflateParams         vtk_zlib_deflateParams
#  define deflatePending        vtk_zlib_deflatePending
#  define deflatePrime          vtk_zlib_deflatePrime
#  define deflateReset          vtk_zlib_deflateReset
#  define deflateResetKeep      vtk_zlib_deflateResetKeep
#  define deflateSetDictionary  vtk_zlib_deflateSetDictionary
#  define deflateSetHeader      vtk_zlib_deflateSetHeader
#  define deflateTune           vtk_zlib_deflateTune
#  define deflate_copyright     vtk_zlib_deflate_copyright
#  define get_crc_table         vtk_zlib_get_crc_table
#  ifndef Z_SOLO
#    define gz_error              vtk_zlib_gz_error
#    define gz_intmax             vtk_zlib_gz_intmax
#    define gz_strwinerror        vtk_zlib_gz_strwinerror
#    define gzbuffer              vtk_zlib_gzbuffer
#    define gzclearerr            vtk_zlib_gzclearerr
#    define gzclose               vtk_zlib_gzclose
#    define gzclose_r             vtk_zlib_gzclose_r
#    define gzclose_w             vtk_zlib_gzclose_w
#    define gzdirect              vtk_zlib_gzdirect
#    define gzdopen               vtk_zlib_gzdopen
#    define gzeof                 vtk_zlib_gzeof
#    define gzerror               vtk_zlib_gzerror
#    define gzflush               vtk_zlib_gzflush
#    define gzgetc                vtk_zlib_gzgetc
#    define gzgetc_               vtk_zlib_gzgetc_
#    define gzgets                vtk_zlib_gzgets
#    define gzoffset              vtk_zlib_gzoffset
#    define gzoffset64            vtk_zlib_gzoffset64
#    define gzopen                vtk_zlib_gzopen
#    define gzopen64              vtk_zlib_gzopen64
#    ifdef _WIN32
#      define gzopen_w              vtk_zlib_gzopen_w
#    endif
#    define gzprintf              vtk_zlib_gzprintf
#    define gzvprintf             vtk_zlib_gzvprintf
#    define gzputc                vtk_zlib_gzputc
#    define gzputs                vtk_zlib_gzputs
#    define gzread                vtk_zlib_gzread
#    define gzrewind              vtk_zlib_gzrewind
#    define gzseek                vtk_zlib_gzseek
#    define gzseek64              vtk_zlib_gzseek64
#    define gzsetparams           vtk_zlib_gzsetparams
#    define gztell                vtk_zlib_gztell
#    define gztell64              vtk_zlib_gztell64
#    define gzungetc              vtk_zlib_gzungetc
#    define gzwrite               vtk_zlib_gzwrite
#  endif
#  define inflate               vtk_zlib_inflate
#  define inflateBack           vtk_zlib_inflateBack
#  define inflateBackEnd        vtk_zlib_inflateBackEnd
#  define inflateBackInit_      vtk_zlib_inflateBackInit_
#  define inflateCopy           vtk_zlib_inflateCopy
#  define inflateEnd            vtk_zlib_inflateEnd
#  define inflateGetHeader      vtk_zlib_inflateGetHeader
#  define inflateInit2_         vtk_zlib_inflateInit2_
#  define inflateInit_          vtk_zlib_inflateInit_
#  define inflateMark           vtk_zlib_inflateMark
#  define inflatePrime          vtk_zlib_inflatePrime
#  define inflateReset          vtk_zlib_inflateReset
#  define inflateReset2         vtk_zlib_inflateReset2
#  define inflateSetDictionary  vtk_zlib_inflateSetDictionary
#  define inflateGetDictionary  vtk_zlib_inflateGetDictionary
#  define inflateSync           vtk_zlib_inflateSync
#  define inflateSyncPoint      vtk_zlib_inflateSyncPoint
#  define inflateUndermine      vtk_zlib_inflateUndermine
#  define inflateResetKeep      vtk_zlib_inflateResetKeep
#  define inflate_copyright     vtk_zlib_inflate_copyright
#  define inflate_fast          vtk_zlib_inflate_fast
#  define inflate_table         vtk_zlib_inflate_table
#  ifndef Z_SOLO
#    define uncompress            vtk_zlib_uncompress
#  endif
#  define zError                vtk_zlib_zError
#  ifndef Z_SOLO
#    define zcalloc               vtk_zlib_zcalloc
#    define zcfree                vtk_zlib_zcfree
#  endif
#  define zlibCompileFlags      vtk_zlib_zlibCompileFlags
#  define zlibVersion           vtk_zlib_zlibVersion

/* all zlib typedefs in zlib.h and zconf.h */
#  define Byte                  vtk_zlib_Byte
#  define Bytef                 vtk_zlib_Bytef
#  define alloc_func            vtk_zlib_alloc_func
#  define charf                 vtk_zlib_charf
#  define free_func             vtk_zlib_free_func
#  ifndef Z_SOLO
#    define gzFile                vtk_zlib_gzFile
#  endif
#  define gz_header             vtk_zlib_gz_header
#  define gz_headerp            vtk_zlib_gz_headerp
#  define in_func               vtk_zlib_in_func
#  define intf                  vtk_zlib_intf
#  define out_func              vtk_zlib_out_func
#  define uInt                  vtk_zlib_uInt
#  define uIntf                 vtk_zlib_uIntf
#  define uLong                 vtk_zlib_uLong
#  define uLongf                vtk_zlib_uLongf
#  define voidp                 vtk_zlib_voidp
#  define voidpc                vtk_zlib_voidpc
#  define voidpf                vtk_zlib_voidpf

/* all zlib structs in zlib.h and zconf.h */
#  define gz_header_s           vtk_zlib_gz_header_s
#  define internal_state        vtk_zlib_internal_state

/* XXX(kitware) this symbol wasn't Z_PREFIX mangled */
#  define z_errmsg              vtk_zlib_errmsg

#endif

#if defined(__MSDOS__) && !defined(MSDOS)
#  define MSDOS
#endif
#if (defined(OS_2) || defined(__OS2__)) && !defined(OS2)
#  define OS2
#endif
#if defined(_WINDOWS) && !defined(WINDOWS)
#  define WINDOWS
#endif
#if defined(_WIN32) || defined(_WIN32_WCE) || defined(__WIN32__)
#  ifndef WIN32
#    define WIN32
#  endif
#endif
#if (defined(MSDOS) || defined(OS2) || defined(WINDOWS)) && !defined(WIN32)
#  if !defined(__GNUC__) && !defined(__FLAT__) && !defined(__386__)
#    ifndef SYS16BIT
#      define SYS16BIT
#    endif
#  endif
#endif

/*
 * Compile with -DMAXSEG_64K if the alloc function cannot allocate more
 * than 64k bytes at a time (needed on systems with 16-bit int).
 */
#ifdef SYS16BIT
#  define MAXSEG_64K
#endif
#ifdef MSDOS
#  define UNALIGNED_OK
#endif

#ifdef __STDC_VERSION__
#  ifndef STDC
#    define STDC
#  endif
#  if __STDC_VERSION__ >= 199901L
#    ifndef STDC99
#      define STDC99
#    endif
#  endif
#endif
#if !defined(STDC) && (defined(__STDC__) || defined(__cplusplus))
#  define STDC
#endif
#if !defined(STDC) && (defined(__GNUC__) || defined(__BORLANDC__))
#  define STDC
#endif
#if !defined(STDC) && (defined(MSDOS) || defined(WINDOWS) || defined(WIN32))
#  define STDC
#endif
#if !defined(STDC) && (defined(OS2) || defined(__HOS_AIX__))
#  define STDC
#endif

#if defined(__OS400__) && !defined(STDC)    /* iSeries (formerly AS/400). */
#  define STDC
#endif

#ifndef STDC
#  ifndef const /* cannot use !defined(STDC) && !defined(const) on Mac */
#    define const       /* note: need a more gentle solution here */
#  endif
#endif

#if defined(ZLIB_CONST) && !defined(z_const)
#  define z_const const
#else
#  define z_const
#endif

/* Some Mac compilers merge all .h files incorrectly: */
#if defined(__MWERKS__)||defined(applec)||defined(THINK_C)||defined(__SC__)
#  define NO_DUMMY_DECL
#endif

/* Maximum value for memLevel in deflateInit2 */
#ifndef MAX_MEM_LEVEL
#  ifdef MAXSEG_64K
#    define MAX_MEM_LEVEL 8
#  else
#    define MAX_MEM_LEVEL 9
#  endif
#endif

/* Maximum value for windowBits in deflateInit2 and inflateInit2.
 * WARNING: reducing MAX_WBITS makes minigzip unable to extract .gz files
 * created by gzip. (Files created by minigzip can still be extracted by
 * gzip.)
 */
#ifndef MAX_WBITS
#  define MAX_WBITS   15 /* 32K LZ77 window */
#endif

/* The memory requirements for deflate are (in bytes):
            (1 << (windowBits+2)) +  (1 << (memLevel+9))
 that is: 128K for windowBits=15  +  128K for memLevel = 8  (default values)
 plus a few kilobytes for small objects. For example, if you want to reduce
 the default memory requirements from 256K to 128K, compile with
     make CFLAGS="-O -DMAX_WBITS=14 -DMAX_MEM_LEVEL=7"
 Of course this will generally degrade compression (there's no free lunch).

   The memory requirements for inflate are (in bytes) 1 << windowBits
 that is, 32K for windowBits=15 (default value) plus a few kilobytes
 for small objects.
*/

                        /* Type declarations */

#ifndef OF /* function prototypes */
#  ifdef STDC
#    define OF(args)  args
#  else
#    define OF(args)  ()
#  endif
#endif

#ifndef Z_ARG /* function prototypes for stdarg */
#  if defined(STDC) || defined(Z_HAVE_STDARG_H)
#    define Z_ARG(args)  args
#  else
#    define Z_ARG(args)  ()
#  endif
#endif

/* The following definitions for FAR are needed only for MSDOS mixed
 * model programming (small or medium model with some far allocations).
 * This was tested only with MSC; for other MSDOS compilers you may have
 * to define NO_MEMCPY in zutil.h.  If you don't need the mixed model,
 * just define FAR to be empty.
 */
#ifdef SYS16BIT
#  if defined(M_I86SM) || defined(M_I86MM)
     /* MSC small or medium model */
#    define SMALL_MEDIUM
#    ifdef _MSC_VER
#      define FAR _far
#    else
#      define FAR far
#    endif
#  endif
#  if (defined(__SMALL__) || defined(__MEDIUM__))
     /* Turbo C small or medium model */
#    define SMALL_MEDIUM
#    ifdef __BORLANDC__
#      define FAR _far
#    else
#      define FAR far
#    endif
#  endif
#endif

#if defined(WINDOWS) || defined(WIN32)
   /* If building or using zlib as a DLL, define ZLIB_DLL.
    * This is not mandatory, but it offers a little performance increase.
    */
#  ifdef ZLIB_DLL
#    if defined(WIN32) && (!defined(__BORLANDC__) || (__BORLANDC__ >= 0x500))
#      ifdef ZLIB_INTERNAL
#        define ZEXTERN extern __declspec(dllexport)
#      else
#        define ZEXTERN extern __declspec(dllimport)
#      endif
#    endif
#  endif  /* ZLIB_DLL */
   /* If building or using zlib with the WINAPI/WINAPIV calling convention,
    * define ZLIB_WINAPI.
    * Caution: the standard ZLIB1.DLL is NOT compiled using ZLIB_WINAPI.
    */
#  ifdef ZLIB_WINAPI
#    ifdef FAR
#      undef FAR
#    endif
#    include <windows.h>
     /* No need for _export, use ZLIB.DEF instead. */
     /* For complete Windows compatibility, use WINAPI, not __stdcall. */
#    define ZEXPORT WINAPI
#    ifdef WIN32
#      define ZEXPORTVA WINAPIV
#    else
#      define ZEXPORTVA FAR CDECL
#    endif
#  endif
#endif

#if defined (__BEOS__)
#  ifdef ZLIB_DLL
#    ifdef ZLIB_INTERNAL
#      define ZEXPORT   __declspec(dllexport)
#      define ZEXPORTVA __declspec(dllexport)
#    else
#      define ZEXPORT   __declspec(dllimport)
#      define ZEXPORTVA __declspec(dllimport)
#    endif
#  endif
#endif

#ifndef ZEXTERN
#  define ZEXTERN extern
#endif
#ifndef ZEXPORT
#  define ZEXPORT
#endif
#ifndef ZEXPORTVA
#  define ZEXPORTVA
#endif

#ifndef FAR
#  define FAR
#endif

#if !defined(__MACTYPES__)
typedef unsigned char  Byte;  /* 8 bits */
#endif
typedef unsigned int   uInt;  /* 16 bits or more */
typedef unsigned long  uLong; /* 32 bits or more */

#ifdef SMALL_MEDIUM
   /* Borland C/C++ and some old MSC versions ignore FAR inside typedef */
#  define Bytef Byte FAR
#else
   typedef Byte  FAR Bytef;
#endif
typedef char  FAR charf;
typedef int   FAR intf;
typedef uInt  FAR uIntf;
typedef uLong FAR uLongf;

#ifdef STDC
   typedef void const *voidpc;
   typedef void FAR   *voidpf;
   typedef void       *voidp;
#else
   typedef Byte const *voidpc;
   typedef Byte FAR   *voidpf;
   typedef Byte       *voidp;
#endif

#if !defined(Z_U4) && !defined(Z_SOLO) && defined(STDC)
#  include <limits.h>
#  if (UINT_MAX == 0xffffffffUL)
#    define Z_U4 unsigned
#  elif (ULONG_MAX == 0xffffffffUL)
#    define Z_U4 unsigned long
#  elif (USHRT_MAX == 0xffffffffUL)
#    define Z_U4 unsigned short
#  endif
#endif

#ifdef Z_U4
   typedef Z_U4 z_crc_t;
#else
   typedef unsigned long z_crc_t;
#endif

#ifdef HAVE_UNISTD_H    /* may be set to #if 1 by ./configure */
#  define Z_HAVE_UNISTD_H
#endif

#ifdef HAVE_STDARG_H    /* may be set to #if 1 by ./configure */
#  define Z_HAVE_STDARG_H
#endif

#ifdef STDC
#  ifndef Z_SOLO
#    include <sys/types.h>      /* for off_t */
#  endif
#endif

#if defined(STDC) || defined(Z_HAVE_STDARG_H)
#  ifndef Z_SOLO
#    include <stdarg.h>         /* for va_list */
#  endif
#endif

#ifdef _WIN32
#  ifndef Z_SOLO
#    include <stddef.h>         /* for wchar_t */
#  endif
#endif

/* a little trick to accommodate both "#define _LARGEFILE64_SOURCE" and
 * "#define _LARGEFILE64_SOURCE 1" as requesting 64-bit operations, (even
 * though the former does not conform to the LFS document), but considering
 * both "#undef _LARGEFILE64_SOURCE" and "#define _LARGEFILE64_SOURCE 0" as
 * equivalently requesting no 64-bit operations
 */
#if defined(_LARGEFILE64_SOURCE) && -_LARGEFILE64_SOURCE - -1 == 1
#  undef _LARGEFILE64_SOURCE
#endif

#if defined(__WATCOMC__) && !defined(Z_HAVE_UNISTD_H)
#  define Z_HAVE_UNISTD_H
#endif
#ifndef Z_SOLO
#  if defined(Z_HAVE_UNISTD_H) || defined(_LARGEFILE64_SOURCE)
#    include <unistd.h>         /* for SEEK_*, off_t, and _LFS64_LARGEFILE */
#    ifdef VMS
#      include <unixio.h>       /* for off_t */
#    endif
#    ifndef z_off_t
#      define z_off_t off_t
#    endif
#  endif
#endif

#if defined(_LFS64_LARGEFILE) && _LFS64_LARGEFILE-0
#  define Z_LFS64
#endif

#if defined(_LARGEFILE64_SOURCE) && defined(Z_LFS64)
#  define Z_LARGE64
#endif

#if defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS-0 == 64 && defined(Z_LFS64)
#  define Z_WANT64
#endif

#if !defined(SEEK_SET) && !defined(Z_SOLO)
#  define SEEK_SET        0       /* Seek from beginning of file.  */
#  define SEEK_CUR        1       /* Seek from current position.  */
#  define SEEK_END        2       /* Set file pointer to EOF plus "offset" */
#endif

#ifndef z_off_t
#  define z_off_t long
#endif

#if !defined(_WIN32) && defined(Z_LARGE64)
#  define z_off64_t off64_t
#else
#  if defined(_WIN32) && !defined(__GNUC__) && !defined(Z_SOLO)
#    define z_off64_t __int64
#  else
#    define z_off64_t z_off_t
#  endif
#endif

/* MVS linker does not support external names larger than 8 bytes */
#if defined(__MVS__)
  #pragma map(deflateInit_,"DEIN")
  #pragma map(deflateInit2_,"DEIN2")
  #pragma map(deflateEnd,"DEEND")
  #pragma map(deflateBound,"DEBND")
  #pragma map(inflateInit_,"ININ")
  #pragma map(inflateInit2_,"ININ2")
  #pragma map(inflateEnd,"INEND")
  #pragma map(inflateSync,"INSY")
  #pragma map(inflateSetDictionary,"INSEDI")
  #pragma map(compressBound,"CMBND")
  #pragma map(inflate_table,"INTABL")
  #pragma map(inflate_fast,"INFA")
  #pragma map(inflate_copyright,"INCOPY")
#endif

#endif /* ZCONF_H */
