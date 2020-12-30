// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Animation/AnimMontage.h"
#include "Weapon/Weapon.h"
#include "Character/Skill/IceStone.h"
#include "Character/Skill/XBlade.h"
#include "XCharacter.generated.h"

UCLASS()
class INFINITYBLADE_API AXCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	//摄像机目标点  
	USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere)
	//跟随相机  
	UCameraComponent* FollowCamera;
	//武器类
	UPROPERTY(EditAnywhere, Category = "Weapon")
		TSubclassOf<AWeapon> XWeaponClass;
	//总血量
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float TotalHP;
	//MP
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float TotalMP;
	//伤害值
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float AttackDamage;
	//连击动画蒙太奇
	UPROPERTY(EditAnywhere, Category = "Montage")
		UAnimMontage* SerialAttackMontage;
	//skillbtn1子弹
	UPROPERTY(EditAnywhere, Category = "SkillBtn1")
		TSubclassOf<AIceStone> AIceStoneClass;
	//Skillbtn1蒙太奇
	UPROPERTY(EditAnywhere, Category = "Montage")
		UAnimMontage* SkillBtn1Montage;
	//Skillbtn2蒙太奇
	UPROPERTY(EditAnywhere, Category = "Montage")
		UAnimMontage* SkillBtn2Montage;
	//Skillbtn3蒙太奇
	UPROPERTY(EditAnywhere, Category = "Montage")
		UAnimMontage* SkillBtn3Montage;
	UPROPERTY(EditAnywhere, Category = "SkillBtn4")
		TSubclassOf<AXBlade> XBladeClass;
	//SkillBtn4蒙太奇
	UPROPERTY(EditAnywhere, Category = "Montage")
		UAnimMontage* SkillBtn4Montage;
public:
	// Sets default values for this character's properties
	//构造函数
	AXCharacter();

public:
	// Called when the game starts or when spawned
	//游戏开始调用的方法
	virtual void BeginPlay() override;
	//重写伤害的方法
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
};
