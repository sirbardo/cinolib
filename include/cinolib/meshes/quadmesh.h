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
#ifndef CINO_QUADMESH_H
#define CINO_QUADMESH_H

#include <vector>
#include <sys/types.h>
#include <cinolib/meshes/mesh_attributes.h>
#include <cinolib/meshes/abstract_polygonmesh.h>

namespace cinolib
{

template<class M = Mesh_std_attributes, // default template arguments
         class V = Vert_std_attributes,
         class E = Edge_std_attributes,
         class P = Polygon_std_attributes>
class Quadmesh : public AbstractPolygonMesh<M,V,E,P>
{
    protected:

        std::vector<std::vector<uint>> triangulated_polys; // triangles covering each quad. Useful for
                                                           // robust normal estimation and rendering

    public:

        explicit Quadmesh(){}

        explicit Quadmesh(const char * filename);

        explicit Quadmesh(const std::vector<vec3d> & verts,
                          const std::vector<uint>  & polys);

        explicit Quadmesh(const std::vector<double> & coords,
                          const std::vector<uint>   & polys);

        explicit Quadmesh(const std::vector<vec3d>             & verts,
                          const std::vector<std::vector<uint>> & polys);

        explicit Quadmesh(const std::vector<double>            & coords,
                          const std::vector<std::vector<uint>> & polys);

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        MeshType mesh_type() const { return QUADMESH; }

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        void clear();
        void init();

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        void update_p_normal(const uint pid);
        void update_poly_tessellation();

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        uint verts_per_poly(const uint) const { return 4; }
        uint verts_per_poly()           const { return 4; }
        uint edges_per_poly(const uint) const { return 4; }
        uint edges_per_poly()           const { return 4; }

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        void operator+=(const Quadmesh<M,V,E,P> & m);

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        std::vector<uint> get_ordered_boundary_vertices() const;

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        void              vert_switch_id  (const uint vid0, const uint vid1);
        bool              vert_is_singular(const uint vid) const;
        bool              vert_is_regular (const uint vid) const;
        std::vector<uint> vert_chain      (const uint start, const uint next) const;

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        uint                           edge_opposite_to(const uint pid, const uint eid) const;
        std::vector<uint>              edges_opposite_to(const uint eid) const;
        std::vector<uint>              edge_chain(const uint eid) const;
        std::vector<std::vector<uint>> edge_chains() const;

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        const std::vector<uint> & poly_tessellation       (const uint pid) const;
              void                poly_switch_id          (const uint pid0, const uint pid1);
              void                poly_remove_unreferenced(const uint pid);
};

}

#ifndef  CINO_STATIC_LIB
#include "quadmesh.cpp"
#endif

#endif // CINO_QUADMESH_H
