#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoDirectionalLight.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/nodes/SoSeparator.h>

int main(int argc, char **argv){
    QWidget * mainwin = SoQt::init(argc, argv, argv[0]);

    SoSeparator *root = new SoSeparator;
    SoPerspectiveCamera *myCamera = new SoPerspectiveCamera;
    SoMaterial *myMaterial = new SoMaterial;
    root->ref();
    root->addChild(myCamera);
    root->addChild(new SoDirectionalLight);
    myMaterial->diffuseColor.setValue(1.0, 0.0, 0.0);
    root->addChild(myMaterial);
    root->addChild(new SoCone);

    // Create a renderArea in which to see our scene graph.
    // The render area will appear within the main window.
    SoQtRenderArea *myRenderArea = new SoQtRenderArea(mainwin);

    // Make myCamera see everything
    myCamera->viewAll(root, myRenderArea->getViewportRegion());

    myRenderArea->setSceneGraph(root);
    myRenderArea->setTitle("Hello Cone");
    myRenderArea->show();
    SoQt::show(mainwin);
    SoQt::mainLoop();
    
    root->unref();
    delete myRenderArea;
    return 0;

    return 0;
}