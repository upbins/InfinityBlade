// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "UI/StartUserWidget.h"
#include "StartGameMode.generated.h"

/**
 * 游戏开始的游戏模式类
 */
UCLASS()
class INFINITYBLADE_API AStartGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UStartUserWidget *m_StartUserWidget;
public:

	//游戏开始调用的方式
	virtual void BeginPlay() override;
};
