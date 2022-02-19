// © 2022 KITATUS and Friends LTD. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_CoinWidget_Base.generated.h"

class UTextBlock;

UCLASS()
class KFEVENTDISPATCHERS_API UUW_CoinWidget_Base : public UUserWidget
{
	GENERATED_BODY()

protected:
	
	virtual void NativeConstruct() override;
	
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* Txt_CoinCounter = nullptr;

	UPROPERTY()
	int iCoinAmount;

	UFUNCTION()
	void CoinCollected();
	
};
