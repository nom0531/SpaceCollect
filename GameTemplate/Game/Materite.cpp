#include "stdafx.h"
#include "Materite.h"
#include "player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

//��Q���̏���
Materite::Materite()
{
	modelRender.SetRaytracingWorld(false);

	//���f���ǂݍ���
	//modelRender.Init("Assets/modelData/stage_sf/materite_01.tkm");

	//�X�e�[�g����
	Stete();

	//Player��T��
	player = FindGO<Player>("player");
	//�傫���̕ύX
	modelRender.SetScale({ 2.5f,2.5f,2.5f });
	//���ʉ��̓ǂݍ���
	g_soundEngine->ResistWaveFileBank(9, "Assets/sound/damege.wav");
}

Materite::~Materite()
{

}

void Materite::Stete()
{
	//0�`2�̒l�������_���ɕԂ�
	materiteState = rand() % 3;

	switch (materiteState) {
	case 0:
		//modelRender.Init("Assets/modelData/stage_sf/materite_01.tkm");
		modelRender.Init("Assets/modelData/stage_sf/materite_01a.tkm");
		break;
	case 1:
		//modelRender.Init("Assets/modelData/stage_sf/materite_02.tkm");
		modelRender.Init("Assets/modelData/stage_sf/materite_02a.tkm");
		break;
	case 2:
		//modelRender.Init("Assets/modelData/stage_sf/materite_03.tkm");
		modelRender.Init("Assets/modelData/stage_sf/materite_03a.tkm");
		break;
	}
}

void Materite::Update()
{

	//��O�Ɉړ�
	position.z -= 15.0f;

	//y���Az�������ɉ�]��������
	rot.AddRotationDegY(2.0f);
	rot.AddRotationDegZ(2.0f);
	//��]����
	modelRender.SetRotation(rot);

	//�Փˏ���
	Vector3 diff = player->position - position;
	if (diff.Length() <= 100.0f)
	{
		player->playerHP -= 1;
		//�~�X�����J�E���g
		player->materiteCount += 1;

		//���ʉ��̏���
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(9);
		se->Play(false);
		//���ʂ��グ��
		se->SetVolume(3.5f);

		DeleteGO(this);
	}

	//������x�̈ʒu�ō폜
	if (position.z == -300.0f)
	{
		DeleteGO(this);
	}
	//���ʂ̂�����x�͈̔͂̏���
	if (position.x < 300.0f && position.y < 300.0f && position.x > -300.0f && position.y > -300.0f) {
		if (position.z == -30.0f) {
			DeleteGO(this);
		}
	}
	modelRender.SetPosition(position);
	modelRender.Update();
}

void Materite::Render(RenderContext& rc)
{
	//�`�揈��
	modelRender.Draw(rc);
}