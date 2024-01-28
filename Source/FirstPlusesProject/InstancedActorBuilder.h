// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "InstancedActorBuilder.generated.h"

UCLASS()
class FIRSTPLUSESPROJECT_API AInstancedActorBuilder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInstancedActorBuilder();
	UPROPERTY(EditAnywhere)
	int8 CountX = 1;
	UPROPERTY(EditAnywhere)
	int8 CountY = 1;
	UPROPERTY(EditAnywhere)
	UInstancedStaticMeshComponent* BaseInstancedMesh;
	UPROPERTY(EditAnywhere)
	int32 XAmplitude = 400;
	UPROPERTY(EditAnywhere)
	int32 YAmplitude = 400;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void CreateInstances() const;
	#if WITH_EDITOR
		virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
		virtual void PostRegisterAllComponents() override;
	#endif
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
