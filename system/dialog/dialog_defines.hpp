///////////////////////////////////////////////////////////////////////////
/// Styles
///////////////////////////////////////////////////////////////////////////

// Control types
#define CT_STATIC           0
#define CT_BUTTON           1
#define CT_EDIT             2
#define CT_SLIDER           3
#define CT_COMBO            4
#define CT_LISTBOX          5
#define CT_TOOLBOX          6
#define CT_CHECKBOXES       7
#define CT_PROGRESS         8
#define CT_HTML             9
#define CT_STATIC_SKEW      10
#define CT_ACTIVETEXT       11
#define CT_TREE             12
#define CT_STRUCTURED_TEXT  13
#define CT_CONTEXT_MENU     14
#define CT_CONTROLS_GROUP   15
#define CT_SHORTCUTBUTTON   16
#define CT_XKEYDESC         40
#define CT_XBUTTON          41
#define CT_XLISTBOX         42
#define CT_XSLIDER          43
#define CT_XCOMBO           44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT           80
#define CT_OBJECT_ZOOM      81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK        98
#define CT_USER             99
#define CT_MAP              100
#define CT_MAP_MAIN         101
#define CT_LISTNBOX         102
#define CT_CHECKBOX         77

// Static styles
#define ST_POS            0x0F
#define ST_HPOS           0x03
#define ST_VPOS           0x0C
#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02
#define ST_DOWN           0x04
#define ST_UP             0x08
#define ST_VCENTER        0x0C

#define ST_TYPE           0xF0
#define ST_SINGLE         0x00
#define ST_MULTI          0x10
#define ST_TITLE_BAR      0x20
#define ST_PICTURE        0x30
#define ST_FRAME          0x40
#define ST_BACKGROUND     0x50
#define ST_GROUP_BOX      0x60
#define ST_GROUP_BOX2     0x70
#define ST_HUD_BACKGROUND 0x80
#define ST_TILE_PICTURE   0x90
#define ST_WITH_RECT      0xA0
#define ST_LINE           0xB0

#define ST_SHADOW         0x100
#define ST_NO_RECT        0x200
#define ST_KEEP_ASPECT_RATIO  0x800

#define ST_TITLE          ST_TITLE_BAR + ST_CENTER

// Slider styles
#define SL_DIR            0x400
#define SL_VERT           0
#define SL_HORZ           0x400

#define SL_TEXTURES       0x10

// progress bar 
#define ST_VERTICAL       0x01
#define ST_HORIZONTAL     0

// Listbox styles
#define LB_TEXTURES       0x10
#define LB_MULTI          0x20

// Tree styles
#define TR_SHOWROOT       1
#define TR_AUTOCOLLAPSE   2

// MessageBox styles
#define MB_BUTTON_OK      1
#define MB_BUTTON_CANCEL  2
#define MB_BUTTON_USER    4

#define GUI_GRID_X		(0)
#define GUI_GRID_Y		(0)
#define GUI_GRID_W		(0.025)
#define GUI_GRID_H		(0.040)
#define GUI_GRID_WAbs	(1)
#define GUI_GRID_HAbs	(1)

////////////////////////////////////////////////////////

class CDAH_RscScrollBar
{
	color[] = {1,1,1,0.6};
	colorActive[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.3};
	thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
	arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
	arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
	border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	shadow = 0;
	scrollSpeed = 0.06;
	width = 0;
	height = 0;
	autoScrollEnabled = 1;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
};

class CDAH_RscControlsGroup {
	type = 15;
	idc = -1;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	shadow = 0;
	style = 16;
	
	class VScrollBar : CDAH_RscScrollBar
	{
		width = 0.021;
		autoScrollEnabled = 1;
	};
	
	class HScrollBar : CDAH_RscScrollBar
	{
		height = 0.028;
	};
	
	class Controls {};
};

class CDAH_RscControlsGroupNoScrollbars : CDAH_RscControlsGroup {
	class VScrollbar : VScrollbar {
		width = 0;
	};
	
