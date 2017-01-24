// Fill out your copyright notice in the Description page of Project Settings.

#include "Island.h"
#include "Grid.h"


// Sets default values for this component's properties
UGrid::UGrid()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrid::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrid::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UGrid::AddPushableBlock(FVector v)
{
	int x = (int)v.X;
	int y = (int)v.Y;
	Cells[x][y] = 1;
}

void UGrid::AddObstacle(FVector v)
{
	int x = (int)v.X;
	int y = (int)v.Y;
	Cells[x][y] = 2;
}

void UGrid::AddGoal(FVector v)
{
	int x = (int)v.X;
	int y = (int)v.Y;
	Cells[x][y] = -1;
}

FVector UGrid::PushBlockInDirection(FVector v, FVector dir)
{
	int x = (int)v.X;
	int y = (int)v.Y;	
	int xDir = (int)dir.X;
	int yDir = (int)dir.Y;
	Cells[x][y] = 0;
	while (isValidMove(x + xDir, y + yDir))
	{
		x += xDir;
		y += yDir;
	}

	Cells[x][y] = 1;
	return FVector(x, y, 0);
}

bool UGrid::IsValidCell(int x, int y)
{
	return x >= 0 && x < Width && y >= 0 && y < Height;
}

bool UGrid::isValidMove(int x, int y)
{
	return IsValidCell(x, y) && Cells[x][y] <= 0;
}

