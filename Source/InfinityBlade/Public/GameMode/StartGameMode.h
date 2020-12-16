// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "UI/StartUserWidget.h"
#include "StartGameMode.generated.h"

/**
 * ��Ϸ��ʼ����Ϸģʽ��
 */
UCLASS()
class INFINITYBLADE_API AStartGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UStartUserWidget *m_StartUserWidget;
public:

	//��Ϸ��ʼ���õķ�ʽ
	virtual void BeginPlay() override;
};
