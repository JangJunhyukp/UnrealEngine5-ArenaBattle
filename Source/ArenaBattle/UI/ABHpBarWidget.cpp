// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABHpBarWidget.h"
#include "Components/ProgressBar.h"
#include "Interface/ABCharacterWidgetInterface.h"

UABHpBarWidget::UABHpBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    MaxHp = -1.0f;
}

void UABHpBarWidget::NativeConstruct()
{
    Super::NativeConstruct();

    HpProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PbHpBar")));
    ensure(HpProgressBar);

    IABCharacterWidgetInterface* CharacterWidget = Cast<IABCharacterWidgetInterface>(OwningActor);
    if (CharacterWidget)
    {
        CharacterWidget->SetupCharacterWidget(this);
    }
}

void UABHpBarWidget::UpdateHpBar(float NewCurrentHp)
{
    ensure(MaxHp > 0.0f);
    if (HpProgressBar)
    {
        // 빌드설정에서 UMG 모듈을 추가해야함, ProgressBar의 현재 값을 설정하는 함수.
        HpProgressBar->SetPercent(NewCurrentHp / MaxHp);
    }
}
