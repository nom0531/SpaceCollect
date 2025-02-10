#pragma once
#include"sound/SoundSource.h"
#include "Level3DRender/LevelRender.h"

class Player;
class GameCamera;
class Stage;//�w�i
class Result;
class Materite;//覐΁i��Q���j
class Item;
class Title;
class Gameover;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//�����o�ϐ�
	SpriteRender spriteRender;
	//�e�L�X�g�\��
	FontRender fontRender;
	FontRender fontRender_HP;

	Player* player;
	GameCamera* gameCamera;
	Stage* stage;//�w�i
	SoundSource* GameBGM;//BGM
	Result* result;//���U���g���
	Title* title;//�^�C�g�����
	Gameover* gameover;//�Q�[���I�[�o�[����

	//���Ԑ���
	//10����\���������ۂ�11�ƋL�q����
	//float Timer = 21.0f;
	float Timer = 21.0f;

	//��Q��
	float materiteTimer = 0.1f;
	int materiteStete = 0;
	Vector3 position_materite;
	//�A�C�e��
	float itemTimer = 0.1f;
	int itemStete = 0;
	Vector3 position_item;

	//�摜���W
	Vector3 position_sprite;
	//�f�B���N�V�������C�g
	float d_timer;
	Quaternion d_rotation;
	Vector3 dir = { 10,10,0 };
	//�X�|�b�g���C�g
	SpotLight m_spotLight;
	//�{�����[�����C�g
	VolumeSpotLight m_volumeSpotLight;
	Vector3 m_position;
	Quaternion m_rotation;//��]
	float m_timer;
};

