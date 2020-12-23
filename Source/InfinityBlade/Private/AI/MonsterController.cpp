// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/MonsterController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AMonsterController::AMonsterController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AMonsterController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	Monster = Cast<AAICharacter>(InPawn);
	/** 初始化动画实例 */
	AnimInstance = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());
	//增加武器挂件
	if (Monster->AIWeaponClass) 
	{
		//生成一个武器对象
		AIWeapon = GetWorld()->SpawnActor<AWeapon>(Monster->AIWeaponClass);
		//绑定规则
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
		/** 绑定武器 */
		AIWeapon->AttachToComponent(Monster->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
		/** 绑定武器重叠事件 */
		AIWeapon->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AMonsterController::WeaponOverlapDamage);
	}
	//判断行为树组件
	if (Monster->BehaviorTree) 
	{
		BlackboardComponent->InitializeBlackboard(*(Monster->BehaviorTree->BlackboardAsset));
		BehaviorTreeComponent->StartTree(*(Monster->BehaviorTree));
	}
}

/** 武器重叠伤害事件 */
void AMonsterController::WeaponOverlapDamage(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "AI Damage...");
	if (AnimInstance->IsPlayAnimation)
	{
		UGameplayStatics::ApplyDamage(OtherActor, 20.f, this, Monster, nullptr);
	}
}