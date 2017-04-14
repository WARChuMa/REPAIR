
class CfgInteractionMenus
{
	class Car 
	{
		targetType = 2;
		target = "Car";

		class Actions 
		{
			
			class RepairInfoLand: ExileAbstractAction
			{
				title = "Repair";
				condition = "true";
                //action = "['RepairVehicle', _this select 0] call ExileClient_action_execute";
				action = "_this call EXSYS_fnc_dialog_repair_menu";
			};

	};

	class Tank 
	{
		targetType = 2;
		target = "Tank";

		class Actions 
		{
			
			// Repairs a vehicle to 100%. Requires Duckttape
			class Repair: ExileAbstractAction
			{
				title = "Repair";
				condition = "true";
				//action = "['RepairVehicle', _this select 0] call ExileClient_action_execute";
				action = "_this call EXSYS_fnc_dialog_repair_menu";
			};

			
		};
	};
	
	
	class Air
	{
		target = "Air";
		targetType = 2;

		class Actions
		{
			
			
			// Repairs a vehicle to 100%. Requires Duckttape
			class Repair: ExileAbstractAction
			{
				title = "Repair";
				condition = "true";
				//action = "['RepairVehicle', _this select 0] call ExileClient_action_execute";
				action = "_this call EXSYS_fnc_dialog_repair_menu";
			};

			
		};
	};
	
	