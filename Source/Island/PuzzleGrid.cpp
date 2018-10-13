// Fill out your copyright notice in the Description page of Project Settings.

#include "Island.h"
#include "PuzzleGrid.h"


// Sets default values
APuzzleGrid::APuzzleGrid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APuzzleGrid::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APuzzleGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuzzleGrid::InitializeWithSize(int width, int height)
{
	Cells = new int*[width];
	for (int i = 0; i < width; i++)
		Cells[i] = new int[height];


	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
		{
			Cells[i][j] = 0;
		}

	Width = width;
	Height = height;
}

void APuzzleGrid::AddPushableBlock(int x, int y)
{
	if (!IsValidCell(x, y)) return;

	Cells[x][y] = 1;
}

void APuzzleGrid::AddObstacle(int x, int y)
{
	if (!IsValidCell(x, y)) return;

	Cells[x][y] = 2;
}

void APuzzleGrid::AddGoal(int x, int y)
{
	if (!IsValidCell(x, y)) return;

	Cells[x][y] = -1;
}

FVector APuzzleGrid::PushBlockInDirection(int x, int y, int xDir, int yDir)
{
	if (!IsValidCell(x, y)) return FVector(-1, -1, 0);

	Cells[x][y] = 0;
	while (IsValidMove(x + xDir, y + yDir))
	{
		x += xDir;
		y += yDir;
	}

	Cells[x][y] = 1;

	return FVector(x, y, 0);
}

bool APuzzleGrid::IsValidCell(int x, int y)
{
	return x >= 0 && x < Width && y >= 0 && y < Height;
}

bool APuzzleGrid::IsValidMove(int x, int y)
{
	return IsValidCell(x, y) && Cells[x][y] <= 0;
}