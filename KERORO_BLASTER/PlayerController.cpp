#include "PlayerController.h"

PlayerController::PlayerController(
	ISceneManager* sceneManager,
	IVideoDriver* videoDriver,
	ISceneCollisionManager* collision
) 
{
	//Irrlicht systems
	smgr = sceneManager;
	driver = videoDriver;
	collisionManager = collision;

	player = nullptr;
	camera = nullptr;

	//movement
	moveSpeed = 15.0f;
	jumpForce = 25.0f;
	gravity = 50.0f;

	jumpCount = 0;

	//player sates
	grounded = false;
	shooting = false;

	//shooting cooldown: Keroro has a cool down 
	shootCooldown = 0.5f;
	shootTimer = 0.0f;

	velocity = vector3df(0, 0, 0);

	//animation
	currentAnimation = IDLE;

	//keyboard not pressed 
	for (int i = 0; i < KEY_KEY_CODES_COUNT; i++) 
	{
		keys[i] = false;
	}
}
//Destructor 
PlayerController::~PlayerController() 
{
	//Delete bullet 
	for (Bullet* bullet : bullets) 
	{
		delete bullet;
	}

	bullets.clear();
}

//load keroro model 
bool PlayerController::LoadPlayer(const io::path& modelPath, const vector3df& spawnPosition) 
{
	IAnimatedMesh* mesh = smgr->getMesh(modelPath);
	if (!mesh) 
	{
		return false;
	}

	player = smgr->addAnimatedMeshSceneNode(mesh);
	if (!player) 
	{
		return false;
	}

	//keropoint in cc  
	player->setPosition(spawnPosition);

	player->setScale(vector3df(1, 1, 1));

	player->setAnimationSpeed(24);
	player->setFrameLoop(1, 24);
	player->setLoopMode(true);
	player->setMaterialFlag(EMF_LIGHTING, false);

	return true;
}

//camera 
void PlayerController::SetCamera(ICameraSceneNode* cam) 
{
	camera = cam;
}