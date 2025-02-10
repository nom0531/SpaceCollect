#pragma once

class Game;
class Title;
class Result;

class NowLoading:public IGameObject
{
public:
	NowLoading();
	~NowLoading();

	void Update();
	void Render(RenderContext& rc);

	//メンバ変数
	SpriteRender spriteRender;
	float Timer = 1.0f;
	float AnimTimer = 0.1f;
	//アニメーション
	int animeStete = 0;

	Game* game;
	Title* title;
	Result* result;
};

