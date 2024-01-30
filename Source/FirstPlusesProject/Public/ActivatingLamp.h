// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Lamp.h"
#include "Components/TimelineComponent.h"
#include "Components/AudioComponent.h"
#include "ActivatingLamp.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPLUSESPROJECT_API AActivatingLamp : public ALamp
{
	GENERATED_BODY()
	
public:
	AActivatingLamp();
	UPROPERTY(EditAnywhere)
	float ActivateDistance = 600;
	virtual void Tick(float DeltaSeconds) override;
	UPROPERTY(EditAnywhere)
	float MaxIntensity = 5000;

protected:
	bool CheckActivate() const;
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
	UTimelineComponent* TimelineComponent;
	UPROPERTY(EditAnywhere)
	UCurveFloat* CurveFloat;
	UFUNCTION(BlueprintCallable)
	void OnTimelineTick(float Output);
	bool IsActivated = false;
	UPROPERTY(EditAnywhere)
	UAudioComponent* AudioComponent;
	UPROPERTY(EditAnywhere)
	USoundBase* TurnOnSound;
};
