#include "stdafx.h"
#include "Title.h"
#include"NowLoading.h"
#include "Guide.h"
#include"sound/SoundEngine.h"
#include "sound/SoundSource.h"

Title::Title()
{
	//タイトル画面の読み込み処理
	spriteRender.Init("Assets/sprite/title_anime/Title_0.DDS",1920.0f,1080.0f);
	//bgm
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/Title.wav");
	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(0);
	titleBGM->Play(true);
	//効果音
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/A_button.wav");
	g_soundEngine->ResistWaveFileBank(8, "Assets/sound/Start_game.wav");
}

Title::~Title()
{
	DeleteGO(titleBGM);
}

void Title::Update()
{
	//アニメーション処理
	AnimTimer -= g_gameTime->GetFrameDeltaTime();
	if (AnimTimer <= 0.0f)
	{

		AnimTimer = 0.25f;

		titleStete++;
		if (titleStete == 1) {
			spriteRender.Init("Assets/sprite/title_anime/Title_1.DDS", 1920.0f, 1080.0f);
		}
		if (titleStete == 2) {
			spriteRender.Init("Assets/sprite/title_anime/Title_2.DDS", 1920.0f, 1080.0f);
		}
		if (titleStete == 3) {
			spriteRender.Init("Assets/sprite/title_anime/Title_3.DDS", 1920.0f, 1080.0f);
		}
		if (titleStete == 4) {
			spriteRender.Init("Assets/sprite/title_anime/Title_4.DDS", 1920.0f, 1080.0f);
		}
		if (titleStete == 5) {
			spriteRender.Init("Assets/sprite/title_anime/Title_3.DDS", 1920.0f, 1080.0f);
		}
		if (titleStete == 6) {
			spriteRender.Init("Assets/sprite/title_anime/Title_2.DDS", 1920.0f, 1080.0f);
		}
		if (titleStete == 7) {
			titleStete = 0;
			spriteRender.Init("Assets/sprite/title_anime/Title_1.DDS", 1920.0f, 1080.0f);
		}
	}

	spriteRender.Update();

	//Aボタンが押された時のdelete処理
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//効果音の再生
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(8);
		se->Play(false);

		nowLoading = NewGO<NowLoading>(10);
		DeleteGO(this);
	}

	//Xボタンが押された時の処理(※変更有)
	if (g_pad[0]->IsTrigger(enButtonX))
	{
		//効果音の再生
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(3);
		se->Play(false);

		DeleteGO(this);
		//操作説明の生成
		NewGO<Guide>(0);
	}

}

void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
