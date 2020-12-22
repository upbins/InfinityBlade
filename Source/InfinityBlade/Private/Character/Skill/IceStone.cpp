// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Skill/IceStone.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
// Sets default values
AIceStone::AIceStone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AIceStone::OnOverlap);
	//CapsuleComponent->SetupAttachment(RootComponent);
	SetRootComponent(CapsuleComponent);
	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	ParticleSystemComponent->SetupAttachment(CapsuleComponent);
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(ParticleSystemComponent);
	//设置速度
	ProjectileMovementComponent->InitialSpeed = 3000.0f;
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
	if (OtherActor)
	{
		/** 对击中的AI产生伤害 */
		UGameplayStatics::ApplyPointDamage(OtherActor, 50.f, HitResult.ImpactPoint, HitResult, nullptr, this, nullptr);
		/** 产生爆炸粒子特效 */
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BoomPartical, OtherActor->GetActorLocation());
		/** 播放爆炸声音 */
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), BoomSound, OtherActor->GetActorLocation());
		/** 隐藏粒子系统 */
		ParticleSystemComponent->SetVisibility(false);
	}
}

