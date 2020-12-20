// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Character/XPlayerState.h"
#include "XAnimInstance.generated.h"

/**
 * Ӣ�۽�ɫ�Ķ���ʵ��
 */
UCLASS()
class INFINITYBLADE_API UXAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	//�����ƶ��ٶ�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;
	UPROPERTY()
		AXPlayerState *XPlayerState;
	//�Ƿ��ڲ��Ŷ���״̬
	bool bIsPlayingAnimation;
	//�Ƿ���л�����
	bool bIsCanChangeAttack;
	//�Ƿ��ڹ�����
	bool bIsAttacking;
	//��ǰ�ڼ��ι���
	int IntCurAttackIndex = 0;
	//��������
	float BaseAttack;
	/** �Ƿ����ڶ������� */
	bool bIsEnableSecondAttack;
	/** �Ƿ������������� */
	bool bIsEnableThreeAttack;
	/** �Ƿ������Ĵ����� */
	bool bIsEnableFourAttack;
	/** �Ƿ������������ */
	bool bIsEnableFiveAttack;
public:
	//���������ƶ��ٶ�
	UFUNCTION(BlueprintCallable)
		void UpdateSpeed();
	//��ʼ������̫��
	UFUNCTION()
		void AnimNotify_PlayStart(UAnimNotify* Notity);
	//����������̫��
	UFUNCTION()
		void AnimNotify_PlayEnd(UAnimNotify* Notity);
	//��ʼ������̫��
	UFUNCTION()
		void AnimNotify_AttackStart(UAnimNotify* Notify);
	//����������̫��
	UFUNCTION()
		void AnimNotify_AttackEnd(UAnimNotify* Notify);
	//�Ƿ���л�����
	UFUNCTION()
		void AnimNotify_IsCanChangeAttack(UAnimNotify* Notity);
	//��������״̬
	UFUNCTION()
		void AnimNotify_ResetSerialAttack(UAnimNotify* Notity);
	UFUNCTION()
	////��ʼ��״̬
	void InitState();
};
