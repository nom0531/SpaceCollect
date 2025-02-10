#include "stdafx.h"
#include "Guide.h"
#include "Title.h"
#include"sound/SoundEngine.h"
#include "sound/SoundSource.h"

Guide::Guide()
{
	//画像の読み込み
	spriteRender.Init("Assets/sprite/guide_anime/Guide_01.DDS", 1920.0f, 1080.0f);

	//BGM
	g_soundEngine->ResistWaveFileBank(7, "Assets/sound/Guide.wav");
	GuideBGM = NewGO<SoundSource>(0);
	GuideBGM->Init(7);
	GuideBGM->Play(true);

	//効果音
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
		//効果音の再生
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(6);
		se->Play(false);
	}
	if (g_pad[0]->IsTrigger(enButtonLeft)) {
		//効果音の再生
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(6);
		se->Play(false);
	}

	//右ボタンを押したとき
	if (g_pad[0]->IsTrigger(enButtonRight)) {
		spriteRender.Init("Assets/sprite/guide_anime/Guide_02.DDS", 1920.0f, 1080.0f);
	}
	//左ボタンを押したとき
	if (g_pad[0]->IsTrigger(enButtonLeft)) {
		spriteRender.Init("Assets/sprite/guide_anime/Guide_01.DDS", 1920.0f, 1080.0f);
	}

	spriteRender.Update();

	//Bボタンを押したときの処理
	if (g_pad[0]->IsTrigger(enButtonB)) {
		//効果音の再生
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