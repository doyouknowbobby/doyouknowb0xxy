# Frame1/B0XX layout style public-source digital controller software for the Raspberry Pi Pico (v2.0.0)

This is a modular, runtime-remappable and easily extensible digital controller software for the Raspberry Pi Pico, that can identify as various controllers such as a GCC to USB adapter, an Xbox controller, a Switch pro-like controller, a generic controller and keyboard and communicate over the Joybus (Gamecube/Wii) and USB protocols and using various conversion logics, namely at least Melee, P+, Ultimate.

It is intended for use with the Rana Digital controller/layout (standard frame1 "rectangle" layout with the addition of up2 in a WASD layout). Other Pico-based controllers will need to disable up2 (in code, then recompile) or via runtime-remapping every time its plugged in.

## TOC

1. [Safety Information](#safety)
2. [Quick Start](#quick-start)
3. [Changing Modes](#modes)
4. [Default Button Mapping](#buttons)
5. [Runtime Button Remapping](#remapping)
6. [Updating the Firmeware](#updating)
7. [Other Documentation](#docs)
8. [LEGAL INFORMATION](#legal)
9. [Gratitude](#thanks)
10. [Contact](#contact)

### Safety Information

<a name="safety"/>

Don't have this board plugged via USB and via its Gamecube port at the same time. This would feed the USB 5v to the 3v line of the console and likely damage it.

If you want to prevent this electrically, use Schottky diodes, or power VSYS with the 5v from the console and don't connect the console 3v. Be aware that doing this implies the controller won't work on consoles with broken rumble lines anymore.

### Quick Start

<a name="quick-start"/>


### Changing Modes

<a name="modes"/>

### Default Button Mapping

<a name="buttons"/>

### Runtime Button Remapping

<a name="remapping"/>

### Updating Firmware

<a name="updating"/>

### Other Documentation

<a name="docs"/>

* [Mode Select](docs/MODES.md)
* [Button Mapping](docs/MAPPING.md)
* [Arte README (v 1.2.4)](docs/README_arte_v124.md)
* [Rana README (v 1.1.0)](docs/README_rana-digital_v110.md)

### LEGAL INFORMATION

<a name="legal"/>

This project is free to use in 'digital' game controllers (colloquially known as fightsticks or rectangles), but only in non-commercial settings.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

In particular, when communicating over USB, device using this software may use the 0x057E USB Vendor ID, that is affiliated with Nintendo, and other proprietary USB vendor IDs. By uploading this software onto your board, you assert that you understand what that means and take entire responsibility for it.

### Gratitude

<a name="thanks"/>

Thanks to:

### Contact

<a name="contact"/>

Discord: doyouknowbobby#1234567890

Twitter: https://twitter.com/doyouknowbobby