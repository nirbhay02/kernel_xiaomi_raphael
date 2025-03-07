/*
Copyright (c) 2017, 2019 The Linux Foundation. All rights reserved.
Copyright (C) 2019 XiaoMi, Inc.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License version 2 and
only version 2 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*
*/

#include <linux/kernel.h>
#include <linux/module.h>
#include "q6_init.h"

static int __init audio_q6_init(void)
{
	adsp_err_init();
	audio_cal_init();
	rtac_init();
	adm_init();
	afe_init();
	spk_params_init();
	q6asm_init();
	q6lsm_init();
	voice_init();
	core_init();
	msm_audio_ion_init();
	audio_slimslave_init();
	avtimer_init();
#ifdef CONFIG_MSM_CSPL
	crus_sp_init();
#endif
	msm_mdf_init();
#if CONFIG_VOICE_MHI
	voice_mhi_init();
#endif
#ifdef CONFIG_ELLIPTIC_ULTRASOUND
	elliptic_driver_init();
#endif
/* for mius start */
#ifdef CONFIG_US_PROXIMITY
	mius_driver_init();
#endif
/* for mius end */
	return 0;
}

static void __exit audio_q6_exit(void)
{
	msm_mdf_exit();
#ifdef CONFIG_MSM_CSPL
	crus_sp_exit();
#endif
	avtimer_exit();
	audio_slimslave_exit();
	msm_audio_ion_exit();
	core_exit();
	voice_exit();
	q6lsm_exit();
	q6asm_exit();
	afe_exit();
	spk_params_exit();
	adm_exit();
	rtac_exit();
	audio_cal_exit();
	adsp_err_exit();
#if CONFIG_VOICE_MHI
	voice_mhi_exit();
#endif
#ifdef CONFIG_ELLIPTIC_ULTRASOUND
	elliptic_driver_exit();
#endif
/* for mius start */
#ifdef CONFIG_US_PROXIMITY
	mius_driver_exit();
#endif
/* for mius end */
}

module_init(audio_q6_init);
module_exit(audio_q6_exit);
MODULE_DESCRIPTION("Q6 module");
MODULE_LICENSE("GPL v2");
