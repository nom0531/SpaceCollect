#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	//キャラクターモデルの読み込み
	modelRender.Init("Assets/modelData/SpaceShip/SpaceShip.tkm");

	//大きさの変更
	modelRender.SetScale({ 0.6f,0.6f,0.6f });
	//初期地点
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = -500.0f;
	//当たり判定
	characterController.Init(25.0f, -10.0f, position);

	//ポイントライト
	m_pointLight.Init();
	//位置
	m_pointLight.SetPosition(0.0f,0.0f,0.0f);
	//カラー
	m_pointLight.SetColor(Vector3(10.0f, 10.0f, 10.0f));
	//影響率の累乗（？）
	m_pointLight.SetAffectPowParam(0.5f);
	//範囲
	m_pointLight.SetRange(m_scale);
}

Player::~Player()
{
}

bool Player::Start()
{
	return true;
}

void Player::Update()
{
	//移動処理
	Move();

	modelRender.Update();
	//範囲
	//m_timer+= g_gameTime->GetFrameDeltaTime();
	//float move = m_timer * 10.0f;
	//m_scale += move;
	//m_pointLight.SetRange(m_scale);

	//位置を教える
	m_pointLight.SetPosition(position);
	m_pointLight.Update();
}

void Player::Move()
{
	//xzの移動速度を0.0fにする
	moveSpeed.x = 0.0f;
	moveSpeed.y = 0.0f;

	//左スティックの入力量を取得
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	moveSpeed.x += stickL.x * 150.0f;
	moveSpeed.y += stickL.y * 150.0f;

	//キャラクターコントローラーで座標を移動
	position = characterController.Execute(moveSpeed, 1.0f / 6.0f);

	//移動範囲の制限
	//x軸
	if (position.x < -600.0f){
		position.x = -600.0f;
		characterController.SetPosition(position);
	}
	else if (position.x > 600.0f){
		position.x = 600.0f;
		characterController.SetPosition(position);
	}
	//y軸
	if (position.y < -300.0f){
		position.y = -300.0f;
		characterController.SetPosition(position);
	}
	else if (position.y > 400.0f){
		position.y = 400.0f;
		characterController.SetPosition(position);
	}
		//座標を教える
		modelRender.SetPosition(position);
}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}