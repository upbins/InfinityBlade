// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XPlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Character/Skill/IceStone.h"
#include "AI/AICharacter.h"
//游戏开始调用方法
void AXPlayerController::BeginPlay()
{
	//设置显示鼠标
	bShowMouseCursor = true;
	
	//初始化英雄
	XCharacter = Cast<AXCharacter>(GetPawn());
	//初始化动画实例
	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());
	//初始化玩家状态
	XPlayerState = Cast<AXPlayerState>(this->PlayerState);
	//初始化玩家状态
	InitState();

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
		//绑定武器重叠事件
		Weapon->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AXPlayerController::WeaponOverlapDamage);
	}
	//初始化按钮点击事件
	InitBtnWidgetEvent();
	UpdateUI();
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
	if (MainUserWidget->m_SkillButton_1)
	{
		MainUserWidget->m_SkillButton_1->OnClicked.AddDynamic(this, &AXPlayerController::SkillButton1Eevent);
	}
}

void AXPlayerController::SkillButton1Eevent()
{
	if (XAnimInstance->bIsPlayingAnimation) {
		return;
	}
	if (XPlayerState->GetCurrentMP() >= 10.f) {
		//获得连击动画蒙太奇
		UAnimMontage * SkillBtn1Montage = XCharacter->SkillBtn1Montage;
		LockAI();
		XAnimInstance->Montage_Play(SkillBtn1Montage,1.f);
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
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red,CurrentSection.ToString() + FString::SanitizeFloat(XAnimInstance->bIsCanChangeAttack));
	LockAI();
	if (CurrentSection.IsNone()) {
		//默认播放第一个节
		XAnimInstance->Montage_Play(SerialAttackMontage);
	}
	if (XAnimInstance->bIsCanChangeAttack) {
		if (CurrentSection.IsEqual(FName("FirstAttack")))
		{
			//播放第二节
			XAnimInstance->Montage_JumpToSection(FName("SecondAttack"), SerialAttackMontage);
		}
		else if (CurrentSection.IsEqual(FName("SecondAttack")))
		{
			//播放第三节
			XAnimInstance->Montage_JumpToSection(FName("ThreeAttack"), SerialAttackMontage);
		}
		else if (CurrentSection.IsEqual(FName("ThreeAttack")))
		{
			//播放第四节
			XAnimInstance->Montage_JumpToSection(FName("FourAttack"), SerialAttackMontage);
		}
		else if (CurrentSection.IsEqual(FName("FourAttack")))
		{
			//播放第五节
			XAnimInstance->Montage_JumpToSection(FName("FiveAttack"), SerialAttackMontage);
		}
	}
}

void AXPlayerController::InitState()
{
	XPlayerState->SetCurrentHP(XCharacter->TotalHP);
	XPlayerState->SetCurrentMP(XCharacter->TotalMP);
	XPlayerState->SetAttackDamage(XCharacter->AttackDamage);
}

void AXPlayerController::UpdateUI()
{
	if (MainUserWidget->m_ProgressBar_HP) {
		MainUserWidget->m_ProgressBar_HP->SetPercent(1.0 - (XPlayerState->GetCurrentHP() / XCharacter->TotalHP));
	}
	if (MainUserWidget->m_ProgressBar_MP) {
		MainUserWidget->m_ProgressBar_MP->SetPercent(1.0 - (XPlayerState->GetCurrentMP() / XCharacter->TotalMP));
	}
}

void AXPlayerController::WeaponOverlapDamage(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitResult)
{
	//是否处于攻击状态
	if (XAnimInstance->bIsAttacking)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Overlap...");
		UGameplayStatics::ApplyDamage(OtherActor, XPlayerState->GetAttackDamage(), this, XCharacter, nullptr);
	}
}

/** 锁定敌人方法 */
void AXPlayerController::LockAI()
{
		/** 获取自己的位置 */
		FVector Location = XCharacter->GetActorLocation();
		/** 获取所有的敌人列表 */
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAICharacter::StaticClass(), AiArray);
		/** 判断敌人数量 */
		int AiNum = AiArray.Num();
		if (AiNum > 0)
		{
			/** 获取默认最近距离 */
			float MinDistance = FVector::Dist(Location, AiArray[0]->GetActorLocation());
			/** 距离玩家最近的AI */
			AActor* MinActor = AiArray[0];
			/** 遍历所有敌人 */
			for (int i = 0; i < AiNum; i++)
			{
				/** 判断敌人是否已经死亡 */
				if (Cast<AAICharacter>(AiArray[i])->bIsDead)
				{
					continue;
				}
				/** 获取距离 */
				float TmpDistance = FVector::Dist(Location, AiArray[i]->GetActorLocation());
				/** 判断最近距离 */
				if (MinDistance >= TmpDistance)
				{
					MinDistance = TmpDistance;
					MinActor = AiArray[i];
				}
			}
			/** 判断距离是否距离玩家足够的近 */
			if (MinDistance <= 4000)
			{
				/** 设置Rotation只左右旋转 */
				FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(Location, MinActor->GetActorLocation());
				/** 修改Rotation */
				Rotation.Pitch = XCharacter->GetCapsuleComponent()->GetComponentRotation().Pitch;
				Rotation.Roll = XCharacter->GetCapsuleComponent()->GetComponentRotation().Roll;
				/** 设置玩家胶囊体朝向 */
				XCharacter->GetCapsuleComponent()->SetRelativeRotation(Rotation);
			}
	}
}