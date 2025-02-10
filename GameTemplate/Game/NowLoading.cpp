#include "stdafx.h"
#include "NowLoading.h"
#include "Game.h"
#include "Title.h"
#include "Result.h"


NowLoading::NowLoading()
{
	//‰æ‘œ‚Ì“Ç‚Ýž‚Ý
	spriteRender.Init("Assets/sprite/nowLoading_anime/Now_loading_00.DDS", 1920.0f, 1080.0f);
}

NowLoading::~NowLoading()
{

}

void NowLoading::Update()
{
	Timer -= g_gameTime->GetFrameDeltaTime();
	if (Timer <= 0.0f) {
		NewGO<Game>(0);
		DeleteGO(this);
	}

	spriteRender.Update();
}

void NowLoading::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}

