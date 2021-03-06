#pragma once

#include "Components/ActorComponent.h"

#include "EzEase.h"
#include "EzPeriodicAnimationComponent.h"

#include "EzEaseVectorAnimationComponent.generated.h"

class UEzAnimationFunctionLibrary;

UCLASS( ClassGroup=(Custom) )
class EZANIMPLUGIN_API UEzEaseVectorAnimationComponent : public UEzPeriodicAnimationComponent {
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	
	UEzEaseVectorAnimationComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetStartAndEndValue(const FVector &start, const FVector &end);
	inline FVector GetEaseValue() const;

private:
	// 미리 설정된 값이 BeginPlay에서 덮어씌워지는걸 방지한다.
	void FreezeStartValue();

private:
	UPROPERTY(EditAnywhere, Category = "EzAnim_Easing")
	bool useCurve;

	UPROPERTY(EditAnywhere, Category = "EzAnim_Easing", meta = (EditCondition = "useCurve"))
	UCurveVector *curve;

	UPROPERTY(EditAnywhere, Category = "EzAnim_Easing", meta = (EditCondition = "!useCurve"))
	TEnumAsByte<EzEaseType> easeType;

	FVector startValue, deltaValue;

	bool frozen;
};
