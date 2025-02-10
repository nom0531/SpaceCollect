#include "stdafx.h"
#include "Result.h"
#include "Player.h"
#include "Title.h"
#include "Game.h"
#include "NowLoading.h"
#include "Item.h"
#include "Materite.h"
#include"sound/SoundEngine.h"
#include "sound/SoundSource.h"

//���U���g���
Result::Result()
{
	spriteRender.Init("Assets/sprite/result.DDS",1920.0f,1080.0f);
	//BGM
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/Result.wav");
	resultBGM = NewGO<SoundSource>(0);
	resultBGM->Init(2);
	resultBGM->Play(true);
	//���ʉ�
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/A_button.wav");
	g_soundEngine->ResistWaveFileBank(11, "Assets/sound/Score.wav");
}

Result::~Result()
{
	DeleteGO(resultBGM);
}

void Result::Update()
{
	//���U���g�\��
	Point();

	//�����N�v�Z
	Rank();
	
	//�S�ĕ\����
	if (drawState == 5) {
		//�^�C�g������
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(3);
			se->Play(false);
			//�^�C�g���𐶐�
			NewGO<Title>(0);
			DeleteGO(this);
		}
		//���g���C����
		else if (g_pad[0]->IsTrigger(enButtonB))
		{
			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(3);
			se->Play(false);
			//���g���C(game)���Đ���
			NewGO<NowLoading>(0);
			DeleteGO(this);
		}
	}
}

void Result::Point()
{
	//�N���X�^����
	wchar_t Item[256];
	//�����̎w��
	swprintf_s(Item, 256, L"%d", Itemcount);
	fontRender_item.SetText(Item);
	fontRender_item.SetPosition({ 5.0f, 200.0f, 0.0f });
	fontRender_item.SetColor(g_vec4White);
	//��Z�|�C���g
	fontRender_item_A.SetText(L"100");
	fontRender_item_A.SetPosition({ -300.0f, 200.0f, 0.0f });
	fontRender_item_A.SetColor(g_vec4White);

	//�c��HP
	wchar_t HP[256];
	//�����̎w��
	swprintf_s(HP, 256, L"%d", playerHP);
	fontRender_hp.SetText(HP);
	fontRender_hp.SetPosition({ 5.0f, 100.0f, 0.0f });
	fontRender_hp.SetColor(g_vec4White);
	//��Z�|�C���g
	fontRender_hp_A.SetText(L"400");
	fontRender_hp_A.SetPosition({ -300.0f, 100.0f, 0.0f });
	fontRender_hp_A.SetColor(g_vec4White);

	//miss��
	wchar_t Miss[256];
	//�����̎w��
	swprintf_s(Miss, 256, L"%d", Materite);
	fontRender_miss.SetText(Miss);
	fontRender_miss.SetPosition({ 5.0f, 0.0f, 0.0f });
	fontRender_miss.SetColor(g_vec4White);
	//��Z�|�C���g
	fontRender_miss_A.SetText(L"-100");
	fontRender_miss_A.SetPosition({ -310.0f, 0.0f, 0.0f });
	fontRender_miss_A.SetColor(g_vec4White);

}

