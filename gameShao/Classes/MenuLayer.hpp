//
//  MenuLayer.hpp
//  gameShao
//
//  Created by shao on 2019/1/9.
//

#ifndef MenuLayer_hpp
#define MenuLayer_hpp
#include <iostream>
#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SceneManager.hpp"
#include "reader/CreatorReader.h"
#include "reader/Macros.h"
USING_NS_CC;
using namespace ui;
class SceneManager;
class MenuLayer : public Layer{
public:
    bool init(Scene *scene);
    void init_L();
public:
    void touchCallBack(Ref *sender,Widget::TouchEventType controlEvent);
public:
    SceneManager *tsm;
    Scene *scene;
};

#endif /* MenuLayer_hpp */
