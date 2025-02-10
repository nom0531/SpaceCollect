#pragma once
#include"sound/SoundSource.h"

class Title;
class Game;
class NowLoading;
class Player;
class Item;
class Materite;

class Result :public IGameObject
{
public:
	Result();
	~Result();

	void Render(RenderContext& rc);
	void Update();
	void Rank();
	void Point();
	//void Scoretext();

	//メンバ変数
	SpriteRender spriteRender;
	FontRender fontRender_item;
	FontRender fontRender_hp;
	FontRender fontRender_miss;
	//ランク
	FontRender fontRender_rank;
	//ポイント
	FontRender fontRender_item_A;
	FontRender fontRender_hp_A;
	FontRender fontRender_miss_A;
	//総合
	FontRender fontRender_item_B;
	FontRender fontRender_hp_B;
	FontRender fontRender_miss_B;
	FontRender fontRender_score;

	SoundSource* resultBGM;//BGM
	//タイトル
	Title* title;
	Game* game;
	NowLoading* nowLoading;
	Item* item;
	Materite* materite;

	int playerHP = 0;
	int Itemcount = 0;
	int Materite = 0;

	//描画用の変数
	int itemScore_draw = 0;
	int playerScore_draw = 0;	
	int missScore_draw = 0;
	int allScore_draw = 0;

	int RankStete = 0;

	float drawTimer = 0.5f;
	//順番に表示するためのステート
	int drawState = 0;
};

