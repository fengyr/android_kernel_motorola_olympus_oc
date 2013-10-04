/*
 * include/asm-arm/arch-tegra/include/mach/sdhci.h
 *
 * Copyright (C) 2009 Palm, Inc.
 * Copyright 2013: Olympus Kernel Project
 * <http://forum.xda-developers.com/showthread.php?t=2016837>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __ASM_ARM_ARCH_TEGRA_SDHCI_H
#define __ASM_ARM_ARCH_TEGRA_SDHCI_H

#include <linux/mmc/host.h>
#include <asm/mach/mmc.h>

struct tegra_sdhci_platform_data {
	int cd_gpio;
	int wp_gpio;
	int power_gpio;
	int is_8bit;
	int pm_flags;
	int pm_caps;
	unsigned int max_clk_limit;
	unsigned int tap_delay;
	struct mmc_platform_data mmc_data;
#ifdef CONFIG_MACH_OLYMPUS

#ifdef CONFIG_MMC_START_OFFSET
	unsigned long start_offset;	/* offset in blocks to MBR */
#endif

	unsigned int ocr_mask;	/* available voltages */
	int (*register_status_notify)\
		(void (*callback)(void *dev_id), void *dev_id);
	struct embedded_sdio_data *embedded_sdio;
#endif
};

#endif