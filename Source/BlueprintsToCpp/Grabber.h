// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Grabber.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class BLUEPRINTSTOCPP_API UGrabber : public USceneComponent
{
  GENERATED_BODY()

public:
  // Sets default values for this component's properties
  UGrabber();

protected:
  // Called when the game starts
  virtual void BeginPlay() override;
  UFUNCTION(BlueprintCallable, BlueprintPure)
  FVector GetMaxGrabLocation() const;

  UFUNCTION(BlueprintCallable, BlueprintPure)
  FVector GetHoldLocation() const;

  UFUNCTION(BlueprintCallable, BlueprintPure)
  UPhysicsHandleComponent* GetPhysicsComponent() const;

  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
  void NotifyQuestActor(AActor* Actor);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  bool TraceForPhysicsBodies(AActor*& HitActor, UPrimitiveComponent*& HitComponent);

public:
  // Called every frame
  virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float MaxGrabDistance = 100.f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float HoldDistance = 100.f;


};
