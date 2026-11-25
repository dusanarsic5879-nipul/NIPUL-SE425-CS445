#pragma once
#include <irrlicht.h>
#include <vector>
#include "Bullet.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class PlayerController 
{
private:

	IAnimatedMeshSceneNode* player;
	ISceneManager* smgr;
	IVideoDriver* driver;
	ISceneCollisionManager* collisionManager;
	ICameraSceneNode* camera;

	ISceneNodeAnimator* gravityAnimator;
	std::vector<Bullet*> bullets; //This is multiple bullets so vector
	vector3df movement;
	vector3df velocity;

	f32 moveSpeed;//f32 is used for these, literaly float
	f32 jumpForce;
	f32 gravity;

	//Jumping and count for double jump
	int jumpCount;
	const int maxJumps = 2;

	bool grounded;
	bool shooting;

	f32 shootCooldown;
	f32 shootTimer;

	//keyboard inputs ALL 256
	bool keys[KEY_KEY_CODES_COUNT];

	enum PlayerAnimation 
	{
		IDLE,
		RUN,
		JUMP,
		SHOOT
	};

	PlayerAnimation currentAnimation;

	void UpdateMovement(f32 deltaTime);
	void UpdateJump(f32 deltaTime);
	void UpdateShooting(f32 deltaTime);
	void UpdateAnimation();

public:
	PlayerController(ISceneManager* sceneManager, IVideoDriver* videoDriver, ISceneCollisionManager* collision);

	~PlayerController();

	bool LoadPlayer(const io::path& modelPath, const vector3df& spawnPosition);

	void SetCamera(ICameraSceneNode* cam);

	void Update(f32 deltaTime);

	void OnKeyDown(EKEY_CODE key);
	void OnKeyUp(EKEY_CODE key);

	void Shoot();
	IAnimatedMeshSceneNode* GetPlayer();
};



