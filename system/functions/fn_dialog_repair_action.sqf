/*
	File: [] call EXSYS_fnc_dialog_repair_action;
*/
private["_target","_damage","_hitpoint","_availableHitpoints","_hitPointName","_removeItem","_equippedMagazines","_removeName"];
_target = CDAH_vehicle_to_repair;
if ((isNil "_target")or(isNull _target))exitWith{
	closeDialog 0;
	["ErrorTitleOnly", ["No vehicle found."]] call ExileClient_gui_toaster_addTemplateToast;
	true
};
disableSerialization;
if((lbCurSel 1500) == -1) exitWith {
	closeDialog 0; 
	["ErrorTitleOnly", ["Select a vehicle part to repair this vehicle."]] call ExileClient_gui_toaster_addTemplateToast;
	true
};
_damage = lbValue[1500,(lbCurSel 1500)]; 
_hitpoint = lbData[1500,(lbCurSel 1500)];
_removeItem = "";
if (!(isNil "_hitpoint") && (_damage < 100)) then {

	/*-------------*/
		if(["Engine",_hitpoint,false] call EXSYS_fnc_findString) then {
			_removeItem = "CDAH_engine_item";
		};
		if(["HRotor",_hitpoint,false] call EXSYS_fnc_findString) then {
			_removeItem = "CDAH_rotor_blade_item";
		};
		if(["VRotor",_hitpoint,false] call EXSYS_fnc_findString) then {
			_removeItem = "CDAH_rotor_blade_item";
		};
		if(["Fuel",_hitpoint,false] call EXSYS_fnc_findString) then {
			_removeItem = "CDAH_exhaust_item";
		};
		if(["Wheel",_hitpoint,false] call EXSYS_fnc_findString) then {
			_removeItem = "Exile_Item_CarWheel";
		};
		if(["Track",_hitpoint,false] call EXSYS_fnc_findString) then {
			_removeItem = "Exile_Item_CarWheel";
		};
		if(["Glass",_hitpoint,false] call EXSYS_fnc_findString) then {
			_removeItem = "CDAH_car_glass_item";
		};
		if(["Body",_hitpoint,false] call EXSYS_fnc_findString) then {
			_removeItem = "Exile_Item_JunkMetal";
		};
		if(["Hull",_hitpoint,false] call EXSYS_fnc_findString) then {
			_removeItem = "Exile_Item_JunkMetal";
		};
		if(["Avionics",_hitpoint,false] call EXSYS_fnc_findString) then {
			_removeItem = "CDAH_CarBattery_item";
		};
	/*-------------*/

	_equippedMagazines = magazines player;
	if not(_removeItem in _equippedMagazines) exitWith {
		_removeName = _removeItem call ExileClient_util_gear_getConfigNameByClassName;
		_removeName = getText(configFile >> _removeName >> _removeItem >> "displayName");
		["ErrorTitleOnly", [format["You need a %1.",_removeName]]] call ExileClient_gui_toaster_addTemplateToast;
		closeDialog 0;
		true
	};
	
	if (_removeItem isEqualTo "") exitWith {
		["ErrorTitleOnly", ["You need a vehicle part to do that!"]] call ExileClient_gui_toaster_addTemplateToast;
		closeDialog 0;
		true
	};
	
	player removeMagazine _removeItem;
	
	if (_hitpoint isEqualTo "Body")then
	{
		_availableHitpoints = (getAllHitPointsDamage _target) select 0;
		{
			if !(_x isEqualTo "") then 
			{
					if not(_x in ["HitEngine","HitEngine1","HitEngine2","HitEngine3","HitFuel","HitHRotor","HitVRotor","HitHull","HitAvionics","HitGlass","HitGlass1","HitGlass2","HitGlass3","HitGlass4","HitGlass5","HitGlass6","HitGlass7","HitGlass8","HitGlass9","HitGlass10","HitFWheel","HitBWheel","HitLFWheel","HitRFWheel","HitLF2Wheel","HitLMWheel","HitRF2Wheel","HitRMWheel"])then {
						_target setHitPointDamage[format["%1",_x],0];
					};
			};
		}
		forEach _availableHitpoints;
		
		player playMove "AinvPknlMstpSnonWnonDr_medic3";
		["SuccessTitleOnly",[format["%1 repaired",_hitpoint]]] call ExileClient_gui_notification_event_addNotification;
		[player,player] say3D "fxCDAH_repair";
	} 
	else 
	{
		_target setHitPointDamage[format["Hit%1",_hitpoint],0];
		
		player playMove "AinvPknlMstpSnonWnonDr_medic3";
		["SuccessTitleOnly",[format["%1 repaired",_hitpoint]]] call ExileClient_gui_notification_event_addNotification;
		[player,player] say3D "fxCDAH_repair";
	};
};
closeDialog 0;
true


