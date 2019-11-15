// Fill out your copyright notice in the Description page of Project Settings.


#include "GravityObject.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
// Sets default values
AGravityObject::AGravityObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	InnerSphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("InnerSphereComp"));
	InnerSphereComp->SetSphereRadius(100);
	InnerSphereComp->SetupAttachment(MeshComp);

	InnerSphereComp->OnComponentBeginOverlap.AddDynamic(this, &AGravityObject::OverlapInnerSphere);

	GravitySphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("OuterSphereComp"));
	GravitySphereComp->SetSphereRadius(3000);
	GravitySphereComp->SetupAttachment(MeshComp);

}
void AGravityObject::OverlapInnerSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	/*Handle what ever happen iof a certain object hit the inner cylinder of the planet/asteroid*/
}

// Called every frame
void AGravityObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TArray<UPrimitiveComponent*> OverlappingComps;
	GravitySphereComp->GetOverlappingComponents(OverlappingComps);
	for (int32 i = 0; i < OverlappingComps.Num(); i++)
	{
		UPrimitiveComponent* PrimComp = OverlappingComps[i];
		if (PrimComp && PrimComp->IsSimulatingPhysics()) {
			const float SphereRadius = GravitySphereComp->GetScaledSphereRadius();
			const float ForceStrength = forcePower;
			PrimComp->AddRadialForce(GetActorLocation(), SphereRadius, ForceStrength, ERadialImpulseFalloff::RIF_Constant, true);
			PrimComp->AddForce(FVector(-1000, 0, 0), FName(), true);
		}
	}
}

