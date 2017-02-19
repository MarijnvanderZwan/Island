// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PuzzleGrid.generated.h"

UCLASS()
class ISLAND_API APuzzleGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzleGrid();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category="PuzzleGrid")
	void InitializeWithSize(int width, int height);

	UFUNCTION(BlueprintCallable, Category = "PuzzleGrid")
	void AddPushableBlock(int x, int y);

	UFUNCTION(BlueprintCallable, Category = "PuzzleGrid")
	void AddObstacle(int x, int y);

	UFUNCTION(BlueprintCallable, Category = "PuzzleGrid")
	void AddGoal(int x, int y);

	UFUNCTION(BlueprintCallable, Category = "PuzzleGrid")
	FVector PushBlockInDirection(int x, int y, int xDir, int yDir);

	bool IsValidCell(int x, int y);

	bool IsValidMove(int x, int y);


	int** Cells;
	int Width;
	int Height;
};
