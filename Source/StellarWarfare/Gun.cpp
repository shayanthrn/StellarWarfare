// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DamageEvents.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(FireParticle, Mesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));
	FVector ViewLocation;
	FRotator ViewRotation;
	Cast<APawn>(GetOwner())->GetController()->GetPlayerViewPoint(ViewLocation,ViewRotation);
	FVector End = ViewLocation + ViewRotation.Vector() * MaxRange;
	FHitResult hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	bool sucess = GetWorld()->LineTraceSingleByChannel(hit,ViewLocation,End,ECollisionChannel::ECC_GameTraceChannel1,Params);
	if(sucess){
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactParticle,hit.ImpactPoint);
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, hit.Location);
		AActor* HitActor = hit.GetActor();
		if (HitActor)
		{
			FPointDamageEvent DamageEvent = FPointDamageEvent(DamageAmount, hit, -ViewRotation.Vector(), nullptr);
			HitActor->TakeDamage(DamageAmount, DamageEvent, Cast<APawn>(GetOwner())->GetController(), this);
		}

	}
}

