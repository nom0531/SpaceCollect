#pragma once
class Stage:public IGameObject
{
public:
	Stage();
	~Stage();

	void Render(RenderContext& rc);

	//�����o�ϐ�
	ModelRender modelRender;
	//�ÓI�����I�u�W�F�N�g
	PhysicsStaticObject physicsStaticObject;

};

