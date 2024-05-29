#ifndef DAC_ALGORITHMS__XBOX_360_HPP
#define DAC_ALGORITHMS__XBOX_360_HPP

#include "usb_configurations/xbox_360.hpp"

#include "gpio_to_button_sets/F1.hpp"

namespace DACAlgorithms {
namespace Xbox360 {

void actuateXbox360Report(GpioToButtonSets::F1::ButtonSet buttonSet);

void actuateLeverlessReport(GpioToButtonSets::F1::ButtonSet buttonSet);

void actuateMultiversusReport(GpioToButtonSets::F1::ButtonSet buttonSet);

}
}
#endif

