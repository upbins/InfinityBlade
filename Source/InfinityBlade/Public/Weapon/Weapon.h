// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Weapon.generated.h"

UCLASS()
class INFINITYBLADE_API AWeapon : public AActor
{
	GENERATED_BODY()
public:
	//碰撞体组件
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent *CapsuleComponent;
	//武器模型组件
	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent *WeaponComponent;
public:	
	// Sets default values for this actor's properties
	AWeapon();
};
