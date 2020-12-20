// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainUserWidget.h"

bool UMainUserWidget::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	}
	//初始化开始按钮
	m_NormalAttackButton = Cast<UButton>(GetWidgetFromName(TEXT("NormalAttackButton")));
	return true;
}