	class HScrollbar : HScrollbar {
		height = 0;
	};
};

class CDAH_RscHud 
{
	idc = -1;
	type = 0;
	style = 0x00;
	colorBackground[] = { 1 , 1 , 1 , 0 };
	colorText[] = { 1 , 1 , 1 , 1 };
	font = "PuristaSemibold";
	sizeEx = 0.025;
	h = 0.25;
	text = "";
};

class CDAH_RscListNBox
{
	style = 16;
	type = 102;
	shadow = 0;
	font = "PuristaMedium";
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	color[] = {0.95,0.95,0.95,1};
	colorText[] = {1,1,1,1.0};
	colorDisabled[] = {1,1,1,0.25};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,1};
	colorScrollbar[] = {0.95,0.95,0.95,1};
	colorSelect[] = {0,0,0,1};
	colorSelect2[] = {0,0,0,1};
	colorSelectBackground[] = {0.8,0.8,0.8,1};
	colorSelectBackground2[] = {1,1,1,0.5};
	soundSelect[] = {"",0.1,1};
	soundExpand[] = {"",0.1,1};
	soundCollapse[] = {"",0.1,1};
	period = 1.2;
	maxHistoryDelay = 0.5;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	rowHeight = 0.04;
	drawSideArrows = 0;
	idcLeft = -1;
	idcRight = -1;
	class ListScrollBar: CDAH_RscScrollBar{};
	class ScrollBar: CDAH_RscScrollBar{};
};


class CDAH_RscText {
	x = 0;
	y = 0;
	h = 0.037;
	w = 0.3;
	type = 0;
	style = ST_CENTER;
	shadow = 1;
	colorShadow[] = {0, 0, 0, 0.5};
	font = "PuristaMedium";
	SizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	text = "";
	colorText[] = {1, 1, 1, 1.0};
	colorBackground[] = {0, 0, 0, 0};
	linespacing = 1;
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
};

class CDAH_RscLine : CDAH_RscText {
	idc = -1;
	style = 176;
	x = 0.17;
	y = 0.48;
	w = 0.66;
	h = 0;
	text = "";
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {1, 1, 1, 1.0};
};

class CDAH_RscTree {
	style = 2;
	font = "PuristaMedium";
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	expandedTexture = "A3\ui_f\data\gui\Rsccommon\Rsctree\expandedTexture_ca.paa";
	hiddenTexture = "A3\ui_f\data\gui\Rsccommon\Rsctree\hiddenTexture_ca.paa";
	rowHeight = 0.0439091;
	color[] = {1, 1, 1, 1};
	colorSelect[] = {0.7, 0.7, 0.7, 1};
	colorBackground[] = {0, 0, 0, 0};
	colorSelectBackground[] = {0, 0, 0, 0.5};
	colorBorder[] = {0, 0, 0, 0};
	borderSize = 0;
};

class CDAH_RscTitle : CDAH_RscText {
	style = 0;
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	colorText[] = {0.95, 0.95, 0.95, 1};
};

class CDAH_RscPicture {
	shadow = 0;
	type = 0;
	style = 48;
	sizeEx = 0.023;
	font = "PuristaMedium";
	colorBackground[] = {};
	colorText[] = {};
	x = 0;
	y = 0;
	w = 0.2;
	h = 0.15;
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
};

class CDAH_RscTextMulti : CDAH_RscText
{
	linespacing = 1;
	style = 0 + 16 + 0x200;
};

class CDAH_RscPictureKeepAspect : CDAH_RscPicture 
{
	style = 0x30 + 0x800;
};

class CDAH_RscStructuredText {
	type = 13;
	style = 0;
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.1;
	text = "";
	size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	colorText[] = {1, 1, 1, 1.0};
	shadow = 1;
	
	class Attributes {
		font = "PuristaMedium";
		color = "#ffffff";
		align = "left";
		shadow = 1;
	};
};

