#pragma once
#include"sound/SoundSource.h"
#include "Level3DRender/LevelRender.h"

class Player;
class GameCamera;
class Stage;//背景
class Result;
class Materite;//隕石（障害物）
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

	//メンバ変数
	SpriteRender spriteRender;
	//テキスト表示
	FontRender fontRender;
	FontRender fontRender_HP;

	Player* player;
	GameCamera* gameCamera;
	Stage* stage;//背景
	SoundSource* GameBGM;//BGM
	Result* result;//リザルト画面
	Title* title;//タイトル画面
	Gameover* gameover;//ゲームオーバー処理

	//時間制限
	//10から表示したい際は11と記述する
	//float Timer = 21.0f;
	float Timer = 21.0f;

	//障害物
	float materiteTimer = 0.1f;
	int materiteStete = 0;
	Vector3 position_materite;
	//アイテム
	float itemTimer = 0.1f;
	int itemStete = 0;
	Vector3 position_item;

	//画像座標
	Vector3 position_sprite;
	//ディレクションライト
	float d_timer;
	Quaternion d_rotation;
	Vector3 dir = { 10,10,0 };
	//スポットライト
	SpotLight m_spotLight;
	//ボリュームライト
	VolumeSpotLight m_volumeSpotLight;
	Vector3 m_position;
	Quaternion m_rotation;//回転
	float m_timer;
};

