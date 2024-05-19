# Frame1/B0XX layout style public-source digital controller software for the Raspberry Pi Pico (v2.0.0)

This is a modular, runtime-remappable and easily extensible digital controller software for the Raspberry Pi Pico, that can identify as various controllers such as a GCC to USB adapter, an Xbox controller, a Switch Pro-like controller, a generic controller and keyboard and communicate over the Joybus (Gamecube/Wii) and USB protocols and using various conversion logics, namely at least Melee, P+, Ultimate.

It is intended for use with the Rana Digital controller/layout (standard frame1 "rectangle" layout with the addition of `up2` in a WASD layout). Other Pico-based controllers will need to disable `up2` (in code, then recompile) or via runtime-remapping.

## TOC

1. [Safety Information](#safety-information)
2. [Quick Start](#quick-start)
3. [Changing Modes](#changing-modes)
4. [Runtime Button Remapping](#runtime-button-remapping)
5. [Updating the Firmeware](#updating-firmware)
6. [Other Documentation](#other-documentation)
7. [LEGAL INFORMATION](#legal-information)
8. [Gratitude](#gratitude)
9. [Contact](#contact)

### Safety Information

Don't have this board plugged via USB and via its GameCube port at the same time. This would feed the USB 5v to the 3v line of the console and likely damage it.

If you want to prevent this electrically, use Schottky diodes, or power VSYS with the 5v from the console and don't connect the console 3v. Be aware that doing this implies the controller won't work on consoles with broken rumble lines anymore.

### Quick Start

### Changing Modes

Hold a specified button while plugging the controller in, and that mode will be selected until the controller is disconnected.

**The advised modes are the following**:
- `BOOTSEL` mode for updating firmware => (`CRight`)
- Runtime remapping mode => (`Up`)
- Playing Melee resp. P+ on console => Melee resp. P+ + Joybus
- Playing Melee resp. P+ on PC => Melee resp. P+ + Adapter mode
- Playing Ultimate on Switch or PC => Ultimate + Adapter mode
- Playing other games on Switch => WFPP + WFPP (`Left`)
- Playing other games on PC => XInput + Leverless (`no button`) or XInput + Xbox360 (`A`) or 8KeysSet + Keyboard (`Start`)
- Playing other games on Xbox (requires Brooks Wingman XB) => XInput + Leverless (`no button`) or XInput + Xbox360 (`A`) or Melee + Xbox360 (`CLeft`)
- Playing other games on PlayStation (requires Brooks Wingman XE) =>  XInput + Leverless (`no button`) or XInput + Xbox360 (`A`) or WFPP + WFPP (`Left`)
- Playing (non-Smash) platform fighters on Xbox or PC => Melee + Xbox360 (`CLeft`) or 
- Playing Melee/P+ on PC on the same setup as someone using a Gamecube controller and therefore an adapter => Melee/P+ + HID & configure the HID

Find more details, including button mapping [here](docs/MODES.md).

### Runtime Button Remapping

Enter Runtime Rempapping mode by holding `Up` when plugging in the controller.

Find more details, including the order of button presses [here](docs/MAPPING.md).

### Updating Firmware

Enter `BOOTSEL` mode by holding `CRight` when plugging in the controller while connected to a PC. You can then choose a new `.uf2` compiled binary to overwrite the current firmware.

Find more details, including the order of button presses [here](docs/MAPPING.md).

### Other Documentation

* [Modes and Button Mapping](docs/MODES.md)
* [Button Remapping and Firmware Update](docs/MAPPING.md)
* [JulienBernard3383279/pico-rectangle (Arte) README (v 1.2.4)](docs/vendor/arte/README_arte_v124.md)
* [rana-sylvatica/pico-rectangle-rana-digital README (v 1.1.0)](docs/vendor/rd/README_rana-digital_v110.md)

### LEGAL INFORMATION

This project is free to use in 'digital' game controllers (colloquially known as fightsticks or rectangles), but only in non-commercial settings.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

In particular, when communicating over USB, device using this software may use the 0x057E USB Vendor ID, that is affiliated with Nintendo, and other proprietary USB vendor IDs. By uploading this software onto your board, you assert that you understand what that means and take entire responsibility for it.

### Gratitude

Thanks to:

### Contact

Discord: doyouknowbobby#1234567890

Twitter: https://twitter.com/doyouknowbobby