class CDAH_RscActiveText {
idc = -1;
    type = 11;
    style = 0;
    x = 0;
    y = 0;
    h = 0.037;
    w = 0.3;
    sizeEx = 0.040;
    font = "PuristaLight";
    color[] = {1, 1, 1, 1};
    colorActive[] = {1, 0.2, 0.2, 1};
	colorDisabled[] = {0.4,0.4,0.4,1};
    soundEnter[] = {"\A3\ui_f\data\sound\onover", 0.09, 1};
    soundPush[] = {"\A3\ui_f\data\sound\new1", 0.0, 0};
    soundClick[] = {"\A3\ui_f\data\sound\onclick", 0.07, 1};
    soundEscape[] = {"\A3\ui_f\data\sound\onescape", 0.09, 1};
    action = "";
    text = "";
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
};

class CDAH_RscButton 
{
	style = 2;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	shadow = 2;
	font = "PuristaMedium";
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	colorText[] = {1,1,1,1.0};
	colorDisabled[] = {0.4,0.4,0.4,1};
	colorBackground[] = {"(missionNamespace getVariable ['ZO_GUI_BCG_RGB_R',0.69])","(missionNamespace getVariable ['ZO_GUI_BCG_RGB_G',0.75])","(missionNamespace getVariable ['ZO_GUI_BCG_RGB_B',0.5])",0.7};
	colorBackgroundActive[] = {"(missionNamespace getVariable ['ZO_GUI_BCG_RGB_R',0.69])","(missionNamespace getVariable ['ZO_GUI_BCG_RGB_G',0.75])","(missionNamespace getVariable ['ZO_GUI_BCG_RGB_B',0.5])",1};
	colorBackgroundDisabled[] = {0.95,0.95,0.95,1};
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	colorFocused[] = {"(missionNamespace getVariable ['ZO_GUI_BCG_RGB_R',0.69])","(missionNamespace getVariable ['ZO_GUI_BCG_RGB_G',0.75])","(missionNamespace getVariable ['ZO_GUI_BCG_RGB_B',0.5])",1};
	colorShadow[] = {0,0,0,1};
	colorBorder[] = {0,0,0,1};
	borderSize = 0.0;
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
};

class CDAH_RscButtonTextOnly : CDAH_RscButton {
	SizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	colorBackground[] = {1, 1, 1, 0};
	colorBackgroundActive[] = {1, 1, 1, 0};
	colorBackgroundDisabled[] = {1, 1, 1, 0};
	colorFocused[] = {1, 1, 1, 0};
	colorShadow[] = {1, 1, 1, 0};
	borderSize = 0.0;
};

class CDAH_RscShortcutButton {
	idc = -1;
	style = 0;
	default = 0;
	shadow = 1;
	w = 0.183825;
	h = "(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
	color[] = {1,1,1,1.0};
	colorFocused[] = {1,1,1,1.0};
	color2[] = {0.95,0.95,0.95,1};
	colorDisabled[] = {1,1,1,0.25};
	colorBackground[] = {"(missionNamespace getVariable ['ZO_GUI_BCG_RGB_R',0.69])","(missionNamespace getVariable ['ZO_GUI_BCG_RGB_G',0.75])","(missionNamespace getVariable ['ZO_GUI_BCG_RGB_B',0.5])",1};
	colorBackgroundFocused[] = {"(missionNamespace getVariable ['ZO_GUI_BCG_RGB_R',0.69])","(missionNamespace getVariable ['ZO_GUI_BCG_RGB_G',0.75])","(missionNamespace getVariable ['ZO_GUI_BCG_RGB_B',0.5])",1};
	colorBackground2[] = {1,1,1,1};
	animTextureDefault = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureNormal = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureDisabled = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureOver = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\over_ca.paa";
	animTextureFocused = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\focus_ca.paa";
	animTexturePressed = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\down_ca.paa";
	periodFocus = 1.2;
	periodOver = 0.8;
	class HitZone
	{
		left = 0.0;
		top = 0.0;
		right = 0.0;
		bottom = 0.0;
	};
	class ShortcutPos
	{
		left = 0;
		top = "(			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		w = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
		h = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	};
	class TextPos
	{
		left = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
		top = "(			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		right = 0.005;
		bottom = 0.0;
	};
	period = 0.4;
	font = "PuristaMedium";
	size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	text = "";
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
	action = "";
	class Attributes
	{
		font = "PuristaMedium";
		color = "#E5E5E5";
		align = "left";
		shadow = "true";
	};
	class AttributesImage
	{
		font = "PuristaMedium";
		color = "#E5E5E5";
		align = "left";
	};
};

