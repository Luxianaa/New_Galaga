// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB02/CommandDestruction.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCommandDestruction() {}
// Cross Module References
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_ACommandDestruction_NoRegister();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_ACommandDestruction();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB02();
// End Cross Module References
	void ACommandDestruction::StaticRegisterNativesACommandDestruction()
	{
	}
	UClass* Z_Construct_UClass_ACommandDestruction_NoRegister()
	{
		return ACommandDestruction::StaticClass();
	}
	struct Z_Construct_UClass_ACommandDestruction_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACommandDestruction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB02,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACommandDestruction_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CommandDestruction.h" },
		{ "ModuleRelativePath", "CommandDestruction.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACommandDestruction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACommandDestruction>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACommandDestruction_Statics::ClassParams = {
		&ACommandDestruction::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACommandDestruction_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACommandDestruction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACommandDestruction()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACommandDestruction_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACommandDestruction, 2963695876);
	template<> GALAGA_USFX_LAB02_API UClass* StaticClass<ACommandDestruction>()
	{
		return ACommandDestruction::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACommandDestruction(Z_Construct_UClass_ACommandDestruction, &ACommandDestruction::StaticClass, TEXT("/Script/Galaga_USFX_LAB02"), TEXT("ACommandDestruction"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACommandDestruction);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
