

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
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::FromInt(XPlayerState->GetAttackDamage()));
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