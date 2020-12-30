// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/StartGameMode.h"

//游戏开始调用的方式
void AStartGameMode::BeginPlay()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("BeginPlay"));
	//初始化游戏开始界面
	m_StartUserWidget = CreateWidget<UStartUserWidget>(GetGameInstance(), LoadClass<UStartUserWidget>(this, TEXT("WidgetBlueprint'/Game/Character/BluePrint/UI/BP_StartUserWidget.BP_StartUserWidget_C'")));
	//添加到视图中
	m_StartUserWidget->AddToViewport();
}


