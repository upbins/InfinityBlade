// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "XBlade.generated.h"

UCLASS()
class INFINITYBLADE_API AXBlade : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere)
		USceneComponent *SceneComponent;
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent * ParticleSystemComponent;
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent *CapsuleComponent;
public:	
	// Sets default values for this actor's properties
	AXBlade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
