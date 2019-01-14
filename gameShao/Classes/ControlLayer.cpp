//
//  ControlLayer.cpp
//  gameShao
//
//  Created by shao on 2019/1/10.
//

#include "ControlLayer.hpp"
Sprite *spriteEnemy;

bool ControlLayer::init(){
    return true;
}
void ControlLayer::Scene_init(Scene *scene){
    this->scene=scene;
    auto camera = scene->getChildByName<Node *>("Canvas");
    camera1 = camera->getChildByName<Camera *>("camera_main");
    this->setCameraMask((unsigned short)CameraFlag::USER1);
    camera1->setCameraFlag(CameraFlag::USER1);
    player = camera1->getChildByName<Sprite *>("player");
    label = scene->getChildByName<Label *>("labelMath");
    auto myKeyListener = EventListenerKeyboard::create();
    myKeyListener->onKeyPressed   =  CC_CALLBACK_2(ControlLayer::onKeyPressed, this);
    myKeyListener->onKeyReleased  =  CC_CALLBACK_2(ControlLayer::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
    
    spriteEnemy=camera1->getChildByName<Sprite *>("spriteEnemy");
    gameFMS = GameFMS::create();
    gameFMS->setCamera(camera1,player);
    gameFMS->retain();
    
    scheduleUpdate();
};

int start=0;

void ControlLayer::Collision(){
    if(spriteEnemy!=nullptr && camera1->getChildByName<Sprite *>("spriteEnemy")){
        Rect rect_player=player->getBoundingBox();
        Rect rect_spriteEnemy=spriteEnemy->getBoundingBox();
        if(rect_player.intersectsRect(rect_spriteEnemy)){
            start++;
            camera1->removeChild(spriteEnemy);
        }
    }
};
void ControlLayer::Collision1(){
    if(!camera1->getChildByName<Sprite *>("spriteEnemy")){
        spriteEnemy=Sprite::create();
        spriteEnemy->setTexture("starSprite.png");
        spriteEnemy->setName("spriteEnemy");
        spriteEnemy->setPosition(Vec2(146, 170));
        camera1->addChild(spriteEnemy);
    }
}
int aff=0;
void ControlLayer::update(float dt){
    Collision();
        if(aff>=90){
            Collision1();
            aff=0;
        }
    
    std::string a=std::to_string(start);
    label->setString(a);
    aff++;
}
int j;
void ControlLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event *event){
    CCLOG("aaaaaa&&&&&&&&&&& %d",(int)keyCode);
    
    switch((int)keyCode){
//D键
        case 127:
            this->schedule(schedule_selector(ControlLayer::onMoveKeyboard));
            move=2;
            aboolean=true;
            break;
//A键
        case 124:
            this->schedule(schedule_selector(ControlLayer::onMoveKeyboard));
            move=1;
            aboolean1=true;
            break;
        case 59:
            gameFMS->changeJump();
            break;
        case 6:
            toMenu1Layer();
            break;
    };
}

void ControlLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event){
    switch((int)keyCode){
        case 127:
            if(!aboolean1){
                this->unschedule(schedule_selector(ControlLayer::onMoveKeyboard));
            }
            aboolean=false;
            aboolean1=false;

            break;
        case 124:
            if(!aboolean){
                this->unschedule(schedule_selector(ControlLayer::onMoveKeyboard));
            }
            aboolean=false;
            aboolean1=false;
            break;
            
        default:
            break;
    };
}
void ControlLayer::toMenu1Layer(){
    creator::CreatorReader* reader = creator::CreatorReader::createWithFilename("cocosMenu.ccreator");
    reader->setup();
    Scene *menu1Scene=reader->getSceneGraph();
    menu1Layer=Menu1Layer::create();
    menu1Layer->score=50;
    menu1Layer->init_L(menu1Scene);
    menu1Scene->addChild(menu1Layer);
    Director::getInstance()->replaceScene(menu1Scene);
    
}
void ControlLayer::onMoveKeyboard(float dt){
    gameFMS->Control(move);
    if(aaa>=35){
        gameFMS->changeJump1();
        aaa=0;
    }
    aaa++;
};



