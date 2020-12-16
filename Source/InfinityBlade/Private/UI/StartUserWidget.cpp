// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/StartUserWidget.h"

bool UStartUserWidget::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	};
	/*初始化开始按钮*/
	m_StartGameButton = Cast<UButton>(GetWidgetFromName(TEXT("StartGameButton")));
	/*初始化注册按钮*/
	m_RegisterGameBtn = Cast<UButton>(GetWidgetFromName(TEXT("RegisterGameBtn")));
	/*初始化退出按钮*/
	m_ExitGameBtn = Cast<UButton>(GetWidgetFromName(TEXT("ExitGameBtn")));
	//退出按钮回调
	m_ExitGameBtn->OnClicked.AddDynamic(this, &UStartUserWidget::ExitGameBtnClickEvent);
	return true;
}

void UStartUserWidget::ExitGameBtnClickEvent()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("ExitGameBtnClickEvent"));
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr,EQuitPreference::Quit,false);
}
