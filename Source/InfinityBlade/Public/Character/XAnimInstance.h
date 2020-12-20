// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
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
	//�Ƿ��ڲ��Ŷ���״̬
	bool bIsPlayingAnimation;
	//�Ƿ���л�����
	bool bIsCanChangeAttack;

	//�Ƿ����ڶ�������
	bool bIsEnableSecondAttack;
	//�Ƿ�������������
	bool bIsEnableThreeAttack;
	//�Ƿ������Ķ�����
	bool bIsEnableFourAttack;
	//�Ƿ������������
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
	UFUNCTION()
		void AnimNotify_IsCanChangeAttack(UAnimNotify* Notity);
	//����ڶ�������
	UFUNCTION()
		void AnimNotify_SecondAttackInput(UAnimNotify* Notity);
	//�������������
	UFUNCTION()
		void AnimNotify_ThreeAttackInput(UAnimNotify* Notity);
	//������Ĵ�����
	UFUNCTION()
		void AnimNotify_FourAttackInput(UAnimNotify* Notity);
	//������������
	UFUNCTION()
		void AnimNotify_FiveAttackInput(UAnimNotify* Notity);
	//��������״̬
	UFUNCTION()
		void AnimNotify_ResetSerialAttack(UAnimNotify* Notity);
};
