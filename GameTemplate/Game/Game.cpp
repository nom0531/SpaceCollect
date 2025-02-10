#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "Player.h"
#include "Stage.h"
#include "sound/SoundEngine.h"
#include "Result.h"
#include "Materite.h"
#include "Item.h"
#include "Title.h"
#include "Gameover.h"

Game::Game()
{
	//プレイヤー生成
	player = NewGO<Player>(0, "player");
	//カメラを生成
	gameCamera = NewGO<GameCamera>(0,"gamecamera");
	//ステージを生成
	stage = NewGO<Stage>(0);
	
	//BGMの再生
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/Stage.wav");
	GameBGM = NewGO<SoundSource>(0);
	GameBGM->Init(1);
	GameBGM->Play(true);


	//オブジェクトの生成
	Materite* materite1 = NewGO<Materite>(0, "materite");
	materite1->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),500.0f };

	Materite* materite2 = NewGO<Materite>(0, "materite");
	materite2->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),500.0f };

	Materite* materite3 = NewGO<Materite>(0, "materite");
	materite3->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),500.0f };

	Item* item1 = NewGO<Item>(0, "item");
	item1->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),500.0f };

	//tonemapで明るさ変更


	//ディレクションライト(平行光源)
	//x,y,zで定義
	Vector3 dir = { 0,1,-100 };
	dir.Normalize();
	g_renderingEngine->SetDirectionLight(
		//ライトの番号
		0,
		//方向
		dir,
		//ライトのカラー
		//R,G,Bで定義する
		{1,1,1}
	);
	//環境光
	//g_renderingEngine->SetAmbient({ 0,0,0 });

	//ボリュームライト・スポットライト
	//スポットライトを初期化。
	//m_spotLight.Init();
	////ライトの有効距離を設定。
	//m_spotLight.SetRange(400.0f);

	//Vector3 color;
	//float a, b;
	//a = m_position.x * m_position.z;
	//b = m_position.x + m_position.z;

	////RGBで指定できる
	//color.x = int(fabsf(a)) % 2 + 1;
	//color.y = int(fabsf(b)) % 2 + 1;
	//color.z = int(fabsf(a * b)) % 2 + 1;

	//// １本目は大外まで広がる光。
	//m_spotLight.SetColor(color);
	//m_spotLight.SetAngle(Math::DegToRad(15.0f));
	//m_spotLight.SetRangeAffectPowParam(2.0f);
	//m_spotLight.SetAngleAffectPowParam(2.0f);

	//// ２本目は根元の光
	//m_spotLight.SetColor2({ 1000.0f, 1000.0f, 1000.0f });
	//m_spotLight.SetAngle2(Math::DegToRad(15.0f));
	//m_spotLight.SetRangeAffectPowParam2(40.0f);
	//m_spotLight.SetAngleAffectPowParam2(0.5f);

	//// 3本目は中心を通っている光。
	//m_spotLight.SetColor3(color * 2.2f);
	//m_spotLight.SetAngle3(Math::DegToRad(15.0f));
	//m_spotLight.SetRangeAffectPowParam3(3.0f);
	//m_spotLight.SetAngleAffectPowParam3(2.0f);


	//Vector3 direction = Vector3::AxisY;
	////ライトの方向を設定。
	//m_spotLight.SetDirection(direction);
	////ライトの座標を設定。
	//m_spotLight.SetPosition(0.0f,0.0f,-500.0f);
	////ボリュームライトをスポットライトで初期化。
	//m_volumeSpotLight.Init(m_spotLight);

	//ブルーム
	g_renderingEngine->SetBloomThreshold(50.0f);
	//トーンマップ
	g_renderingEngine->SetSceneMiddleGray(0.05f);
}

Game::~Game()
{
	//DeleteGOの処理
	DeleteGO(player);
	DeleteGO(gameCamera);
	DeleteGO(stage);
	DeleteGO(GameBGM);
}


bool Game::Start()
{
	return true;
}

void Game::Update()
{
	//ディレクションライト
	//d_timer += g_gameTime->GetFrameDeltaTime();
	//float move = cosf(d_timer) * 2.0f;
	//d_rotation.AddRotationDegZ(-move);
	//Vector3 dir = Vector3::AxisY;
	//d_rotation.Apply(dir);
	//
	//g_renderingEngine->SetDirectionLight(
	//	//ライトの番号
	//	0,
	//	//方向
	//	dir,
	//	//ライトのカラー
	//	//R,G,Bで定義する
	//	{ 0,2,2 }
	//);

	//z軸方向に動かす
	//m_timer += g_gameTime->GetFrameDeltaTime();
	//float angle = cosf(m_timer) * 1.7f;
	//m_rotation.AddRotationDegZ(-angle);
	//Vector3 direction = Vector3::AxisY;
	//m_rotation.Apply(direction);
	////ライトの方向を設定。
	//m_spotLight.SetDirection(direction);
	////スポットライトを更新。
	//m_spotLight.Update();
	////ボリュームライトを更新。
	//m_volumeSpotLight.Update();

	//限度 x:600.0～-600.0 y:400.0～-300.0
	//x:550～-550 y:250～-250
	//障害物の生成
	materiteTimer -= g_gameTime->GetFrameDeltaTime();
	if (materiteTimer <= 0.0f){
		materiteTimer = 0.6f;
		//ステート
		materiteStete++;
		if (materiteStete == 1) {
			Materite* materite_p = NewGO<Materite>(0, "materite");
			materite_p->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),2000.0f };
			//繰り返す
			materiteStete = 0;
		}
	}
	
	//アイテムの生成
	itemTimer -= g_gameTime->GetFrameDeltaTime();
	if (itemTimer <= 0.0f) {
		itemTimer = 1.4f;
		//ステート
		itemStete++;
		if (itemStete == 1) {
			Item* item = NewGO<Item>(0, "item");
			item->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),2000.0f };
			//繰り返す
			itemStete = 0;
		}
	}

	//時間制限の表示
	wchar_t Timertext[256];
	//桁数の指定
	swprintf_s(Timertext, 256, L"%4.2f秒", (float)Timer);
	//swprintf_s(Timertext, 256, L"%d秒", (int)Timer);

	fontRender.SetText(Timertext);
	fontRender.SetPosition({ 725.0f,500.0f,0.0f });

	//HPの処理
	fontRender_HP.SetText(L"HP x3");
	fontRender_HP.SetPosition({ 735.0f,450.0f,0.0f });

	switch (player->playerHP) {
		case 2:
			fontRender_HP.SetText(L"HP x2");
			fontRender_HP.SetPosition({ 735.0f,450.0f,0.0f });
			break;
		case 1:
			fontRender_HP.SetText(L"HP x1");
			fontRender_HP.SetPosition({ 735.0f,450.0f,0.0f });
	}

	//時間制限
	Timer -= g_gameTime->GetFrameDeltaTime();
	if (Timer <= 1.0f) {
		//リザルト
		result = NewGO<Result>(0, "result");

		result->Itemcount = player->itemCount;
		result->playerHP = player->playerHP;
		result->Materite = player->materiteCount;
		DeleteGO(this);
	}

	//ゲームオーバー処理
	if (player->playerHP == 0) {
		DeleteGO(this);
		gameover = NewGO<Gameover>(0, "gameover");
	}
}

void Game::Render(RenderContext& rc)
{
	fontRender.Draw(rc);
	//HPの描画処理
	fontRender_HP.Draw(rc);
}