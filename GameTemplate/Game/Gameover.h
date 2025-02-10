#pragma once
#include"sound/SoundSource.h"

class Title;
class NowLoading;

class Gameover:public IGameObject
{
public:
	Gameover();
	~Gameover();

	void Update();
	void Render(RenderContext& rc);

	//�����o�ϐ�
	SpriteRender spriteRender;
	SoundSource* gameoverBGM;//BGM

	Title* tiele;
	NowLoading* nowLoading;
};

