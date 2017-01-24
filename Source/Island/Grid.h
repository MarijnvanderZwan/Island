// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Grid.generated.h"


UCLASS()
class ISLAND_API UGrid : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrid();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	
};
