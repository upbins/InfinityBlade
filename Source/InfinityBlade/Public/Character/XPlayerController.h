// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Character/XCharacter.h"
#include "UI/MainUserWidget.h"
#include "XPlayerController.generated.h"

/**
 * ����Ӣ�۵Ŀ�����
 */
UCLASS()
class INFINITYBLADE_API AXPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY()
		AXCharacter* XCharacter;
	UPROPERTY()
		UMainUserWidget* MainUserWidget;
	UPROPERTY()
		AWeapon *Weapon;
public:
	//��д������ؼ��ķ�ʽ
	virtual void SetupInputComponent() override;
	//��д��Ϸ��ʼ���÷���
	virtual void BeginPlay() override;
public:
	//ǰ���ƶ�
	UFUNCTION()
		void MoveForward(float Speed);
	//�����ƶ�
	UFUNCTION()
		void MoveRight(float Speed);
};
