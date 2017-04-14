class RscCDAHVehicleRepairDialog
{
	idd = 2991;
	onLoad = "true call ExileClient_gui_postProcessing_toggleDialogBackgroundBlur; uiNamespace setVariable ['RscCDAHVehicleRepairDialog', _this select 0]";
	onUnload = "false call ExileClient_gui_postProcessing_toggleDialogBackgroundBlur; uiNamespace setVariable ['RscCDAHVehicleRepairDialog', displayNull]";

	class controlsBackground {

		class DialogBackground: CDAH_RscText { //Title
			idc = -1;
			text = "";
			x = 9.5 * GUI_GRID_W + GUI_GRID_X;
			y = 12 * GUI_GRID_H + GUI_GRID_Y;
			w = 21 * GUI_GRID_W;
			h = 4.5 * GUI_GRID_H;
			colorBackground[] = {0.000000, 0.000000, 0.000000, 0.500000}; //1.000000
		};
		
		class DialogCation: CDAH_RscText { //Title
			idc = -1;
			text = "Select a vehicle part to repair this vehicle";
			x = 9.5 * GUI_GRID_W + GUI_GRID_X;
			y = 11 * GUI_GRID_H + GUI_GRID_Y;
			w = 21 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0.000000, 0.000000, 0.000000, 0.800000}; //1.000000
		};
	
	};
	
	class controls {
		
		//ListBox
		class RepaiRscListbox_1500: CDAH_RscCombo
		{
			idc = 1500;
			x = 10.5 * GUI_GRID_W + GUI_GRID_X;
			y = 13 * GUI_GRID_H + GUI_GRID_Y;
			w = 16 * GUI_GRID_W;
			h = 2.25 * GUI_GRID_H;
		};

		//Button
		class RepaiRscButton_Ok: CDAH_RscButtonMenu
		{
			idc = -1;
			text = "GO";
			onButtonClick = "[] call EXSYS_fnc_dialog_repair_action;";
			x = 27.25 * GUI_GRID_W + GUI_GRID_X;
			y = 13 * GUI_GRID_H + GUI_GRID_Y;
			w = 2.25 * GUI_GRID_W;
			h = 2.25 * GUI_GRID_H;
		};
		
	};
};