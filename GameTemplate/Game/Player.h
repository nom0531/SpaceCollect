#pragma once

//�v���C���[�N���X�B
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);
	//�ړ�����
	void Move();

	//�����o�ϐ�
	Vector3 position;
	Vector3 moveSpeed;
	ModelRender modelRender;
	//�L�����N�^�[�R���g���[���[
	CharacterController characterController;
	int itemCount = 0;
	int materiteCount = 0;
	//HP
	int playerHP = 3;
	//�e�L�X�g�\��
	FontRender fontRender;
	//�|�C���g���C�g
	PointLight m_pointLight;
	float m_timer;
	float m_scale = 400.0f;
};

