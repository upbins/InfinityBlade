// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/StartGameMode.h"

//��Ϸ��ʼ���õķ�ʽ
void AStartGameMode::BeginPlay()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Hello GameMode"));
	//��ʼ����Ϸ��ʼ����
	m_StartUserWidget = CreateWidget<UStartUserWidget>(GetGameInstance(), LoadClass<UStartUserWidget>(this, TEXT("WidgetBlueprint'/Game/BluePrint/BP_StartUseWidget.BP_StartUseWidget_C'")));
	//��ӵ���ͼ��
	m_StartUserWidget->AddToViewport();
}
