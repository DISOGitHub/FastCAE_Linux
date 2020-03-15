/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_glew.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_glew_h
#define vtk_glew_h

#define GLEW_NO_GLU

#define VTK_BUILD_SHARED_LIBS

#ifdef WIN32
#  ifndef VTK_BUILD_SHARED_LIBS
#    define GLEW_STATIC
#  endif
#endif


#ifdef __APPLE__
#include "TargetConditionals.h"
#endif

#define VTK_OPENGL_ES_VERSION 

#ifdef ANDROID
# if VTK_OPENGL_ES_VERSION == 20
#  include <GLES2/gl2.h>
# else
#  include <GLES3/gl3.h>
# endif
#else
# if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#  if VTK_OPENGL_ES_VERSION == 20
#   include <OpenGLES/ES2/gl.h>
#  else
#   include <OpenGLES/ES3/gl.h>
#  endif
# else
/* Use the glew library configured for VTK.  */
/* #undef VTK_USE_SYSTEM_GLEW */
//#define VTK_USE_X
#  ifdef VTK_USE_SYSTEM_GLEW
#    include <GL/glew.h>
#    ifdef WIN32
#      include <GL/wglew.h>
#    endif
//#    ifdef VTK_USE_X
//#      include <GL/glxew.h>
//#    endif
#  else
#    include <vtkglew/include/GL/glew.h>
#    ifdef WIN32
#      include <vtkglew/include/GL/wglew.h>
#    endif
//#    ifdef VTK_USE_X
//#      include <vtkglew/include/GL/glxew.h>
//#    endif
#  endif
# endif
#endif

/* some fixes for both ES 2 and 3 */
#if GL_ES_VERSION_2_0 == 1 || GL_ES_VERSION_3_0 == 1
#  define glDrawBuffer(arg)
#  define GL_BACK_LEFT 0
#  define GL_BACK_RIGHT 0
#  define GL_FRONT_LEFT 0
#  define GL_FRONT_RIGHT 0

/* this sends all the data each time as opposed to allowing a subset */
#  define glMultiDrawElements(mode, counts, type, indicies, primcount) \
      for (size_t eCount = 0; eCount < primcount; ++eCount) \
        { \
        glDrawElements(mode, *(counts + eCount), \
          type, (GLvoid *)(indicies[eCount])); \
        }

#endif

/*** deal with some GLES 2.0 specific issues ***/
#if GL_ES_VERSION_2_0 == 1 && GL_ES_VERSION_3_0 != 1

/* most bufer selection does not exist on ES 2.0 */
#  define glReadBuffer(arg)

/* probably so very wrong */
#  define GL_TEXTURE_RECTANGLE GL_TEXTURE_2D

/* VAOs are not part of 2.0  */
#  define GLEW_ARB_vertex_array_object 0
#  define glDeleteVertexArrays(arg1, arg2)
#  define glGenVertexArrays(arg1, arg2)
#  define glBindVertexArray(arg1)

/* this sends all the data each time as opposed to allowing a subset */
#  define glDrawRangeElements(mode, start, end, count, type, indicies) \
     assert("gles 2.0 glDrawRangeElements misuse " && start==0); \
     glDrawElements(mode, count, type, indicies)

#ifndef GL_DRAW_FRAMEBUFFER
#define GL_DRAW_FRAMEBUFFER GL_FRAMEBUFFER
#endif

#endif

/*** deal with some GLES 3.0 specific issues ***/
#if GL_ES_VERSION_3_0 == 1
#  define GLEW_ARB_vertex_array_object 1
#  define GLEW_ARB_instanced_arrays 1
#endif

#endif
