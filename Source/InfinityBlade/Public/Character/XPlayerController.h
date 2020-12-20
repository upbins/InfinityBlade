// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Character/XCharacter.h"
#include "Character/XAnimInstance.h"
#include "Character/XPlayerState.h"
#include "UI/MainUserWidget.h"
#include "XPlayerController.generated.h"

/**
 * 主角英雄的控制器
 */
UCLASS()
class INFINITYBLADE_API AXPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY()
		AXCharacter* XCharacter;
	UPROPERTY()
		AXPlayerState* XPlayerState;
	UPROPERTY()
		UXAnimInstance* XAnimInstance;
	UPROPERTY()
		UMainUserWidget* MainUserWidget;
	UPROPERTY()
		AWeapon *Weapon;
public:
	//重写绑定输入控件的方式
	virtual void SetupInputComponent() override;
	//重写游戏开始调用方法
	virtual void BeginPlay() override;
	////重写绑定Character的方法
	//virtual void Possess(APawn* InPawn) override;
public:
	//前后移动
	UFUNCTION()
		void MoveForward(float Speed);
	//左右移动
	UFUNCTION()
		void MoveRight(float Speed);
	//初始化按钮事件的方法
	UFUNCTION()
		void InitBtnWidgetEvent();
	//攻击事件
	UFUNCTION()
		void NormalAttackBtnEevent();
	UFUNCTION()
		void InitState();
	UFUNCTION()
		void UpdateUI();
};
