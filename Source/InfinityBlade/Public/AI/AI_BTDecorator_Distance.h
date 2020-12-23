// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "AI_BTDecorator_Distance.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UAI_BTDecorator_Distance : public UBTDecorator
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Prop")
		float Distance;
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
};
