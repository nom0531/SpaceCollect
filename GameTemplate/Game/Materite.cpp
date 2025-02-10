#include "stdafx.h"
#include "Materite.h"
#include "player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

//障害物の処理
Materite::Materite()
{
	modelRender.SetRaytracingWorld(false);

	//モデル読み込み
	//modelRender.Init("Assets/modelData/stage_sf/materite_01.tkm");

	//ステート処理
	Stete();

	//Playerを探す
	player = FindGO<Player>("player");
	//大きさの変更
	modelRender.SetScale({ 2.5f,2.5f,2.5f });
	//効果音の読み込み
	g_soundEngine->ResistWaveFileBank(9, "Assets/sound/damege.wav");
}

Materite::~Materite()
{

}

void Materite::Stete()
{
	//0～2の値をランダムに返す
	materiteState = rand() % 3;

	switch (materiteState) {
	case 0:
		//modelRender.Init("Assets/modelData/stage_sf/materite_01.tkm");
		modelRender.Init("Assets/modelData/stage_sf/materite_01a.tkm");
		break;
	case 1:
		//modelRender.Init("Assets/modelData/stage_sf/materite_02.tkm");
		modelRender.Init("Assets/modelData/stage_sf/materite_02a.tkm");
		break;
	case 2:
		//modelRender.Init("Assets/modelData/stage_sf/materite_03.tkm");
		modelRender.Init("Assets/modelData/stage_sf/materite_03a.tkm");
		break;
	}
}

void Materite::Update()
{

	//手前に移動
	position.z -= 15.0f;

	//y軸、z軸方向に回転し続ける
	rot.AddRotationDegY(2.0f);
	rot.AddRotationDegZ(2.0f);
	//回転処理
	modelRender.SetRotation(rot);

	//衝突処理
	Vector3 diff = player->position - position;
	if (diff.Length() <= 100.0f)
	{
		player->playerHP -= 1;
		//ミス数をカウント
		player->materiteCount += 1;

		//効果音の処理
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(9);
		se->Play(false);
		//音量を上げる
		se->SetVolume(3.5f);

		DeleteGO(this);
	}

	//ある程度の位置で削除
	if (position.z == -300.0f)
	{
		DeleteGO(this);
	}
	//正面のある程度の範囲の処理
	if (position.x < 300.0f && position.y < 300.0f && position.x > -300.0f && position.y > -300.0f) {
		if (position.z == -30.0f) {
			DeleteGO(this);
		}
	}
	modelRender.SetPosition(position);
	modelRender.Update();
}

void Materite::Render(RenderContext& rc)
{
	//描画処理
	modelRender.Draw(rc);
}