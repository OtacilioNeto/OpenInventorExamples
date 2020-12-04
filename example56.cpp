#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/SoDB.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoRotationXYZ.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoScale.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/nodes/SoDirectionalLight.h>

int main(int argc, char **argv){
    QWidget *mainwin = SoQt::init(argc, argv, argv[0]);

    SoSeparator         *root       = new SoSeparator;
    SoPerspectiveCamera *myCamera   = new SoPerspectiveCamera;
    root->ref();
    root->addChild(myCamera);
    root->addChild(new SoDirectionalLight);

    // Create two separators, for left and right objects
    SoSeparator *leftSep            = new SoSeparator;
    SoSeparator *rightSep           = new SoSeparator;

    // Create the transformation nodes.
    SoTranslation *leftTranslation  = new SoTranslation;
    SoTranslation *rightTranslation = new SoTranslation;
    SoRotationXYZ *myRotation       = new SoRotationXYZ;
    SoScale *myScale                = new SoScale;

    SoMaterial *myMaterial = new SoMaterial;

    root->addChild(leftSep);
    root->addChild(rightSep);

    // Fill in the values.
    leftTranslation->translation.setValue(  5.0, 0.0, 0.0);
    rightTranslation->translation.setValue(-5.0, 0.0, 0.0);
    myRotation->angle = M_PI/2;
    myRotation->axis  = SoRotationXYZ::X;
    myScale->scaleFactor.setValue(2.0, 1.0, 3.0);

    // Add transforms to the scene.
    leftSep->addChild(leftTranslation);     // left graph
    leftSep->addChild(myRotation);          // then rotated
    leftSep->addChild(myScale);             // first scaled

    rightSep->addChild(rightTranslation);     // left graph
    rightSep->addChild(myScale);             // first scaled
    rightSep->addChild(myRotation);          // then rotated
    
    // Read an object from file. 
    SoInput myInput;
    if(argc != 2 ){
        fprintf(stderr, "Você precisa informar um arquivo .iv\n");
        return 1;
    }
    if (!myInput.openFile(argv[1])){
        fprintf(stderr, "Não foi possível abrir %s\n", argv[1]);
        return 1;
    }
    
    SoSeparator *fileContents = SoDB::readAll(&myInput);
    if(fileContents == NULL){
        fprintf(stderr, "Conteúdo de %s ilegível\n", argv[1]);
        return 1;
    }
    myInput.closeFile();

    // Add an instance of the object under each separator.
    leftSep->addChild(fileContents);
    rightSep->addChild(fileContents);
    
    // Construct a renderArea and display the scene.
    SoQtRenderArea *myRenderArea = new SoQtRenderArea(mainwin);

    // Make myCamera see everything
    SoQtExaminerViewer *myViewer = new SoQtExaminerViewer(mainwin);
    myViewer->setSceneGraph(root);

    myCamera->viewAll(root, myViewer->getViewportRegion());

    myViewer->setSceneGraph(root);
    myViewer->setTitle("Ordenando as transformações");
    myViewer->show();
    SoQt::show(mainwin);
    SoQt::mainLoop();
    
    root->unref();
    delete myViewer;

    return 0;
}