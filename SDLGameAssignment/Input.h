#pragma once
#include <SDL.h>
#include "Vector.h"
/*===================================================================#
| These are the physical key codes                                   |
#===================================================================*/
constexpr auto HM_KEY_A = 4;
constexpr auto HM_KEY_B = 5;
constexpr auto HM_KEY_C = 6;
constexpr auto HM_KEY_D = 7;
constexpr auto HM_KEY_E = 8;
constexpr auto HM_KEY_F = 9;
constexpr auto HM_KEY_G = 10;
constexpr auto HM_KEY_H = 11;
constexpr auto HM_KEY_I = 12;
constexpr auto HM_KEY_J = 13;
constexpr auto HM_KEY_K = 14;
constexpr auto HM_KEY_L = 15;
constexpr auto HM_KEY_M = 16;
constexpr auto HM_KEY_N = 17;
constexpr auto HM_KEY_O = 18;
constexpr auto HM_KEY_P = 19;
constexpr auto HM_KEY_Q = 20;
constexpr auto HM_KEY_R = 21;
constexpr auto HM_KEY_S = 22;
constexpr auto HM_KEY_T = 23;
constexpr auto HM_KEY_U = 24;
constexpr auto HM_KEY_V = 25;
constexpr auto HM_KEY_W = 26;
constexpr auto HM_KEY_X = 27;
constexpr auto HM_KEY_Y = 28;
constexpr auto HM_KEY_Z = 29;

constexpr auto HM_KEY_1 = 30;
constexpr auto HM_KEY_2 = 31;
constexpr auto HM_KEY_3 = 32;
constexpr auto HM_KEY_4 = 33;
constexpr auto HM_KEY_5 = 34;
constexpr auto HM_KEY_6 = 35;
constexpr auto HM_KEY_7 = 36;
constexpr auto HM_KEY_8 = 37;
constexpr auto HM_KEY_9 = 38;
constexpr auto HM_KEY_0 = 39;

constexpr auto HM_KEY_RETURN = 40;
constexpr auto HM_KEY_ESCAPE = 41;
constexpr auto HM_KEY_BACKSPACE = 42;
constexpr auto HM_KEY_TAB = 43;
constexpr auto HM_KEY_SPACE = 44;

constexpr auto HM_KEY_MINUS = 45;
constexpr auto HM_KEY_EQUALS = 46;
constexpr auto HM_KEY_LEFTBRACKET = 47;
constexpr auto HM_KEY_RIGHTBRACKET = 48;
constexpr auto HM_KEY_BACKSLASH = 49;

constexpr auto HM_KEY_SEMICOLON = 51;
constexpr auto HM_KEY_APOSTROPHE = 52;
constexpr auto HM_KEY_GRAVE = 53;
constexpr auto HM_KEY_COMMA = 54;
constexpr auto HM_KEY_PERIOD = 55;
constexpr auto HM_KEY_SLASH = 56;

constexpr auto HM_KEY_CAPSLOCK = 57;

constexpr auto HM_KEY_F1 = 58;
constexpr auto HM_KEY_F2 = 59;
constexpr auto HM_KEY_F3 = 60;
constexpr auto HM_KEY_F4 = 61;
constexpr auto HM_KEY_F5 = 62;
constexpr auto HM_KEY_F6 = 63;
constexpr auto HM_KEY_F7 = 64;
constexpr auto HM_KEY_F8 = 65;
constexpr auto HM_KEY_F9 = 66;
constexpr auto HM_KEY_F10 = 67;
constexpr auto HM_KEY_F11 = 68;
constexpr auto HM_KEY_F12 = 69;

constexpr auto HM_KEY_PRINTSCREEN = 70;
constexpr auto HM_KEY_SCROLLLOCK = 71;
constexpr auto HM_KEY_PAUSE = 72;
constexpr auto HM_KEY_INSERT = 73;
constexpr auto HM_KEY_HOME = 74;
constexpr auto HM_KEY_PAGEUP = 75;
constexpr auto HM_KEY_DELETE = 76;
constexpr auto HM_KEY_END = 77;
constexpr auto HM_KEY_PAGEDOWN = 78;
constexpr auto HM_KEY_RIGHT = 79;
constexpr auto HM_KEY_LEFT = 80;
constexpr auto HM_KEY_DOWN = 81;
constexpr auto HM_KEY_UP = 82;

