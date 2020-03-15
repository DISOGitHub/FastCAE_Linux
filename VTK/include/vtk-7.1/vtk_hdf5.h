/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_hdf5.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_hdf5_h
#define vtk_hdf5_h

/* Use the zlib library configured for VTK.  */
/* #undef VTK_USE_SYSTEM_HDF5 */
#ifdef VTK_USE_SYSTEM_HDF5
# include <hdf5.h>
#else
# include <vtkhdf5/src/hdf5.h>
#endif

#endif
