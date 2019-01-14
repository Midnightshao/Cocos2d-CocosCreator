//
//  GameFMS.hpp
//  gameShao
//
//  Created by shao on 2019/1/11.
//

#ifndef GameFMS_hpp
#define GameFMS_hpp

#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SceneManager.hpp"
#include "reader/CreatorReader.h"
#include "reader/Macros.h"
USING_NS_CC;

class GameFMS :public Layer{
public:
    bool init();
    void setCamera(Camera *camera,Sprite *sprite);
    void Control(int a);
    void changeStop();
    void changeLeft();
    void changeRight();
    void changeJump();
    void changeJump1();
    CREATE_FUNC(GameFMS);
private:
    Sprite *player;
    Camera *camera;
};

#endif /* GameFMS_hpp */
