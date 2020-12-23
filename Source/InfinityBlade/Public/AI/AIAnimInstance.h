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
	//更新人物移动速度
	UFUNCTION(BlueprintCallable)
		void UpdateSpeed();
	//开始播放蒙太奇
	UFUNCTION()
		void AnimNotify_PlayStart(UAnimNotify* Notity);
	//结束播放蒙太奇
	UFUNCTION()
		void AnimNotify_PlayEnd(UAnimNotify* Notity);
	//死亡蒙太奇
	UFUNCTION()
		void AnimNotify_PlayDeath(UAnimNotify *Notity);
};
