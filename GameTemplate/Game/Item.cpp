#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

//アイテム処理
Item::Item()
{
	modelRender.SetRaytracingWorld(false);

	modelRender.Init("Assets/modelData/Crystal/Crystal.tkm");
	//Playerを探す
	player = FindGO<Player>("player");
	//効果音の読み込み
	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/get_Item.wav");

	//大きさの変更
	modelRender.SetScale({ 1.0f,1.0f,1.0f });
}

Item::~Item()
{

}

void Item::Update()
{
	//移動処理
	Move();
	//回転
	rot.AddRotationDegY(2.0f);
	//回転処理
	modelRender.SetRotation(rot);

	//獲得処理
	Vector3 diff = player->position - position;

	if (diff.Length() <= 150.0f)
	{
		player->itemCount += 1;

		//効果音の処理
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(4);
		se->Play(false);

		DeleteGO(this);
	}
	modelRender.Update();
}

void Item::Move()
{
	//前に移動
	position.z -= 15.0f;

	//獲得できなかった時の処理
	if (position.z == -300.0f)
	{
		DeleteGO(this);
	}
	if (position.x < 300.0f && position.y < 300.0f && position.x > -300.0f && position.y > -300.0f) {
		if (position.z == -30.0f) {
			DeleteGO(this);
		}
	}
	modelRender.SetPosition(position);
}

void Item::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}