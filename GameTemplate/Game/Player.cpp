#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	//�L�����N�^�[���f���̓ǂݍ���
	modelRender.Init("Assets/modelData/SpaceShip/SpaceShip.tkm");

	//�傫���̕ύX
	modelRender.SetScale({ 0.6f,0.6f,0.6f });
	//�����n�_
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = -500.0f;
	//�����蔻��
	characterController.Init(25.0f, -10.0f, position);

	//�|�C���g���C�g
	m_pointLight.Init();
	//�ʒu
	m_pointLight.SetPosition(0.0f,0.0f,0.0f);
	//�J���[
	m_pointLight.SetColor(Vector3(10.0f, 10.0f, 10.0f));
	//�e�����̗ݏ�i�H�j
	m_pointLight.SetAffectPowParam(0.5f);
	//�͈�
	m_pointLight.SetRange(m_scale);
}

Player::~Player()
{
}

bool Player::Start()
{
	return true;
}

void Player::Update()
{
	//�ړ�����
	Move();

	modelRender.Update();
	//�͈�
	//m_timer+= g_gameTime->GetFrameDeltaTime();
	//float move = m_timer * 10.0f;
	//m_scale += move;
	//m_pointLight.SetRange(m_scale);

	//�ʒu��������
	m_pointLight.SetPosition(position);
	m_pointLight.Update();
}

void Player::Move()
{
	//xz�̈ړ����x��0.0f�ɂ���
	moveSpeed.x = 0.0f;
	moveSpeed.y = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ��擾
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	moveSpeed.x += stickL.x * 150.0f;
	moveSpeed.y += stickL.y * 150.0f;

	//�L�����N�^�[�R���g���[���[�ō��W���ړ�
	position = characterController.Execute(moveSpeed, 1.0f / 6.0f);

	//�ړ��͈͂̐���
	//x��
	if (position.x < -600.0f){
		position.x = -600.0f;
		characterController.SetPosition(position);
	}
	else if (position.x > 600.0f){
		position.x = 600.0f;
		characterController.SetPosition(position);
	}
	//y��
	if (position.y < -300.0f){
		position.y = -300.0f;
		characterController.SetPosition(position);
	}
	else if (position.y > 400.0f){
		position.y = 400.0f;
		characterController.SetPosition(position);
	}
		//���W��������
		modelRender.SetPosition(position);
}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}