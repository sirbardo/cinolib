/*********************************************************************************
*  Copyright(C) 2016: Marco Livesu                                               *
*  All rights reserved.                                                          *
*                                                                                *
*  This file is part of CinoLib                                                  *
*                                                                                *
*  CinoLib is dual-licensed:                                                     *
*                                                                                *
*   - For non-commercial use you can redistribute it and/or modify it under the  *
*     terms of the GNU General Public License as published by the Free Software  *
*     Foundation; either version 3 of the License, or (at your option) any later *
*     version.                                                                   *
*                                                                                *
*   - If you wish to use it as part of a commercial software, a proper agreement *
*     with the Author(s) must be reached, based on a proper licensing contract.  *
*                                                                                *
*  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE       *
*  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.     *
*                                                                                *
*  Author(s):                                                                    *
*                                                                                *
*     Marco Livesu (marco.livesu@gmail.com)                                      *
*     http://pers.ge.imati.cnr.it/livesu/                                        *
*                                                                                *
*     Italian National Research Council (CNR)                                    *
*     Institute for Applied Mathematics and Information Technologies (IMATI)     *
*     Via de Marini, 6                                                           *
*     16149 Genoa,                                                               *
*     Italy                                                                      *
**********************************************************************************/
#include <cinolib/stl_container_utilities.h>

namespace cinolib
{

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#ifndef NDEBUG
template<typename C>
CINO_INLINE
void CHECK_BOUNDS(const C & container, int index)
{
    assert(index >= 0);
    assert(index < (int)container.size());
}
#else
template<typename C>
CINO_INLINE void CHECK_BOUNDS(const C &, int) {}
#endif

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

template<typename C,typename E>
CINO_INLINE
bool CONTAINS(const C & container, const E & element)
{
    return (container.find(element) != container.end());
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

template<typename C,typename E>
CINO_INLINE
bool DOES_NOT_CONTAIN(const C & container, const E & element)
{
    return !CONTAINS(container,element);
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

template<typename C,typename E>
CINO_INLINE
bool CONTAINS_VEC(const C & container, const E & element)
{
    return (std::find(container.begin(), container.end(), element) != container.end());
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

template<typename C,typename E>
CINO_INLINE
bool DOES_NOT_CONTAIN_VEC(const C & container, const E & element)
{
    return !CONTAINS_VEC(container,element);
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

template<typename T>
CINO_INLINE
void REMOVE_FROM_VEC(std::vector<T> & vec, const T & elem)
{
    // https://en.wikipedia.org/wiki/Erase–remove_idiom
    //
    // IMPORTANT: erase–remove can only be used with containers
    // holding elements with full value semantics without incurring
    // resource leaks.
    //
    vec.erase(std::remove(vec.begin(), vec.end(), elem), vec.end());
}

}
