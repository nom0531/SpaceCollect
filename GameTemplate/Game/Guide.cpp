#include "stdafx.h"
#include "Guide.h"
#include "Title.h"
#include"sound/SoundEngine.h"
#include "sound/SoundSource.h"

Guide::Guide()
{
	//�摜�̓ǂݍ���
	spriteRender.Init("Assets/sprite/guide_anime/Guide_01.DDS", 1920.0f, 1080.0f);

	//BGM
	g_soundEngine->ResistWaveFileBank(7, "Assets/sound/Guide.wav");
	GuideBGM = NewGO<SoundSource>(0);
	GuideBGM->Init(7);
	GuideBGM->Play(true);

	//���ʉ�
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/A_button.wav");
	g_soundEngine->ResistWaveFileBank(5, "Assets/sound/B_button.wav");
	g_soundEngine->ResistWaveFileBank(6, "Assets/sound/LR_button.wav");
}

Guide::~Guide()
{
	DeleteGO(GuideBGM);
}

void Guide::Update()
{

	if (g_pad[0]->IsTrigger(enButtonRight)) {
		//���ʉ��̍Đ�
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(6);
		se->Play(false);
	}
	if (g_pad[0]->IsTrigger(enButtonLeft)) {
		//���ʉ��̍Đ�
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(6);
		se->Play(false);
	}

	//�E�{�^�����������Ƃ�
	if (g_pad[0]->IsTrigger(enButtonRight)) {
		spriteRender.Init("Assets/sprite/guide_anime/Guide_02.DDS", 1920.0f, 1080.0f);
	}
	//���{�^�����������Ƃ�
	if (g_pad[0]->IsTrigger(enButtonLeft)) {
		spriteRender.Init("Assets/sprite/guide_anime/Guide_01.DDS", 1920.0f, 1080.0f);
	}

	spriteRender.Update();

	//B�{�^�����������Ƃ��̏���
	if (g_pad[0]->IsTrigger(enButtonB)) {
		//���ʉ��̍Đ�
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(5);
		se->Play(false);

		NewGO<Title>(0);
		DeleteGO(this);
	}
}

void Guide::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}