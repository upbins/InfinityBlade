// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Character/XPlayerState.h"
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
	UPROPERTY()
		AXPlayerState *XPlayerState;
	//是否处于播放动作状态
	bool bIsPlayingAnimation;
	//是否可切换动作
	bool bIsCanChangeAttack;
	//是否处于攻击中
	bool bIsAttacking;
	//当前第几段攻击
	int IntCurAttackIndex = 0;
	//基本攻击
	float BaseAttack;
	/** 是否进入第二次连击 */
	bool bIsEnableSecondAttack;
	/** 是否进入第三次连击 */
	bool bIsEnableThreeAttack;
	/** 是否进入第四次连击 */
	bool bIsEnableFourAttack;
	/** 是否进入第五次连击 */
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
	//开始攻击蒙太奇
	UFUNCTION()
		void AnimNotify_AttackStart(UAnimNotify* Notify);
	//结束攻击蒙太奇
	UFUNCTION()
		void AnimNotify_AttackEnd(UAnimNotify* Notify);
	//是否可切换动作
	UFUNCTION()
		void AnimNotify_IsCanChangeAttack(UAnimNotify* Notity);
	//重置连击状态
	UFUNCTION()
		void AnimNotify_ResetSerialAttack(UAnimNotify* Notity);
	UFUNCTION()
	////初始化状态
	void InitState();
};
