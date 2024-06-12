// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB02/IBallAdapter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIBallAdapter() {}
// Cross Module References
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_UIBallAdapter_NoRegister();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_UIBallAdapter();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB02();
// End Cross Module References
	void UIBallAdapter::StaticRegisterNativesUIBallAdapter()
	{
	}
	UClass* Z_Construct_UClass_UIBallAdapter_NoRegister()
	{
		return UIBallAdapter::StaticClass();
	}
	struct Z_Construct_UClass_UIBallAdapter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UIBallAdapter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB02,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIBallAdapter_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "IBallAdapter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UIBallAdapter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IIBallAdapter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UIBallAdapter_Statics::ClassParams = {
		&UIBallAdapter::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UIBallAdapter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UIBallAdapter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UIBallAdapter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UIBallAdapter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIBallAdapter, 3079779382);
	template<> GALAGA_USFX_LAB02_API UClass* StaticClass<UIBallAdapter>()
	{
		return UIBallAdapter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIBallAdapter(Z_Construct_UClass_UIBallAdapter, &UIBallAdapter::StaticClass, TEXT("/Script/Galaga_USFX_LAB02"), TEXT("UIBallAdapter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIBallAdapter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
