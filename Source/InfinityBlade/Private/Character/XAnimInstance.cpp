

#include "Character/XAnimInstance.h"
#include "Character/XPlayerController.h"
#include "Character/XCharacter.h"


void UXAnimInstance::InitState()
{
	if (XPlayerState == nullptr) {
		//获取contrller
		AXPlayerController* XPlayerContrroller = Cast<AXPlayerController>(TryGetPawnOwner()->GetController());
		//获取状态
		XPlayerState = XPlayerContrroller->XPlayerState;
		if (IntCurAttackIndex == 0) //第一段开始的时候记录下初始攻击
		{
			BaseAttack = XPlayerState->GetAttackDamage();
		}
	}
}

void UXAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner() != nullptr) {
		Speed = TryGetPawnOwner()->GetVelocity().Size();
	}
}

void UXAnimInstance::AnimNotify_PlayStart(UAnimNotify* Notity)
{

	bIsPlayingAnimation = true;
	bIsCanChangeAttack = false;
	IntCurAttackIndex = IntCurAttackIndex + 1;
	if (XPlayerState != nullptr) {
		XPlayerState->SetAttackDamage(BaseAttack + BaseAttack * IntCurAttackIndex);
	}
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::FromInt(XPlayerState->GetAttackDamage()));
}

void UXAnimInstance::AnimNotify_PlayEnd(UAnimNotify * Notity)
{
	bIsPlayingAnimation = false;
}

void UXAnimInstance::AnimNotify_AttackStart(UAnimNotify* Notify)
{
	bIsAttacking = true;
}

void UXAnimInstance::AnimNotify_AttackEnd(UAnimNotify* Notify)
{
	bIsAttacking = false;
}

void UXAnimInstance::AnimNotify_IsCanChangeAttack(UAnimNotify* Notity)
{
	bIsCanChangeAttack = true;
}
void UXAnimInstance::AnimNotify_ResetSerialAttack(UAnimNotify * Notity)
{
	//是否可切换连击
	bIsCanChangeAttack = false;
	IntCurAttackIndex = 0;
	InitState();
	if (XPlayerState != nullptr) {
		XPlayerState->SetAttackDamage(BaseAttack);
	}
}

void UXAnimInstance::AnimNotify_SkillBtn1(UAnimNotify* Notity)
{
	//获取角色
	AXCharacter* XCharacter = Cast<AXCharacter>(TryGetPawnOwner());
	//获取socket发射位置
	FVector Location = XCharacter->GetMesh()->GetSocketLocation(TEXT("IceStone"));
	//获取socket旋转
	FRotator Rotation = XCharacter->GetMesh()->GetSocketRotation(TEXT("IceStone"));
	AIceStone *IceStone = GetWorld()->SpawnActor<AIceStone>(XCharacter->AIceStoneClass, Location, Rotation);
	//发射子弹
	IceStone->OnShoot(Rotation.Vector());
	MinusMP(10.0f);
}

void UXAnimInstance::AnimNotify_SkillBtn2(UAnimNotify* Notity)
{
	//获取角色
	AXCharacter* XCharacter = Cast<AXCharacter>(TryGetPawnOwner());
	//加血和更新UI
	InitState();
	/** 设置当前的HP */
	XPlayerState->SetCurrentHP(XPlayerState->GetCurrentHP() + 30.f);
	/** 判断HP是否溢出 */
	if (XPlayerState->GetCurrentHP() > XCharacter->TotalHP)
	{
		XPlayerState->SetCurrentHP(XCharacter->TotalHP);
	}
	/** 获取Controller */
	AXPlayerController* XPlayerController = Cast<AXPlayerController>(TryGetPawnOwner()->GetController());
	
	/** 更新HP的UI */
	XPlayerController->MainUserWidget->m_ProgressBar_HP->SetPercent(1.f - (XPlayerState->GetCurrentHP() / XCharacter->TotalHP));
	/** 扣除魔法值 */
	MinusMP(10.f);
}

/** 雷霆之光产生通知 */
void UXAnimInstance::AnimNotify_SkillBtn3(UAnimNotify* Notify)
{
	/** 初始化状态 */
	InitState();
	/** 扣除魔法值 */
	MinusMP(10.f);
	/** 产生伤害 */
	TArray<AActor*> IgnoreActors;
	IgnoreActors.Add(TryGetPawnOwner());
	float CurDamage = XPlayerState->GetExtendDamage() + XPlayerState->GetAttackDamage();
	UGameplayStatics::ApplyRadialDamage(GetWorld(), 50.f, TryGetPawnOwner()->GetActorLocation(), 500.f, nullptr, IgnoreActors, TryGetPawnOwner(), TryGetPawnOwner()->GetController(), true, ECC_Visibility);
}

//技能4产生通知

void UXAnimInstance::AnimNotify_SkillBtn4(UAnimNotify* Notify)
{
	/** 初始化状态 */
	InitState();
	//获取角色
	AXCharacter* XCharacter = Cast<AXCharacter>(TryGetPawnOwner());
	if (XCharacter->XBladeClass && XBlade == nullptr)
	{
		//生成武器对象
		XBlade = GetWorld()->SpawnActor<AXBlade>(XCharacter->XBladeClass);
		//绑定规则
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
		//绑定武器
		XBlade->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
		/** 扣除魔法值 */
		MinusMP(40.f);
		//增伤
		if (XPlayerState != nullptr) 
		{
			XPlayerState->SetExtendDamage(60);
		}
		/** 开启定时器 */
		XCharacter->GetWorldTimerManager().SetTimer(TimerHandle, this, &UXAnimInstance::TimerCallback, 10.f, false);
	}
}

/** 定时器回调方法 */
void UXAnimInstance::TimerCallback()
{
	/** 初始化状态 */
	InitState();
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Timer...");
	if (XPlayerState != nullptr)
	{
		XPlayerState->SetExtendDamage(0);
	}
	/** 获取英雄角色 */
	AXCharacter* XCharacter = Cast<AXCharacter>(TryGetPawnOwner());
	FDetachmentTransformRules DetachmentTransformRule(EDetachmentRule::KeepRelative,true);
	XBlade->DetachFromActor(DetachmentTransformRule);
	XBlade->Destroy();
	XBlade = nullptr;
	/** 清除定时器 */
	XCharacter->GetWorldTimerManager().ClearTimer(TimerHandle);
}


//减少魔法值
void UXAnimInstance::MinusMP(float MP)
{
	InitState();
	XPlayerState->SetCurrentMP(XPlayerState->GetCurrentMP() - MP);
	UpdateMPUI();
}
//更新MPUI
void UXAnimInstance::UpdateMPUI()
{
	/** 获取Controller */
	AXPlayerController* XPlayerController = Cast<AXPlayerController>(TryGetPawnOwner()->GetController());
	/** 获取角色 */
	AXCharacter* XCharacter = Cast<AXCharacter>(TryGetPawnOwner());
	/** 设置MP的UI */
	XPlayerController->MainUserWidget->m_ProgressBar_MP->SetPercent(1.f - (XPlayerState->GetCurrentMP() / XCharacter->TotalMP));
}
