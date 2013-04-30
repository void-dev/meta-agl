# Common distro configuration for AGL distros

# QEMU targets and settings
QEMU_TARGETS ?= "arm i386 mips mipsel ppc x86_64"
AGLQEMUDEPS = "${@base_contains("INCOMPATIBLE_LICENSE", "GPLv3", "", "qemu-config",d)}"
DISTRO_EXTRA_RDEPENDS_append_qemuarm = " ${AGLQEMUDEPS}"
DISTRO_EXTRA_RDEPENDS_append_qemumips = " ${AGLQEMUDEPS}"
DISTRO_EXTRA_RDEPENDS_append_qemuppc = " ${AGLQEMUDEPS}"
DISTRO_EXTRA_RDEPENDS_append_qemux86 = " ${AGLQEMUDEPS}"
DISTRO_EXTRA_RDEPENDS_append_qemux86-64 = " ${AGLQEMUDEPS}"

# Source mirrors
PREMIRRORS ??= "\
bzr://.*/.*   http://downloads.yoctoproject.org/mirror/sources/ \n \
cvs://.*/.*   http://downloads.yoctoproject.org/mirror/sources/ \n \
git://.*/.*   http://downloads.yoctoproject.org/mirror/sources/ \n \
hg://.*/.*    http://downloads.yoctoproject.org/mirror/sources/ \n \
osc://.*/.*   http://downloads.yoctoproject.org/mirror/sources/ \n \
p4://.*/.*    http://downloads.yoctoproject.org/mirror/sources/ \n \
svk://.*/.*   http://downloads.yoctoproject.org/mirror/sources/ \n \
svn://.*/.*   http://downloads.yoctoproject.org/mirror/sources/ \n"

MIRRORS =+ "\
ftp://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
http://.*/.*     http://downloads.yoctoproject.org/mirror/sources/ \n \
https://.*/.*    http://downloads.yoctoproject.org/mirror/sources/ \n"

# The CONNECTIVITY_CHECK_URI's are used to test whether we can succesfully
# fetch from the network (and warn you if not). To disable the test set
# the variable to be empty.
# Git example url: git://git.yoctoproject.org/yocto-firewall-test;protocol=git;rev=HEAD

CONNECTIVITY_CHECK_URIS ?= " \
             https://eula-downloads.yoctoproject.org/index.php \
             http://bugzilla.yoctoproject.org/report.cgi"

# Default hash policy for distro
BB_SIGNATURE_HANDLER ?= 'OEBasicHash'

#
# OELAYOUT_ABI allows us to notify users when the format of TMPDIR changes in 
# an incompatible way. Such changes should usually be detailed in the commit
# that breaks the format and have been previously discussed on the mailing list 
# with general agreement from the core team.
#
OELAYOUT_ABI = "8"

# Sanity checks
SANITY_TESTED_DISTROS ?= " \
            Yocto-1.2 \n \
            Poky-1.2 \n \
            Poky-1.3 \n \
            Poky-1.4 \n \
            Ubuntu-10.04 \n \
            Ubuntu-11.10 \n \
            Ubuntu-12.04 \n \
            Ubuntu-12.10 \n \
            Fedora-16 \n \
            Fedora-17 \n \
            Fedora-18 \n \
            CentOS-5.6 \n \
            CentOS-5.7 \n \
            CentOS-5.8 \n \
            CentOS-6.3 \n \
            CentOS-6.4 \n \
            Debian-6.0 \n \
            Debian-7.0 \n \
            SUSE-LINUX-11.4 \n \
            SUSE-LINUX-12.1 \n \
            SUSE-LINUX-12.2 \n \
            openSUSE-project-12.3 \n \
            "


# Include this for autotooled packages that support out-of-tree building: ${B} != ${S}
include conf/distro/include/seperatebuilddir.inc
