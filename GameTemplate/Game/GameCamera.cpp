#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
	//�J�����̃j�A�N���b�v�ƃt�@�[�N���b�v��ݒ肷��B
	g_camera3D->SetNear(1.0f);
	g_camera3D->SetFar(20000.0f);
}

GameCamera::~GameCamera()
{

}

bool GameCamera::Start()
{
	//�����_���王�_�܂ł̃x�N�g����ݒ�B
	m_toCameraPos.Set(0.0f, 125.0f, -250.0f);
	//�v���C���[�̃C���X�^���X��T���B
	player = FindGO<Player>("player");

	return true;
}

void GameCamera::Update()
{
	Vector3 target;
	target.x = 0.0f;
	//�v���C���[��菭����̈ʒu
	target.y = 0.0f;

	g_camera3D->SetTarget(target);

	Vector3 cameraPos;
	cameraPos = target;
	//�v���C���[����O�̈ʒu
	cameraPos.z = -1200.0f;
	cameraPos.y = 70.0f;

	g_camera3D->SetPosition(cameraPos);
}