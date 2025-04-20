// Developed by Neko


#include "Utilities/UtilitiesLibrary.h"
#include "Grid/TileData.h"

FVector UUtilitiesLibrary::SnapVectorToVector(FVector A, FVector B)
{
	float X = FMath::GridSnap(A.X, B.X);
	float Y = FMath::GridSnap(A.Y, B.Y);
	float Z = FMath::GridSnap(A.Z, B.Z);

	return FVector(X, Y, Z);
}

FVector UUtilitiesLibrary::GetColorByTileType(ETileType TileType)
{
	switch (TileType) {
	case ETileType::None:
		return FVector(0, 0, 0);;
	case ETileType::Normal:
		return FVector(0.058, 1, 0.91);
	case ETileType::Obstacle:
		return FVector(1, 0, 0);
	}
	return FVector(0, 0, 0);
}

bool UUtilitiesLibrary::IsTileTypeWalkable(ETileType InTileType)
{
	if (InTileType == ETileType::None || InTileType == ETileType::Obstacle) return false;
	return true;
}
