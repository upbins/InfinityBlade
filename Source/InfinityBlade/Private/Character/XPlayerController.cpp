// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XPlayerController.h"

//��Ϸ��ʼ���÷���
void AXPlayerController::BeginPlay()
{
	//������ʾ���
	bShowMouseCursor = true;
	//��ʼ��Ӣ��
	XCharacter = Cast<AXCharacter>(GetPawn());
	//��ʼ������ʵ��
	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());
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
	//��ʼ����ť����¼�
	InitBtnWidgetEvent();
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

void AXPlayerController::InitBtnWidgetEvent()
{
	if (MainUserWidget->m_NormalAttackButton)
	{
		MainUserWidget->m_NormalAttackButton->OnClicked.AddDynamic(this, &AXPlayerController::NormalAttackBtnEevent);
	}
}

void AXPlayerController::NormalAttackBtnEevent()
{
	
	//�жϵ�ǰ��̫���Ƿ��ڲ���,������ڲ�������ֹ
	if (XAnimInstance->bIsPlayingAnimation) 
	{
		return;
	}
	//�������������̫��
	UAnimMontage * SerialAttackMontage = XCharacter->SerialAttackMontage;
	//��ȡ��ǰ���ŵĽ�
	FName CurrentSection = XAnimInstance->Montage_GetCurrentSection(SerialAttackMontage);
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, CurrentSection.ToString());
	if (CurrentSection.IsNone()) {
		//Ĭ�ϲ��ŵ�һ����
		XAnimInstance->Montage_Play(SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("FirstAttack")) && XAnimInstance->bIsEnableSecondAttack)
	{
		//���ŵڶ���
		XAnimInstance->Montage_JumpToSection(FName("SecondAttack"), SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("SecondAttack")) && XAnimInstance->bIsEnableThreeAttack)
	{
		//���ŵ�����
		XAnimInstance->Montage_JumpToSection(FName("ThreeAttack"), SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("ThreeAttack")) && XAnimInstance->bIsEnableFourAttack)
	{
		//���ŵ��Ľ�
		XAnimInstance->Montage_JumpToSection(FName("FourAttack"),SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("FourAttack")) && XAnimInstance->bIsEnableFiveAttack)
	{
		//���ŵ����
		XAnimInstance->Montage_JumpToSection(FName("FiveAttack"),SerialAttackMontage);
	}
}
