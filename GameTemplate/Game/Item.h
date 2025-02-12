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

	//メンバ変数
	ModelRender modelRender;
	Vector3 position;
	Quaternion rot;
	Player* player;
};

