// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AIAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UAIAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;
	bool IsPlayAnimation;
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
	//������̫��
	UFUNCTION()
		void AnimNotify_PlayDeath(UAnimNotify *Notity);
};
