#ifndef INTEL_DRIVER_H
#define INTEL_DRIVER_H

#define INTEL_VERSION 4000
#define INTEL_NAME "intel"
#define INTEL_DRIVER_NAME "intel"

#define INTEL_VERSION_MAJOR PACKAGE_VERSION_MAJOR
#define INTEL_VERSION_MINOR PACKAGE_VERSION_MINOR
#define INTEL_VERSION_PATCH PACKAGE_VERSION_PATCHLEVEL

#ifndef PCI_CHIP_I810
#define PCI_CHIP_I810              0x7121
#define PCI_CHIP_I810_DC100        0x7123
#define PCI_CHIP_I810_E            0x7125
#define PCI_CHIP_I815              0x1132
#define PCI_CHIP_I810_BRIDGE       0x7120
#define PCI_CHIP_I810_DC100_BRIDGE 0x7122
#define PCI_CHIP_I810_E_BRIDGE     0x7124
#define PCI_CHIP_I815_BRIDGE       0x1130
#endif

#ifndef PCI_CHIP_I830_M
#define PCI_CHIP_I830_M            0x3577
#define PCI_CHIP_I830_M_BRIDGE     0x3575
#endif

#ifndef PCI_CHIP_845_G
#define PCI_CHIP_845_G		   0x2562
#define PCI_CHIP_845_G_BRIDGE	   0x2560
#endif

#ifndef PCI_CHIP_I854
#define PCI_CHIP_I854		   0x358E
#define PCI_CHIP_I854_BRIDGE	   0x358C
#endif

#ifndef PCI_CHIP_I855_GM
#define PCI_CHIP_I855_GM	   0x3582
#define PCI_CHIP_I855_GM_BRIDGE	   0x3580
#endif

#ifndef PCI_CHIP_I865_G
#define PCI_CHIP_I865_G		   0x2572
#define PCI_CHIP_I865_G_BRIDGE	   0x2570
#endif

#ifndef PCI_CHIP_I915_G
#define PCI_CHIP_I915_G		   0x2582
#define PCI_CHIP_I915_G_BRIDGE	   0x2580
#endif

#ifndef PCI_CHIP_I915_GM
#define PCI_CHIP_I915_GM	   0x2592
#define PCI_CHIP_I915_GM_BRIDGE	   0x2590
#endif

#ifndef PCI_CHIP_E7221_G
#define PCI_CHIP_E7221_G	   0x258A
/* Same as I915_G_BRIDGE */
#define PCI_CHIP_E7221_G_BRIDGE	   0x2580
#endif

#ifndef PCI_CHIP_I945_G
#define PCI_CHIP_I945_G        0x2772
#define PCI_CHIP_I945_G_BRIDGE 0x2770
#endif

#ifndef PCI_CHIP_I945_GM
#define PCI_CHIP_I945_GM        0x27A2
#define PCI_CHIP_I945_GM_BRIDGE 0x27A0
#endif

#ifndef PCI_CHIP_I945_GME
#define PCI_CHIP_I945_GME	 0x27AE
#define PCI_CHIP_I945_GME_BRIDGE 0x27AC
#endif

#ifndef PCI_CHIP_IGD_GM
#define PCI_CHIP_IGD_GM		0xA011
#define PCI_CHIP_IGD_GM_BRIDGE	0xA010
#define PCI_CHIP_IGD_G		0xA001
#define PCI_CHIP_IGD_G_BRIDGE	0xA000
#endif

#ifndef PCI_CHIP_G35_G
#define PCI_CHIP_G35_G		0x2982
#define PCI_CHIP_G35_G_BRIDGE 	0x2980
#endif

#ifndef PCI_CHIP_I965_Q
#define PCI_CHIP_I965_Q		0x2992
#define PCI_CHIP_I965_Q_BRIDGE 	0x2990
#endif

#ifndef PCI_CHIP_I965_G
#define PCI_CHIP_I965_G		0x29A2
#define PCI_CHIP_I965_G_BRIDGE 	0x29A0
#endif

#ifndef PCI_CHIP_I946_GZ
#define PCI_CHIP_I946_GZ		0x2972
#define PCI_CHIP_I946_GZ_BRIDGE 	0x2970
#endif

#ifndef PCI_CHIP_I965_GM
#define PCI_CHIP_I965_GM        0x2A02
#define PCI_CHIP_I965_GM_BRIDGE 0x2A00
#endif

#ifndef PCI_CHIP_I965_GME
#define PCI_CHIP_I965_GME       0x2A12
#define PCI_CHIP_I965_GME_BRIDGE 0x2A10
#endif

