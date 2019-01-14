//
//  ControlLayer.hpp
//  gameShao
//
//  Created by shao on 2019/1/10.
//

#ifndef ControlLayer_hpp
#define ControlLayer_hpp

#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SceneManager.hpp"
#include "reader/CreatorReader.h"
#include "reader/Macros.h"
#include "MenuLayer.hpp"
#include "Menu1Layer.hpp"
#include "GameFMS.hpp"
USING_NS_CC;
using namespace ui;
class GameFMS;
class MenuLayer;
class Menu1Layer;
class SceneManager;
class ControlLayer:public cocos2d::Layer{
public:
    virtual bool init();
    CREATE_FUNC(ControlLayer);
    
    void Collision();
    void Collision1();

    void onMoveKeyboard(float dt);
    void Scene_init(Scene *scene);
    void update(float dt);
    void toMenu1Layer();
    void onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
public:
    int aaa;
    bool aboolean;
    Label *label;
    bool aboolean1;
    bool aboolean2;
    GameFMS *gameFMS;
    int move;
    Vector<Sprite *> vector;
    Menu1Layer *menu1Layer;
    Scene *scene;
    Camera *camera1;
    Sprite *player;
    SceneManager *tsm;
};

#endif /* ControlLayer_hpp */