class CDAH_RscButtonMenu : CDAH_RscShortcutButton {
	idc = -1;
	type = 16;
	style = "0x02 + 0xC0";
	default = 0;
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
	animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
	animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
	colorBackground[] = {0,0,0,0.8};
	colorBackgroundFocused[] = {1,1,1,1};
	colorBackground2[] = {0.75,0.75,0.75,1};
	color[] = {1,1,1,1};
	colorFocused[] = {0,0,0,1};
	color2[] = {0,0,0,1};
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	period = 1.2;
	periodFocus = 1.2;
	periodOver = 1.2;
	size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	class TextPos
	{
		left = "0.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		top = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		right = 0.005;
		bottom = 0.0;
	};
	class Attributes
	{
		font = "PuristaLight";
		color = "#E5E5E5";
		align = "left";
		shadow = "false";
	};
	class ShortcutPos
	{
		left = "(6.25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005";
		top = 0.005;
		w = 0.0225;
		h = 0.03;
	};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",0.09,1};
	textureNoShortcut = "";
};

class CDAH_RscShortcutButtonMain : CDAH_RscShortcutButton {
	idc = -1;
	style = 0;
	default = 0;
	w = 0.313726;
	h = 0.104575;
	color[] = {1, 1, 1, 1.0};
	colorDisabled[] = {1, 1, 1, 0.25};
	
	class HitZone {
		left = 0.0;
		top = 0.0;
		right = 0.0;
		bottom = 0.0;
	};
	
	class ShortcutPos {
		left = 0.0145;
		top = "(			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)) / 2";
		w = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2) * (3/4)";
		h = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
	};
	
	class TextPos {
		left = "(		((safezoneW / safezoneH) min 1.2) / 32) * 1.5";
		top = "(			(		(		((safezoneW / safezoneH) min 1.2) / 1.2) / 20)*2 - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)) / 2";
		right = 0.005;
		bottom = 0.0;
	};
	animTextureNormal = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
	animTextureDisabled = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\disabled_ca.paa";
	animTextureOver = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\over_ca.paa";
	animTextureFocused = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\focus_ca.paa";
	animTexturePressed = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\down_ca.paa";
	animTextureDefault = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
	period = 0.5;
	font = "PuristaMedium";
	size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
	text = "";
	soundEnter[] = {"\A3\ui_f\data\sound\onover", 0.09, 1};
	soundPush[] = {"\A3\ui_f\data\sound\new1", 0.0, 0};
	soundClick[] = {"\A3\ui_f\data\sound\onclick", 0.07, 1};
	soundEscape[] = {"\A3\ui_f\data\sound\onescape", 0.09, 1};
	action = "";
	
	class Attributes {
		font = "PuristaMedium";
		color = "#E5E5E5";
		align = "left";
		shadow = "false";
	};
	
	class AttributesImage {
		font = "PuristaMedium";
		color = "#E5E5E5";
		align = "false";
	};
};

class CDAH_RscCheckbox
{
	access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
	idc = -1; // Control identification (without it, the control won't be displayed)
	type = 77; // Type
	style = ST_LEFT + ST_MULTI; // Style
	default = 0; // Control selected by default (only one within a display can be used)
	blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

	x = "LINE_X(XVAL)";
	y = LINE_Y;
	w = "LINE_W(WVAL)";
	h = 0.029412;

