#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/manips/SoTrackballManip.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoDirectionalLight.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>
//#include <Inventor/nodes/SoRotationXYZ.h>
#include <Inventor/nodes/SoSeparator.h>
//#include <Inventor/engines/SoElapsedTime.h>

int main(int argc, char **argv){
    QWidget * mainwin = SoQt::init(argc, argv, argv[0]);

    SoSeparator *root = new SoSeparator;
    root->ref();

    SoPerspectiveCamera *myCamera = new SoPerspectiveCamera;
    root->addChild(myCamera);               // child 0
    root->addChild(new SoDirectionalLight); // child 1
    root->addChild(new SoTrackballManip);   // child 2

    SoMaterial *myMaterial = new SoMaterial;
    myMaterial->diffuseColor.setValue(1.0, 1.0, 1.0);
    root->addChild(myMaterial);
    root->addChild(new SoCone);

    SoQtRenderArea *myRenderArea = new SoQtRenderArea(mainwin);
    myCamera->viewAll(root, myRenderArea->getViewportRegion());

    myRenderArea->setSceneGraph(root);
    myRenderArea->setTitle("Trackball");
    myRenderArea->show();
    SoQt::show(mainwin);
    SoQt::mainLoop();
    
    root->unref();
    delete myRenderArea;
    return 0;
}