// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AIAnimInstance.h"
#include "AI/MonsterController.h"

void UAIAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner() != nullptr) {
		Speed = TryGetPawnOwner()->GetVelocity().Size();
	}
}

void UAIAnimInstance::AnimNotify_PlayStart(UAnimNotify* Notity)
{
	IsPlayAnimation = true;
}

void UAIAnimInstance::AnimNotify_PlayEnd(UAnimNotify* Notity)
{
	IsPlayAnimation = false;
}

void UAIAnimInstance::AnimNotify_PlayDeath(UAnimNotify *Notity)
{
	AMonsterController* Controller = Cast<AMonsterController>(TryGetPawnOwner()->GetController());
	Controller->AIWeapon->Destroy();
	TryGetPawnOwner()->Destroy();
}
