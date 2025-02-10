#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"
#include "NowLoading.h"
#include"sound/SoundEngine.h"
#include "sound/SoundSource.h"

Gameover::Gameover()
{
	//画像処理
	spriteRender.Init("Assets/sprite/Gameover.DDS",1920.0f, 1080.0f);
	//BGM
	g_soundEngine->ResistWaveFileBank(10, "Assets/sound/Gameover.wav");
	gameoverBGM = NewGO<SoundSource>(0);
	gameoverBGM->Init(10);
	gameoverBGM->Play(true);
	//効果音
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/A_button.wav");
}

Gameover::~Gameover()
{
	DeleteGO(gameoverBGM);
}

void Gameover::Update()
{
	//Aボタンの処理
	if (g_pad[0]->IsTrigger(enButtonA)) {
		//効果音
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(3);
		se->Play(false);
		//タイトル
		NewGO<Title>(0);
		DeleteGO(this);
	}

	//Bボタンの処理
	if (g_pad[0]->IsTrigger(enButtonB)) {
		//効果音
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(3);
		se->Play(false);
		//リトライ
		NewGO<NowLoading>(0);
		DeleteGO(this);
	}
}

void Gameover::Render(RenderContext& rc)
{
	//描画処理
	spriteRender.Draw(rc);
}