// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "XPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API AXPlayerState : public APlayerState
{
	GENERATED_BODY()
	
private:
	//普通伤害
	float m_AttackDamage;
	//当前Mp
	float m_CurrentMP;
	//当前血量
	float m_CurrentHP;
public:

	//Mp
	FORCEINLINE void SetCurrentMP(float CurrentMP) { this->m_CurrentHP = CurrentMP; };
	//Mp
	FORCEINLINE float GetCurrentMP() {
		return m_CurrentHP;
	};

	//Hp
	FORCEINLINE void SetCurrentHP(float CurrentHP) { this->m_CurrentHP = CurrentHP; };
	//Hp
	FORCEINLINE float GetCurrentHP() {
		return m_CurrentHP;
	};

	//设置伤害
	FORCEINLINE void SetAttackDamage(float AttackDamage) { this->m_AttackDamage = AttackDamage; };
	//返回伤害
	FORCEINLINE float GetAttackDamage() { 
		return m_AttackDamage;
	}

};
