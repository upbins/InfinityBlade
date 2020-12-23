// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Weapon/Weapon.h"
#include "AI/AIAnimInstance.h"
#include "AI/AICharacter.h"
#include "MonsterController.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API AMonsterController : public AAIController
{
	GENERATED_BODY()
public:
	//行为树控件
	UPROPERTY()
		UBehaviorTreeComponent* BehaviorTreeComponent;
	/** 黑板控件 */
	UPROPERTY()
		UBlackboardComponent* BlackboardComponent;
	/** 武器对象 */
	UPROPERTY()
		AWeapon* AIWeapon;
	/** AI类 */
	UPROPERTY()
		AAICharacter* Monster;
	/** AI动画实例 */
	UPROPERTY()
		UAIAnimInstance* AnimInstance;
public:
	//构造函数
	AMonsterController();
	void OnPossess(APawn* InPawn) override;
	/** 武器重叠伤害事件 */
	UFUNCTION()
		void WeaponOverlapDamage(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitResult);
};
