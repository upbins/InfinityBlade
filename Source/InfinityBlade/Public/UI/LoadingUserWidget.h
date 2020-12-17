// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CircularThrobber.h"
#include "Components/TextBlock.h"
#include "LoadingUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API ULoadingUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY()
		UCircularThrobber* m_CircularThrobber;
	UPROPERTY()
		UTextBlock* m_LoadingText;
public:
	virtual bool Initialize() override;
	UFUNCTION()
		void FinishLoading();
};