constexpr auto HM_KEY_NUMLOCK = 83;
constexpr auto HM_KEY_KP_DIVIDE = 84;
constexpr auto HM_KEY_KP_MULTIPLY = 85;
constexpr auto HM_KEY_KP_MINUS = 86;
constexpr auto HM_KEY_KP_PLUS = 87;
constexpr auto HM_KEY_KP_ENTER = 88;
constexpr auto HM_KEY_KP_1 = 89;
constexpr auto HM_KEY_KP_2 = 90;
constexpr auto HM_KEY_KP_3 = 91;
constexpr auto HM_KEY_KP_4 = 92;
constexpr auto HM_KEY_KP_5 = 93;
constexpr auto HM_KEY_KP_6 = 94;
constexpr auto HM_KEY_KP_7 = 95;
constexpr auto HM_KEY_KP_8 = 96;
constexpr auto HM_KEY_KP_9 = 97;
constexpr auto HM_KEY_KP_0 = 98;
constexpr auto HM_KEY_KP_PERIOD = 99;

constexpr auto HM_KEY_APPLICATION = 101;
constexpr auto HM_KEY_POWER = 102;
constexpr auto HM_KEY_KP_EQUALS = 103;
constexpr auto HM_KEY_F13 = 104;
constexpr auto HM_KEY_F14 = 105;
constexpr auto HM_KEY_F15 = 106;
constexpr auto HM_KEY_F16 = 107;
constexpr auto HM_KEY_F17 = 108;
constexpr auto HM_KEY_F18 = 109;
constexpr auto HM_KEY_F19 = 110;
constexpr auto HM_KEY_F20 = 111;
constexpr auto HM_KEY_F21 = 112;
constexpr auto HM_KEY_F22 = 113;
constexpr auto HM_KEY_F23 = 114;
constexpr auto HM_KEY_F24 = 115;
constexpr auto HM_KEY_EXECUTE = 116;
constexpr auto HM_KEY_HELP = 117;
constexpr auto HM_KEY_MENU = 118;
constexpr auto HM_KEY_SELECT = 119;
constexpr auto HM_KEY_STOP = 120;
constexpr auto HM_KEY_AGAIN = 121;
constexpr auto HM_KEY_UNDO = 122;
constexpr auto HM_KEY_CUT = 123;
constexpr auto HM_KEY_COPY = 124;
constexpr auto HM_KEY_PASTE = 125;
constexpr auto HM_KEY_FIND = 126;
constexpr auto HM_KEY_MUTE = 127;
constexpr auto HM_KEY_VOLUMEUP = 128;
constexpr auto HM_KEY_VOLUMEDOWN = 129;

constexpr auto HM_KEY_KP_COMMA = 133;
constexpr auto HM_KEY_KP_EQUALSAS400 = 134;

constexpr auto HM_KEY_ALTERASE = 153;
constexpr auto HM_KEY_SYSREQ = 154;
constexpr auto HM_KEY_CANCEL = 155;
constexpr auto HM_KEY_CLEAR = 156;
constexpr auto HM_KEY_PRIOR = 157;
constexpr auto HM_KEY_RETURN2 = 158;
constexpr auto HM_KEY_SEPARATOR = 159;
constexpr auto HM_KEY_OUT = 160;
constexpr auto HM_KEY_OPER = 161;
constexpr auto HM_KEY_CLEARAGAIN = 162;
constexpr auto HM_KEY_CRSEL = 163;
constexpr auto HM_KEY_EXSEL = 164;

