#include "MyGalaga_USFX_LAB02Bomb.h"
#include "Galaga_USFX_LAB02Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "UObject/ConstructorHelpers.h"




//AMyGalaga_USFX_LAB02Bomb::AMyGalaga_USFX_LAB02Bomb()
//{
//	static ConstructorHelpers::FObjectFinder<UStaticMesh> BombMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile_3.TwinStickProjectile_3'")); 
//	ProjectileMesh->SetStaticMesh(BombMesh.Object);    
//	SetActorScale3D(FVector(3.0, 3.0f, 3.0f)); 
//	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
//	ProjectileMesh->OnComponentHit.AddDynamic(this, &AMyGalaga_USFX_LAB02Bomb::OnHit);   
//
//	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));    
//	ProjectileMovement->InitialSpeed = 3000.0f;
//	ProjectileMovement->MaxSpeed = 2000.0f;
//	ProjectileMovement->bRotationFollowsVelocity = true;//
//	ProjectileMovement->bShouldBounce = false;//
//	ProjectileMovement->ProjectileGravityScale = 0.0f; // No gravity
//}
//
//void AMyGalaga_USFX_LAB02Bomb::FireInDirection(const FVector& ShootDirection)
//{
//	ProjectileMovement->Velocity = GetActorForwardVector() * ProjectileMovement->InitialSpeed;
//}
//
//void AMyGalaga_USFX_LAB02Bomb::FireBomb()
//{
//	FVector NewLocation = GetActorLocation() + GetActorForwardVector() * 300.0f; 
//	SetActorLocation(NewLocation); 
//}

