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
	//∆’Õ®…À∫¶
	float m_AttackDamage;
	//µ±«∞Mp
	float m_CurrentMP;
	//µ±«∞—™¡ø
	float m_CurrentHP;
	//∂ÓÕ‚…À∫¶
	float m_ExtendDamge = 0.f;
public:

	//Mp
	FORCEINLINE void SetCurrentMP(float CurrentMP) { this->m_CurrentMP = CurrentMP; };
	//Mp
	FORCEINLINE float GetCurrentMP() {
		return m_CurrentMP;
	};

	//Hp
	FORCEINLINE void SetCurrentHP(float CurrentHP) { this->m_CurrentHP = CurrentHP; };
	//Hp
	FORCEINLINE float GetCurrentHP() {
		return m_CurrentHP;
	};

	//…Ë÷√…À∫¶
	FORCEINLINE void SetAttackDamage(float AttackDamage) { this->m_AttackDamage = AttackDamage; };
	//∑µªÿ…À∫¶
	FORCEINLINE float GetAttackDamage() { 
		return m_AttackDamage;
	}

	//…Ë÷√…À∫¶
	FORCEINLINE void SetExtendDamage(float ExtendDamge) { this->m_ExtendDamge = ExtendDamge; };
	//∑µªÿ…À∫¶
	FORCEINLINE float GetExtendDamage() {
		return m_ExtendDamge;
	}
};
