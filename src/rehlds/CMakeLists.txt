add_library(steam_api SHARED IMPORTED)
add_library(libacof32 SHARED IMPORTED)

target_include_directories(steam_api INTERFACE ${BASEDIR}/src/public/steam)

if (WIN32)
	set_target_properties(steam_api PROPERTIES IMPORTED_IMPLIB "${BASEDIR}/lib/public/steam_api.lib")
	set_target_properties(libacof32 PROPERTIES IMPORTED_IMPLIB "${BASEDIR}/lib/public/libacof32.lib")
else()
	set_target_properties(steam_api PROPERTIES IMPORTED_IMPLIB "${BASEDIR}/lib/public/linux/libsteam_api.so")
endif()

add_library(rehlds SHARED)

add_dependencies(rehlds
	bzip2
)

set_common_properties(rehlds)

target_link_libraries(rehlds PRIVATE
	$<$<PLATFORM_ID:Windows>:ws2_32>
	$<$<PLATFORM_ID:Windows>:psapi>
	$<$<PLATFORM_ID:Linux>:dl>
	$<$<PLATFORM_ID:Linux>:rt>
	$<$<PLATFORM_ID:Linux>:m>
	$<$<PLATFORM_ID:Linux>:aelf32>
	steam_api
	libacof32
)

# Include directories
target_include_directories(rehlds PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${BASEDIR}/src
	${BASEDIR}/src/common
	${BASEDIR}/src/engine
	${BASEDIR}/src/movement
	${BASEDIR}/src/public
	${BASEDIR}/src/public/rehlds
	${BASEDIR}/utils
)

target_compile_definitions(rehlds PRIVATE
	REHLDS_FIXES
	VERSION_SAFE_STEAM_API_INTERFACES
	REHLDS_SSE
	REHLDS_OPT_PEDANTIC
	REHLDS_SELF
	REHLDS_CHECKS
	HAVE_OPT_STRTOOLS
	DEDICATED
	SWDS
)

set_target_properties(rehlds PROPERTIES OUTPUT_NAME "swds")
if (UNIX)
	set_target_properties(rehlds PROPERTIES OUTPUT_NAME "engine_i486")
endif(UNIX)

################################################################################
# Source groups
################################################################################
set(Misc
	"../public/tier0/pointeroverride.asm"
)
source_group("Misc" FILES ${Misc})

set(Source_Files
	"engine.h"
	"main.cpp"
	"platform.cpp"
	"platform.h"
	"rehlds_interfaces_impl.cpp"
	"rehlds_interfaces_impl.h"
	"rehlds_security.cpp"
	"rehlds_security.h"
)
source_group("Source Files" FILES ${Source_Files})

set(Common
	"../common/BaseSystemModule.cpp"
	"../common/beamdef.h"
	"../common/cl_entity.h"
	"../common/com_model.h"
	"../common/con_nprint.h"
	"../common/const.h"
	"../common/crc.h"
	"../common/cvardef.h"
	"../common/demo_api.h"
	"../common/director_cmds.h"
	"../common/dlight.h"
	"../common/dll_state.h"
	"../common/entity_state.h"
	"../common/entity_types.h"
	"../common/enums.h"
	"../common/event_api.h"
	"../common/event_args.h"
	"../common/event_flags.h"
	"../common/hltv.h"
	"../common/IGameServerData.h"
	"../common/in_buttons.h"
	"../common/ivoicetweak.h"
	"../common/kbutton.h"
	"../common/mathlib.h"
	"../common/md5.h"
	"../common/net_api.h"
	"../common/netadr.h"
	"../common/nowin.h"
	"../common/ObjectList.cpp"
	"../common/parsemsg.h"
	"../common/particledef.h"
	"../common/pmtrace.h"
	"../common/port.h"
	"../common/qfont.h"
	"../common/qlimits.h"
	"../common/quakedef.h"
	"../common/r_efx.h"
	"../common/r_studioint.h"
	"../common/ref_params.h"
	"../common/screenfade.h"
	"../common/Sequence.h"
	"../common/SteamCommon.h"
	"../common/studio_event.h"
	"../common/TokenLine.cpp"
	"../common/triangleapi.h"
	"../common/usercmd.h"
	"../common/vmodes.h"
	"../common/weaponinfo.h"
	"../common/winsani_in.h"
	"../common/winsani_out.h"
)
source_group("Common" FILES ${Common})

