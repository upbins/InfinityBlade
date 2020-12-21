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
		AXPlayerState* XPlayerState;
	UPROPERTY()
		UXAnimInstance* XAnimInstance;
	UPROPERTY()
		UMainUserWidget* MainUserWidget;
	UPROPERTY()
		AWeapon *Weapon;
	UPROPERTY()
		TArray<AActor*> AiArray;
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
	//��ʼ����ť�¼��ķ���
	UFUNCTION()
		void InitBtnWidgetEvent();
	//�����¼�
	UFUNCTION()
		void NormalAttackBtnEevent();
	UFUNCTION()
		void SkillButton1Eevent();
	UFUNCTION()
		void InitState();
	UFUNCTION()
		void UpdateUI();
	//�����˺�����
	UFUNCTION()
		void WeaponOverlapDamage(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitResult);
	void LockAI();
};
