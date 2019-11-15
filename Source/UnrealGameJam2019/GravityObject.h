// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GravityObject.generated.h"

UCLASS()
class UNREALGAMEJAM2019_API AGravityObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGravityObject();
	UPROPERTY(EditInstanceOnly, Category = "Components")
		float forcePower;

protected:

	/* Mesh of the inner sphere*/
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		USphereComponent* InnerSphereComp;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		USphereComponent* GravitySphereComp;
	UFUNCTION()
		void OverlapInnerSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
