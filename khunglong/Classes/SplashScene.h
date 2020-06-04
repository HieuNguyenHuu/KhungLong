

#include "cocos2d.h"
#include "../Classes/Definitions.h"

class SplashScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SplashScene);
private:
	void switchtomainmenu(float dt);
};