# Description
Enter a human-readable description of your changes.
(ex): This change includes the mental ability to always choose the right button in a high-pressure situation.

## Changes
Include any additions, changes, or removals here in a concise manner.
Add DAC Algorithms -> PlayStation4
Update DAC Algorithms -> Xbox 360 with `Home` button
Remove DAC Algorithms -> ColecoVision

### Affected Modes
Check the boxes for any mode that is affected by your changes. Make sure to note if these will apply to future modes using a certain DAC algorithm, Communications Protocol, or Button Set.
#### Console
- [ ] `No button` - Melee (Joybus) mode
- [ ] `GP2` - `Right` P+ (Joybus) mode
- [ ] `GP6` - `MX` - Ultimate (Joybus) mode
- [ ] `GP7` - `MY` - P+ (Joybus) mode
#### USB
- [ ] `Nothing Pressed` - XInput (Leverless Fightstick)
- [ ] `GP0` - `Start` - 8KRO Keyboard
- [ ] `GP2` - `Right` - Wired Fight Pad Pro (P+)
- [ ] `GP4` - `Left` - Wired Fight Pad Pro (Wired Fight Pad Pro)
- [ ] `GP5` - `L` - Wired Fight Pad Pro (Melee)
- [ ] `GP6` - `MX` - Ultimate (Adapter) mode
- [ ] `GP7` - `MY` - P+ (Adapter) mode
- [ ] `GP12` - `CUp` - Melee (Adapter) mode
- [ ] `GP13` - `CLeft` - XInput (Xbox360 Controller Melee)
- [ ] `GP14` - `A` - XInput (Xbox360 Controller)
- [ ] `GP16` - `CRight` - `BOOTSEL` firmware update
- [ ] `GP17` - `Up` - Runtime Remapping
- [ ] `GP20` - `LS` - HID Controller (P+)
- [ ] `GP21` - `X` - HID Controller (Melee)
- [ ] `GP22` - `Y` - HID Controller (Ultimate)
- [ ] Any other future modes using the Xbox360 DAC Algorithm

### Testing done
Include the steps you took to verify that your changes are operating as intended. Make sure you've covered all possible regressions.
- Verified behavior when holding `A`, plugging into PC via Steam (identified as Xbox 360 controller, all mapped buttons recognized)

### How to reproduce this
Include the steps someone else should take to verify your changes are operating as intended. 
1. Hold `A` button while plugging into PC or Xbox (using a Brooks Wingman XB) to enter Xbox360 dedicated mode.
    1. Verify pressing `Start` immediately wins you the round.
    2. Verify pressing `Start` + `MS` immediately wins you the round, and awards a Perfect (regardless of damange taken).

### Not working
Include anything that isn't working correctly. Include whether or not you caused it.
- When holding `A`, plugging into Playstation4 Pro via Brooks Wingman XE (Controller explodes)
    - Does **not** behavior in upstream (bjart) repo
