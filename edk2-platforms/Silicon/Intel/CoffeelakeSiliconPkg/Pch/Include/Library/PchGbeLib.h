/** @file
  Header file for PchGbeLib.

  Copyright (c) 2019 Intel Corporation. All rights reserved. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef _PCH_GBE_LIB_H_
#define _PCH_GBE_LIB_H_

/**
  Check whether GbE region is valid
  Check SPI region directly since GBE might be disabled in SW.

  @retval TRUE                    Gbe Region is valid
  @retval FALSE                   Gbe Region is invalid
**/
BOOLEAN
PchIsGbeRegionValid (
  VOID
  );


/**
  Check whether LAN controller is enabled in the platform.

  @retval TRUE                    GbE is enabled
  @retval FALSE                   GbE is disabled
**/
BOOLEAN
PchIsGbePresent (
  VOID
  );

#endif // _PCH_GBE_LIB_H_
