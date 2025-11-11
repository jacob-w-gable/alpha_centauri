use crate::{args::parse_args, device::Device};
use std::path::Path;
use tracing_subscriber::{fmt, layer::SubscriberExt, util::SubscriberInitExt, EnvFilter, Layer};

mod args;
mod command;
mod device;
mod usb;

fn main() -> anyhow::Result<()> {
    initialize_tracing();

    let command = parse_args()?;

    let home_dir = std::env::var("HOME")?;
    let keyboard_config_path = Path::new(&home_dir)
        .join("Projects")
        .join("alpha_centauri")
        .join("keyboard.json");

    tracing::debug!("Using keyboard config path: {:?}", keyboard_config_path);

    let usb = usb::get_usb(keyboard_config_path)?;
    let device = Device::new(usb)?;

    device.command(command)
}

fn initialize_tracing() {
    let env_filter_layer =
        EnvFilter::try_from_default_env().unwrap_or_else(|_| EnvFilter::new("info,rgb_ctrl=debug"));
    let fmt_layer = fmt::layer()
        .with_target(false)
        .with_filter(env_filter_layer);

    tracing_subscriber::registry().with(fmt_layer).init();
}
