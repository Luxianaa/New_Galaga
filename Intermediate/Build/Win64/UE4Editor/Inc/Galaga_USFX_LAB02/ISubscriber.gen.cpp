// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB02/ISubscriber.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeISubscriber() {}
// Cross Module References
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_UISubscriber_NoRegister();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_UISubscriber();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB02();
// End Cross Module References
	void UISubscriber::StaticRegisterNativesUISubscriber()
	{
	}
	UClass* Z_Construct_UClass_UISubscriber_NoRegister()
	{
		return UISubscriber::StaticClass();
	}
	struct Z_Construct_UClass_UISubscriber_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UISubscriber_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB02,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UISubscriber_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "ISubscriber.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UISubscriber_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IISubscriber>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UISubscriber_Statics::ClassParams = {
		&UISubscriber::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UISubscriber_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UISubscriber_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UISubscriber()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UISubscriber_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UISubscriber, 3363139815);
	template<> GALAGA_USFX_LAB02_API UClass* StaticClass<UISubscriber>()
	{
		return UISubscriber::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UISubscriber(Z_Construct_UClass_UISubscriber, &UISubscriber::StaticClass, TEXT("/Script/Galaga_USFX_LAB02"), TEXT("UISubscriber"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UISubscriber);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
