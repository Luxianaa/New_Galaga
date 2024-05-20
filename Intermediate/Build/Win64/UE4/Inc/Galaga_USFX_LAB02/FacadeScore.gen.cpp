// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB02/FacadeScore.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFacadeScore() {}
// Cross Module References
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AFacadeScore_NoRegister();
	GALAGA_USFX_LAB02_API UClass* Z_Construct_UClass_AFacadeScore();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB02();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AFacadeScore::execColisionar)
	{
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Colisionar(Z_Param_OtherActor);
		P_NATIVE_END;
	}
	void AFacadeScore::StaticRegisterNativesAFacadeScore()
	{
		UClass* Class = AFacadeScore::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Colisionar", &AFacadeScore::execColisionar },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFacadeScore_Colisionar_Statics
	{
		struct FacadeScore_eventColisionar_Parms
		{
			AActor* OtherActor;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFacadeScore_Colisionar_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FacadeScore_eventColisionar_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFacadeScore_Colisionar_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFacadeScore_Colisionar_Statics::NewProp_OtherActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFacadeScore_Colisionar_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);\n" },
		{ "ModuleRelativePath", "FacadeScore.h" },
		{ "ToolTip", "void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFacadeScore_Colisionar_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFacadeScore, nullptr, "Colisionar", nullptr, nullptr, sizeof(FacadeScore_eventColisionar_Parms), Z_Construct_UFunction_AFacadeScore_Colisionar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFacadeScore_Colisionar_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFacadeScore_Colisionar_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFacadeScore_Colisionar_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFacadeScore_Colisionar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFacadeScore_Colisionar_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFacadeScore_NoRegister()
	{
		return AFacadeScore::StaticClass();
	}
	struct Z_Construct_UClass_AFacadeScore_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFacadeScore_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB02,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFacadeScore_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFacadeScore_Colisionar, "Colisionar" }, // 1660039720
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFacadeScore_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FacadeScore.h" },
		{ "ModuleRelativePath", "FacadeScore.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFacadeScore_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFacadeScore>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFacadeScore_Statics::ClassParams = {
		&AFacadeScore::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFacadeScore_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFacadeScore_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFacadeScore()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFacadeScore_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFacadeScore, 448318077);
	template<> GALAGA_USFX_LAB02_API UClass* StaticClass<AFacadeScore>()
	{
		return AFacadeScore::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFacadeScore(Z_Construct_UClass_AFacadeScore, &AFacadeScore::StaticClass, TEXT("/Script/Galaga_USFX_LAB02"), TEXT("AFacadeScore"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFacadeScore);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
