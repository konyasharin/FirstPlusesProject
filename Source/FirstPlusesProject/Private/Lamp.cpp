// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPlusesProject/Public/Lamp.h"

// Sets default values
ALamp::ALamp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("LampStaticMesh");
	SetRootComponent(StaticMeshComponent);
	PointLightComponent = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	PointLightComponent->SetupAttachment(StaticMeshComponent);
}

// Called when the game starts or when spawned
void ALamp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALamp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