constexpr auto HM_KEY_KP_00 = 176;
constexpr auto HM_KEY_KP_000 = 177;
constexpr auto HM_KEY_THOUSANDSSEPARATOR = 178;
constexpr auto HM_KEY_DECIMALSEPARATOR = 179;
constexpr auto HM_KEY_CURRENCYUNIT = 180;
constexpr auto HM_KEY_CURRENCYSUBUNIT = 181;
constexpr auto HM_KEY_KP_LEFTPAREN = 182;
constexpr auto HM_KEY_KP_RIGHTPAREN = 183;
constexpr auto HM_KEY_KP_LEFTBRACE = 184;
constexpr auto HM_KEY_KP_RIGHTBRACE = 185;
constexpr auto HM_KEY_KP_TAB = 186;
constexpr auto HM_KEY_KP_BACKSPACE = 187;
constexpr auto HM_KEY_KP_A = 188;
constexpr auto HM_KEY_KP_B = 189;
constexpr auto HM_KEY_KP_C = 190;
constexpr auto HM_KEY_KP_D = 191;
constexpr auto HM_KEY_KP_E = 192;
constexpr auto HM_KEY_KP_F = 193;
constexpr auto HM_KEY_KP_XOR = 194;
constexpr auto HM_KEY_KP_POWER = 195;
constexpr auto HM_KEY_KP_PERCENT = 196;
constexpr auto HM_KEY_KP_LESS = 197;
constexpr auto HM_KEY_KP_GREATER = 198;
constexpr auto HM_KEY_KP_AMPERSAND = 199;
constexpr auto HM_KEY_KP_DBLAMPERSAND = 200;
constexpr auto HM_KEY_KP_VERTICALBAR = 201;
constexpr auto HM_KEY_KP_DBLVERTICALBAR = 202;
constexpr auto HM_KEY_KP_COLON = 203;
constexpr auto HM_KEY_KP_HASH = 204;
constexpr auto HM_KEY_KP_SPACE = 205;
constexpr auto HM_KEY_KP_AT = 206;
constexpr auto HM_KEY_KP_EXCLAM = 207;
constexpr auto HM_KEY_KP_MEMSTORE = 208;
constexpr auto HM_KEY_KP_MEMRECALL = 209;
constexpr auto HM_KEY_KP_MEMCLEAR = 210;
constexpr auto HM_KEY_KP_MEMADD = 211;
constexpr auto HM_KEY_KP_MEMSUBTRACT = 212;
constexpr auto HM_KEY_KP_MEMMULTIPLY = 213;
constexpr auto HM_KEY_KP_MEMDIVIDE = 214;
constexpr auto HM_KEY_KP_PLUSMINUS = 215;
constexpr auto HM_KEY_KP_CLEAR = 216;
constexpr auto HM_KEY_KP_CLEARENTRY = 217;
constexpr auto HM_KEY_KP_BINARY = 218;
constexpr auto HM_KEY_KP_OCTAL = 219;
constexpr auto HM_KEY_KP_DECIMAL = 220;
constexpr auto HM_KEY_KP_HEXADECIMAL = 221;

constexpr auto HM_KEY_LCTRL = 224;
constexpr auto HM_KEY_LSHIFT = 225;
constexpr auto HM_KEY_LALT = 226;
constexpr auto HM_KEY_LGUI = 227;
constexpr auto HM_KEY_RCTRL = 228;
constexpr auto HM_KEY_RSHIFT = 229;
constexpr auto HM_KEY_RALT = 230;
constexpr auto HM_KEY_RGUI = 231;

constexpr auto HM_KEY_MODE = 257;

constexpr auto HM_KEY_AUDIONEXT = 258;
constexpr auto HM_KEY_AUDIOPREV = 259;
constexpr auto HM_KEY_AUDIOSTOP = 260;
constexpr auto HM_KEY_AUDIOPLAY = 261;
constexpr auto HM_KEY_AUDIOMUTE = 262;
constexpr auto HM_KEY_MEDIASELECT = 263;
constexpr auto HM_KEY_WWW = 264;
constexpr auto HM_KEY_MAIL = 265;
constexpr auto HM_KEY_CALCULATOR = 266;
constexpr auto HM_KEY_COMPUTER = 267;
constexpr auto HM_KEY_AC_SEARCH = 268;
constexpr auto HM_KEY_AC_HOME = 269;
constexpr auto HM_KEY_AC_BACK = 270;
constexpr auto HM_KEY_AC_FORWARD = 271;
constexpr auto HM_KEY_AC_STOP = 272;
constexpr auto HM_KEY_AC_REFRESH = 273;
constexpr auto HM_KEY_AC_BOOKMARKS = 274;

