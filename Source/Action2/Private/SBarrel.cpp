// Fill out your copyright notice in the Description page of Project Settings.


#include "SBarrel.h"

#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ASBarrel::ASBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	Mesh->SetSimulatePhysics(true);
	

	force = CreateDefaultSubobject<URadialForceComponent>("Force");
	force->SetupAttachment(Mesh);
	force->Radius = 600;
	force->AddObjectTypeToAffect(TEnumAsByte<EObjectTypeQuery>(ECollisionChannel::ECC_WorldDynamic));
	force->ImpulseStrength = 500;
	force->bImpulseVelChange = true;
	Mesh->OnComponentHit.AddDynamic(this,&ASBarrel::OnHit);
}

void ASBarrel::OnHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,FVector NormalImpulse, const FHitResult& Hit)
{
	force->FireImpulse();
	Other->Destroy();
}

// Called when the game starts or when spawned
void ASBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