#ifndef PCI_CHIP_G33_G
#define PCI_CHIP_G33_G		0x29C2
#define PCI_CHIP_G33_G_BRIDGE 	0x29C0
#endif

#ifndef PCI_CHIP_Q35_G
#define PCI_CHIP_Q35_G		0x29B2
#define PCI_CHIP_Q35_G_BRIDGE 	0x29B0
#endif

#ifndef PCI_CHIP_Q33_G
#define PCI_CHIP_Q33_G		0x29D2
#define PCI_CHIP_Q33_G_BRIDGE 	0x29D0
#endif

#ifndef PCI_CHIP_GM45_GM
#define PCI_CHIP_GM45_GM	0x2A42
#define PCI_CHIP_GM45_BRIDGE    0x2A40
#endif

#ifndef PCI_CHIP_IGD_E_G
#define PCI_CHIP_IGD_E_G	0x2E02
#define PCI_CHIP_IGD_E_G_BRIDGE 0x2E00
#endif

#ifndef PCI_CHIP_G45_G
#define PCI_CHIP_G45_G		0x2E22
#define PCI_CHIP_G45_G_BRIDGE	0x2E20
#endif

#ifndef PCI_CHIP_Q45_G
#define PCI_CHIP_Q45_G		0x2E12
#define PCI_CHIP_Q45_G_BRIDGE	0x2E10
#endif

#ifndef PCI_CHIP_G41_G
#define PCI_CHIP_G41_G		0x2E32
#define PCI_CHIP_G41_G_BRIDGE	0x2E30
#endif

#ifndef PCI_CHIP_B43_G
#define PCI_CHIP_B43_G		0x2E42
#define PCI_CHIP_B43_G_BRIDGE	0x2E40
#endif

#ifndef PCI_CHIP_B43_G1
#define PCI_CHIP_B43_G1		0x2E92
#define PCI_CHIP_B43_G1_BRIDGE	0x2E90
#endif

#ifndef PCI_CHIP_IGDNG_D_G
#define PCI_CHIP_IGDNG_D_G		0x0042
#define PCI_CHIP_IGDNG_D_G_BRIDGE	0x0040
#endif

#ifndef PCI_CHIP_IGDNG_M_G
#define PCI_CHIP_IGDNG_M_G		0x0046
#define PCI_CHIP_IGDNG_M_G_BRIDGE	0x0044
#endif

#ifndef PCI_CHIP_SANDYBRIDGE_BRIDGE
#define PCI_CHIP_SANDYBRIDGE_BRIDGE	0x0100	/* Desktop */
#define PCI_CHIP_SANDYBRIDGE_GT1	0x0102
#define PCI_CHIP_SANDYBRIDGE_GT2	0x0112
#define PCI_CHIP_SANDYBRIDGE_GT2_PLUS	0x0122
#define PCI_CHIP_SANDYBRIDGE_BRIDGE_M	0x0104	/* Mobile */
#define PCI_CHIP_SANDYBRIDGE_M_GT1	0x0106
#define PCI_CHIP_SANDYBRIDGE_M_GT2	0x0116
#define PCI_CHIP_SANDYBRIDGE_M_GT2_PLUS	0x0126
#define PCI_CHIP_SANDYBRIDGE_BRIDGE_S	0x0108	/* Server */
#define PCI_CHIP_SANDYBRIDGE_S_GT	0x010A
#endif

#define I85X_CAPID			0x44
#define I85X_VARIANT_MASK			0x7
#define I85X_VARIANT_SHIFT			5
#define I855_GME				0x0
#define I855_GM					0x4
#define I852_GME				0x2
#define I852_GM					0x5

#define I810_MEMBASE(p,n) (p)->regions[(n)].base_addr
#define VENDOR_ID(p)      (p)->vendor_id
#define DEVICE_ID(p)      (p)->device_id
#define SUBVENDOR_ID(p)	  (p)->subvendor_id
#define SUBSYS_ID(p)      (p)->subdevice_id
#define CHIP_REVISION(p)  (p)->revision

#define IS_I810(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I810 ||	\
			DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I810_DC100 || \
			DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I810_E)
#define IS_I815(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I815)
#define IS_I830(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I830_M)
#define IS_845G(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_845_G)
#define IS_I85X(pI810)  (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I855_GM || \
			 DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I854)
