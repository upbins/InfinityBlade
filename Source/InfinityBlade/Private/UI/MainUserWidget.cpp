// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainUserWidget.h"

bool UMainUserWidget::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	}
	//��ʼ����ʼ��ť
	m_NormalAttackButton = Cast<UButton>(GetWidgetFromName(TEXT("NormalAttackButton")));
	return true;
}
