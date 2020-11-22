#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCube.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoTransform.h>

int main(int argc, char ** argv){
    QWidget * mainwin = SoQt::init(argc, argv, argv[0]);

    SoSeparator *root = new SoSeparator;
    root->ref();
    
    SoSeparator *sep = new SoSeparator;
    root->addChild(sep);
    SoMaterial *mat = new SoMaterial;
    mat->diffuseColor.setValue(0, 0, 1);
    SoCube *cube = new SoCube;
    sep->addChild(mat);
    sep->addChild(cube);

    SoTransform *trans = new SoTransform;
    trans->translation.setValue(3, 2, 0);
    root->addChild(trans);

    SoCube *cube2 = new SoCube;
    root->addChild(cube2);
    
    SoQtExaminerViewer *eviewer = new SoQtExaminerViewer(mainwin);
    eviewer->setSceneGraph(root);
    eviewer->show();
    SoQt::show(mainwin);
    SoQt::mainLoop();
    
    root->unref();
    delete eviewer;
    return 0;
}