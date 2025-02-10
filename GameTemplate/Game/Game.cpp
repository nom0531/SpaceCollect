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
	//�v���C���[����
	player = NewGO<Player>(0, "player");
	//�J�����𐶐�
	gameCamera = NewGO<GameCamera>(0,"gamecamera");
	//�X�e�[�W�𐶐�
	stage = NewGO<Stage>(0);
	
	//BGM�̍Đ�
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/Stage.wav");
	GameBGM = NewGO<SoundSource>(0);
	GameBGM->Init(1);
	GameBGM->Play(true);


	//�I�u�W�F�N�g�̐���
	Materite* materite1 = NewGO<Materite>(0, "materite");
	materite1->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),500.0f };

	Materite* materite2 = NewGO<Materite>(0, "materite");
	materite2->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),500.0f };

	Materite* materite3 = NewGO<Materite>(0, "materite");
	materite3->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),500.0f };

	Item* item1 = NewGO<Item>(0, "item");
	item1->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),500.0f };

	//tonemap�Ŗ��邳�ύX


	//�f�B���N�V�������C�g(���s����)
	//x,y,z�Œ�`
	Vector3 dir = { 0,1,-100 };
	dir.Normalize();
	g_renderingEngine->SetDirectionLight(
		//���C�g�̔ԍ�
		0,
		//����
		dir,
		//���C�g�̃J���[
		//R,G,B�Œ�`����
		{1,1,1}
	);
	//����
	//g_renderingEngine->SetAmbient({ 0,0,0 });

	//�{�����[�����C�g�E�X�|�b�g���C�g
	//�X�|�b�g���C�g���������B
	//m_spotLight.Init();
	////���C�g�̗L��������ݒ�B
	//m_spotLight.SetRange(400.0f);

	//Vector3 color;
	//float a, b;
	//a = m_position.x * m_position.z;
	//b = m_position.x + m_position.z;

	////RGB�Ŏw��ł���
	//color.x = int(fabsf(a)) % 2 + 1;
	//color.y = int(fabsf(b)) % 2 + 1;
	//color.z = int(fabsf(a * b)) % 2 + 1;

	//// �P�{�ڂ͑�O�܂ōL������B
	//m_spotLight.SetColor(color);
	//m_spotLight.SetAngle(Math::DegToRad(15.0f));
	//m_spotLight.SetRangeAffectPowParam(2.0f);
	//m_spotLight.SetAngleAffectPowParam(2.0f);

	//// �Q�{�ڂ͍����̌�
	//m_spotLight.SetColor2({ 1000.0f, 1000.0f, 1000.0f });
	//m_spotLight.SetAngle2(Math::DegToRad(15.0f));
	//m_spotLight.SetRangeAffectPowParam2(40.0f);
	//m_spotLight.SetAngleAffectPowParam2(0.5f);

	//// 3�{�ڂ͒��S��ʂ��Ă�����B
	//m_spotLight.SetColor3(color * 2.2f);
	//m_spotLight.SetAngle3(Math::DegToRad(15.0f));
	//m_spotLight.SetRangeAffectPowParam3(3.0f);
	//m_spotLight.SetAngleAffectPowParam3(2.0f);


	//Vector3 direction = Vector3::AxisY;
	////���C�g�̕�����ݒ�B
	//m_spotLight.SetDirection(direction);
	////���C�g�̍��W��ݒ�B
	//m_spotLight.SetPosition(0.0f,0.0f,-500.0f);
	////�{�����[�����C�g���X�|�b�g���C�g�ŏ������B
	//m_volumeSpotLight.Init(m_spotLight);

	//�u���[��
	g_renderingEngine->SetBloomThreshold(50.0f);
	//�g�[���}�b�v
	g_renderingEngine->SetSceneMiddleGray(0.05f);
}

Game::~Game()
{
	//DeleteGO�̏���
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
	//�f�B���N�V�������C�g
	//d_timer += g_gameTime->GetFrameDeltaTime();
	//float move = cosf(d_timer) * 2.0f;
	//d_rotation.AddRotationDegZ(-move);
	//Vector3 dir = Vector3::AxisY;
	//d_rotation.Apply(dir);
	//
	//g_renderingEngine->SetDirectionLight(
	//	//���C�g�̔ԍ�
	//	0,
	//	//����
	//	dir,
	//	//���C�g�̃J���[
	//	//R,G,B�Œ�`����
	//	{ 0,2,2 }
	//);

	//z�������ɓ�����
	//m_timer += g_gameTime->GetFrameDeltaTime();
	//float angle = cosf(m_timer) * 1.7f;
	//m_rotation.AddRotationDegZ(-angle);
	//Vector3 direction = Vector3::AxisY;
	//m_rotation.Apply(direction);
	////���C�g�̕�����ݒ�B
	//m_spotLight.SetDirection(direction);
	////�X�|�b�g���C�g���X�V�B
	//m_spotLight.Update();
	////�{�����[�����C�g���X�V�B
	//m_volumeSpotLight.Update();

	//���x x:600.0�`-600.0 y:400.0�`-300.0
	//x:550�`-550 y:250�`-250
	//��Q���̐���
	materiteTimer -= g_gameTime->GetFrameDeltaTime();
	if (materiteTimer <= 0.0f){
		materiteTimer = 0.6f;
		//�X�e�[�g
		materiteStete++;
		if (materiteStete == 1) {
			Materite* materite_p = NewGO<Materite>(0, "materite");
			materite_p->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),2000.0f };
			//�J��Ԃ�
			materiteStete = 0;
		}
	}
	
	//�A�C�e���̐���
	itemTimer -= g_gameTime->GetFrameDeltaTime();
	if (itemTimer <= 0.0f) {
		itemTimer = 1.4f;
		//�X�e�[�g
		itemStete++;
		if (itemStete == 1) {
			Item* item = NewGO<Item>(0, "item");
			item->position = { (float)(rand() % 1101 - 550),(float)(rand() % 401 - 200),2000.0f };
			//�J��Ԃ�
			itemStete = 0;
		}
	}

	//���Ԑ����̕\��
	wchar_t Timertext[256];
	//�����̎w��
	swprintf_s(Timertext, 256, L"%4.2f�b", (float)Timer);
	//swprintf_s(Timertext, 256, L"%d�b", (int)Timer);

	fontRender.SetText(Timertext);
	fontRender.SetPosition({ 725.0f,500.0f,0.0f });

	//HP�̏���
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

	//���Ԑ���
	Timer -= g_gameTime->GetFrameDeltaTime();
	if (Timer <= 1.0f) {
		//���U���g
		result = NewGO<Result>(0, "result");

		result->Itemcount = player->itemCount;
		result->playerHP = player->playerHP;
		result->Materite = player->materiteCount;
		DeleteGO(this);
	}

	//�Q�[���I�[�o�[����
	if (player->playerHP == 0) {
		DeleteGO(this);
		gameover = NewGO<Gameover>(0, "gameover");
	}
}

void Game::Render(RenderContext& rc)
{
	fontRender.Draw(rc);
	//HP�̕`�揈��
	fontRender_HP.Draw(rc);
}