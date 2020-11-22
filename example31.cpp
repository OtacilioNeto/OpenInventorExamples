#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoDirectionalLight.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoSphere.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoSphere.h>

int main(int argc, char **argv){
    QWidget             *mainwin = SoQt::init(argc, argv, argv[0]);

    SoSeparator         *root           = new SoSeparator;
    SoPerspectiveCamera *myCamera       = new SoPerspectiveCamera;
    root->ref();

    // Construct all parts
    SoGroup             *waterMolecule  = new SoGroup;   // water molecule

    SoGroup             *oxygen         = new SoGroup;          // oxygen atom
    SoMaterial          *redPlastic     = new SoMaterial;
    SoSphere            *sphere1        = new SoSphere;

    SoGroup             *hydrogen1      = new SoGroup;       // hydrogen atoms
    SoGroup             *hydrogen2      = new SoGroup;
    SoTransform         *hydrogenXform1 = new SoTransform;
    SoTransform         *hydrogenXform2 = new SoTransform;
    SoMaterial          *whitePlastic   = new SoMaterial;
    SoSphere            *sphere2        = new SoSphere;
    SoSphere            *sphere3        = new SoSphere;

    // Set all field values for the oxygen atom
    redPlastic->ambientColor.setValue(1.0, 0.0, 0.0);
    redPlastic->diffuseColor.setValue(1.0, 0.0, 0.0);
    redPlastic->specularColor.setValue(0.5, 0.5, 0.5);
    redPlastic->shininess = 0.5;

    // Set all field values for the hydrogen atoms
    hydrogenXform1->scaleFactor.setValue(0.75, 0.75, 0.75);
    hydrogenXform1->translation.setValue(1.2,  1.2, 0.0);
    hydrogenXform2->translation.setValue(-3.2, 0.0, 0.0);

    whitePlastic->ambientColor.setValue(1.0, 1.0, 1.0);
    whitePlastic->diffuseColor.setValue(1.0, 1.0, 1.0);
    whitePlastic->specularColor.setValue(0.5, 0.5, 0.5);
    whitePlastic->shininess = 0.5;

    // Create a hierarchy
    waterMolecule->addChild(oxygen);
    waterMolecule->addChild(hydrogen1);
    waterMolecule->addChild(hydrogen2);

    oxygen->addChild(redPlastic);
    oxygen->addChild(sphere1);
    hydrogen1->addChild(hydrogenXform1);
    hydrogen1->addChild(whitePlastic);
    hydrogen1->addChild(sphere2);
    hydrogen2->addChild(hydrogenXform2);
    hydrogen2->addChild(sphere3);

    root->addChild(myCamera);
    root->addChild(new SoDirectionalLight);
    root->addChild(waterMolecule);
    
    
    // Set up viewer:
    SoQtExaminerViewer *myViewer = new SoQtExaminerViewer(mainwin);
    myViewer->setSceneGraph(root);

    myCamera->viewAll(root, myViewer->getViewportRegion());

    myViewer->setSceneGraph(root);
    myViewer->setTitle("Molecula de Água");
    myViewer->show();
    SoQt::show(mainwin);
    SoQt::mainLoop();
    
    root->unref();
    delete myViewer;
    return 0;
}