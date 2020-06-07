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
LayerColor *bgColor = LayerColor::create(Color4B(168, 218, 217, 179));
    this->addChild(bgColor, -10);
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

background1 = Sprite::create("road_1.png");
background1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
background1->setScale(3);
background1->setPosition(Vec2(origin.x, origin.y + 300));
background2 = Sprite::create("road_2.png");
background2->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
background2->setScale(3);
background2->setPosition(Vec2(origin.x + background2->getContentSize().width + background1->getContentSize().width, origin.y + 300));
this->addChild(background1, -1);
this->addChild(background2, -1);

_backgroundElements = InfiniteParallaxNode::create();

	// 
	unsigned int rocksQuantity = 5;
	for (unsigned int i = 0; i < rocksQuantity; i++)
	{
		auto rock = Sprite::create("cactus_1.png");
		rock->setAnchorPoint(Point::ZERO);
		rock->setScale(randomValueBetween(2, 3));
		_backgroundElements->addChild(rock,
			randomValueBetween(-10, -6),
			Point(0.95, 1.0),
			Point(
			(visibleSize.height / 5) * (i + 1) + randomValueBetween(0, 100),
			background1->getContentSize().height - 5+ 300));
	}
    addChild(_backgroundElements, -1);
    this->scheduleUpdate();
    
    return true;
}
void GameScene::update(float delta)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    background1->setPositionX(background1->getPositionX() - (SCROLLING_BACKGROUND_SPEED*visibleSize.width));
	background2->setPositionX(background2->getPositionX() - (SCROLLING_BACKGROUND_SPEED*visibleSize.width));

	if (background1->getPositionX() <= -background1->getContentSize().width)
	{
		background1->setPositionX(background2->getPositionX() + background2->getContentSize().width );
	}
	if (background2->getPositionX() <= -background2->getContentSize().width)
	{
		background2->setPositionX(background1->getPositionX() + background1->getContentSize().width);
	}
    Point scrollDecrement = Point(5, 0); 
	_backgroundElements->setPosition(_backgroundElements->getPosition() - scrollDecrement);
	_backgroundElements->updatePosition();
}
float GameScene::randomValueBetween(float low, float high)
{
	return (((float)rand() / RAND_MAX) * (high - low)) + low;
}