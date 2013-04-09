DESCRIPTION = "An Automotive Grade Linux (AGL) image."
LICENSE = "MIT"

PV = "0.0.0"
PR = "r1"

# core-image-minimal
IMAGE_INSTALL = "packagegroup-core-boot ${ROOTFS_PKGMANAGE_BOOTSTRAP} ${CORE_IMAGE_EXTRA_INSTALL}"

# core-imgae-x11
IMAGE_FEATURES += "splash package-management x11-base"

EXTRA_IMAGE_FEATURES = "debug-tweaks"
EXTRA_IMAGEDEPENDS += "qemu-native qemu-helper-native"

IMAGE_LINGUAS = " "

inherit core-image buildhistory
BUILDHISTORY_COMMIT = "1"
IMAGE_ROOTFS_SIZE = "8192"

# Add image specific packages
IMAGE_INSTALL_append = " packagegroup-agl"
