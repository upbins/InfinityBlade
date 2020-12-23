// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AI_BTService_Tick.h"
#include "AI/MonsterController.h"
#include "Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


void UAI_BTService_Tick::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	//��ȡController
	AMonsterController * MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
	//��ȡ�ڰ�ؼ�
	UBlackboardComponent *Blackboard = MonsterController->BlackboardComponent;
	//����SelfLocation
	Blackboard->SetValueAsVector(TEXT("SelfLocation"), MonsterController->GetPawn()->GetActorLocation());
	//��ȡai��ɫ
	AAICharacter *Monster = Cast<AAICharacter>(MonsterController->GetPawn());
	//��ȡ����
	FRotator Rotation = Monster->GetMesh()->GetComponentRotation();
	/** ����SelfDirection */
	Blackboard->SetValueAsVector(TEXT("SelfDirection"), Rotation.Vector());
	/** ��ȡ����λ�� */
	FVector TargetLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
	/** ����TargetLocation */
	Blackboard->SetValueAsVector(TEXT("TargetLocation"), TargetLocation);
}