#define IS_I852(pI810)  (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I855_GM && (pI810->variant == I852_GM || pI810->variant == I852_GME))
#define IS_I854(pI810)  (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I854)
#define IS_I855(pI810)  (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I855_GM && (pI810->variant == I855_GM || pI810->variant == I855_GME))
#define IS_I865G(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I865_G)
#define IS_I8XX(pI810)	(IS_I830(pI810) || IS_845G(pI810) || IS_I85X(pI810) || IS_I865G(pI810))

#define IS_I915G(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I915_G || DEVICE_ID(pI810->PciInfo) == PCI_CHIP_E7221_G)
#define IS_I915GM(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I915_GM)
#define IS_I945G(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I945_G)
#define IS_I945GM(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I945_GM || DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I945_GME)
#define IS_IGDGM(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_IGD_GM)
#define IS_IGDG(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_IGD_G)
#define IS_IGD(pI810) (IS_IGDG(pI810) || IS_IGDGM(pI810))
#define IS_GM45(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_GM45_GM)
#define IS_G4X(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_IGD_E_G || DEVICE_ID(pI810->PciInfo) == PCI_CHIP_G45_G || DEVICE_ID(pI810->PciInfo) == PCI_CHIP_Q45_G || DEVICE_ID(pI810->PciInfo) == PCI_CHIP_G41_G || DEVICE_ID(pI810->PciInfo) == PCI_CHIP_B43_G || IS_GM45(pI810))
#define IS_I965GM(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I965_GM || DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I965_GME)
#define IS_965_Q(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I965_Q)
#define IS_IGDNG_D(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_IGDNG_D_G)
#define IS_IGDNG_M(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_IGDNG_M_G)
#define IS_IGDNG(pI810) (IS_IGDNG_D(pI810) || IS_IGDNG_M(pI810))
#define IS_I965G(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I965_G || \
			 DEVICE_ID(pI810->PciInfo) == PCI_CHIP_G35_G || \
			 DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I965_Q || \
			 DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I946_GZ || \
			 DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I965_GM || \
			 DEVICE_ID(pI810->PciInfo) == PCI_CHIP_I965_GME || \
			 IS_G4X(pI810) || \
			 IS_IGDNG(pI810) || \
			 IS_GEN6(pI810))
#define IS_G33CLASS(pI810) (DEVICE_ID(pI810->PciInfo) == PCI_CHIP_G33_G ||\
 			    DEVICE_ID(pI810->PciInfo) == PCI_CHIP_Q35_G ||\
			    DEVICE_ID(pI810->PciInfo) == PCI_CHIP_Q33_G || \
			    IS_IGD(pI810))

#define IS_I9XX(pI810) (IS_I915G(pI810) ||			\
			IS_I915GM(pI810) ||			\
			IS_I945G(pI810) ||			\
			IS_I945GM(pI810) ||			\
			IS_I965G(pI810) ||			\
			IS_G33CLASS(pI810))

#define IS_I915(pI810) (IS_I915G(pI810) || IS_I915GM(pI810) || IS_I945G(pI810) || IS_I945GM(pI810) || IS_G33CLASS(pI810))

#define IS_GEN6(pI810) ((pI810)->PciInfo->device_id == PCI_CHIP_SANDYBRIDGE_GT1 || \
			(pI810)->PciInfo->device_id == PCI_CHIP_SANDYBRIDGE_GT2 || \
			(pI810)->PciInfo->device_id == PCI_CHIP_SANDYBRIDGE_GT2_PLUS || \
			(pI810)->PciInfo->device_id == PCI_CHIP_SANDYBRIDGE_M_GT1 ||\
			(pI810)->PciInfo->device_id == PCI_CHIP_SANDYBRIDGE_M_GT2 || \
			(pI810)->PciInfo->device_id == PCI_CHIP_SANDYBRIDGE_M_GT2_PLUS ||\
			(pI810)->PciInfo->device_id == PCI_CHIP_SANDYBRIDGE_S_GT)

#define IS_MOBILE(pI810) (IS_I830(pI810) || IS_I85X(pI810) || IS_I915GM(pI810) || IS_I945GM(pI810) || IS_I965GM(pI810) || IS_GM45(pI810) || IS_IGD(pI810) || IS_IGDNG_M(pI810))
/* supports Y tiled surfaces (pre-965 Mesa isn't ready yet) */
#define SUPPORTS_YTILING(pI810) (IS_I965G(intel))

extern SymTabRec *intel_chipsets;

struct intel_chipset {
    const char *name;
    int variant;
};

void intel_detect_chipset(ScrnInfoPtr scrn,
			  struct pci_device *pci,
			  struct intel_chipset *chipset);

#endif /* INTEL_DRIVER_H */
