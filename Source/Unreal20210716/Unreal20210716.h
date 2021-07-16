// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(BC, Log, All);
#define BCLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define BCLOG_S(Verbosity) UE_LOG(BC, Verbosity, TEXT("%s"), *BCLOG_CALLINFO)
#define BCLOG(Verbosity, Format, ...) UE_LOG(BC, Verbosity, TEXT("%s %s"), *BCLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))