void Result::Rank()
{
	//�����N�t������
	int item_point = Itemcount * 100;
	int HP_point = playerHP * 400;
	int miss_point = Materite * 100;
	//�v�Z
	int Rank = (item_point + HP_point) - miss_point;

	//Item�̑��|�C���g
	wchar_t Item_all[256];
	//�����̎w��
	swprintf_s(Item_all, 256, L"%d", itemScore_draw);
	fontRender_item_B.SetText(Item_all);
	fontRender_item_B.SetPosition({ 255.0f, 200.0f, 0.0f });
	fontRender_item_B.SetColor(g_vec4White);

	//HP�̑��|�C���g
	wchar_t HP_all[256];
	//�����̎w��
	swprintf_s(HP_all, 256, L"%d", playerScore_draw);
	fontRender_hp_B.SetText(HP_all);
	fontRender_hp_B.SetPosition({ 255.0f, 100.0f, 0.0f });
	fontRender_hp_B.SetColor(g_vec4White);

	//miss�̑��|�C���g
	wchar_t Miss_all[256];
	//�����̎w��
	swprintf_s(Miss_all, 256, L"-%d", missScore_draw);
	fontRender_miss_B.SetText(Miss_all);
	fontRender_miss_B.SetPosition({ 250.0f, 0.0f, 0.0f });
	fontRender_miss_B.SetColor(g_vec4White);

	//���v���_
	wchar_t Score[256];
	//�����̎w��
	swprintf_s(Score, 256, L"%d", allScore_draw);
	fontRender_score.SetText(Score);
	fontRender_score.SetPosition({ 255.0f, -126.0f, 0.0f });
	fontRender_score.SetColor(g_vec4White);

	//����
	if (Rank > 2000) {
		RankStete = 1;
	}
	else if (Rank > 1500 && Rank <= 2000) {
		RankStete = 2;
	}
	else if (Rank > 1000 && Rank <= 1500) {
		RankStete = 3;
	}
	else if (Rank >=500 && Rank <= 1000) {
		RankStete = 4;
	}
	else if (Rank >= -1 && Rank <= 500) {
		RankStete = 5;
	}

	//���_�\��
	drawTimer -= g_gameTime->GetFrameDeltaTime();
	if (drawTimer <= 0.0f) {
		//�A�C�e��
		if (drawState == 0) {
			if (itemScore_draw < item_point) {
				itemScore_draw++;
				drawTimer = 0.0000000001f;
			}
			if (itemScore_draw == item_point) {
				drawState = 1;
			}
		}
		//�c��HP
		if (drawState == 1) {
			if (playerScore_draw < HP_point) {
				playerScore_draw++;
				drawTimer = 0.0000000001f;
			}
			if (playerScore_draw == HP_point) {
				drawState = 2;
			}
		}
		//�~�X
		if (drawState == 2) {
			if(missScore_draw < miss_point) {
				missScore_draw++;
				drawTimer = 0.0000000001f;
			}
			if (missScore_draw == miss_point) {
				drawState = 3;
			}
		}
		//����
		if (drawState == 3) {
			if (allScore_draw < Rank) {
				allScore_draw++;
				drawTimer = 0.00000000000001f;
			}
			if (allScore_draw == Rank) {
				drawState = 4;
			}
		}
		//�J�b�g����
		if (drawState == 0 || drawState == 1 || drawState == 2 || drawState == 3) {
			if (g_pad[0]->IsTrigger(enButtonX)) {
				//�v�Z�����l����
				itemScore_draw = item_point;
				playerScore_draw = HP_point;
				missScore_draw = miss_point;
				allScore_draw = Rank;

				//�����N�Ɉڍs
				drawState = 4;
			}
		}
		//�����N
		if (drawState == 4) {

			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(11);
			se->Play(false);

			//�e�L�X�g�\��
			switch (RankStete) {
			case 1:
				fontRender_rank.SetText(L"S");
				break;
			case 2:
				fontRender_rank.SetText(L"A");
				break;
			case 3:
				fontRender_rank.SetText(L"B");
				break;
			case 4:
				fontRender_rank.SetText(L"C");
				break;
			case 5:
				fontRender_rank.SetText(L"D");
				break;
			}
			//�e�L�X�g�ڍ�
			fontRender_rank.SetPosition({ 300.0f, -220.0f, 0.0f });
			fontRender_rank.SetColor(g_vec4White);
			fontRender_rank.SetScale({ 2.2f });

			drawState = 5;
		}
		
	}
}

void Result::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
	//�X�R�A�\��
	fontRender_item.Draw(rc);
	fontRender_hp.Draw(rc);
	fontRender_miss.Draw(rc);
	//�����N
	fontRender_rank.Draw(rc);
	//�e�|�C���g
	fontRender_item_A.Draw(rc);
	fontRender_hp_A.Draw(rc);
	fontRender_miss_A.Draw(rc);
	//����
	fontRender_item_B.Draw(rc);
	fontRender_hp_B.Draw(rc);
	fontRender_miss_B.Draw(rc);
	fontRender_score.Draw(rc);
}