set(Dlls
	"../dlls/activity.h"
	"../dlls/activitymap.h"
	"../dlls/animation.h"
	"../dlls/basemonster.h"
	"../dlls/cbase.h"
	"../dlls/cdll_dll.h"
	"../dlls/client.h"
	"../dlls/decals.h"
	"../dlls/doors.h"
	"../dlls/effects.h"
	"../dlls/enginecallback.h"
	"../dlls/explode.h"
	"../dlls/extdll.h"
	"../dlls/func_break.h"
	"../dlls/game.h"
	"../dlls/gamerules.h"
	"../dlls/hornet.h"
	"../dlls/items.h"
	"../dlls/maprules.h"
	"../dlls/monsterevent.h"
	"../dlls/monsters.h"
	"../dlls/nodes.h"
	"../dlls/plane.h"
	"../dlls/player.h"
	"../dlls/saverestore.h"
	"../dlls/schedule.h"
	"../dlls/scriptevent.h"
	"../dlls/skill.h"
	"../dlls/soundent.h"
	"../dlls/spectator.h"
	"../dlls/talkmonster.h"
	"../dlls/teamplay_gamerules.h"
	"../dlls/trains.h"
	"../dlls/util.h"
	"../dlls/vector.h"
	"../dlls/weapons.h"
)
source_group("Dlls" FILES ${Dlls})

set(Engine
	"../engine/mathlib.cpp"
	"../engine/mathlib_e.h"
	"../engine/mathlib_sse.cpp"
	"../engine/mathlib_sse.h"
	"../engine/public_amalgamation.cpp"
	"../engine/sse_mathfun.cpp"
	"../engine/sse_mathfun.h"
)
source_group("Engine" FILES ${Engine})

set(Engine_Client
	"../engine/APIProxy.h"
	"../engine/cdll_int.h"
	"../engine/client.h"
	"../engine/delta_packet.h"
	"../engine/sound.h"
)
source_group("Engine\\Client" FILES ${Engine_Client})

set(Engine_Common
	"../engine/buildnum.cpp"
	"../engine/cmd.cpp"
	"../engine/cmd.h"
	"../engine/cmodel.cpp"
	"../engine/cmodel.h"
	"../engine/com_custom.cpp"
	"../engine/com_custom.h"
	"../engine/common.cpp"
	"../engine/common.h"
	"../engine/consistency.h"
	"../engine/crc.cpp"
	"../engine/custom_int.h"
	"../engine/cvar.cpp"
	"../engine/cvar.h"
	"../engine/decal.h"
	"../engine/decals.cpp"
	"../engine/delta.cpp"
	"../engine/delta.h"
	"../engine/delta_jit.cpp"
	"../engine/delta_jit.h"
	"../engine/ed_strpool.cpp"
	"../engine/ed_strpool.h"
	"../engine/event.h"
	"../engine/filesystem.cpp"
	"../engine/filesystem_.h"
	"../engine/filesystem_internal.cpp"
	"../engine/filesystem_internal.h"
	"../engine/filter.h"
	"../engine/hashpak.cpp"
	"../engine/hashpak.h"
	"../engine/host.cpp"
	"../engine/host.h"
	"../engine/host_cmd.cpp"
	"../engine/host_cmd.h"
	"../engine/iengine.h"
	"../engine/igame.h"
	"../engine/info.cpp"
	"../engine/info.h"
	"../engine/inst_baseline.h"
	"../engine/ipratelimit.cpp"
	"../engine/ipratelimit.h"
	"../engine/keys.h"
	"../engine/l_studio.cpp"
	"../engine/l_studio.h"
	"../engine/md5.cpp"
	"../engine/mem.cpp"
	"../engine/mem.h"
	"../engine/model.cpp"
	"../engine/model_rehlds.h"
	"../engine/modinfo.h"
	"../engine/module.cpp"
	"../engine/net.h"
	"../engine/net_chan.cpp"
	"../engine/net_chan.h"
	"../engine/net_ws.cpp"
	"../engine/net_ws.h"
	"../engine/pmove.cpp"
	"../engine/pmove.h"
	"../engine/pmovetst.cpp"
	"../engine/pmovetst.h"
	"../engine/pr_cmds.cpp"
	"../engine/pr_cmds.h"
	"../engine/pr_edict.cpp"
	"../engine/pr_edict.h"
	"../engine/r_studio.cpp"
	"../engine/server.h"
	"../engine/server_static.h"
	"../engine/snd_null.cpp"
	"../engine/studio_rehlds.h"
	"../engine/sys_dll.cpp"
	"../engine/sys_dll.h"
	"../engine/sys_engine.cpp"
	"../engine/sys_engine.h"
	"../engine/sys_linuxwind.cpp"
	"../engine/sys_linuxwnd.h"
	"../engine/SystemWrapper.cpp"
	"../engine/SystemWrapper.h"
	"../engine/textures.cpp"
	"../engine/textures.h"
	"../engine/tmessage.cpp"
	"../engine/tmessage.h"
	"../engine/traceinit.cpp"
	"../engine/traceinit.h"
	"../engine/unicode_strtools.cpp"
	"../engine/unicode_strtools.h"
	"../engine/userid.h"
	"../engine/usermsg.h"
	"../engine/vid_null.h"
	"../engine/wad.cpp"
	"../engine/wad.h"
	"../engine/world.cpp"
	"../engine/world.h"
	"../engine/zone.cpp"
	"../engine/zone.h"
)
source_group("Engine\\Common" FILES ${Engine_Common})

