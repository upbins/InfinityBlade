// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AI_BTTask_Attack.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "AI/MonsterController.h"
#include "AI/AICharacter.h"
#include "AI/AIAnimInstance.h"
EBTNodeResult::Type UAI_BTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	/** ��ȡController */
	AMonsterController* Controller = Cast<AMonsterController>(OwnerComp.GetAIOwner());
	/** ��ȡAI */
	AAICharacter* Monster = Cast<AAICharacter>(Controller->GetPawn());
	/** ��ȡ����ʵ�� */
	UAIAnimInstance* AIAnimInstance = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());
	/** �жϵ�ǰ�Ƿ����ڲ��Ŷ�����̫�� */
	if (!AIAnimInstance->IsPlayAnimation)
	{
		/** ������� */
		Controller->SetFocus(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		/** ��ȡ����� */
		uint8 RandomNum = FMath::FloorToInt(FMath::RandRange(0.f, Monster->AttackMontages.Num()*1.f));
		/** ������Ŷ�����̫�� */
		AIAnimInstance->Montage_Play(Monster->AttackMontages[RandomNum], 1.f);
		return EBTNodeResult::Succeeded;
	}
	else 
	{
		return EBTNodeResult::Failed;
	}

	
}