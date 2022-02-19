// © 2022 KITATUS and Friends LTD. All Rights Reserved.

#include "Example02/AKF_Pickup.h"
#include "Components/SphereComponent.h"

AAKF_Pickup::AAKF_Pickup()
{
	PrimaryActorTick.bCanEverTick = false;
	SphereComp = CreateDefaultSubobject<USphereComponent>(FName("SphereComp"));
	SphereComp->InitSphereRadius(50.0f);
	SetRootComponent(SphereComp);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshComp"));
	MeshComp->SetupAttachment(SphereComp);
}

void AAKF_Pickup::BeginPlay()
{
	Super::BeginPlay();
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AAKF_Pickup::OverlapStarted);
}

void AAKF_Pickup::OverlapStarted_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnCoinPickup.Broadcast();
	
	// Another example of a delegate using an Actor reference
	// OnActorCoinPickup.Broadcast(OtherActor);
	
	Destroy();
}
