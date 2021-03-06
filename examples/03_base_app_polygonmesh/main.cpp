/* This is a base application for cinolib (https://github.com/maxicino/cinolib).
 * It will show a GL canvas (and associated control panel) to interact
 * with a general polygon mesh.
 *
 * In case you don't need a GUI, you can drop the "Drawable" prefix from the mesh data type.
 * What you will get is a lighter yet fully operational mesh data structure, just
 * without the burden of OpenGL code necessary for rendering!
 *
 * Enjoy!
*/

#include <QApplication>
#include <cinolib/meshes/meshes.h>
#include <cinolib/gui/qt/glcanvas.h>
#include <cinolib/gui/qt/surface_mesh_control_panel.h>

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    std::string s = (argc==2) ? std::string(argv[1]) : std::string(DATA_PATH) + "/lion_vase_poly.off";

    cinolib::DrawablePolygonmesh<> m(s.c_str());

    cinolib::GLcanvas gui;
    gui.push_obj(&m);
    gui.show();

    cinolib::SurfaceMeshControlPanel<cinolib::DrawablePolygonmesh<>> panel(&m, &gui);
    panel.show();

    return a.exec();
}
