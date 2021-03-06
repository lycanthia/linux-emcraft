/*
 *  arch/arm/mach-vexpress/include/mach/hardware.h
 *
 *  This file contains the hardware definitions for the Versatile Express boards.
 *
 *  Copyright (C) 2009 ARM Limited.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef __ASM_ARCH_HARDWARE_H
#define __ASM_ARCH_HARDWARE_H

#include <asm/sizes.h>

/*
 * System Register Interface
 */
#define ARM_VEXPRESS_SYS_CFG_DATA	0x100000A0
#define ARM_VEXPRESS_SYS_CFG_CTRL	0x100000A4
#define ARM_VEXPRESS_SYS_CFG_STAT	0x100000A8

/* macro to get at IO space when running virtually */
/*
 * Statically mapped addresses:
 *
 * 10xx xxxx -> fbxx xxxx
 * 1exx xxxx -> fdxx xxxx
 * 1fxx xxxx -> fexx xxxx
 */
#ifdef CONFIG_MMU
#define IO_ADDRESS(x)		(((x) & 0x03ffffff) + 0xfb000000)
#else
#define IO_ADDRESS(x)		(x)
#endif
#define __io_address(n)		__io(IO_ADDRESS(n))

#endif