	//Colors
	color[] = { 1, 1, 1, 0.7 }; // Texture color
	colorFocused[] = { 1, 1, 1, 0.7 }; // Focused texture color
	colorHover[] = { 1, 1, 1, 0.7 }; // Mouse over texture color
	colorPressed[] = { 1, 1, 1, 0.7 }; // Mouse pressed texture color
	colorDisabled[] = { 1, 1, 1, 0.7 }; // Disabled texture color

	//Background colors
	colorBackground[] = { 0, 0, 0, 0.7 }; // Fill color
	colorBackgroundFocused[] = { 0, 0, 0, 0.7 }; // Focused fill color
	colorBackgroundHover[] = { 0, 0, 0, 0.7 }; // Mouse hover fill color
	colorBackgroundPressed[] = { 0, 0, 0, 0.7 }; // Mouse pressed fill color
	colorBackgroundDisabled[] = { 0, 0, 0, 0.7 }; // Disabled fill color

	//Textures
	textureChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";		//Texture of checked CheckBox.
	textureUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";		//Texture of unchecked CheckBox.
	textureFocusedChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";	//Texture of checked focused CheckBox (Could be used for showing different texture when focused).
	textureFocusedUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";	//Texture of unchecked focused CheckBox.
	textureHoverChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureHoverUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	texturePressedChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	texturePressedUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureDisabledChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureDisabledUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";

