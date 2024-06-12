// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB02/JuniorShip.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJuniorShip() {}
// Cross Module References
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AJuniorShip_NoRegister();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AJuniorShip();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB02();
// End Cross Module References
	void AJuniorShip::StaticRegisterNativesAJuniorShip()
	{
	}
	UClass* Z_Construct_UClass_AJuniorShip_NoRegister()
	{
		return AJuniorShip::StaticClass();
	}
	struct Z_Construct_UClass_AJuniorShip_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AJuniorShip_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB02,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AJuniorShip_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "JuniorShip.h" },
		{ "ModuleRelativePath", "JuniorShip.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AJuniorShip_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJuniorShip>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AJuniorShip_Statics::ClassParams = {
		&AJuniorShip::StaticClass,
		"Game",
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
		METADATA_PARAMS(Z_Construct_UClass_AJuniorShip_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AJuniorShip_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AJuniorShip()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AJuniorShip_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AJuniorShip, 2545985769);
	template<> GALAGA_USFX_LAB02_API UClass* StaticClass<AJuniorShip>()
	{
		return AJuniorShip::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AJuniorShip(Z_Construct_UClass_AJuniorShip, &AJuniorShip::StaticClass, TEXT("/Script/Galaga_USFX_LAB02"), TEXT("AJuniorShip"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AJuniorShip);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
