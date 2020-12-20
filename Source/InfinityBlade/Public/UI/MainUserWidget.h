// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/ProgressBar.h"
#include "MainUserWidget.generated.h"
/**
 * ������UI
 */
UCLASS()
class INFINITYBLADE_API UMainUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	//�չ���ť
	UPROPERTY()
		UButton *m_NormalAttackButton;
	UPROPERTY()
		UButton *m_SkillButton_1;
	UPROPERTY()
		UButton *m_SkillButton_2;
	UPROPERTY()
		UButton *m_SkillButton_3;
	UPROPERTY()
		UButton *m_SkillButton_4;
	UPROPERTY()
		UProgressBar *m_ProgressBar_MP;
	UPROPERTY()
		UProgressBar *m_ProgressBar_Engery;
	UPROPERTY()
		UProgressBar *m_ProgressBar_HP;
public:
	//�ؼ�������ɺ��ʼ������
	virtual bool Initialize() override;
};
