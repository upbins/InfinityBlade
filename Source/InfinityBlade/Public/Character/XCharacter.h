// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "XCharacter.generated.h"

UCLASS()
class INFINITYBLADE_API AXCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UCameraComponent* CameraComponent;
public:
	// Sets default values for this character's properties
	//构造函数
	AXCharacter();

protected:
	// Called when the game starts or when spawned
	//游戏开始调用的方法
	virtual void BeginPlay() override;
};
