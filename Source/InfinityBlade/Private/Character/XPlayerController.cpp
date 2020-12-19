// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XPlayerController.h"

//��Ϸ��ʼ���÷���
void AXPlayerController::BeginPlay()
{
	//������ʾ���
	bShowMouseCursor = true;
	//��ʼ��Ӣ��
	XCharacter = Cast<AXCharacter>(GetPawn());
	//��Ϸ����ĳ�ʼ��
	MainUserWidget = CreateWidget<UMainUserWidget>(GetGameInstance(), LoadClass<UMainUserWidget>(nullptr,TEXT("WidgetBlueprint'/Game/BluePrint/UI/BP_MainUserWidget.BP_MainUserWidget_C'")));
	MainUserWidget->AddToViewport();
	if (XCharacter->XWeaponClass)
	{
		//������������
		Weapon = GetWorld()->SpawnActor<AWeapon>(XCharacter->XWeaponClass);
		//�󶨹���
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
		//������
		Weapon->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
	}
	
}

////������ؼ�
void AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	////������
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
	FRotator _Rotation = XCharacter->GetControlRotation();
	//����ƫ����
	FRotator YawRotation(0.f, _Rotation.Yaw, 0.f);
	//��ȡ�ƶ�����
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	//�ڸ÷�������λ��
	XCharacter->AddMovementInput(Direction, Speed);
}
