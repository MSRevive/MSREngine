//========= Copyright � 1996-2008, Valve LLC, All rights reserved. ============
//
// Purpose:
//
//=============================================================================

#ifndef STEAMTYPES_H
#define STEAMTYPES_H
#ifdef _WIN32
#pragma once
#endif

#define S_CALLTYPE __cdecl

// Steam-specific types. Defined here so this header file can be included in other code bases.
#ifndef WCHARTYPES_H
typedef unsigned char uint8;
#endif

#if defined( __GNUC__ ) && !defined(POSIX)
	#if __GNUC__ < 4
		#error "Steamworks requires GCC 4.X (4.2 or 4.4 have been tested)"
	#endif
	#define POSIX 1
#endif

#if defined(__x86_64__) || defined(_WIN64)
#define X64BITS
#endif

// Make sure VALVE_BIG_ENDIAN gets set on PS3, may already be set previously in Valve internal code.
#if !defined(VALVE_BIG_ENDIAN) && defined(_PS3)
#define VALVE_BIG_ENDIAN
#endif

#ifdef API_GEN
# define CLANG_ATTR(ATTR) __attribute__((annotate( ATTR )))
#else
# define CLANG_ATTR(ATTR)
#endif

#define METHOD_DESC(DESC) CLANG_ATTR( "desc:" #DESC ";" )
#define IGNOREATTR() CLANG_ATTR( "ignore" )
#define OUT_STRUCT() CLANG_ATTR( "out_struct: ;" )
#define OUT_STRING() CLANG_ATTR( "out_string: ;" )
#define OUT_ARRAY_CALL(COUNTER,FUNCTION,PARAMS) CLANG_ATTR( "out_array_call:" #COUNTER "," #FUNCTION "," #PARAMS ";" )
#define OUT_ARRAY_COUNT(COUNTER, DESC) CLANG_ATTR( "out_array_count:" #COUNTER  ";desc:" #DESC )
#define ARRAY_COUNT(COUNTER) CLANG_ATTR( "array_count:" #COUNTER ";" )
#define ARRAY_COUNT_D(COUNTER, DESC) CLANG_ATTR( "array_count:" #COUNTER ";desc:" #DESC )
#define BUFFER_COUNT(COUNTER) CLANG_ATTR( "buffer_count:" #COUNTER ";" )
#define OUT_BUFFER_COUNT(COUNTER) CLANG_ATTR( "out_buffer_count:" #COUNTER ";" )
#define OUT_STRING_COUNT(COUNTER) CLANG_ATTR( "out_string_count:" #COUNTER ";" )
#define DESC(DESC) CLANG_ATTR("desc:" #DESC ";")
#define CALL_RESULT(RESULT_TYPE) CLANG_ATTR("callresult:" #RESULT_TYPE ";")
#define CALL_BACK(RESULT_TYPE) CLANG_ATTR("callback:" #RESULT_TYPE ";")

const int k_cubSaltSize   = 8;
typedef	uint8 Salt_t[ k_cubSaltSize ];

//-----------------------------------------------------------------------------
// GID (GlobalID) stuff
// This is a globally unique identifier.  It's guaranteed to be unique across all
// racks and servers for as long as a given universe persists.
//-----------------------------------------------------------------------------
// NOTE: for GID parsing/rendering and other utils, see gid.h
typedef uint64 GID_t;

const GID_t k_GIDNil = 0xffffffffffffffffull;

// For convenience, we define a number of types that are just new names for GIDs
typedef uint64 JobID_t;			// Each Job has a unique ID
typedef GID_t TxnID_t;			// Each financial transaction has a unique ID

const GID_t k_TxnIDNil = k_GIDNil;
const GID_t k_TxnIDUnknown = 0;

const JobID_t k_JobIDNil = 0xffffffffffffffffull;

// this is baked into client messages and interfaces as an int, 
// make sure we never break this.
typedef uint32 PackageId_t;
const PackageId_t k_uPackageIdFreeSub = 0x0;
const PackageId_t k_uPackageIdInvalid = 0xFFFFFFFF;

typedef uint32 BundleId_t;
const BundleId_t k_uBundleIdInvalid = 0;

// this is baked into client messages and interfaces as an int, 
// make sure we never break this.
typedef uint32 AppId_t;
const AppId_t k_uAppIdInvalid = 0x0;

typedef uint64 AssetClassId_t;
const AssetClassId_t k_ulAssetClassIdInvalid = 0x0;

typedef uint32 PhysicalItemId_t;
const PhysicalItemId_t k_uPhysicalItemIdInvalid = 0x0;


// this is baked into client messages and interfaces as an int, 
// make sure we never break this.  AppIds and DepotIDs also presently
// share the same namespace, but since we'd like to change that in the future
// I've defined it seperately here.
typedef uint32 DepotId_t;
const DepotId_t k_uDepotIdInvalid = 0x0;

// RTime32
// We use this 32 bit time representing real world time.
// It offers 1 second resolution beginning on January 1, 1970 (Unix time)
typedef uint32 RTime32;

typedef uint32 CellID_t;
const CellID_t k_uCellIDInvalid = 0xFFFFFFFF;

// handle to a Steam API call
typedef uint64 SteamAPICall_t;
const SteamAPICall_t k_uAPICallInvalid = 0x0;

typedef uint32 AccountID_t;

typedef uint32 PartnerId_t;
const PartnerId_t k_uPartnerIdInvalid = 0;

// ID for a depot content manifest
typedef uint64 ManifestId_t; 
const ManifestId_t k_uManifestIdInvalid = 0;



#endif // STEAMTYPES_H
