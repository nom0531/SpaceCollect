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

	//�����o�ϐ�
	ModelRender modelRender;
	Vector3 position;
	Quaternion rot;//��]
	Player* player;
	//�X�e�[�g����
	int materiteState = 0;
};

