#pragma once
#include"sound/SoundSource.h"

class NowLoading;
class Guide;

class Title:public IGameObject
{
public:
	Title();
	~Title();

	void Render(RenderContext& rc);
	void Update();

	//メンバ変数
	SpriteRender spriteRender;
	SoundSource* titleBGM;//BGM
	float Timer = 1.0f;
	float AnimTimer = 0.1f;

	NowLoading* nowLoading;
	Guide* guide;
	//ステート
	int titleStete = 0;
};

