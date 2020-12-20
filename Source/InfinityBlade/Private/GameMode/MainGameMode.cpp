// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MainGameMode.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Character/XPlayerController.h"
#include "Character/XPlayerState.h"
#include "GameFramework/Character.h"

AMainGameMode::AMainGameMode()
{
	//找到资源里面的Charater蓝图类
	ConstructorHelpers::FClassFinder<ACharacter> CharacterFinder(TEXT("/Game/BluePrint/Character/BP_XCharacter"));
	DefaultPawnClass = CharacterFinder.Class;
	//设置PlayerController
	PlayerControllerClass = AXPlayerController::StaticClass();
	//设置PlayerState
	PlayerStateClass = AXPlayerState::StaticClass();
}
