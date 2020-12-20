// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "XAnimInstance.generated.h"

/**
 * 英雄角色的动画实例
 */
UCLASS()
class INFINITYBLADE_API UXAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	//人物移动速度
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;
	//是否处于播放动作状态
	bool bIsPlayingAnimation;
	//是否可切换动作
	bool bIsCanChangeAttack;

	//是否进入第二段连击
	bool bIsEnableSecondAttack;
	//是否进入第三段连击
	bool bIsEnableThreeAttack;
	//是否进入第四段连击
	bool bIsEnableFourAttack;
	//是否进入第五段连击
	bool bIsEnableFiveAttack;
	
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
	UFUNCTION()
		void AnimNotify_IsCanChangeAttack(UAnimNotify* Notity);
	//进入第二次连击
	UFUNCTION()
		void AnimNotify_SecondAttackInput(UAnimNotify* Notity);
	//进入第三次连击
	UFUNCTION()
		void AnimNotify_ThreeAttackInput(UAnimNotify* Notity);
	//进入第四次连击
	UFUNCTION()
		void AnimNotify_FourAttackInput(UAnimNotify* Notity);
	//进入第五次连击
	UFUNCTION()
		void AnimNotify_FiveAttackInput(UAnimNotify* Notity);
	//重置连击状态
	UFUNCTION()
		void AnimNotify_ResetSerialAttack(UAnimNotify* Notity);
};
