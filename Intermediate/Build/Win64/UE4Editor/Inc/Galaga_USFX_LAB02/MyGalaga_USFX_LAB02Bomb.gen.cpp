// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB02/MyGalaga_USFX_LAB02Bomb.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyGalaga_USFX_LAB02Bomb() {}
// Cross Module References
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb_NoRegister();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AGalaga_USFX_LAB02Projectile();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB02();
// End Cross Module References
	void AMyGalaga_USFX_LAB02Bomb::StaticRegisterNativesAMyGalaga_USFX_LAB02Bomb()
	{
	}
	UClass* Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb_NoRegister()
	{
		return AMyGalaga_USFX_LAB02Bomb::StaticClass();
	}
	struct Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGalaga_USFX_LAB02Projectile,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB02,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MyGalaga_USFX_LAB02Bomb.h" },
		{ "ModuleRelativePath", "MyGalaga_USFX_LAB02Bomb.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyGalaga_USFX_LAB02Bomb>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb_Statics::ClassParams = {
		&AMyGalaga_USFX_LAB02Bomb::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyGalaga_USFX_LAB02Bomb, 3389924141);
	template<> GALAGA_USFX_LAB02_API UClass* StaticClass<AMyGalaga_USFX_LAB02Bomb>()
	{
		return AMyGalaga_USFX_LAB02Bomb::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyGalaga_USFX_LAB02Bomb(Z_Construct_UClass_AMyGalaga_USFX_LAB02Bomb, &AMyGalaga_USFX_LAB02Bomb::StaticClass, TEXT("/Script/Galaga_USFX_LAB02"), TEXT("AMyGalaga_USFX_LAB02Bomb"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyGalaga_USFX_LAB02Bomb);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
