#pragma once
class Stage:public IGameObject
{
public:
	Stage();
	~Stage();

	void Render(RenderContext& rc);

	//メンバ変数
	ModelRender modelRender;
	//静的物理オブジェクト
	PhysicsStaticObject physicsStaticObject;

};

