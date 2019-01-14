//
//  Menu1Layer.cpp
//  gameShao
//
//  Created by shao on 2019/1/12.
//

#include "Menu1Layer.hpp"
bool Menu1Layer::init(){
    

    return true;
}
void Menu1Layer::init_L(Scene *scene){

    scroll = scene->getChildByName<ScrollView *>("scrollview");
    scroll->setInnerContainerSize(Size(1280, 4500));
    scroll->setDirection(ui::ScrollView::Direction::VERTICAL);
    scroll->retain();
    
    layout = scene->getChildByName<Sprite *>("Layout");
    auto layout1 = layout->getChildByName<Sprite *>("Layout1");
    auto sprite1 = layout1->getChildByName<Sprite *>("sprite");
    auto label   = layout1->getChildByName<Label *>("label");
//    scroll->setBounceEnabled(true);
    scroll->setScrollBarEnabled(true);
    scroll->setScrollBarWidth(5.0);
    scroll->setAnchorPoint(Vec2(0.5, 0.5));
    
    for(int i=0;i<score;i++){
        auto layout_0 = Sprite::create();
        layout_0->setName("layout");
        layout_0->setAnchorPoint(Vec2(0.5, 0.5));
        layout_0->setColor(Color3B(48, 47, 47));
        layout_0->setTexture("background2.png");
        layout_0->setPosition(Vec2(scroll->getPositionX()/3,2000));
        layout_0->setContentSize(layout->getContentSize());
        
        auto layout_1 = Sprite::create();
        layout_1->setTexture("background2.png");
        layout_1->setPosition(Vec2(layout1->getPositionX(),layout1->getPositionY()));
        layout_1->setColor(Color3B(255, 255, 255));
        layout_1->setContentSize(layout1->getContentSize());
        layout_0->addChild(layout_1);
        
        auto Sprite_start=Sprite::create();
        Sprite_start->setTexture("starSprite.png");
        Sprite_start->setPosition(sprite1->getPosition());
        Sprite_start->setContentSize(sprite1->getContentSize());
        layout_1->addChild(Sprite_start);
    
        auto label_0 = Label::create();
        label_0->setString("jaweklfjaiowjgifta");
        label_0->setColor(Color3B(0, 0, 0));
        label_0->setPosition(label->getPosition());
        label_0->setContentSize(label->getContentSize());
        layout_1->addChild(label_0);
        vector.pushBack(layout_0);
    }
    for(int i=0;i<score;i++){
        Sprite *layout=vector.at(i);
        if(i%3==0){
         j++;
         }
         Vec2 vec(scroll->getPositionX()/3 +300 *(i%3),4800 -j*(layout->getContentSize().height+20));
         layout->setPosition(vec);
         layout->setName("ddddfdfafasd");
         scroll->addChild(layout,5);
    }
//        CCLOG("求余数。。。。。。%d",i%3);
    auto myKeyListener = EventListenerKeyboard::create();
    myKeyListener->onKeyPressed   =  CC_CALLBACK_2(Menu1Layer::onKeyPressed, this);
    myKeyListener->onKeyReleased  =  CC_CALLBACK_2(Menu1Layer::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
    
//    scroll->scrollToBottom(1,true);
    
    scheduleUpdate();
}
void Menu1Layer::onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event *event){
    CCLOG("aaaaaa&&&&&&&&&&& %d",(int)keyCode);
    int c=score_l/6;
    int g=score_l/9;
    switch((int)keyCode){
            //D键
        case 127:
            score_l=score_l+1;
            break;
            //A键
        case 124:
            if(score_l>0&&score_l<score){
            score_l=score_l-1;
            }
            break;
            //W键
        case 146:
            scroll->jumpToPercentVertical(g*15);
            if(score_l>=3){
                score_l=score_l-3;
            }
            break;
            //S键
        case 142:
            if(score-score_l>=3&&score_l+3<=score){
                score_l=score_l+3;
            }
            scroll->jumpToPercentVertical(c*12);
            break;
        case 6:
            creator::CreatorReader* reader = creator::CreatorReader::createWithFilename("cocosGameShao.ccreator");
            reader->setup();
            Scene *creatorGame=reader->getSceneGraph();
            ControlLayer *control1=ControlLayer::create();
            control1->init();
            control1->Scene_init(creatorGame);
            creatorGame->addChild(control1);
            Director::getInstance()->replaceScene(creatorGame);
            break;
    }
}
void Menu1Layer::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event){
    switch((int)keyCode){
        case 127:
            
            break;
        case 124:
            
            break;
        case 146:
            
            break;
        case 142:
            
            break;
    }
}
void Menu1Layer::update(float dt){
    
    for(int i=0;i<vector.size();i++){
        Sprite *sprite=vector.at(i);
        if(i==score_l){
            CCLOG("YYYYYYUYUUUUUAAAAA %f",sprite->getPositionY());
            sprite->setColor(Color3B(232,201 ,100));
        }else{
            sprite->setColor(Color3B(72,71 ,71));
        }
    }
}



