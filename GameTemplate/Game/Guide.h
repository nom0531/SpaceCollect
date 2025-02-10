#pragma once
#include"sound/SoundSource.h"
class Guide: public IGameObject
{
public:
	Guide();
	~Guide();

	void Update();
	void Render(RenderContext& rc);

	//メンバ変数
	SoundSource* GuideBGM;//BGM

	SpriteRender spriteRender;
	float Timer = 1.0f;
	float AnimTimer = 0.1f;
	//アニメーション
	int animeStete = 0;
};

