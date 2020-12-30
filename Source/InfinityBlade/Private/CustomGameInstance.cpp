// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameInstance.h"
#include "GameMode/StartGameMode.h"
#include <MoviePlayer.h>

//初始化方法
void UCustomGameInstance::Init()
{
	UGameInstance::Init();
	//开始加载地图的委托
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UCustomGameInstance::PreLoadMap);
	//结束加载地图的委托
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UCustomGameInstance::PostLoadMap);
	//加载Loading-UI
	m_LoadUserWidget = CreateWidget<ULoadingUserWidget>(this, LoadClass<ULoadingUserWidget>(this, TEXT("WidgetBlueprint'/Game/Character/BluePrint/UI/BP_LoadUserWidget.BP_LoadUserWidget_C'")));
}
/** 地图加载开始的方法 */
void UCustomGameInstance::PreLoadMap(const FString& Map)
{
	if (Map.Equals("/Game/Map/MainGame_Map")) 
	{
		if (!IsRunningDedicatedServer())
		{
			//创建一个屏幕加载的属性对象
			FLoadingScreenAttributes LoadingAttr;
			//设置手动点击之后继续
			LoadingAttr.bWaitForManualStop = true;
			//添加到屏幕
			LoadingAttr.WidgetLoadingScreen = m_LoadUserWidget->TakeWidget();
			GetMoviePlayer()->SetupLoadingScreen(LoadingAttr);
		};
	};
}

/** 地图加载结束的方法 */
void UCustomGameInstance::PostLoadMap(UWorld* World)
{
	
}

/** 是否加载完成 */
bool UCustomGameInstance::GetLoadStatus()
{
	/** 返回是否已经加载完成 */
	return GetMoviePlayer()->IsLoadingFinished();
}

void UCustomGameInstance::FinishLoadMap()
{
	m_LoadUserWidget->FinishLoading();
}
