/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_oggtheora.h

  Copyright (c) Michael Wild, Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_oggtheora_h
#define vtk_oggtheora_h

/* Use the ogg/theora library configured for VTK.  */
/* #undef VTK_USE_SYSTEM_OGGTHEORA */

#ifdef VTK_USE_SYSTEM_OGGTHEORA
# include <ogg/ogg.h>
# include <theora/theoraenc.h>
#else
# include <vtkoggtheora/include/ogg/ogg.h>
# include <vtkoggtheora/include/theora/theoraenc.h>
#endif

#endif
