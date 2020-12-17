// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XCharacter.h"
// Sets default values
AXCharacter::AXCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	//设置角色移动的朝向
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//设置角色控制器是否控制朝向
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	//初始化相机组件
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	//设置到父组件上
	CameraComponent->SetupAttachment(RootComponent);
	//相机角色控制器控制朝向
	CameraComponent->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void AXCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

