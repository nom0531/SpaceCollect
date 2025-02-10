#pragma once
class Player;
class Materite:public IGameObject
{
public:
	Materite();
	~Materite();

	void Update();
	void Render(RenderContext& rc);
	void Stete();

	//メンバ変数
	ModelRender modelRender;
	Vector3 position;
	Quaternion rot;//回転
	Player* player;
	//ステート処理
	int materiteState = 0;
};

