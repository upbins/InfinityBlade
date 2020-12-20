

#include "Character/XAnimInstance.h"
#include "Character/XPlayerController.h"
#include "Character/XCharacter.h"


void UXAnimInstance::InitState()
{
	if (XPlayerState == nullptr) {
		//��ȡcontrller
		AXPlayerController* XPlayerContrroller = Cast<AXPlayerController>(TryGetPawnOwner()->GetController());
		//��ȡ״̬
		XPlayerState = XPlayerContrroller->XPlayerState;
		if (IntCurAttackIndex == 0) //��һ�ο�ʼ��ʱ���¼�³�ʼ����
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
	//�Ƿ���л�����
	bIsCanChangeAttack = false;
	IntCurAttackIndex = 0;
	InitState();
	if (XPlayerState != nullptr) {
		XPlayerState->SetAttackDamage(BaseAttack);
	}
}