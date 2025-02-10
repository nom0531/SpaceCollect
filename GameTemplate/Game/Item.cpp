#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

//�A�C�e������
Item::Item()
{
	modelRender.SetRaytracingWorld(false);

	modelRender.Init("Assets/modelData/Crystal/Crystal.tkm");
	//Player��T��
	player = FindGO<Player>("player");
	//���ʉ��̓ǂݍ���
	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/get_Item.wav");

	//�傫���̕ύX
	modelRender.SetScale({ 1.0f,1.0f,1.0f });
}

Item::~Item()
{

}

void Item::Update()
{
	//�ړ�����
	Move();
	//��]
	rot.AddRotationDegY(2.0f);
	//��]����
	modelRender.SetRotation(rot);

	//�l������
	Vector3 diff = player->position - position;

	if (diff.Length() <= 150.0f)
	{
		player->itemCount += 1;

		//���ʉ��̏���
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(4);
		se->Play(false);

		DeleteGO(this);
	}
	modelRender.Update();
}

void Item::Move()
{
	//�O�Ɉړ�
	position.z -= 15.0f;

	//�l���ł��Ȃ��������̏���
	if (position.z == -300.0f)
	{
		DeleteGO(this);
	}
	if (position.x < 300.0f && position.y < 300.0f && position.x > -300.0f && position.y > -300.0f) {
		if (position.z == -30.0f) {
			DeleteGO(this);
		}
	}
	modelRender.SetPosition(position);
}

void Item::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}