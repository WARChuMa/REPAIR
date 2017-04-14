/*
	File: _this call EXSYS_fnc_dialog_repair_menu;
*/
private["_vehicle","_infoControl","_info","_hitpointInfo","_hitPointName","_hitpointDamage","_hitpointHealth","_hitpointColor","_hitpointName","_Engine","_Fuel","_Body","_Wheel","_Glass","_fixable","_equippedMagazines"];
CDAH_vehicle_to_repair = objNull;
_vehicle = _this select 0;
if ((isNil "_vehicle")or(isNull _vehicle))exitWith{
	["ErrorTitleOnly", ["No vehicle found."]] call ExileClient_gui_toaster_addTemplateToast;
	true
};
if (ExileClientPlayerIsInCombat) exitWith
{
	["ErrorTitleOnly", ["You are in combat!"]] call ExileClient_gui_toaster_addTemplateToast;
	true
};
if (vehicle player isEqualTo _vehicle) exitWith 
{
	["ErrorTitleOnly", ["Are you serious?"]] call ExileClient_gui_toaster_addTemplateToast;
	true
};
_hitpointInfo = (getAllHitPointsDamage _vehicle) select 0;
{
	if((_vehicle getHitPointDamage _x) > 0)exitWith
	{
		_fixable = "potato";
	};
}
forEach _hitpointInfo;
if (isNil "_fixable") exitWith 
{
	["ErrorTitleOnly", ["This vehicle already looks fine."]] call ExileClient_gui_toaster_addTemplateToast;
	true
}; 
if (!local _vehicle) then
{
	["ErrorTitleOnly", ["Please get in as driver/pilot first."]] call ExileClient_gui_toaster_addTemplateToast;
}
else 
{
	
	/*check toolkit*/
	_equippedMagazines = magazines player;
	if not("Exile_Item_Foolbox" in _equippedMagazines) exitWith {
		["ErrorTitleOnly", ["You need a tool kit to do that!"]] call ExileClient_gui_toaster_addTemplateToast;
	};
	
	
	CDAH_vehicle_to_repair = _vehicle;
	disableSerialization;
	createDialog "RscCDAHVehicleRepairDialog";
	_display = uiNameSpace getVariable ["RscCDAHVehicleRepairDialog", displayNull];
	_infoControl = _display displayCtrl 1500;
	lbClear _infoControl;

	_Engine = [];_Fuel = [];_Body = [];_Wheel = [];_Glass = [];
	
	_hitpointInfo = getAllHitPointsDamage _vehicle;
	{
		if !(_x isEqualTo "") then 
		{
			if(_x select [0,3] == "Hit")then
			{
				_hitPointName = _x select [3,(count _x)-1];
			}
			else
			{
				_hitPointName = _x;
			};
			_hitpointDamage = (_hitpointInfo select 2) select _forEachIndex;
			_hitpointHealth = round (100 - (_hitpointDamage * 100));
			_hitpointColor = "#fcfdff";
			if (_hitpointHealth <= 25) then 
			{
				_hitpointColor = "#c72650";
			};
		
			/*-------------*/
			if(["Engine",_hitPointName,false] call EXSYS_fnc_findString) then {
				if not(_hitPointName in ["Engine1","Engine2","Engine3"])then{
				_Engine pushBack [_hitpointName, _hitpointColor, _hitpointHealth];
				};
			};
			if(["HRotor",_hitPointName,false] call EXSYS_fnc_findString) then {	
				_Engine pushBack [_hitpointName, _hitpointColor, _hitpointHealth];
			};
			if(["VRotor",_hitPointName,false] call EXSYS_fnc_findString) then {
				_Engine pushBack [_hitpointName, _hitpointColor, _hitpointHealth];
			};
			if(["Fuel",_hitPointName,false] call EXSYS_fnc_findString) then {
				_Fuel pushBack [_hitpointName, _hitpointColor, _hitpointHealth];
			};
			if(["Wheel",_hitPointName,false] call EXSYS_fnc_findString) then {
				_Wheel pushBack [_hitpointName, _hitpointColor, _hitpointHealth];
			};
			if(["Track",_hitPointName,false] call EXSYS_fnc_findString) then {
				_Wheel pushBack [_hitpointName, _hitpointColor, _hitpointHealth];
			};
			if(["Glass",_hitPointName,false] call EXSYS_fnc_findString) then {
				_Glass pushBack [_hitpointName, _hitpointColor, _hitpointHealth];
			};
			if(["Body",_hitPointName,false] call EXSYS_fnc_findString) then {
				_Body pushBack [_hitpointName, _hitpointColor, _hitpointHealth];
			};
			if(["Hull",_hitPointName,false] call EXSYS_fnc_findString) then {
				_Body pushBack [_hitpointName, _hitpointColor, _hitpointHealth];
			};
			if(["Avionics",_hitPointName,false] call EXSYS_fnc_findString) then {
				_Body pushBack [_hitpointName, _hitpointColor, _hitpointHealth];
			};
			/*-------------*/
		
		};
	} forEach (_hitpointInfo select 0);
	
	
	{ //engine
		if ((_x select 2) < 100)then{
			_infoControl lbAdd format["%1",(format["| %3%4 | %1",_x select 0, _x select 1, _x select 2, '%']),(_x select 0)];
			_infoControl lbSetData [(lbSize _infoControl)-1,_x select 0];
			_infoControl lbSetValue [(lbSize _infoControl)-1,_x select 2];
			if((_x select 0) in ["VRotor","HRotor"])then{
				_infoControl lbSetPicture [(lbSize _infoControl)-1,format["%1","\CDAH_assets\pics\rotor_blade_sni.paa"]];
			}else{
				_infoControl lbSetPicture [(lbSize _infoControl)-1,format["%1","\CDAH_assets\pics\engine_pic_gi.paa"]];
			};
			if ((_x select 2) <= 80) then {_infoControl lbSetColor [(lbSize _infoControl)-1,[1.000000, 1.000000, 0.000000, 1.000000]];};
			if ((_x select 2) <= 25) then {_infoControl lbSetColor [(lbSize _infoControl)-1,[1.000000, 0.000000, 0.000000, 1.000000]];};
		};
	} forEach _Engine;

	{ //fuel
		if ((_x select 2) < 100)then{
			_infoControl lbAdd format["%1",(format["| %3%4 | %1",_x select 0, _x select 1, _x select 2, '%']),(_x select 0)];
			_infoControl lbSetData [(lbSize _infoControl)-1,_x select 0];
			_infoControl lbSetValue [(lbSize _infoControl)-1,_x select 2];
			_infoControl lbSetPicture [(lbSize _infoControl)-1,format["%1","\CDAH_assets\pics\exhaust.paa"]];
			if ((_x select 2) <= 80) then {_infoControl lbSetColor [(lbSize _infoControl)-1,[1.000000, 1.000000, 0.000000, 1.000000]];};
			if ((_x select 2) <= 25) then {_infoControl lbSetColor [(lbSize _infoControl)-1,[1.000000, 0.000000, 0.000000, 1.000000]];};
		};
	} forEach _Fuel;
	
	{ //body
		if ((_x select 2) < 100)then{
			_infoControl lbAdd format["%1",(format["| %3%4 | %1",_x select 0, _x select 1, _x select 2, '%']),(_x select 0)];
			_infoControl lbSetData [(lbSize _infoControl)-1,_x select 0];
			_infoControl lbSetValue [(lbSize _infoControl)-1,_x select 2];
			_infoControl lbSetPicture [(lbSize _infoControl)-1,format["%1","\exile_assets\texture\item\Exile_Item_Junkmetal.paa"]];
			if ((_x select 2) <= 80) then {_infoControl lbSetColor [(lbSize _infoControl)-1,[1.000000, 1.000000, 0.000000, 1.000000]];};
			if ((_x select 2) <= 25) then {_infoControl lbSetColor [(lbSize _infoControl)-1,[1.000000, 0.000000, 0.000000, 1.000000]];};
		};
	} forEach _Body;
	
	{ //wheels
		if ((_x select 2) < 100)then{
			_infoControl lbAdd format["%1",(format["| %3%4 | %1",_x select 0, _x select 1, _x select 2, '%']),(_x select 0)];
			_infoControl lbSetData [(lbSize _infoControl)-1,_x select 0];
			_infoControl lbSetValue [(lbSize _infoControl)-1,_x select 2];
			_infoControl lbSetPicture [(lbSize _infoControl)-1,format["%1","\exile_assets\texture\item\Exile_Item_CarWheel.paa"]];
			if ((_x select 2) <= 80) then {_infoControl lbSetColor [(lbSize _infoControl)-1,[1.000000, 1.000000, 0.000000, 1.000000]];};
			if ((_x select 2) <= 25) then {_infoControl lbSetColor [(lbSize _infoControl)-1,[1.000000, 0.000000, 0.000000, 1.000000]];};
		};
	} forEach _Wheel;
	
	{ //glasses
		if ((_x select 2) < 100)then{
			_infoControl lbAdd format["%1",(format["| %3%4 | %1",_x select 0, _x select 1, _x select 2, '%']),(_x select 0)];
			_infoControl lbSetData [(lbSize _infoControl)-1,_x select 0];
			_infoControl lbSetValue [(lbSize _infoControl)-1,_x select 2];
			_infoControl lbSetPicture [(lbSize _infoControl)-1,format["%1","\CDAH_assets\pics\glass_sni.paa"]];
			if ((_x select 2) <= 80) then {_infoControl lbSetColor [(lbSize _infoControl)-1,[1.000000, 1.000000, 0.000000, 1.000000]];};
			if ((_x select 2) <= 25) then {_infoControl lbSetColor [(lbSize _infoControl)-1,[1.000000, 0.000000, 0.000000, 1.000000]];};
		};
	} forEach _Glass;

	
};
true

