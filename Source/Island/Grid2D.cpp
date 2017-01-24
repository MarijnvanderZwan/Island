// Fill out your copyright notice in the Description page of Project Settings.

#include "Island.h"
#include "Grid2D.h"


// Sets default values for this component's properties
UGrid2D::UGrid2D()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrid2D::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrid2D::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

