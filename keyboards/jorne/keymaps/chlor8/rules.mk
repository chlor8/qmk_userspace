# Inherit userspace rules; USER_PATH resolves users/chlor8 for the shared code.
USER_NAME = chlor8
SRC += $(USER_PATH)/chlor8.c

# Hold Q (left) or P (right) while plugging USB into that half to enter the bootloader.
BOOTMAGIC_ENABLE = yes
