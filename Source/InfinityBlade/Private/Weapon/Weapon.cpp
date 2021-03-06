﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Weapon.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	WeaponComponent = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponComponent");
	//WeaponComponent->SetupAttachment(RootComponent);
	SetRootComponent(WeaponComponent);
	CapsuleComponent = CreateDefaultSubobject <UCapsuleComponent>("CapsuleComponent");
	CapsuleComponent->SetupAttachment(WeaponComponent);
}


