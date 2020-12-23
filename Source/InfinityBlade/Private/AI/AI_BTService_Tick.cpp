// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AI_BTService_Tick.h"
#include "AI/MonsterController.h"
#include "Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


void UAI_BTService_Tick::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	//获取Controller
	AMonsterController * MonsterController = Cast<AMonsterController>(OwnerComp.GetAIOwner());
	//获取黑板控件
	UBlackboardComponent *Blackboard = MonsterController->BlackboardComponent;
	//设置SelfLocation
	Blackboard->SetValueAsVector(TEXT("SelfLocation"), MonsterController->GetPawn()->GetActorLocation());
	//获取ai角色
	AAICharacter *Monster = Cast<AAICharacter>(MonsterController->GetPawn());
	//获取朝向
	FRotator Rotation = Monster->GetMesh()->GetComponentRotation();
	/** 设置SelfDirection */
	Blackboard->SetValueAsVector(TEXT("SelfDirection"), Rotation.Vector());
	/** 获取主角位置 */
	FVector TargetLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
	/** 设置TargetLocation */
	Blackboard->SetValueAsVector(TEXT("TargetLocation"), TargetLocation);
}
