// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XPlayerController.h"

//游戏开始调用方法
void AXPlayerController::BeginPlay()
{
	bShowMouseCursor = true;
	//初始化英雄
	XCharacter = Cast<AXCharacter>(GetPawn());
}

//绑定输入控件
void AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//绑定输入
	InputComponent->BindAxis("MoveForward", this, &AXPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AXPlayerController::MoveRight);
}

//前后移动
void AXPlayerController::MoveForward(float Speed)
{

	//获取控制器的角度
	FRotator _Rotation = XCharacter->GetControlRotation();//GetControlRotation();
	//创建偏航角
	FRotator YawRotation(0.f, _Rotation.Yaw, 0.f);
	//获取移动方向
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	//在该方向增加位移
	XCharacter->AddMovementInput(Direction, Speed);
}

//左右移动
void AXPlayerController::MoveRight(float Speed)
{
	////获取控制器的角度
	//FRotator _Rotation = GetControlRotation();
	////创建偏航角
	//FRotator YawRotation(0.f, _Rotation.Yaw, 0.f);
	////获取移动方向
	//FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	////在该方向增加位移
	//XCharacter->AddMovementInput(Direction, Speed);
}
