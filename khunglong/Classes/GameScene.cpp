#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("gamescene", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    
 SpriteFrameCache::getInstance()->addSpriteFramesWithFile("dw.plist", "dw.png");
 
// Định nghĩa hằng. 
const int numberSprite = 3;
const int maxWord = 50;
 

auto khunglong = Sprite::createWithSpriteFrameName("sdinos_jump.png");

khunglong->setPosition(60, 350);
khunglong->setScale(3);
this->addChild(khunglong);
 
Vector<SpriteFrame*> animFrames;
animFrames.reserve(numberSprite);
 

char spriteFrameByName[maxWord] = { 0 }; 
 

for (int i= 1; i < numberSprite; i++) 
{

     sprintf(spriteFrameByName, "dino_%d.png", i);

     auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);

     animFrames.pushBack(frame);
}

Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
Animate* animate = Animate::create(animation);

khunglong->runAction(RepeatForever::create(animate));

    
    return true;
}
