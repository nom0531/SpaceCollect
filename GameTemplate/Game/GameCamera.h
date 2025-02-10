#pragma once

class Player;
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();

	//ƒvƒŒƒCƒ„[
	Player* player;
	Vector3 m_toCameraPos;
};

