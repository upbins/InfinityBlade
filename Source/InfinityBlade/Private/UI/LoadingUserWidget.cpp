// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/LoadingUserWidget.h"

bool ULoadingUserWidget::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	};
	m_CircularThrobber = Cast<UCircularThrobber>(GetWidgetFromName("CircularThrobberLoading"));
	m_LoadingText = Cast<UTextBlock>(GetWidgetFromName("LoadingText"));
	return true;
}

void ULoadingUserWidget::FinishLoading()
{
	m_CircularThrobber->SetVisibility(ESlateVisibility::Hidden);
	m_LoadingText->SetText(FText::FromString(TEXT("游戏加载完成,请点击继续")));
}
