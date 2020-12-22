// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Character/XPlayerState.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Character/Skill/XBlade.h"
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
	UPROPERTY()
		FTimerHandle TimerHandle;
	UPROPERTY()
		AXBlade* XBlade = nullptr;
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
	//技能1产生通知
	UFUNCTION()
		void AnimNotify_SkillBtn1(UAnimNotify* Notity);
	//技能2产生通知
	UFUNCTION()
		void AnimNotify_SkillBtn2(UAnimNotify* Notity);
	//技能3产生通知
	UFUNCTION()
		void AnimNotify_SkillBtn3(UAnimNotify* Notity);
	//技能4产生通知
	UFUNCTION()
		void AnimNotify_SkillBtn4(UAnimNotify* Notity);
	//定时器
	UFUNCTION()
		void TimerCallback();
	//扣除魔法值
	UFUNCTION()
		void MinusMP(float MP);
	//更新UI
	UFUNCTION()
		void UpdateMPUI();
	UFUNCTION()
	////初始化状态
	void InitState();
};
