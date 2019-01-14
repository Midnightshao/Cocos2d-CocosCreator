//
//  Menu1Layer.hpp
//  gameShao
//
//  Created by shao on 2019/1/12.
//

#ifndef Menu1Layer_hpp
#define Menu1Layer_hpp

#include <iostream>
#include "cocos2d.h"
#include "SceneManager.hpp"
#include "ControlLayer.hpp"
#include "ui/CocosGUI.h"
#include "SceneManager.hpp"
#include "ui/CocosGUI.h"
#include "SceneManager.hpp"
#include "reader/CreatorReader.h"
#include "reader/Macros.h"
#include "reader/CreatorReader.h"
#include "reader/Macros.h"
class ControlLayer;

USING_NS_CC;
using namespace ui;
class ControLayer;
class Menu1Layer : public Layer{
public :
    bool init();
    void init_L(Scene *scene);
    CREATE_FUNC(Menu1Layer);
    void onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
public:
    int score;
    int j=1;
    
    int score_l=0;
    ScrollView *scroll;
    Scene *scene;
    Sprite *layout;
    Vector<Sprite *> vector;
public:
    void update(float dt);
};

#endif /* Menu1Layer_hpp */