constexpr auto HM_KEY_BRIGHTNESSDOWN = 275;
constexpr auto HM_KEY_BRIGHTNESSUP = 276;
constexpr auto HM_KEY_DISPLAYSWITCH = 277;
constexpr auto HM_KEY_KBDILLUMTOGGLE = 278;
constexpr auto HM_KEY_KBDILLUMDOWN = 279;
constexpr auto HM_KEY_KBDILLUMUP = 280;
constexpr auto HM_KEY_EJECT = 281;
constexpr auto HM_KEY_SLEEP = 282;

constexpr auto HM_KEY_APP1 = 283;
constexpr auto HM_KEY_APP2 = 284;

constexpr auto HM_KEY_AUDIOREWIND = 285;
constexpr auto HM_KEY_AUDIOFASTFORWARD = 286;

/*===================================================================#
| These are the key codes for the modifier keys                      |
#===================================================================*/

constexpr auto HM_MOD_NONE = 0;
constexpr auto HM_MOD_LSHIFT = 1;
constexpr auto HM_MOD_RSHIFT = 2;
constexpr auto HM_MOD_LCTRL = 64;
constexpr auto HM_MOD_RCTRL = 128;
constexpr auto HM_MOD_LALT = 256;
constexpr auto HM_MOD_RALT = 512;
constexpr auto HM_MOD_LGUI = 1024;
constexpr auto HM_MOD_RGUI = 2048;
constexpr auto HM_MOD_NUM = 4096;
constexpr auto HM_MOD_CAPS = 8192;
constexpr auto HM_MOD_MODE = 16384;
constexpr auto HM_MOD_RESERVED = 32768;

/*===================================================================#
| These are the custom-made codes to be used when checking the       |
| state of the mouse buttons                                         |
#===================================================================*/

constexpr auto HM_MOUSE_NONE = 0;
constexpr auto HM_MOUSE_LEFT = 1;
constexpr auto HM_MOUSE_MIDDLE = 2;
constexpr auto HM_MOUSE_RIGHT = 4;

class Input
{
public:
	static Input *Instance();

	[[nodiscard]] int GetKey() const;

	[[nodiscard]] int GetMouseButtonUp() const;
	[[nodiscard]] int GetMouseWheel() const;

	[[nodiscard]] const Vector<int> &GetMouseMotion() const;
	[[nodiscard]] const Vector<int> &GetMousePosition() const;

	static void SetCursorState(bool isCursorEnabled, bool isCursorVisible);

	[[nodiscard]] bool IsWindowClosed() const;

	[[nodiscard]] bool IsKeyPressed() const;
	static bool IsKeyPressed(int keyCode);
	[[nodiscard]] bool IsModifierPressed(int modifier_1, int modifier_2 = HM_MOD_NONE) const;

	[[nodiscard]] bool IsMouseClicked() const;
	[[nodiscard]] bool IsMouseClicked(int mouseButton_1, int mouseButton_2 = HM_MOUSE_NONE) const;

	void Update();

	Input(const Input &) = delete;

private:
	Input() = default;

	int m_key{};

	int m_mouseWheel{0};
	int m_modifier{HM_MOD_NONE};
	int m_mouseButton{HM_MOUSE_NONE};
	int m_mouseButtonUp{NULL};

	bool m_isKeyPressed{false};
	bool m_isMouseClicked{false};
	bool m_isWindowClosed{false};

	Vector<int> m_mouseMotion;
	Vector<int> m_mousePosition;
};