// © 2022 KITATUS and Friends LTD. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AKF_Pickup.generated.h"

class USphereComponent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FKFOnCoinPickup);

// Another example of a delegate using an Actor reference
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FKFOnActorCoinPickup, AActor*, ActorRef);

UCLASS()
class KFEVENTDISPATCHERS_API AAKF_Pickup : public AActor
{
	GENERATED_BODY()
public:	
	AAKF_Pickup();

	UPROPERTY(BlueprintAssignable)
	FKFOnCoinPickup OnCoinPickup;

	// Another example of a delegate using an Actor reference
	//UPROPERTY(BlueprintAssignable)
	//FKFOnActorCoinPickup OnActorCoinPickup;

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	USphereComponent* SphereComp;
	
	UPROPERTY(EditAnywhere, Category="Changeables")
	UStaticMeshComponent* MeshComp;

	UFUNCTION(BlueprintNativeEvent, Category="Overlap")
	void OverlapStarted(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
};
