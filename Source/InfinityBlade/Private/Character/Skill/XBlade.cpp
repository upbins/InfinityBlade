// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Skill/XBlade.h"

// Sets default values
AXBlade::AXBlade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);
	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	ParticleSystemComponent->SetupAttachment(SceneComponent);
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->SetupAttachment(SceneComponent);
}

// Called when the game starts or when spawned
void AXBlade::BeginPlay()
{
	Super::BeginPlay();
	
}