	tooltip = ""; // Tooltip text
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};

	//Sounds
	soundClick[] = { "\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1 }; // Sound played after control is activated in format {file, volume, pitch}
	soundEnter[] = { "\A3\ui_f\data\sound\RscButton\soundEnter", 0.09, 1 }; // Sound played when mouse cursor enters the control
	soundPush[] = { "\A3\ui_f\data\sound\RscButton\soundPush", 0.09, 1 }; // Sound played when the control is pushed down
	soundEscape[] = { "\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1 }; // Sound played when the control is released after pushing down

};

class CDAH_RscProgress 
{
	type = 8;
	style = 0;
	x = 0.344;
	y = 0.619;
	w = 0.313726;
	h = 0.0261438;
	texture = "";
	shadow = 2;
	colorFrame[] = {0, 0, 0, 1};
	colorBackground[] = {0,0,0,0.7};
	colorBar[] = {"(missionNamespace getVariable ['ZO_GUI_BCG_RGB_R',0.706])", "(missionNamespace getVariable ['ZO_GUI_BCG_RGB_G',0.075])", "(missionNamespace getVariable ['ZO_GUI_BCG_RGB_B',0.216])", "(missionNamespace getVariable ['ZO_GUI_BCG_RGB_A',1])"};
};

class CDAH_RscListBox 
{
	sizeEx = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	sizeEx2 = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	rowHeight = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	canDrag = 0;
	itemSpacing = 0.001000;
	period = 1.200000;
	shadow = 0;
	maxHistoryDelay = 1;
	fade = 0;
	deletable = 0;
	type = 5;
	style = 16;
	colorBackground[] = {0, 0, 0, 0.300000};
	colorDisabled[] = {1, 1, 1, 0.250000};
	colorPicture[] = {1, 1, 1, 1};
	colorPictureDisabled[] = {1, 1, 1, 0.250000};
	colorPictureRight[] = {1, 1, 1, 1};
	colorPictureRightDisabled[] = {1, 1, 1, 0.250000};
	colorPictureSelected[] = {1, 1, 1, 1};
	colorScrollbar[] = {1, 0, 0, 0};
	colorSelect2[] = {0, 0, 0, 1};
	colorSelect2Right[] = {0, 0, 0, 1};
	colorSelectBackground2[] = {1, 1, 1, 0.500000};
	colorSelectBackground[] = {0.950000, 0.950000, 0.950000, 1};
	colorSelectRight[] = {0, 0, 0, 1};
	colorShadow[] = {0, 0, 0, 0.500000};
	colorText[] = {1, 1, 1, 1};
	colorTextRight[] = {1, 1, 1, 1};
	disabledCtrlColor[] = {1, 1, 1, 0.500000};
	itemBackground[] = {1, 1, 1, 0.100000};
	tooltipColorBox[] = {1, 1, 1, 1};
	tooltipColorShade[] = {0, 0, 0, 0.650000};
	tooltipColorText[] = {1, 1, 1, 1};
};

class CDAH_RscEdit {
	type = 2;
	style = 0x00 + 0x40;
	font = "PuristaMedium";
	shadow = 2;
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	colorBackground[] = {0, 0, 0, 1};
	soundSelect[] = {"",0.1,1};
	soundExpand[] = {"",0.1,1};
	colorText[] = {0.95, 0.95, 0.95, 1};
	colorDisabled[] = {1, 1, 1, 0.25};
	autocomplete = false;
	colorSelection[] = {"(missionNamespace getVariable ['ZO_GUI_BCG_RGB_R',0.706])", "(missionNamespace getVariable ['ZO_GUI_BCG_RGB_G',0.075])", "(missionNamespace getVariable ['ZO_GUI_BCG_RGB_B',0.216])", 1};
	canModify = 1;
};

class CDAH_RscSlider {
	h = 0.025;
	color[] = {1, 1, 1, 0.8};
	colorActive[] = {1, 1, 1, 1};
};

class CDAH_RscXSliderH 
{
	style = 1024;
	type = 43;
	shadow = 2;
	x = 0;
	y = 0;
	h = 0.029412;
	w = 0.400000;
	color[] = {
			1, 1, 1, 0.7
	};
	colorActive[] = {
			1, 1, 1, 1
	};
	colorDisabled[] = {
			1, 1, 1, 0.500000
	};
	arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
	arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
	border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
	thumb = "\A3\ui_f\data\gui\cfg\slider\thumb_ca.paa";
};

class CDAH_RscFrame {
	type = 0;
	idc = -1;
	style = 64;
	shadow = 2;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {1, 1, 1, 1};
	font = "PuristaMedium";
	sizeEx = 0.02;
	text = "";
};

class CDAH_RscBackground : CDAH_RscText {
	type = 0;
	IDC = -1;
	style = 512;
	shadow = 0;
	x = 0.0;
	y = 0.0;
	w = 1.0;
	h = 1.0;
	text = "";
	ColorBackground[] = {0.48, 0.5, 0.35, 1};
	ColorText[] = {0.1, 0.1, 0.1, 1};
	font = "PuristaMedium";
	SizeEx = 1;
};

class CDAH_RscHTML {
	type = 9;
	style = 0;
	colorText[] = {1, 1, 1, 1.0};
	colorBold[] = {1, 1, 1, 1.0};
	colorLink[] = {1, 1, 1, 0.75};
	colorLinkActive[] = {1, 1, 1, 1.0};
	colorBackground[] = {1,1,1,0.5};
	colorPicture[] = {1, 1, 1, 1};
	colorPictureBorder[] = {1, 0, 0, 1};
	colorPictureLink[] = {0, 0, 1, 1};
	colorPictureSelected[] = {0, 1, 0, 1};	
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	prevPage = "\A3\ui_f\data\gui\Rsccommon\Rschtml\arrow_left_ca.paa";
	nextPage = "\A3\ui_f\data\gui\Rsccommon\Rschtml\arrow_right_ca.paa";
	shadow = 2;
	
	class VScrollBar : CDAH_RscScrollBar
	{
		width = 0.021;
		autoScrollEnabled = 1;
	};
	
	class HScrollBar : CDAH_RscScrollBar
	{
		height = 0.028;
	};	
	class H1 {
		font = "PuristaMedium";
		fontBold = "PuristaSemibold";
		sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
		align = "left";
	};
	
	class H2 {
		font = "PuristaMedium";
		fontBold = "PuristaSemibold";
		sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align = "right";
	};
	
	class H3 {
		font = "PuristaMedium";
		fontBold = "PuristaSemibold";
		sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align = "left";
	};
	
	class H4 {
		font = "PuristaMedium";
		fontBold = "PuristaSemibold";
		sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align = "left";
	};
	
	class H5 {
		font = "PuristaMedium";
		fontBold = "PuristaSemibold";
		sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align = "left";
	};
	
	class H6 {
		font = "PuristaMedium";
		fontBold = "PuristaSemibold";
		sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align = "left";
	};
	
	class P {
		font = "PuristaMedium";
		fontBold = "PuristaSemibold";
		sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align = "left";
	};
};

class CDAH_RscHitZones {
	x = 0;
	y = 0;
	w = 0.1;
	h = 0.1;
	xCount = 1;
	yCount = 1;
	xSpace = 0;
	ySpace = 0;
};

class CDAH_RscCombo {
	style = 16;
	type = 4;
	x = 0;
	y = 0;
	w = 0.12;
	h = 0.035;
	shadow = 0;
	colorSelect[] = {0, 0, 0, 1};
	soundExpand[] = {"",0.1,1};
	colorText[] = {0.95, 0.95, 0.95, 1};
	soundCollapse[] = {"",0.1,1};
	maxHistoryDelay = 1;
	colorBackground[] = {0.4,0.4,0.4,0.4};
	colorSelectBackground[] = {1, 1, 1, 0.7};
	colow_Rscrollbar[] = {1, 0, 0, 1};
	soundSelect[] = {
			"", 0.000000, 1
	};
	arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
	arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
	wholeHeight = 0.45;
	color[] = {1, 1, 1, 1};
	colorActive[] = {1, 0, 0, 1};
	colorDisabled[] = {1, 1, 1, 0.25};
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictureDisabled[] = {1,1,1,1};
	font = "PuristaMedium";
	//sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	sizeEx = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	sizeEx2 = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	rowHeight = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	canDrag = 0;
	itemSpacing = 0.001000;
	
	class ComboScrollBar : CDAH_RscScrollBar {};
};

class CDAH_RscToolbox {
	colorText[] = {0.95, 0.95, 0.95, 1};
	color[] = {0.95, 0.95, 0.95, 1};
	colorTextSelect[] = {0.95, 0.95, 0.95, 1};
	colorSelect[] = {0.95, 0.95, 0.95, 1};
	colorTextDisable[] = {0.4, 0.4, 0.4, 1};
	colorDisable[] = {0.4, 0.4, 0.4, 1};
	colorSelectedBg[] = {"(missionNamespace getVariable ['ZO_GUI_BCG_RGB_R',0.706])", "(missionNamespace getVariable ['ZO_GUI_BCG_RGB_G',0.075])", "(missionNamespace getVariable ['ZO_GUI_BCG_RGB_B',0.216])", 0.5};
	font = "PuristaMedium";
	sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
};

class CDAH_RscButtonInvisible : CDAH_RscButtonMenu {
	animTextureNormal = "#(argb,8,8,3)color(1,1,1,0)";
	animTextureDisabled = "#(argb,8,8,3)color(1,1,1,0)";
	animTextureOver = "#(argb,8,8,3)color(1,1,1,0)";
	animTextureFocused = "#(argb,8,8,3)color(1,1,1,0)";
	animTexturePressed = "#(argb,8,8,3)color(1,1,1,0)";
	animTextureDefault = "#(argb,8,8,3)color(1,1,1,0)";
	colorBackground[] = {0, 0, 0, 0};
	colorBackground2[] = {1, 1, 1, 0};
	color[] = {1, 1, 1, 0};
	color2[] = {1, 1, 1, 0};
	colorText[] = {1, 1, 1, 0};
	colorDisabled[] = {1, 1, 1, 0};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {0,0,0,1};
	tooltipColorShade[] = {0,0,0,0.65};
};