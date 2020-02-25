#include "OtherScene.h"

#include "HelloWorldScene.h"

USING_NS_CC;

Scene *Other::createScene()
{
  return Other::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoadingOther(const char *filename)
{
  printf("Error while loading other: %s\n", filename);
  printf(
    "Depending on how you compiled you might have to add 'Resources/' in "
    "front of filenames in OtherScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Other::init()
{
  _elapsed = 0.f;

  //////////////////////////////
  // 1. super init first
  if (!Scene::init())
  {
    return false;
  }

  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  /////////////////////////////
  // 2. add a menu item with "X" image, which is clicked to quit the program
  //    you may modify it.

  // add a "close" icon to exit the progress. it's an autorelease object
  auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
                                         CC_CALLBACK_1(Other::menuCloseCallback, this));

  if (closeItem == nullptr || closeItem->getContentSize().width <= 0 ||
      closeItem->getContentSize().height <= 0)
  {
    problemLoadingOther("'CloseNormal.png' and 'CloseSelected.png'");
    return false;
  }
  else
  {
    float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
    float y = origin.y + closeItem->getContentSize().height / 2;
    closeItem->setPosition(Vec2(x, y));
  }

  // create menu, it's an autorelease object
  auto menu = Menu::create(closeItem, NULL);
  menu->setPosition(Vec2::ZERO);
  this->addChild(menu, 1);

  /////////////////////////////
  // 3. add your codes below...

  // add a label shows "Hello World"
  // create and initialize a label

  _label = Label::createWithTTF("Hello \nOther", "fonts/arial.ttf", 250);

  if (_label == nullptr)
  {
    problemLoadingOther("'fonts/arial.ttf'");
    return false;
  }
  else
  {
    _label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    this->addChild(_label, 1);
  }

  schedule(CC_SCHEDULE_SELECTOR(Other::changeScene), 5.0f);

  // add "Other" splash screen"
  auto sprite = Sprite::create("HelloWorld.png");
  if (sprite == nullptr)
  {
    problemLoadingOther("'HelloWorld.png'");
    return false;
  }
  else
  {
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
  }

  scheduleUpdate();

  return true;
}

void Other::menuCloseCallback(Ref *pSender)
{
  // Close the cocos2d-x game scene and quit the application
  Director::getInstance()->end();
}

void Other::changeScene(float dt)
{
  Director::getInstance()->replaceScene(HelloWorld::create());
}

void Other::onExit()
{
  Node::onExit();
}
void Other::update(float dt)
{
  Node::update(dt);
  _elapsed+=dt;
  auto text = StringUtils::format("%.2f", _elapsed);
  _label->setString(text);
}
