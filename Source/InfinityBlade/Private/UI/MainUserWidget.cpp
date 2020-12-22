// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainUserWidget.h"

bool UMainUserWidget::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	}
	//初始化开始按钮
	m_NormalAttackButton = Cast<UButton>(GetWidgetFromName(TEXT("NormalAttackButton")));
	m_SkillButton_1 = Cast<UButton>(GetWidgetFromName(TEXT("SkillButton_1")));
	m_SkillButton_2 = Cast<UButton>(GetWidgetFromName(TEXT("SkillButton_2")));
	m_SkillButton_3 = Cast<UButton>(GetWidgetFromName(TEXT("SkillButton_3")));
	m_SkillButton_4 = Cast<UButton>(GetWidgetFromName(TEXT("SkillButton_4")));
	m_ProgressBar_MP = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_MP")));
	m_ProgressBar_Engery = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_Engery")));
	m_ProgressBar_HP = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_HP")));
	//m_Image->SetBrushFromAsset("Texture2D'/Game/Texture/character/T_Equip_HP.T_Equip_HP'");
	//m_Image->SetBrushFromTexture(Texture);
	m_SkillButton_1->AddChild(m_Image);
	return true;
}
