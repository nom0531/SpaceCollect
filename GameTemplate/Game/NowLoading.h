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

	//�����o�ϐ�
	SpriteRender spriteRender;
	float Timer = 1.0f;
	float AnimTimer = 0.1f;
	//�A�j���[�V����
	int animeStete = 0;

	Game* game;
	Title* title;
	Result* result;
};

