#include "stdafx.h"
#include "Stage.h"

//コントラクタ
Stage::Stage()
{
	modelRender.Init("Assets/modelData/stage_sf/stage_sf.tkm");
	//当たり判定
	physicsStaticObject.CreateFromModel(modelRender.GetModel(),
		modelRender.GetModel().GetWorldMatrix());
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

//デストラクタ
Stage::~Stage()
{

}

void Stage::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}