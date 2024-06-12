// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB02/CommandUndo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCommandUndo() {}
// Cross Module References
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_ACommandUndo_NoRegister();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_ACommandUndo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB02();
// End Cross Module References
	void ACommandUndo::StaticRegisterNativesACommandUndo()
	{
	}
	UClass* Z_Construct_UClass_ACommandUndo_NoRegister()
	{
		return ACommandUndo::StaticClass();
	}
	struct Z_Construct_UClass_ACommandUndo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACommandUndo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB02,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACommandUndo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CommandUndo.h" },
		{ "ModuleRelativePath", "CommandUndo.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACommandUndo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACommandUndo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACommandUndo_Statics::ClassParams = {
		&ACommandUndo::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACommandUndo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACommandUndo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACommandUndo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACommandUndo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACommandUndo, 1884347528);
	template<> GALAGA_USFX_LAB02_API UClass* StaticClass<ACommandUndo>()
	{
		return ACommandUndo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACommandUndo(Z_Construct_UClass_ACommandUndo, &ACommandUndo::StaticClass, TEXT("/Script/Galaga_USFX_LAB02"), TEXT("ACommandUndo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACommandUndo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
