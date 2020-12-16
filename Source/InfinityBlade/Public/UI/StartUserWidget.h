// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "StartUserWidget.generated.h"

/**
 * 游戏开始界面
 */
UCLASS()
class INFINITYBLADE_API UStartUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY()
		//开始按钮
		UButton* m_StartGameButton;
	UPROPERTY()
		//注册按钮
		UButton* m_RegisterGameBtn;
	UPROPERTY()
		//退出按钮
		UButton* m_ExitGameBtn;
private:
	//控件创建完成后初始化方法
	virtual bool Initialize() override;
	UFUNCTION()
	//退出按钮响应时间
	void ExitGameBtnClickEvent();
};
