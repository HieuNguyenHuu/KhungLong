#include "cocos2d.h"
#include "InfiniteParallaxNode.h"
#include "Definitions.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void update(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
    Sprite *background1;
    Sprite *background2;
    InfiniteParallaxNode* _backgroundElements;
	float randomValueBetween(float low, float high);
};
