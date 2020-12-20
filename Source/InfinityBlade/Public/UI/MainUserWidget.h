// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
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
		UButton * m_NormalAttackButton;
public:
	//�ؼ�������ɺ��ʼ������
	virtual bool Initialize() override;
};
