// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB02/FacadeShip.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFacadeShip() {}
// Cross Module References
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AFacadeShip_NoRegister();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AFacadeShip();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB02();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AShipRager_NoRegister();
// End Cross Module References
	void AFacadeShip::StaticRegisterNativesAFacadeShip()
	{
	}
	UClass* Z_Construct_UClass_AFacadeShip_NoRegister()
	{
		return AFacadeShip::StaticClass();
	}
	struct Z_Construct_UClass_AFacadeShip_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShipRager_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShipRager;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFacadeShip_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB02,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFacadeShip_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FacadeShip.h" },
		{ "ModuleRelativePath", "FacadeShip.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFacadeShip_Statics::NewProp_ShipRager_MetaData[] = {
		{ "Category", "Ships" },
		{ "ModuleRelativePath", "FacadeShip.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFacadeShip_Statics::NewProp_ShipRager = { "ShipRager", nullptr, (EPropertyFlags)0x0020080000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFacadeShip, ShipRager), Z_Construct_UClass_AShipRager_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFacadeShip_Statics::NewProp_ShipRager_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFacadeShip_Statics::NewProp_ShipRager_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFacadeShip_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFacadeShip_Statics::NewProp_ShipRager,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFacadeShip_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFacadeShip>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFacadeShip_Statics::ClassParams = {
		&AFacadeShip::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFacadeShip_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFacadeShip_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFacadeShip_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFacadeShip_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFacadeShip()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFacadeShip_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFacadeShip, 1906205658);
	template<> GALAGA_USFX_LAB02_API UClass* StaticClass<AFacadeShip>()
	{
		return AFacadeShip::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFacadeShip(Z_Construct_UClass_AFacadeShip, &AFacadeShip::StaticClass, TEXT("/Script/Galaga_USFX_LAB02"), TEXT("AFacadeShip"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFacadeShip);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
