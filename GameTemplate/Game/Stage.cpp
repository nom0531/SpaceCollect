#include "stdafx.h"
#include "Stage.h"

//�R���g���N�^
Stage::Stage()
{
	modelRender.Init("Assets/modelData/stage_sf/stage_sf.tkm");
	//�����蔻��
	physicsStaticObject.CreateFromModel(modelRender.GetModel(),
		modelRender.GetModel().GetWorldMatrix());
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

//�f�X�g���N�^
Stage::~Stage()
{

}

void Stage::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}