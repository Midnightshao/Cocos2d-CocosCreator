//
//  GameFMS.cpp
//  gameShao
//
//  Created by shao on 2019/1/11.
//

#include "GameFMS.hpp"
bool GameFMS::init(){
    return true;
}
void GameFMS::setCamera(cocos2d::Camera *camera, cocos2d::Sprite *sprite){
    this->camera=camera;
    this->player=sprite;
}
void GameFMS::Control(int a){
    switch (a) {
        case 0:
            changeStop();
            break;
        case 1:
            changeLeft();
            break;
        case 2:
            changeRight();
            break;
        case 3:
            changeJump();
            break;
        default:
            break;
    }
}
void GameFMS::changeStop(){
    
}
void GameFMS::changeLeft(){
    
    this->camera->setPosition(camera->getPositionX()+10,camera->getPositionY());
//    if(this->camera->getPositionX()>=1138){
//        this->camera->setPosition(86,camera->getPositionY());
//    }
    this->player->setPosition(this->player->getPositionX()-10,this->player->getPositionY());
    CCLOG("..................Left %f",camera->getPositionX());
}
void GameFMS::changeRight(){
    this->camera->setPosition(camera->getPositionX()-10,camera->getPositionY());
//    if(this->camera->getPositionX()<=88){
//        this->camera->setPosition(1138,camera->getPositionY());
//    }
    this->player->setPosition(this->player->getPositionX()+10,this->player->getPositionY());

    CCLOG("..................Right %f",camera->getPositionX());
}
void GameFMS::changeJump(){
    auto myMoveBy = MoveBy::create(0.3f, Vec2(10, 330));
    myMoveBy->startWithTarget(player);
    MoveBy *myMoveBy1=myMoveBy->reverse();
    player->runAction(Sequence::create(myMoveBy,myMoveBy1, NULL));
}
void GameFMS::changeJump1(){
    auto myMoveBy = MoveBy::create(0.3f, Vec2(10, 190));
    myMoveBy->startWithTarget(player);
    MoveBy *myMoveBy1=myMoveBy->reverse();
    ActionEase *actionEase = EaseOut::create(myMoveBy,2);
    ActionEase *actionEase1 = EaseIn::create(myMoveBy1,2);
    ActionInterval *ac=Sequence::create(actionEase,actionEase1, NULL);
    
    player->runAction(ac);
}

