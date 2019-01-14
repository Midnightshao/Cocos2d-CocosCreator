//
//  SceneManager.cpp
//  gameShao
//
//  Created by shao on 2019/1/10.
//

#include "SceneManager.hpp"

bool SceneManager::init(){
    return true;
}
void SceneManager::createrGame(){
    creator::CreatorReader* reader = creator::CreatorReader::createWithFilename("cocosCreator.ccreator");
    reader->setup();
    sceneStart=reader->getSceneGraph();
    MenuLayer *menuLayer = new MenuLayer();
    menuLayer->init(sceneStart);
    menuLayer->tsm=this;
    sceneStart->addChild(menuLayer);
}
void SceneManager::toGame(){
    creator::CreatorReader* reader = creator::CreatorReader::createWithFilename("cocosGameShao.ccreator");
    reader->setup();
    creatorGame=reader->getSceneGraph();
    ControlLayer *control=new ControlLayer();
    control->init();
    control->Scene_init(creatorGame);
    control->tsm=this;
    creatorGame->addChild(control);
};
