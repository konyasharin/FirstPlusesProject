// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPlusesProject/Public/ActivatingLamp.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

AActivatingLamp::AActivatingLamp()
{
	TimelineComponent = CreateDefaultSubobject<UTimelineComponent>("TimelineComponent");
	AudioComponent = CreateDefaultSubobject<UAudioComponent>("AudioComponent");
	AudioComponent->SetupAttachment(GetRootComponent());
	AudioComponent->SetPaused(true);
}


void AActivatingLamp::BeginPlay()
{
	Super::BeginPlay();
	FOnTimelineFloat TimelineTickDelegate;
	TimelineTickDelegate.BindUFunction(this, "OnTimelineTick");
	TimelineComponent->AddInterpFloat(CurveFloat, TimelineTickDelegate);
	PointLightComponent->SetIntensity(0);
}


bool AActivatingLamp::CheckActivate() const
{
	float const Distance = FVector::Distance(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)
		->GetActorLocation(), GetActorLocation());
	if(Distance < ActivateDistance)
	{
		return true;
	}
	return false;
}

void AActivatingLamp::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(CheckActivate())
	{
		TimelineComponent->Play();
	}
}

void AActivatingLamp::OnTimelineTick(float const Output)
{
	if(!IsActivated)
	{
		UGameplayStatics::PlaySoundAtLocation(this, TurnOnSound, GetActorLocation());
		IsActivated = true;
		AudioComponent->SetPaused(false);
	}
	PointLightComponent->SetIntensity(FMath::Lerp(0, MaxIntensity, Output));
}


