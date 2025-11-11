use crate::{
    command::{command_to_report, Command},
    usb::Usb,
};
use anyhow::Context;
use hidapi::{HidApi, HidDevice};

const USAGE_PAGE: u16 = 0xFF60;
const USAGE_ID: u16 = 0x61;

pub struct Device {
    device: HidDevice,
}

impl Device {
    pub fn new(usb: Usb) -> anyhow::Result<Self> {
        tracing::debug!("Initializing HID API");

        let api = HidApi::new()?;

        // Find the Raw HID interface
        let device_info = api
            .device_list()
            .filter(|d| {
                d.vendor_id() == usb.vid
                    && d.product_id() == usb.pid
                    && d.usage_page() == USAGE_PAGE
                    && d.usage() == USAGE_ID
            })
            .next()
            .context("Keyboard raw HID interface not found")?;
        let device = device_info.open_device(&api)?;

        tracing::debug!(
            "Opened device: VID={:04x}, PID={:04x}, Path={}",
            usb.vid,
            usb.pid,
            device_info.path().to_string_lossy()
        );

        Ok(Device { device })
    }

    pub fn command<C>(&self, command: C) -> anyhow::Result<()>
    where
        C: Command,
    {
        let report = command_to_report(command)?;

        tracing::debug!("Sending report: {:02x?}", &report);

        self.device.write(&report)?;

        tracing::info!("Command sent successfully");

        Ok(())
    }
}
