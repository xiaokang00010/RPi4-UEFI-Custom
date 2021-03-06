//
//  Copyright (c) 2012-2013, ARM Limited. All rights reserved.
//
//  SPDX-License-Identifier: BSD-2-Clause-Patent
//
//

#include <Library/ArmLib.h>

#include <ArmPlatform.h>

  INCLUDE AsmMacroIoLib.inc

  EXPORT  ArmPlatformPeiBootAction
  EXPORT  ArmPlatformGetCorePosition
  EXPORT  ArmPlatformIsPrimaryCore
  EXPORT  ArmPlatformGetPrimaryCoreMpId

  PRESERVE8
  AREA    CTA15A7Helper, CODE, READONLY

ArmPlatformPeiBootAction FUNCTION
  bx    lr
  ENDFUNC

//UINTN
//ArmPlatformGetCorePosition (
//  IN UINTN MpId
//  );
ArmPlatformGetCorePosition FUNCTION
  and   r1, r0, #ARM_CORE_MASK
  and   r0, r0, #ARM_CLUSTER_MASK
  add   r0, r1, r0, LSR #7
  bx    lr
  ENDFUNC

//UINTN
//ArmPlatformIsPrimaryCore (
//  IN UINTN MpId
//  );
ArmPlatformIsPrimaryCore FUNCTION
  // Extract cpu_id and cluster_id from ARM_SCC_CFGREG48
  // with cpu_id[0:3] and cluster_id[4:7]
  mov32 r1, ARM_CTA15A7_SCC_CFGREG48
  ldr   r1, [r1]
  lsr   r1, #24

  // Shift the SCC value to get the cluster ID at the offset #8
  lsl   r2, r1, #4
  and   r2, r2, #0xF00

  // Keep only the cpu ID from the original SCC
  and   r1, r1, #0x0F
  // Add the Cluster ID to the Cpu ID
  orr   r1, r1, r2

  // Keep the Cluster ID and Core ID from the MPID
  mov32 r2, ARM_CLUSTER_MASK :OR: ARM_CORE_MASK
  and   r0, r0, r2

  // Compare mpid and boot cpu from ARM_SCC_CFGREG48
  cmp   r0, r1
  moveq r0, #1
  movne r0, #0
  bx    lr
  ENDFUNC

//UINTN
//ArmPlatformGetPrimaryCoreMpId (
//  VOID
//  );
ArmPlatformGetPrimaryCoreMpId FUNCTION
  // Extract cpu_id and cluster_id from ARM_SCC_CFGREG48
  // with cpu_id[0:3] and cluster_id[4:7]
  mov32 r0, ARM_CTA15A7_SCC_CFGREG48
  ldr   r0, [r0]
  lsr   r0, #24

  // Shift the SCC value to get the cluster ID at the offset #8
  lsl   r1, r0, #4
  and   r1, r1, #0xF00

  // Keep only the cpu ID from the original SCC
  and   r0, r0, #0x0F
  // Add the Cluster ID to the Cpu ID
  orr   r0, r0, r1
  bx    lr
  ENDFUNC

  END
