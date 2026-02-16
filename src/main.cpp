#include "BaseApp.hpp"
#include <iostream>

class Example : public BaseApp {
    public:
        Example(Ogre::String name="OgreBook_Example") : BaseApp(name) {}
    protected:
        void createScene() override
        {
            mScnMgr->setAmbientLight(Ogre::ColourValue(1.0F,1.0F,1.0F));
            Ogre::Entity* ent = mScnMgr->createEntity("MyEntity","Sinbad.mesh"); 
            Ogre::SceneNode* node = mScnMgr->getRootSceneNode()->createChildSceneNode("Node1");
            node->attachObject(ent);
            node->setPosition(0.0F, 0.0F, 400.0F);
            node->yaw(Ogre::Degree(180.0F), Ogre::Node::TS_LOCAL); // atención a esto que varía la posición de los ejes
            std::cout << "Node1 position: " << node->_getDerivedPosition() << std::endl;

            Ogre::Entity* ent2 = mScnMgr->createEntity("MyEntity2","Sinbad.mesh"); 
            Ogre::SceneNode* node2 = node->createChildSceneNode("Node2");
            node2->attachObject(ent2); 
            node2->setPosition(10.0F, 0.0F, 0.0F); 
            node2->translate(0.0F, 0.0F, 10.0F, Ogre::Node::TS_PARENT);
            std::cout << "Node2 position: " << node2->_getDerivedPosition() << std::endl;

            Ogre::Entity* ent3 = mScnMgr->createEntity("MyEntity3","Sinbad.mesh"); 
            Ogre::SceneNode* node3 = node->createChildSceneNode("Node3"); 
            node3->attachObject(ent3); 
            node3->setPosition(20.0F, 0.0F, 0.0F); 
            node3->translate(0.0F, 0.0F, 10.0F, Ogre::Node::TS_WORLD);
            std::cout << "Node3 position: " << node3->_getDerivedPosition() << std::endl;
        }
};

int main(int argc, char** argv)
{
    try {
        Example app ("Example6");
        app.initApp();
        app.getRoot()->startRendering();
        app.closeApp();
    } catch (const std::exception& e) {
        std::cerr << "Error occurred during execution: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}