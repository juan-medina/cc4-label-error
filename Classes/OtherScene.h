#ifndef __OTHER_SCENE_H__
#define __OTHER_SCENE_H__

#include "cocos2d.h"

class Other : public cocos2d::Scene
{
public:
  static cocos2d::Scene* createScene();

  virtual bool init();

  // a selector callback
  void menuCloseCallback(cocos2d::Ref* pSender);

  // implement the "static create()" method manually
  CREATE_FUNC(Other);

  void onExit() override;

  void update(float dt) override;
private:
  void changeScene(float dt);
  cocos2d::Label* _label;
  float _elapsed;
};

#endif // __OTHER_SCENE_H__
