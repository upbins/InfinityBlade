// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XCharacter.h"
// Sets default values
AXCharacter::AXCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	 //设置控制器不受旋转影响  
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	//设置胶囊碰撞体的大小  
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	//设置控制器在移动时可以旋转  
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//创建一个摄像机目标点 USpringArmComponent 设置父级 长度 可旋转  
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom"); //CreateDefaultSubobject(TEXT("CameraBoom"),false);
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true;
	//创建一个摄像机 绑定到CameraBoom下，不受控制旋转的影响 受CameraBoom旋转影响  
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AXCharacter::BeginPlay()
{
	Super::BeginPlay();
}

