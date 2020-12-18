// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XAnimInstance.h"

void UXAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner() != nullptr) {
		Speed = TryGetPawnOwner()->GetVelocity().Size();
	}
}
