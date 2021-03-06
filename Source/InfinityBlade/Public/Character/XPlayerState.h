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
	//��ͨ�˺�
	float m_AttackDamage;
	//��ǰMp
	float m_CurrentMP;
	//��ǰѪ��
	float m_CurrentHP;
	//�����˺�
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

	//�����˺�
	FORCEINLINE void SetAttackDamage(float AttackDamage) { this->m_AttackDamage = AttackDamage; };
	//�����˺�
	FORCEINLINE float GetAttackDamage() { 
		return m_AttackDamage;
	}

	//�����˺�
	FORCEINLINE void SetExtendDamage(float ExtendDamge) { this->m_ExtendDamge = ExtendDamge; };
	//�����˺�
	FORCEINLINE float GetExtendDamage() {
		return m_ExtendDamge;
	}
};
