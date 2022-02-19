// © 2022 KITATUS and Friends LTD. All Rights Reserved.

#include "Example02/UW_CoinWidget_Base.h"

#include "Components/TextBlock.h"
#include "Example02/AKF_Pickup.h"
#include "Kismet/GameplayStatics.h"

void UUW_CoinWidget_Base::NativeConstruct()
{
	Super::NativeConstruct();
	
	TArray<AActor*> FoundCoins;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAKF_Pickup::StaticClass(), FoundCoins);

	for(int i = 0; i < FoundCoins.Num(); i++)
	{
		AAKF_Pickup* TempCoin = Cast<AAKF_Pickup>(FoundCoins[i]);
		TempCoin->OnCoinPickup.AddDynamic(this, &UUW_CoinWidget_Base::CoinCollected);
	}
	
}

void UUW_CoinWidget_Base::CoinCollected()
{
	iCoinAmount += 1;
	Txt_CoinCounter->SetText(FText::AsNumber(iCoinAmount));
}
