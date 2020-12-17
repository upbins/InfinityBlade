// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XPlayerController.h"

//��Ϸ��ʼ���÷���
void AXPlayerController::BeginPlay()
{
	bShowMouseCursor = true;
	//��ʼ��Ӣ��
	XCharacter = Cast<AXCharacter>(GetPawn());
}

//������ؼ�
void AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//������
	InputComponent->BindAxis("MoveForward", this, &AXPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AXPlayerController::MoveRight);
}

//ǰ���ƶ�
void AXPlayerController::MoveForward(float Speed)
{

	//��ȡ�������ĽǶ�
	FRotator _Rotation = XCharacter->GetControlRotation();//GetControlRotation();
	//����ƫ����
	FRotator YawRotation(0.f, _Rotation.Yaw, 0.f);
	//��ȡ�ƶ�����
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	//�ڸ÷�������λ��
	XCharacter->AddMovementInput(Direction, Speed);
}

//�����ƶ�
void AXPlayerController::MoveRight(float Speed)
{
	////��ȡ�������ĽǶ�
	//FRotator _Rotation = GetControlRotation();
	////����ƫ����
	//FRotator YawRotation(0.f, _Rotation.Yaw, 0.f);
	////��ȡ�ƶ�����
	//FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	////�ڸ÷�������λ��
	//XCharacter->AddMovementInput(Direction, Speed);
}
