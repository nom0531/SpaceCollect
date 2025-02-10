#pragma once

//プレイヤークラス。
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);
	//移動処理
	void Move();

	//メンバ変数
	Vector3 position;
	Vector3 moveSpeed;
	ModelRender modelRender;
	//キャラクターコントローラー
	CharacterController characterController;
	int itemCount = 0;
	int materiteCount = 0;
	//HP
	int playerHP = 3;
	//テキスト表示
	FontRender fontRender;
	//ポイントライト
	PointLight m_pointLight;
	float m_timer;
	float m_scale = 400.0f;
};

