//
//  MenuLayer.cpp
//  gameShao
//
//  Created by shao on 2019/1/9.
//

#include "MenuLayer.hpp"
#include "reader/CreatorReader.h"


bool MenuLayer::init(Scene *scene){
    this->scene=scene;
    
    Button *button=scene->getChildByName<Button *>("button1");
    Button *button1=scene->getChildByName<Button *>("button2");

    button->addTouchEventListener(CC_CALLBACK_2(MenuLayer::touchCallBack, this));
    button1->addTouchEventListener(CC_CALLBACK_2(MenuLayer::touchCallBack, this));

    return true;
}
void MenuLayer::touchCallBack(cocos2d::Ref *sender, Widget::TouchEventType controlEvent){
//    CCLOG("eeeffffff..????11111111111111");

    if(controlEvent==Widget::TouchEventType::ENDED){
        auto button=static_cast<Button *>(sender);
        if(button->getName()=="button1"){
            CCLOG("11111111111111111111");
            tsm->createrGame();
        }
        if(button->getName()=="button2"){
            CCLOG("22222222222222222222");
        }
    }
}
void MenuLayer::init_L(){
    
}
