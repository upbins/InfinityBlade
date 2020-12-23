// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AI_BTDecorator_Distance.h"
#include "AI/MonsterController.h"
#include "AI/AICharacter.h"

bool UAI_BTDecorator_Distance::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AMonsterController *MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
	AAICharacter *Monster = Cast<AAICharacter>(MonsterController->GetPawn());
	UBlackboardComponent *Blackboard = MonsterController->BlackboardComponent;
	FVector TargetLocation = Blackboard->GetValueAsVector(TEXT("TargetLocation"));
	float CurDistance = FVector::Distance(Monster->GetActorLocation(), TargetLocation);
	if (CurDistance <= this->Distance) {
		return true;
	}
	return false;
}
