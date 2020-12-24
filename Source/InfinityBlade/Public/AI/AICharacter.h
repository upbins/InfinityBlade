// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Weapon/Weapon.h"
#include "AICharacter.generated.h"

UCLASS()
class INFINITYBLADE_API AAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAICharacter();

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "State")
	float TotalHP;
	//��ǰѪ��
	float CurrentHP;
	//�Ƿ�����
	bool bIsDead;
	//Ѫ��
	UPROPERTY()
		UProgressBar* HPBar;
	UPROPERTY()
		UTextBlock* HPText;
	UPROPERTY(EditAnywhere, Category = "BehaviorTree")
		UBehaviorTree* BehaviorTree;
	//������
	UPROPERTY(EditAnywhere, Category = "Weapon")
		TSubclassOf<AWeapon> AIWeaponClass;
	/** ����������̫������ */
	UPROPERTY(EditAnywhere, Category = "Montage")
		TArray<UAnimMontage*> AttackMontages;
	/** ���˶�����̫�� */
	UPROPERTY(EditAnywhere, Category = "Montage")
		UAnimMontage* DamageMontage;
		//TArray<UAnimMontage*> DamageMontage;
	UPROPERTY(EditAnywhere, Category = " DamageMontageSectionName")
		TArray<FString> DamageSectionNameList;
	/** ����������̫�� */
	UPROPERTY(EditAnywhere, Category = "Montage")
		UAnimMontage* DeathMontage;
		//TArray<UAnimMontage*> DeathMontage;
	FString CurSectionNameString = "";
	UAnimMontage * CurDamageMontage;
public:	
	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* WidgetComponent;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//��д�˺��ķ���
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
};
