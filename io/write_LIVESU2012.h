/****************************************************************************
* Italian National Research Council                                         *
* Institute for Applied Mathematics and Information Technologies, Genoa     *
* IMATI-GE / CNR                                                            *
*                                                                           *
* Author: Marco Livesu (marco.livesu@gmail.com)                             *
*                                                                           *
* Copyright(C) 2016                                                         *
* All rights reserved.                                                      *
*                                                                           *
* This file is part of CinoLib                                              *
*                                                                           *
* CinoLib is free software; you can redistribute it and/or modify           *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 3 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
****************************************************************************/
#ifndef WRITE_LIVESU2012_H
#define WRITE_LIVESU2012_H

#include "../cinolib.h"

namespace cinolib
{

CINO_INLINE
void write_Livesu2012(const char                          * filename,
                      const std::vector<double>             coords,
                      const std::vector<double>             max_spheres,
                      const std::vector< std::vector<int> > adj_vtx2vtx);

}

#ifndef  CINO_STATIC_LIB
#include "write_LIVESU2012.cpp"
#endif

#endif // WRITE_LIVESU2012