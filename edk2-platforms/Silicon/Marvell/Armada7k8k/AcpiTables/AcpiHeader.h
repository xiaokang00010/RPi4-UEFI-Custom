/** @file

  Multiple APIC Description Table (MADT)

  Copyright (c) 2017, Linaro Ltd. All rights reserved.<BR>
  Copyright (C) 2018, Marvell International Ltd. and its affiliates.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <IndustryStandard/Acpi.h>

#define ACPI_OEM_ID_ARRAY        {'M','V','E','B','U',' '}
#define ACPI_OEM_REVISION        0
#define ACPI_CREATOR_ID          SIGNATURE_32('L','N','R','O')
#define ACPI_CREATOR_REVISION    0

#if defined(ARMADA7K)
#define ACPI_OEM_TABLE_ID        SIGNATURE_64('A','R','M','A','D','A','7','K')
#elif defined (ARMADA8K)
#define ACPI_OEM_TABLE_ID        SIGNATURE_64('A','R','M','A','D','A','8','K')
#endif

/**
 * A macro to initialize the common header part of EFI ACPI tables
 * as defined by EFI_ACPI_DESCRIPTION_HEADER structure.
 **/
#define __ACPI_HEADER(sign, type, rev) {                \
  sign,                   /* UINT32  Signature */       \
  sizeof (type),          /* UINT32  Length */          \
  rev,                    /* UINT8   Revision */        \
  0,                      /* UINT8   Checksum */        \
  ACPI_OEM_ID_ARRAY,      /* UINT8   OemId[6] */        \
  ACPI_OEM_TABLE_ID,      /* UINT64  OemTableId */      \
  ACPI_OEM_REVISION,      /* UINT32  OemRevision */     \
  ACPI_CREATOR_ID,        /* UINT32  CreatorId */       \
  ACPI_CREATOR_REVISION   /* UINT32  CreatorRevision */ \
  }
