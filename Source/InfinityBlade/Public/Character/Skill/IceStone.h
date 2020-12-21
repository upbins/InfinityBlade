// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "IceStone.generated.h"

UCLASS()
class INFINITYBLADE_API AIceStone : public AActor
{
	GENERATED_BODY()
	//粒子系统
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* ParticleSystemComponent;
	//胶囊体
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent* CapsuleComponent;
	//自动移动组件
	UPROPERTY()
		UProjectileMovementComponent* ProjectileMovementComponent;
	//爆炸特效
	UPROPERTY(EditAnywhere, Category = "Particle")
		UParticleSystem* BoomPartical;

public:	
	// Sets default values for this actor's properties
	AIceStone();
	//发射方法
	void OnShoot(FVector Direction);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//击中回调
	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitResult);
};



