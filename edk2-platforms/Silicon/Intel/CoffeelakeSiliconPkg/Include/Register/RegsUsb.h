/** @file
  Register names for USB Host and device controller

  Conventions:

  - Register definition format:
    Prefix_[GenerationName]_[ComponentName]_SubsystemName_RegisterSpace_RegisterName
  - Prefix:
    Definitions beginning with "R_" are registers
    Definitions beginning with "B_" are bits within registers
    Definitions beginning with "V_" are meaningful values within the bits
    Definitions beginning with "S_" are register size
    Definitions beginning with "N_" are the bit position
  - [GenerationName]:
    Three letter acronym of the generation is used .
    Register name without GenerationName applies to all generations.
  - [ComponentName]:
    This field indicates the component name that the register belongs to (e.g. PCH, SA etc.)
    Register name without ComponentName applies to all components.
    Register that is specific to -H denoted by "_PCH_H_" in component name.
    Register that is specific to -LP denoted by "_PCH_LP_" in component name.
  - SubsystemName:
    This field indicates the subsystem name of the component that the register belongs to
    (e.g. PCIE, USB, SATA, GPIO, PMC etc.).
  - RegisterSpace:
    MEM - MMIO space register of subsystem.
    IO  - IO space register of subsystem.
    PCR - Private configuration register of subsystem.
    CFG - PCI configuration space register of subsystem.
  - RegisterName:
    Full register name.

  Copyright (c) 2019 Intel Corporation. All rights reserved. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef _REGS_USB_H_
#define _REGS_USB_H_

//
// USB3 (XHCI) related definitions
// @todo: Add CPU PCI defs for xHCI
//
#define PCI_BUS_NUMBER_PCH_XHCI             0
#define PCI_DEVICE_NUMBER_PCH_XHCI          20
#define PCI_FUNCTION_NUMBER_PCH_XHCI        0

//
// xDCI (OTG) USB Device Controller
//
#define PCI_DEVICE_NUMBER_PCH_XDCI              20
#define PCI_FUNCTION_NUMBER_PCH_XDCI            1
#endif // _REGS_USB_H_

