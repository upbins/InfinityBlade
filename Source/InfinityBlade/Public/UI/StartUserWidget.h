// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "StartUserWidget.generated.h"

/**
 * ��Ϸ��ʼ����
 */
UCLASS()
class INFINITYBLADE_API UStartUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY()
		//��ʼ��ť
		UButton* m_StartGameButton;
	UPROPERTY()
		//ע�ᰴť
		UButton* m_RegisterGameBtn;
	UPROPERTY()
		//�˳���ť
		UButton* m_ExitGameBtn;
private:
	//�ؼ�������ɺ��ʼ������
	virtual bool Initialize() override;
	UFUNCTION()
	//�˳���ť��Ӧʱ��
	void ExitGameBtnClickEvent();
};
