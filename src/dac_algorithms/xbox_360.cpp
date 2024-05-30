#include "dac_algorithms/xbox_360.hpp"

namespace DACAlgorithms {
namespace Xbox360 {

void actuateXbox360Report(GpioToButtonSets::F1::ButtonSet buttonSet) {
    // Modifier button is MS
    bool mod = buttonSet.ms;
	
    // up2 -> up
    // up -> up (might as well)
    buttonSet.up = buttonSet.up || buttonSet.up2;

    // Raw Movement button presses.
    bool left = buttonSet.left && !(mod);
    bool right = buttonSet.right && !(mod);
    bool up = buttonSet.up && !(mod);
    bool down = buttonSet.down && !(mod);

    // Left stick + Modifer button -> D-Pad
    bool dLeft = buttonSet.left && mod;
    bool dRight = buttonSet.right && mod;
    bool dUp = buttonSet.up && mod;
    bool dDown = buttonSet.down && mod;

    // R / B + Modifier Button -> Home / View
    bool home = buttonSet.r && mod;         // Home
    bool r = buttonSet.r && !(mod);         // R
    bool back = buttonSet.b && mod;         // View
    bool b = buttonSet.b && !(mod);         // B

    USBConfigurations::Xbox360::ControllerReport &xInputReport = USBConfigurations::Xbox360::xInputReport;
    xInputReport.reportId = 0;
    xInputReport.rightStickPress = buttonSet.my;
    xInputReport.leftStickPress = buttonSet.mx;
    xInputReport.back = back;
    xInputReport.start = buttonSet.start;
    xInputReport.dRight = dRight;
    xInputReport.dLeft = dLeft;
    xInputReport.dDown = dDown;
    xInputReport.dUp = dUp;
    xInputReport.zl = buttonSet.ls;
    xInputReport.zr = buttonSet.z;
    xInputReport.home = home;
    xInputReport.pad1 = 0;									// Inaccessible
    xInputReport.a = buttonSet.a;
    xInputReport.b = b;
    xInputReport.x = buttonSet.x;
    xInputReport.y = buttonSet.y;
    xInputReport.leftTrigger = buttonSet.l ? 255 : 0;
    xInputReport.rightTrigger = r ? 255 : 0;
    xInputReport.leftStickX = left && right ? 0 : left ? 0x8000 : right ? 0x7FFF : 0;
    xInputReport.leftStickY = down && up ? 0 : down ? 0x8000 : up ? 0x7FFF : 0;
    xInputReport.rightStickX = buttonSet.cLeft && buttonSet.cRight ? 0 : buttonSet.cLeft ? 0x8000 : buttonSet.cRight ? 0x7FFF : 0;
    xInputReport.rightStickY = buttonSet.cDown && buttonSet.cUp ? 0 : buttonSet.cDown ? 0x8000 : buttonSet.cUp ? 0x7FFF : 0;
};

// Map face and shoulder buttons to top two rows on right side. We're a fightstick now.
// Use up2 for up to appease WASD players.
// Use MY for up to appease Hitbox players.
// MX and A are LS Press and RS Press.
// L is a modifier: L+Start = Home, L+Left/Right/Up/Down = Dpad left/right/up/down, L+MY = Back
void actuateLeverlessReport(GpioToButtonSets::F1::ButtonSet buttonSet) {
    // Modifier button is L
    bool mod = buttonSet.l;

    // up -> RB (you can always have too many ups)
    bool zr = buttonSet.up;

    // up2 -> up
    // MY -> up (you can never have too many ups)
    buttonSet.up = (buttonSet.up2 || buttonSet.my);

    bool left = buttonSet.left && !(mod);
    bool right = buttonSet.right && !(mod);
    bool up = buttonSet.up && !(mod);
    bool down = buttonSet.down && !(mod);

    // Left stick + Modifer button -> D-Pad
    bool dLeft = buttonSet.left && mod;
    bool dRight = buttonSet.right && mod;
    bool dUp = buttonSet.up && mod;
    bool dDown = buttonSet.down && mod;

    // R / B + Modifier Button -> Home / View
    bool home = buttonSet.r && mod;         // Home
    bool r = buttonSet.r && !(mod);         // R
    bool back = buttonSet.b && mod;         // View
    bool b = buttonSet.b && !(mod);         // B

    USBConfigurations::Xbox360::ControllerReport &xInputReport = USBConfigurations::Xbox360::xInputReport;
    xInputReport.reportId = 0;
    xInputReport.rightStickPress = buttonSet.a;
    xInputReport.leftStickPress = buttonSet.mx;
    xInputReport.back = back;
    xInputReport.start = buttonSet.start;
    xInputReport.dRight = dRight;
    xInputReport.dLeft = dLeft;
    xInputReport.dDown = dDown;
    xInputReport.dUp = dUp;
    xInputReport.zl = buttonSet.z;
    xInputReport.zr = zr;
    xInputReport.home = home;
    xInputReport.pad1 = 0;									// Inaccessible
    xInputReport.a = b;
    xInputReport.b = buttonSet.x;
    xInputReport.x = r;
    xInputReport.y = buttonSet.y;
    xInputReport.leftTrigger = buttonSet.ls ? 255 : 0;
    xInputReport.rightTrigger = buttonSet.ms ? 255 : 0;
    xInputReport.leftStickX = left && right ? 0 : left ? 0x8000 : right ? 0x7FFF : 0; // Neutral SOCD 
    xInputReport.leftStickY = down && up ? 0x7FFF : down ? 0x8000 : up ? 0x7FFF : 0; // Up overrides down
    xInputReport.rightStickX = buttonSet.cLeft && buttonSet.cRight ? 0 : buttonSet.cLeft ? 0x8000 : buttonSet.cRight ? 0x7FFF : 0; // Neutral SOCD 
    xInputReport.rightStickY = buttonSet.cDown && buttonSet.cUp ? 0x7FFF : buttonSet.cDown ? 0x8000 : buttonSet.cUp ? 0x7FFF : 0; // Up overrides down
};

// Basic-ass DAC Algorithm for Mutliversus. Copied from actuateXbox360Report() so 
// it doesn't have movement modifiers or non-neutral SOCD yet.
void actuateMultiversusReport(GpioToButtonSets::F1::ButtonSet buttonSet) {
    // Modifier button is L
    bool mod = buttonSet.l;
	
    // up2 -> up
    // up -> up (might as well)
    buttonSet.up = buttonSet.up || buttonSet.up2;

    // MX / MY + Modifier Button -> L3 / R3
    bool mx = buttonSet.mx && !(mod);
    bool my = buttonSet.my && !(mod);
    bool l3 = buttonSet.mx && mod;
    bool r3 = buttonSet.my && mod;

    // Raw movement on left stick.
    bool left = buttonSet.left && !(mod);
    bool right = buttonSet.right && !(mod);
    bool up = buttonSet.up && !(mod);
    bool down = buttonSet.down && !(mod);

    // Resolve SOCD on left stick. (Neutral)
    uint8_t lx_coord = left && right ? 0 : left ? 0x8000 : right ? 0x7FFF : 0;
    uint8_t ly_coord = down && up ? 0 : down ? 0x8000 : up ? 0x7FFF : 0;
    
    // Apply Modifier(s) to left stick.
    // lx_coord = ;
    // ly_coord = ;
    
    // Resolve SOCD on right stick (Neutral).
    uint8_t rx_coord = buttonSet.cLeft && buttonSet.cRight ? 0 : buttonSet.cLeft ? 0x8000 : buttonSet.cRight ? 0x7FFF : 0;
    uint8_t ry_coord = buttonSet.cDown && buttonSet.cUp ? 0 : buttonSet.cDown ? 0x8000 : buttonSet.cUp ? 0x7FFF : 0

    // Apply Modifier(s) to right stick.
    // rx_coord = ;
    // ry_coord = ;
	
    // Left stick + Modifer button -> D-Pad
    bool dLeft = buttonSet.left && mod;
    bool dRight = buttonSet.right && mod;
    bool dUp = buttonSet.up && mod;
    bool dDown = buttonSet.down && mod;
	
    // R / B + Modifier Button -> Home / View
    bool home = buttonSet.r && mod;         // Home
    bool r = buttonSet.r && !(mod);         // R
    bool back = buttonSet.b && mod;         // View
    bool b = buttonSet.b && !(mod);         // B

    // LS -> LB
    // MS -> LT

    USBConfigurations::Xbox360::ControllerReport &xInputReport = USBConfigurations::Xbox360::xInputReport;
    xInputReport.reportId = 0;
    xInputReport.rightStickPress = l3;                       // MX + L
    xInputReport.leftStickPress = r3;                        // MY + L
    xInputReport.back = back;
    xInputReport.start = start;
    xInputReport.dRight = dRight;
    xInputReport.dLeft = dLeft;
    xInputReport.dDown = dDown;
    xInputReport.dUp = dUp;
    xInputReport.zl = buttonSet.ls;                         // LS = LB
    xInputReport.zr = buttonSet.z;
    xInputReport.home = home;
    xInputReport.pad1 = 0;                                  // Inaccessible
    xInputReport.a = buttonSet.a;
    xInputReport.b = b;
    xInputReport.x = buttonSet.x;
    xInputReport.y = buttonSet.y;
    xInputReport.leftTrigger = buttonSet.ms ? 255 : 0;      // MS = LT
    xInputReport.rightTrigger = r ? 255 : 0
    xInputReport.leftStickX = lx_coord;
    xInputReport.leftStickY = ly_coord;
    xInputReport.rightStickX = rx_coord;
    xInputReport.rightStickY = ry_coord;
};

}
}
