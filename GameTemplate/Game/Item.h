#pragma once

class Player;
class Item:public IGameObject
{
public:
	Item();
	~Item();

	void Update();
	void Move();
	void Render(RenderContext& rc);

	//�����o�ϐ�
	ModelRender modelRender;
	Vector3 position;
	Quaternion rot;
	Player* player;
};