set(Engine_Server
	"../engine/cl_null.cpp"
	"../engine/sv_log.cpp"
	"../engine/sv_log.h"
	"../engine/sv_main.cpp"
	"../engine/sv_move.cpp"
	"../engine/sv_move.h"
	"../engine/sv_phys.cpp"
	"../engine/sv_phys.h"
	"../engine/sv_pmove.cpp"
	"../engine/sv_pmove.h"
	"../engine/sv_remoteaccess.cpp"
	"../engine/sv_remoteaccess.h"
	"../engine/sv_steam3.cpp"
	"../engine/sv_steam3.h"
	"../engine/sv_upld.cpp"
	"../engine/sv_upld.h"
	"../engine/sv_user.cpp"
	"../engine/sv_user.h"
	"../engine/sys_dll2.cpp"
	"../engine/sys_dll2.h"
	"../engine/vid_null.cpp"
)
source_group("Engine\\Server" FILES ${Engine_Server})

set(Public
	"../public/basetypes.h"
	"../public/commonmacros.h"
	"../public/engine_hlds_api.h"
	"../public/engine_launcher_api.h"
	"../public/FileSystem.h"
	"../public/idedicatedexports.h"
	"../public/interface.h"
	"../public/iregistry.h"
	"../public/registry.cpp"
	"../public/savegame_version.h"
	"../public/steamid.cpp"
	"../public/strtools.h"
	"../public/utlbuffer.cpp"
	"../public/utlbuffer.h"
	"../public/utllinkedlist.h"
	"../public/utlmemory.h"
	"../public/utlrbtree.h"
	"../public/utlvector.h"
)
source_group("Public" FILES ${Public})

set(Public_ReHLDS
	"../public/rehlds/archtypes.h"
	"../public/rehlds/bspfile.h"
	"../public/rehlds/cmd_rehlds.h"
	"../public/rehlds/common_rehlds.h"
	"../public/rehlds/crc32c.h"
	"../public/rehlds/custom.h"
	"../public/rehlds/customentity.h"
	"../public/rehlds/d_local.h"
	"../public/rehlds/edict.h"
	"../public/rehlds/eiface.h"
	"../public/rehlds/keydefs.h"
	"../public/rehlds/maintypes.h"
	"../public/rehlds/model.h"
	"../public/rehlds/modelgen.h"
	"../public/rehlds/osconfig.h"
	"../public/rehlds/pr_dlls.h"
	"../public/rehlds/progdefs.h"
	"../public/rehlds/progs.h"
	"../public/rehlds/rehlds_interfaces.h"
	"../public/rehlds/Sequence.h"
	"../public/rehlds/shake.h"
	"../public/rehlds/spritegn.h"
	"../public/rehlds/static_map.h"
	"../public/rehlds/studio.h"
	"../public/rehlds/sys_shared.h"
	"../public/rehlds/userid_rehlds.h"
)
source_group("Public\\ReHLDS" FILES ${Public_ReHLDS})

set(Public_Steam
	"../public/steam/isteamapps.h"
	"../public/steam/isteambilling.h"
	"../public/steam/isteamclient.h"
	"../public/steam/isteamcontroller.h"
	"../public/steam/isteamfriends.h"
	"../public/steam/isteamgameserver.h"
	"../public/steam/isteamgameserverstats.h"
	"../public/steam/isteamhttp.h"
	"../public/steam/isteammatchmaking.h"
	"../public/steam/isteamnetworking.h"
	"../public/steam/isteamremotestorage.h"
	"../public/steam/isteamscreenshots.h"
	"../public/steam/isteamunifiedmessages.h"
	"../public/steam/isteamuser.h"
	"../public/steam/isteamuserstats.h"
	"../public/steam/isteamutils.h"
	"../public/steam/matchmakingtypes.h"
	"../public/steam/steam_api.h"
	"../public/steam/steam_gameserver.h"
	"../public/steam/steamclientpublic.h"
	"../public/steam/steamhttpenums.h"
	"../public/steam/steamtypes.h"
)
source_group("Public\\Steam" FILES ${Public_Steam})

set(Public_tier0
	"../public/tier0/dbg.cpp"
	"../public/tier0/dbg.h"
	"../public/tier0/platform.h"
)
source_group("Public\\tier0" FILES ${Public_tier0})

set(ALL_FILES
	${Misc}
	${Source_Files}
	${Common}
	${Dlls}
	${Engine}
	${Engine_Client}
	${Engine_Common}
	${Engine_Server}
	${Public}
	${Public_ReHLDS}
	${Public_Steam}
	${Public_tier0}
)

target_precompile_headers(rehlds PRIVATE 
	"./precompiled.h")
target_sources(rehlds PRIVATE ${ALL_FILES})