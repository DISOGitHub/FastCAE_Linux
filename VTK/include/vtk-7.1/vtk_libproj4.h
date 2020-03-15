/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_libproj4.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_libproj4_h
#define vtk_libproj4_h

/* Use the libproj4 library configured for VTK.  */
/* #undef VTK_USE_SYSTEM_LIBPROJ4 */
#ifdef VTK_USE_SYSTEM_LIBPROJ4
# include <projects.h>
# include <proj_api.h>
# include <geodesic.h>
#else
# include <vtklibproj4/src/projects.h>
# include <vtklibproj4/src/proj_api.h>
# include <vtklibproj4/src/geodesic.h>
#endif

#endif
