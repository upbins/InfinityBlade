// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/XPlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "AI/AICharacter.h"
//��Ϸ��ʼ���÷���
void AXPlayerController::BeginPlay()
{
	//������ʾ���
	bShowMouseCursor = true;
	
	//��ʼ��Ӣ��
	XCharacter = Cast<AXCharacter>(GetPawn());
	//��ʼ������ʵ��
	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());
	//��ʼ�����״̬
	XPlayerState = Cast<AXPlayerState>(this->PlayerState);
	//��ʼ�����״̬
	InitState();

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
		//�������ص��¼�
		Weapon->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AXPlayerController::WeaponOverlapDamage);
	}
	//��ʼ����ť����¼�
	InitBtnWidgetEvent();
	UpdateUI();
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
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red,CurrentSection.ToString() + FString::SanitizeFloat(XAnimInstance->bIsCanChangeAttack));
	if (CurrentSection.IsNone()) {
		//Ĭ�ϲ��ŵ�һ����
		XAnimInstance->Montage_Play(SerialAttackMontage);
	}
	if (XAnimInstance->bIsCanChangeAttack) {
		if (CurrentSection.IsEqual(FName("FirstAttack")))
		{
			//���ŵڶ���
			XAnimInstance->Montage_JumpToSection(FName("SecondAttack"), SerialAttackMontage);
		}
		else if (CurrentSection.IsEqual(FName("SecondAttack")))
		{
			//���ŵ�����
			XAnimInstance->Montage_JumpToSection(FName("ThreeAttack"), SerialAttackMontage);
		}
		else if (CurrentSection.IsEqual(FName("ThreeAttack")))
		{
			//���ŵ��Ľ�
			XAnimInstance->Montage_JumpToSection(FName("FourAttack"), SerialAttackMontage);
		}
		else if (CurrentSection.IsEqual(FName("FourAttack")))
		{
			//���ŵ����
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
	//�Ƿ��ڹ���״̬
	if (XAnimInstance->bIsAttacking)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Overlap...");
		UGameplayStatics::ApplyDamage(OtherActor, XPlayerState->GetAttackDamage(), this, XCharacter, nullptr);
	}
}

/** �������˷��� */
void AXPlayerController::LockAI()
{
	/** ��ȡ�Լ���λ�� */
	FVector Location = XCharacter->GetActorLocation();
	/** ��ȡ���еĵ����б� */
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAICharacter::StaticClass(), AiArray);
	/** �жϵ������� */
	int AiNum = AiArray.Num();
	if (AiNum > 0)
	{
		/** ��ȡĬ��������� */
		float MinDistance = FVector::Dist(Location, AiArray[0]->GetActorLocation());
		/** ������������AI */
		AActor* MinActor = AiArray[0];
		/** �������е��� */
		for (int i = 0; i < AiNum; i++)
		{
			/** �жϵ����Ƿ��Ѿ����� */
			if (Cast<AAICharacter>(AiArray[i])->bIsDead)
			{
				continue;
			}
			/** ��ȡ���� */
			float TmpDistance = FVector::Dist(Location, AiArray[i]->GetActorLocation());
			/** �ж�������� */
			if (MinDistance >= TmpDistance)
			{
				MinDistance = TmpDistance;
				MinActor = AiArray[i];
			}
		}
		/** �жϾ����Ƿ��������㹻�Ľ� */
		if (MinDistance <= 400)
		{
			/** ����Rotationֻ������ת */
			FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(Location, MinActor->GetActorLocation());
			/** �޸�Rotation */
			Rotation.Pitch = XCharacter->GetCapsuleComponent()->GetComponentRotation().Pitch;
			Rotation.Roll = XCharacter->GetCapsuleComponent()->GetComponentRotation().Roll;
			/** ������ҽ����峯�� */
			XCharacter->GetCapsuleComponent()->SetRelativeRotation(Rotation);
		}
	}
}