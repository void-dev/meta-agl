DESCRIPTION = "EFL packages required for AGL"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

inherit packagegroup

PACKAGES = "\
    packagegroup-efl-agl \
    "

RDEPENDS_packagegroup-efl-agl = "\
    eina \
    eet \
    evas \
    ecore \
    eio \
    embryo \
    edje \
    efreet \
    edbus \
    eeze \
    emotion \
    ethumb \
    elementary \
    expedite \
    "

RRECOMMENDS_${PN} = "\
    "
