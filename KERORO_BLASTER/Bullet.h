#pragma once
#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

class Bullet 
{
private:
	ISceneManager* smgr;
	ISceneNode* node;
	vector3df direction;

	f32 speed;
	f32 lifetime;
	bool dead;

public:
	Bullet(ISceneManager* sceneManager, vector3df position, vector3df directon);
	~Bullet();
	void Update(f32 deltaTime);
	bool IsDead();
};
