#pragma once
#include"sound/SoundSource.h"
class Guide: public IGameObject
{
public:
	Guide();
	~Guide();

	void Update();
	void Render(RenderContext& rc);

	//�����o�ϐ�
	SoundSource* GuideBGM;//BGM

	SpriteRender spriteRender;
	float Timer = 1.0f;
	float AnimTimer = 0.1f;
	//�A�j���[�V����
	int animeStete = 0;
};

