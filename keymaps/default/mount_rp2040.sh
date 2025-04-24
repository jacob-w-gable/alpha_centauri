#!/bin/bash

set -e

TARGET_LABEL="RPI-RP2"
MOUNT_POINT="/media/$USER/$TARGET_LABEL"
DEVICE=""

echo "[*] Waiting for RP2040 (label: $TARGET_LABEL)..."

# Wait up to 10 seconds for the device to appear
for i in {1..120}; do
  DEVICE=$(lsblk -o NAME,LABEL -r | grep "$TARGET_LABEL" | awk '{print "/dev/" $1}')
  if [[ -n "$DEVICE" ]]; then
    echo "[+] Found device at $DEVICE"
    break
  fi
  sleep 0.5
done

if [[ -z "$DEVICE" ]]; then
  echo "[!] RP2040 device not found."
  exit 1
fi

# Mount with user permissions
echo "[*] Mounting $DEVICE to $MOUNT_POINT..."
for i in {1..20}; do
  if udisksctl info -b "$DEVICE" &>/dev/null; then
    echo "[+] Device ready in UDisks"
    break
  fi
  sleep 0.5
done
udisksctl mount -b "$DEVICE"

if mountpoint -q "$MOUNT_POINT"; then
  echo "[✓] Mounted at $MOUNT_POINT"
else
  echo "[!] Mount failed."
  exit 1
fi
