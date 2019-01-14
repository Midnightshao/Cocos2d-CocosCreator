//
//  SceneManager.hpp
//  gameShao
//
//  Created by shao on 2019/1/10.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <iostream>
#include "cocos2d.h"
#include "ControlLayer.hpp"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "reader/CreatorReader.h"
#include "reader/Macros.h"
#include "MenuLayer.hpp"
class ControlLayer;
using namespace cocos2d::ui;

USING_NS_CC;
class SceneManager{
public:
    Scene *sceneStart;
public:
    Scene *creatorGame;
    
    
    bool init();
    void createrGame();
    void toGame();
};
#endif /* SceneManager_hpp */
