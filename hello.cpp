#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCube.h>

int main(int argc, char ** argv){
    QWidget * mainwin = SoQt::init(argc, argv, argv[0]);

    SoSeparator *root = new SoSeparator;
    root->ref();
    
    SoCube *cube = new SoCube;
    root->addChild(cube);
    
    SoQtExaminerViewer *eviewer = new SoQtExaminerViewer(mainwin);
    eviewer->setSceneGraph(root);
    eviewer->show();
    SoQt::show(mainwin);
    SoQt::mainLoop();
    
    root->unref();
    delete eviewer;
    return 0;
}