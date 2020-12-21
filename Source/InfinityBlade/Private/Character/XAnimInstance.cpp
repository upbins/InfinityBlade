

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

//减少魔法值
void UXAnimInstance::MinusMP(float MP)
{
	InitState();
	XPlayerState->SetCurrentMP(XPlayerState->GetCurrentMP() - MP);
}
