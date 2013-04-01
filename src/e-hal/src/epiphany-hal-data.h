/*
  File: epiphany-hal-data.h

  This file is part of the Epiphany Software Development Kit.

  Copyright (C) 2013 Adapteva, Inc.
  Contributed by Yaniv Sapir <support@adapteva.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License (LGPL)
  as published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  and the GNU Lesser General Public License along with this program,
  see the files COPYING and COPYING.LESSER.  If not, see
  <http://www.gnu.org/licenses/>.
*/

#ifndef __E_HAL_DATA_H__
#define __E_HAL_DATA_H__

#include "epiphany-hal-data-local.h"

#ifdef __cplusplus
extern "C"
{
typedef enum {
	e_false = false,
	e_true  = true,
} e_bool_t;
#else
typedef enum {
	e_false = 0,
	e_true  = 1,
} e_bool_t;
#endif


typedef enum {
	H_D0 = 0,
	H_D1 = 1,
	H_D2 = 2,
	H_D3 = 3,
	H_D4 = 4,
} e_hal_diag_t;


typedef enum {
	EPI_OK   =  0,
	EPI_ERR  = -1,
	EPI_WARN = -2,
} e_return_stat_t;


// Core Registers
#define EPI_CORE_REG_BASE   0xf0000
#define EPI_CONFIG          (EPI_CORE_REG_BASE + 0x0400)
#define EPI_STATUS          (EPI_CORE_REG_BASE + 0x0404)
#define EPI_PC              (EPI_CORE_REG_BASE + 0x0408)
#define EPI_IRET            (EPI_CORE_REG_BASE + 0x0420)
#define EPI_IMASK           (EPI_CORE_REG_BASE + 0x0424)
#define EPI_ILAT            (EPI_CORE_REG_BASE + 0x0428)
#define EPI_ILATST          (EPI_CORE_REG_BASE + 0x042C)
#define EPI_ILATCL          (EPI_CORE_REG_BASE + 0x0430)
#define EPI_IPEND           (EPI_CORE_REG_BASE + 0x0434)
#define EPI_HWSTATUS        (EPI_CORE_REG_BASE + 0x0444)
#define EPI_DEBUGCMD        (EPI_CORE_REG_BASE + 0x0448)
#define EPI_COREID          (EPI_CORE_REG_BASE + 0x0704)
#define EPI_CORE_RESET      (EPI_CORE_REG_BASE + 0x070c)
#define EPI_CMESH_ROUTE     (EPI_CORE_REG_BASE + 0x0710)
#define EPI_XMESH_ROUTE     (EPI_CORE_REG_BASE + 0x0714)
#define EPI_RDMESH_ROUTE    (EPI_CORE_REG_BASE + 0x0718)

// Chip registers
#define EPI_CHIP_REG_BASE   0xf0000
#define EPI_IO_TX_CFG       (EPI_CHIP_REG_BASE + 0x0300)
#define EPI_IO_TX_IO        (EPI_CHIP_REG_BASE + 0x0304)
#define EPI_IO_RX_IO        (EPI_CHIP_REG_BASE + 0x0308)
#define EPI_IO_GPIO_IO      (EPI_CHIP_REG_BASE + 0x030c)
#define EPI_IO_DFT_MON      (EPI_CHIP_REG_BASE + 0x0318)
#define EPI_IO_SYNC         (EPI_CHIP_REG_BASE + 0x031c)
#define EPI_IO_HALT         (EPI_CHIP_REG_BASE + 0x0320)
#define EPI_IO_RESET        (EPI_CHIP_REG_BASE + 0x0324)
#define EPI_IO_BYPASS_CFG   (EPI_CHIP_REG_BASE + 0x0328)
#define EPI_IO_SPI_TX_CFG   (EPI_CHIP_REG_BASE + 0x032c)
#define EPI_IO_SPI_RX_CFG   (EPI_CHIP_REG_BASE + 0x0330)

// Epiphany system registers
#define EPI_SYS_REG_BASE    0x00000000
#define ESYS_CONFIG         (EPI_SYS_REG_BASE + 0x0000)
#define ESYS_RESET          (EPI_SYS_REG_BASE + 0x0004)
#define ESYS_VERSION        (EPI_SYS_REG_BASE + 0x0008)
#define ESYS_FILTERL        (EPI_SYS_REG_BASE + 0x000c)
#define ESYS_FILTERH        (EPI_SYS_REG_BASE + 0x0010)
#define ESYS_FILTERC        (EPI_SYS_REG_BASE + 0x0014)
#define ESYS_TIMEOUT        (EPI_SYS_REG_BASE + 0x0018)


// Core group data structures
typedef struct {
	e_objytpe_t      objtype;     // object type identifier
	e_chiptype_t     type;        // Epiphany chip part number
	unsigned int     num_cores;   // number of cores group
	unsigned int     base_coreid; // group base core ID
	unsigned int     row;         // group absolute row number
	unsigned int     col;         // group absolute col number
	unsigned int     rows;        // number of rows group
	unsigned int     cols;        // number of cols group
	e_core_t       **core;        // e-cores data structures array
	int              memfd;       // for mmap
} e_epiphany_t;


typedef struct {
	e_objytpe_t      objtype;     // object type identifier
	off_t            phy_base;    // physical global base address of external memory buffer as seen by host side
	size_t           map_size;    // size of eDRAM allocated buffer for host side
	off_t            ephy_base;   // physical global base address of external memory buffer as seen by device side
	size_t           emap_size;   // size of eDRAM allocated buffer for device side
	off_t            map_mask;    // for mmap
	void            *mapped_base; // for mmap
	void            *base;        // application space base address of external memory buffer
	int              memfd;       // for mmap
} e_mem_t;


#ifdef __cplusplus
}
#endif

#endif // __E_HAL_DATA_H__
