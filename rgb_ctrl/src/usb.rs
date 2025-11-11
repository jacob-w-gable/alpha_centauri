use serde::Deserialize;
use std::{fs, path::Path};

#[derive(Deserialize)]
struct Config {
    usb: Usb,
}

#[derive(Deserialize)]
pub struct Usb {
    #[serde(deserialize_with = "hex_to_u16")]
    pub vid: u16,
    #[serde(deserialize_with = "hex_to_u16")]
    pub pid: u16,
}

fn hex_to_u16<'de, D>(deserializer: D) -> Result<u16, D::Error>
where
    D: serde::Deserializer<'de>,
{
    let s: &str = Deserialize::deserialize(deserializer)?;
    u16::from_str_radix(s.trim_start_matches("0x"), 16).map_err(serde::de::Error::custom)
}

pub fn get_usb<T: AsRef<Path>>(path: T) -> anyhow::Result<Usb> {
    let keyboard_config = fs::read_to_string(path)?;

    Ok(serde_json::from_str::<Config>(keyboard_config.as_str())
        .inspect(|config| {
            tracing::debug!(
                "USB Config: VID={:04x}, PID={:04x}",
                config.usb.vid,
                config.usb.pid
            )
        })?
        .usb)
}
