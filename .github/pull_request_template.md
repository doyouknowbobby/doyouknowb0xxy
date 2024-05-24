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
- [ ] `No button` - Ultimate (Joybus)
- [ ] `GP1` - `Up2` - Ultimate _Macro_ (Joybus)
- [ ] `GP2` - `Right` P+ (Joybus)
- [ ] `GP6` - `MX` - Ultimate (Joybus)
- [ ] `GP7` - `MY` - P+ (Joybus)
- [ ] `GP15` - `CDown` - Melee (Joybus)
#### USB
- [ ] `No button` - XInput (Leverless Fightstick)
- [X] `GP0` - `Start` - 8KRO Keyboard
- [ ] `GP1` - `Up2` - Ultimate _Macro_ (GCN Adapter)
- [ ] `GP2` - `Right` - Wired Fight Pad Pro (P+)
- [ ] `GP3` - `Down` Wired Fight Pad Pro (Leverless Fightstick)
- [ ] `GP4` - `Left` - Wired Fight Pad Pro (Wired Fight Pad Pro)
- [ ] `GP5` - `L` - Wired Fight Pad Pro (Melee)
- [ ] `GP6` - `MX` - Ultimate (GCN Adapter)
- [ ] `GP7` - `MY` - P+ (GCN Adapter)
- [ ] `GP12` - `CUp` - **OPEN**
- [ ] `GP13` - `CLeft` - XInput (Melee)
- [ ] `GP14` - `A` - XInput (Xbox360 Controller)
- [ ] `GP15` - `CDown` - Melee (GCN Adapter)
- [ ] `GP16` - `CRight` - `BOOTSEL` Firmware Update
- [ ] `GP17` - `Up` - Runtime Remapping
- [ ] `GP18` - `MS` - **OPEN**
- [ ] `GP19` - `Z` - **OPEN**
- [ ] `GP20` - `LS` - HID Controller (P+)
- [ ] `GP21` - `X` - HID Controller (Melee)
- [ ] `GP22` - `Y` - HID Controller (Ultimate)
- [ ] `GP26` - `B` - **OPEN**
- [ ] `GP27` - `R` - **OPEN**
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
