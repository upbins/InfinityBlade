// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainUserWidget.h"
#include "Components/CanvasPanelSlot.h"
bool UMainUserWidget::Initialize()
{
	if (!Super::Initialize()) {
		return false;
	}
	//初始化开始按钮
	m_NormalAttackButton = Cast<UButton>(GetWidgetFromName(TEXT("NormalAttackButton")));
	m_SkillButton_1 = Cast<UButton>(GetWidgetFromName(TEXT("SkillButton_1")));
	m_SkillButton_2 = Cast<UButton>(GetWidgetFromName(TEXT("SkillButton_2")));
	m_SkillButton_3 = Cast<UButton>(GetWidgetFromName(TEXT("SkillButton_3")));
	m_SkillButton_4 = Cast<UButton>(GetWidgetFromName(TEXT("SkillButton_4")));
	m_ProgressBar_MP = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_MP")));
	m_ProgressBar_Engery = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_Engery")));
	m_ProgressBar_HP = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_HP")));
	//UImage* m_Image = NewObject<UImage>(UImage::StaticClass());
	//m_Image->SetVisibility(ESlateVisibility::Visible);
	//m_Image->SetBrushFromTexture(LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/Texture/Common/T_Btn_Gray.T_Btn_Gray'")));
	////m_NormalAttackButton->AddChild(m_Image);
	//UPanelWidget* rootPanel = (UPanelWidget*)this->GetRootWidget();
	//rootPanel->AddChild(m_Image);
	//UCanvasPanelSlot* canvasPanelSlot = (UCanvasPanelSlot*)m_Image->Slot;
	//auto slot = m_Image->Slot;
	//canvasPanelSlot->SetPosition(FVector2D(640, 360));
	return true;
}
