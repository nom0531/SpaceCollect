#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
	//カメラのニアクリップとファークリップを設定する。
	g_camera3D->SetNear(1.0f);
	g_camera3D->SetFar(20000.0f);
}

GameCamera::~GameCamera()
{

}

bool GameCamera::Start()
{
	//注視点から視点までのベクトルを設定。
	m_toCameraPos.Set(0.0f, 125.0f, -250.0f);
	//プレイヤーのインスタンスを探す。
	player = FindGO<Player>("player");

	return true;
}

void GameCamera::Update()
{
	Vector3 target;
	target.x = 0.0f;
	//プレイヤーより少し上の位置
	target.y = 0.0f;

	g_camera3D->SetTarget(target);

	Vector3 cameraPos;
	cameraPos = target;
	//プレイヤーより手前の位置
	cameraPos.z = -1200.0f;
	cameraPos.y = 70.0f;

	g_camera3D->SetPosition(cameraPos);
}