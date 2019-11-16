// Fill out your copyright notice in the Description page of Project Settings.


#include "Cannon.h"
#include "..\Public\Cannon.h"

// Sets default values
ACannon::ACannon()
{


}

void ACannon::Fire()
{

}


// Called to bind functionality to input
void ACannon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &ACannon::AddControllerYawInput);


}

