/*
	File: _result = call EXSYS_fnc_checkVehicleCount;
*/
private["_count","_result","_uid"];
_result = false;
_uid = (getPlayerUID player);
_count = 0;
{
	if(_uid isEqualTo (_x getVariable ["ExileOwnerUID",0])) then 
	{
		if ((_x isKindOf "Car")/* || (_x isKindOf "Air")*/) then
		{
			_count = _count + 1;
			if(_count >= 6) then 
			{
				_result = true;
			};
			diag_log format["VECICLE COUNT: %1 - %2",_count,(_x getVariable ["ExileOwnerUID",0])];
		};
	};
}
forEach vehicles;
_result