// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB02/IBuilderMotherShip.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIBuilderMotherShip() {}
// Cross Module References
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_UIBuilderMotherShip_NoRegister();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_UIBuilderMotherShip();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB02();
// End Cross Module References
	void UIBuilderMotherShip::StaticRegisterNativesUIBuilderMotherShip()
	{
	}
	UClass* Z_Construct_UClass_UIBuilderMotherShip_NoRegister()
	{
		return UIBuilderMotherShip::StaticClass();
	}
	struct Z_Construct_UClass_UIBuilderMotherShip_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UIBuilderMotherShip_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB02,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIBuilderMotherShip_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "IBuilderMotherShip.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UIBuilderMotherShip_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IIBuilderMotherShip>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UIBuilderMotherShip_Statics::ClassParams = {
		&UIBuilderMotherShip::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UIBuilderMotherShip_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UIBuilderMotherShip_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UIBuilderMotherShip()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UIBuilderMotherShip_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIBuilderMotherShip, 578073780);
	template<> GALAGA_USFX_LAB02_API UClass* StaticClass<UIBuilderMotherShip>()
	{
		return UIBuilderMotherShip::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIBuilderMotherShip(Z_Construct_UClass_UIBuilderMotherShip, &UIBuilderMotherShip::StaticClass, TEXT("/Script/Galaga_USFX_LAB02"), TEXT("UIBuilderMotherShip"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIBuilderMotherShip);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
