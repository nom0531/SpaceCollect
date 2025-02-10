#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

//ƒAƒCƒeƒ€ˆ—
Item::Item()
{
	modelRender.SetRaytracingWorld(false);

	modelRender.Init("Assets/modelData/Crystal/Crystal.tkm");
	//Player‚ğ’T‚·
	player = FindGO<Player>("player");
	//Œø‰Ê‰¹‚Ì“Ç‚İ‚İ
	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/get_Item.wav");

	//‘å‚«‚³‚Ì•ÏX
	modelRender.SetScale({ 1.0f,1.0f,1.0f });
}

Item::~Item()
{

}

void Item::Update()
{
	//ˆÚ“®ˆ—
	Move();
	//‰ñ“]
	rot.AddRotationDegY(2.0f);
	//‰ñ“]ˆ—
	modelRender.SetRotation(rot);

	//Šl“¾ˆ—
	Vector3 diff = player->position - position;

	if (diff.Length() <= 150.0f)
	{
		player->itemCount += 1;

		//Œø‰Ê‰¹‚Ìˆ—
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(4);
		se->Play(false);

		DeleteGO(this);
	}
	modelRender.Update();
}

void Item::Move()
{
	//‘O‚ÉˆÚ“®
	position.z -= 15.0f;

	//Šl“¾‚Å‚«‚È‚©‚Á‚½‚Ìˆ—
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