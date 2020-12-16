// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameInstance.h"
#include <MoviePlayer.h>

void UCustomGameInstance::Init()
{
	UGameInstance::Init();
}

/** 地图加载开始的方法 */
void UCustomGameInstance::PreLoadMap(const FString& Map)
{

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
