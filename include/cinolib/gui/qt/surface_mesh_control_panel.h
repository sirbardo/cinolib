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
#ifndef CINO_SURFACE_MESH_CONTROL_PANEL_H
#define CINO_SURFACE_MESH_CONTROL_PANEL_H

#ifdef CINOLIB_USES_QT

#include <cinolib/scalar_field.h>
#include <cinolib/drawable_isocontour.h>
#include <cinolib/drawable_vector_field.h>
#include <cinolib/gui/qt/glcanvas.h>

#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QComboBox>
#include <QSlider>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QColorDialog>

namespace cinolib
{

template<class Mesh>
class SurfaceMeshControlPanel
{
    typedef typename Mesh::M_type M;
    typedef typename Mesh::V_type V;
    typedef typename Mesh::E_type E;
    typedef typename Mesh::P_type P;

    public:

        SurfaceMeshControlPanel(Mesh *m, GLcanvas *canvas, QWidget *parent = NULL);

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        void show();

    protected:

        void connect();
        void set_title();
        void set_tex1d();
        void set_tex2d();
        void set_isocurve();
        void set_slice();

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        Mesh                        *m;
        DrawableIsocontour<M,V,E,P>  isocontour;
        DrawableVectorField<Mesh>    gradient;
        GLcanvas                    *canvas;
        QWidget                     *widget;
        QHBoxLayout                 *global_layout;
        QFont                        global_font;
        //
        QPushButton                 *but_load;
        QPushButton                 *but_save;
        QCheckBox                   *cb_show_mesh;
        QRadioButton                *rb_point_shading;
        QRadioButton                *rb_flat_shading;
        QRadioButton                *rb_smooth_shading;
        //
        QRadioButton                *rb_vert_color;
        QRadioButton                *rb_poly_color;
        QRadioButton                *rb_tex1D;
        QRadioButton                *rb_tex2D;
        QPushButton                 *but_set_vert_color;
        QPushButton                 *but_set_poly_color;
        QPushButton                 *but_load_tex2d;
        std::string                  tex2d_filename;
        QComboBox                   *cb_tex1D_type;
        QComboBox                   *cb_tex2D_type;
        QSlider                     *sl_tex2D_density;
        QPushButton                 *but_serialize_field;
        QPushButton                 *but_deserialize_field;
        //
        QCheckBox                   *cb_wireframe;
        QSlider                     *sl_wireframe_width;
        QSlider                     *sl_wireframe_alpha;
        QPushButton                 *but_wireframe_color;
        //
        QCheckBox                   *cb_isocurve;
        QPushButton                 *but_isocurve_color;
        QSlider                     *sl_isocurve_width;
        QSlider                     *sl_isovalue;
        //
        QCheckBox                   *cb_gradient;
        QSlider                     *sl_gradient_size;
        QPushButton                 *but_gradient_color;
        QPushButton                 *but_gradient_serialize;
        QPushButton                 *but_gradient_deserialize;
        //
        QSlider                     *sl_slice_x;
        QSlider                     *sl_slice_y;
        QSlider                     *sl_slice_z;
        QSlider                     *sl_slice_l;
        QSlider                     *sl_slice_q;
        QCheckBox                   *cb_slice_flip_x;
        QCheckBox                   *cb_slice_flip_y;
        QCheckBox                   *cb_slice_flip_z;
        QCheckBox                   *cb_slice_flip_q;
        QCheckBox                   *cb_slice_flip_l;
        QRadioButton                *rb_slice_AND;
        QRadioButton                *rb_slice_OR;
        QPushButton                 *but_slice_reset;
        //
        QCheckBox                   *cb_marked_edges;
        QPushButton                 *but_marked_edges_color;
        QSlider                     *sl_marked_edges_width;
        //
        //QPushButton                 *but_mark_border_edges;
        //QPushButton                 *but_mark_labeling_border;
        //QPushButton                 *but_mark_sharp_creases;
        //QSpinBox                    *but_sharp_crease_angle;
};

}

#ifndef  CINO_STATIC_LIB
#include "surface_mesh_control_panel.cpp"
#endif

#endif // #ifdef CINOLIB_USES_QT

#endif // CINO_SURFACE_MESH_CONTROL_PANEL_H
