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
	CurrentHP = TotalHP;
	//更新UI
	HPBar->SetPercent(CurrentHP / TotalHP);
}

// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AAICharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//当前血量减少
	CurrentHP -= Damage;
	//更新UI
	HPBar->SetPercent(CurrentHP / TotalHP);
	return Damage;
}
