// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XPlayerController.h"

//游戏开始调用方法
void AXPlayerController::BeginPlay()
{
	//设置显示鼠标
	bShowMouseCursor = true;
	//初始化英雄
	XCharacter = Cast<AXCharacter>(GetPawn());
	//初始化动画实例
	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());
	//游戏界面的初始化
	MainUserWidget = CreateWidget<UMainUserWidget>(GetGameInstance(), LoadClass<UMainUserWidget>(nullptr,TEXT("WidgetBlueprint'/Game/BluePrint/UI/BP_MainUserWidget.BP_MainUserWidget_C'")));
	MainUserWidget->AddToViewport();
	if (XCharacter->XWeaponClass)
	{
		//生成武器对象
		Weapon = GetWorld()->SpawnActor<AWeapon>(XCharacter->XWeaponClass);
		//绑定规则
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
		//绑定武器
		Weapon->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
	}
	//初始化按钮点击事件
	InitBtnWidgetEvent();
}

////绑定输入控件
void AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	////绑定输入
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
	FRotator _Rotation = XCharacter->GetControlRotation();
	//创建偏航角
	FRotator YawRotation(0.f, _Rotation.Yaw, 0.f);
	//获取移动方向
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	//在该方向增加位移
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
	
	//判断当前蒙太奇是否在播放,如果正在播放则终止
	if (XAnimInstance->bIsPlayingAnimation) 
	{
		return;
	}
	//获得连击动画蒙太奇
	UAnimMontage * SerialAttackMontage = XCharacter->SerialAttackMontage;
	//获取当前播放的节
	FName CurrentSection = XAnimInstance->Montage_GetCurrentSection(SerialAttackMontage);
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, CurrentSection.ToString());
	if (CurrentSection.IsNone()) {
		//默认播放第一个节
		XAnimInstance->Montage_Play(SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("FirstAttack")) && XAnimInstance->bIsEnableSecondAttack)
	{
		//播放第二节
		XAnimInstance->Montage_JumpToSection(FName("SecondAttack"), SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("SecondAttack")) && XAnimInstance->bIsEnableThreeAttack)
	{
		//播放第三节
		XAnimInstance->Montage_JumpToSection(FName("ThreeAttack"), SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("ThreeAttack")) && XAnimInstance->bIsEnableFourAttack)
	{
		//播放第四节
		XAnimInstance->Montage_JumpToSection(FName("FourAttack"),SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("FourAttack")) && XAnimInstance->bIsEnableFiveAttack)
	{
		//播放第五节
		XAnimInstance->Montage_JumpToSection(FName("FiveAttack"),SerialAttackMontage);
	}
}
