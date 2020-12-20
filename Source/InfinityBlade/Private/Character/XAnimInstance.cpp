

#include "Character/XAnimInstance.h"

void UXAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner() != nullptr) {
		Speed = TryGetPawnOwner()->GetVelocity().Size();
	}
}

void UXAnimInstance::AnimNotify_PlayStart(UAnimNotify* Notity)
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "AnimNotify_PlayStart");
	bIsPlayingAnimation = true;
	bIsCanChangeAttack = false;
}

void UXAnimInstance::AnimNotify_PlayEnd(UAnimNotify * Notity)
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "AnimNotify_PlayEnd");
	bIsPlayingAnimation = false;
}

void UXAnimInstance::AnimNotify_IsCanChangeAttack(UAnimNotify* Notity)
{
	bIsCanChangeAttack = true;
}

void UXAnimInstance::AnimNotify_SecondAttackInput(UAnimNotify * Notity)
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "AnimNotify_SecondAttackInput");
	bIsEnableSecondAttack = true;
}

void UXAnimInstance::AnimNotify_ThreeAttackInput(UAnimNotify * Notity)
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "AnimNotify_ThreeAttackInput");
	bIsEnableThreeAttack = true;
}

void UXAnimInstance::AnimNotify_FourAttackInput(UAnimNotify * Notity)
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "AnimNotify_FourAttackInput");
	bIsEnableFourAttack = true;
}

void UXAnimInstance::AnimNotify_FiveAttackInput(UAnimNotify * Notity)
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "AnimNotify_FiveAttackInput");
	bIsEnableFiveAttack = true;
}

void UXAnimInstance::AnimNotify_ResetSerialAttack(UAnimNotify * Notity)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red,"AnimNotify_ResetSerialAttack");
	//是否进入第二段连击
	bIsEnableSecondAttack = false;
	//是否进入第三段连击
	bIsEnableThreeAttack = false;
	//是否进入第四段连击
	bIsEnableFourAttack = false;
	//是否进入第五段连击
	bIsEnableFiveAttack = false;
	//是否可切换连击
	bIsCanChangeAttack = false;
}
