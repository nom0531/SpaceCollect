#pragma once

class Player;
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();

	//�v���C���[
	Player* player;
	Vector3 m_toCameraPos;
};

