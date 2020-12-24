// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AICharacter.h"

// Sets default values
AAICharacter::AAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(GetMesh());
}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	HPBar = Cast<UProgressBar>(WidgetComponent->GetUserWidgetObject()->GetWidgetFromName(TEXT("AI_HPBar")));
	HPText = Cast<UTextBlock>(WidgetComponent->GetUserWidgetObject()->GetWidgetFromName(TEXT("AI_HPText")));
	CurrentHP = TotalHP;
	//更新UI
	HPBar->SetPercent(CurrentHP / TotalHP);
	FString HpString = FString::SanitizeFloat(CurrentHP) + "/" + FString::SanitizeFloat(TotalHP);
	HPText->SetText(FText::FromString(HpString));
}

// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AAICharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (DamageCauser == this)
	{
		return 0.f;
	}
	//当前血量减少
	CurrentHP -= Damage;
	//更新UI
	HPBar->SetPercent(CurrentHP / TotalHP);
	FString HpString = FString::SanitizeFloat(CurrentHP) + "/" + FString::SanitizeFloat(TotalHP);
	HPText->SetText(FText::FromString(HpString));
	//随机播放一个动作
	UAnimInstance*  XAnimInstance = GetMesh()->GetAnimInstance();

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, CurSectionNameString + FString::SanitizeFloat(CurrentHP));
	if (CurrentHP <= 0) 
	{ 
		//播放死亡动画
		if (CurSectionNameString != "")
		{
			CurDamageMontage = this->DeathMontage;
			FName CurrentSection = XAnimInstance->Montage_GetCurrentSection(CurDamageMontage);
			if (CurrentSection.IsNone()) {
				//默认播放第一个节
				XAnimInstance->Montage_Play(CurDamageMontage);
			}
			else {
				//播放第第几个节
				XAnimInstance->Montage_JumpToSection(FName(CurSectionNameString), CurDamageMontage);
			}
		}
	
	}
	else
	{
		/** 获取随机数 */
		uint8 RandomNum = FMath::FloorToInt(FMath::RandRange(0.f, this->DamageSectionNameList.Num()*1.f));
		CurSectionNameString = this->DamageSectionNameList[RandomNum];
		//获得受击动画蒙太奇
		CurDamageMontage = this->DamageMontage;
		//获取当前播放的节
		FName CurrentSection = XAnimInstance->Montage_GetCurrentSection(CurDamageMontage);
		if (CurrentSection.IsNone()) {
			//默认播放第一个节
			XAnimInstance->Montage_Play(CurDamageMontage);
		}
		else {
			//播放第第几个节
			XAnimInstance->Montage_JumpToSection(FName(CurSectionNameString), CurDamageMontage);
		}
	}
	return Damage;
}
