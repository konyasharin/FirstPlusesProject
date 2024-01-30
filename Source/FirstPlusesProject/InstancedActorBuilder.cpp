// Fill out your copyright notice in the Description page of Project Settings.


#include "InstancedActorBuilder.h"

// Sets default values
AInstancedActorBuilder::AInstancedActorBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseInstancedMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseInstancedMesh);
}

// Called when the game starts or when spawned
void AInstancedActorBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInstancedActorBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#if WITH_EDITOR
void AInstancedActorBuilder::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if(PropertyChangedEvent.Property != nullptr)
	{
		FName const PropertyName = PropertyChangedEvent.Property->GetFName();
		if(PropertyName == GET_MEMBER_NAME_CHECKED(AInstancedActorBuilder, CountX) ||
			PropertyName == GET_MEMBER_NAME_CHECKED(AInstancedActorBuilder, CountY) ||
			PropertyName == GET_MEMBER_NAME_CHECKED(AInstancedActorBuilder, XAmplitude) ||
			PropertyName == GET_MEMBER_NAME_CHECKED(AInstancedActorBuilder, YAmplitude))
		{
			CreateInstances();
		}
	}
}

void AInstancedActorBuilder::PostRegisterAllComponents()
{
	Super::PostRegisterAllComponents();
	CreateInstances();
}

#endif

void AInstancedActorBuilder::CreateInstances() const
{
	BaseInstancedMesh->ClearInstances();
	FVector const BaseInstancedMeshLocation = BaseInstancedMesh->GetComponentLocation();
	
	for(int i = 0; i < CountX; i++)
	{
		for(int j = 0; j < CountY; j++)
		{
			FTransform CurrentTransform = FTransform(FVector(BaseInstancedMeshLocation.X + XAmplitude * i,
				BaseInstancedMeshLocation.Y + YAmplitude * j, BaseInstancedMeshLocation.Z));
			CurrentTransform.SetRotation(BaseInstancedMesh->GetComponentRotation().Quaternion());
			BaseInstancedMesh->AddInstance(CurrentTransform, true);
		}
	}
}


