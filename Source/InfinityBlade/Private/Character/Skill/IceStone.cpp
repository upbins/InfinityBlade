// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Skill/IceStone.h"

// Sets default values
AIceStone::AIceStone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	ParticleSystemComponent->SetupAttachment(RootComponent);
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AIceStone::OnOverlap);
	CapsuleComponent->SetupAttachment(ParticleSystemComponent);
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(RootComponent);
	//设置速度
	ProjectileMovementComponent->InitialSpeed = 600.0f;
	//生命周期
	InitialLifeSpan = 2.f;
}

// Called when the game starts or when spawned
void AIceStone::BeginPlay()
{
	Super::BeginPlay();
	
}

void AIceStone::OnShoot(FVector Direction)
{
	ProjectileMovementComponent->Velocity = Direction * ProjectileMovementComponent->InitialSpeed;
}

void AIceStone::OnOverlap(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "IceStone...");
}

