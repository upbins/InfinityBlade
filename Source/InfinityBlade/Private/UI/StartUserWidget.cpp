// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/StartUserWidget.h"

bool UStartUserWidget::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	};
	/*��ʼ����ʼ��ť*/
	m_StartGameButton = Cast<UButton>(GetWidgetFromName(TEXT("StartGameButton")));
	/*��ʼ��ע�ᰴť*/
	m_RegisterGameBtn = Cast<UButton>(GetWidgetFromName(TEXT("RegisterGameBtn")));
	/*��ʼ���˳���ť*/
	m_ExitGameBtn = Cast<UButton>(GetWidgetFromName(TEXT("ExitGameBtn")));
	//�˳���ť�ص�
	m_ExitGameBtn->OnClicked.AddDynamic(this, &UStartUserWidget::ExitGameBtnClickEvent);
	return true;
}

void UStartUserWidget::ExitGameBtnClickEvent()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("ExitGameBtnClickEvent"));
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr,EQuitPreference::Quit,false);
}
