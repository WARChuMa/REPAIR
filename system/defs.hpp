#define SYSTEM_ROOT parsingNamespace getVariable "MISSION_ROOT"
/* Macros */
#define SEL(ARRAY,INDEX) (ARRAY select INDEX)
#define EQUAL(condition1,condition2) condition1 isEqualTo condition2
#define KINDOF_ARRAY(a,b) [##a,##b] call {_veh = _this select 0;_types = _this select 1;_res = false; {if (_veh isKindOf _x) exitwith { _res = true };} forEach _types;_res}

#define EXCFG_MAGAZINES "CfgMagazines"
#define EXCFG_WEAPONS "CfgWeapons"
#define EXCFG_VEHICLES "CfgVehicles"
#define EXCFG_AMMO "CfgAmmo"
#define EXCFG_GLASSES "CfgGlasses"

#define CL_RIFLE primaryWeapon player
#define CL_RIFLE_ITEMS primaryWeaponItems player
#define CL_PISTOL handgunWeapon player
#define CL_PISTOL_ITEMS handgunItems player
#define CL_LAUNCHER secondaryWeapon player