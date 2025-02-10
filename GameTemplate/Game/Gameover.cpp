#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"
#include "NowLoading.h"
#include"sound/SoundEngine.h"
#include "sound/SoundSource.h"

Gameover::Gameover()
{
	//�摜����
	spriteRender.Init("Assets/sprite/Gameover.DDS",1920.0f, 1080.0f);
	//BGM
	g_soundEngine->ResistWaveFileBank(10, "Assets/sound/Gameover.wav");
	gameoverBGM = NewGO<SoundSource>(0);
	gameoverBGM->Init(10);
	gameoverBGM->Play(true);
	//���ʉ�
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/A_button.wav");
}

Gameover::~Gameover()
{
	DeleteGO(gameoverBGM);
}

void Gameover::Update()
{
	//A�{�^���̏���
	if (g_pad[0]->IsTrigger(enButtonA)) {
		//���ʉ�
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(3);
		se->Play(false);
		//�^�C�g��
		NewGO<Title>(0);
		DeleteGO(this);
	}

	//B�{�^���̏���
	if (g_pad[0]->IsTrigger(enButtonB)) {
		//���ʉ�
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(3);
		se->Play(false);
		//���g���C
		NewGO<NowLoading>(0);
		DeleteGO(this);
	}
}

void Gameover::Render(RenderContext& rc)
{
	//�`�揈��
	spriteRender.Draw(rc);
}